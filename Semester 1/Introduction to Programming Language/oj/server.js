const express = require('express');
const fs = require('fs');
const path = require('path');
const fetch = require('node-fetch');
const bodyParser = require('body-parser');

const app = express();
const DATA_FILE = path.join(__dirname, 'data.json');
const PORT = process.env.PORT || 3000;

app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, 'public')));

// Load or init data
let data = { participants: {} };
try {
  if (fs.existsSync(DATA_FILE)) {
    data = JSON.parse(fs.readFileSync(DATA_FILE, 'utf8'));
  }
} catch (e) {
  console.error('Failed to read data.json', e);
}

function saveData() {
  fs.writeFileSync(DATA_FILE, JSON.stringify(data, null, 2));
}

// Helper to get client IP (works behind proxies if set)
function getClientIp(req) {
  const forwarded = req.headers['x-forwarded-for'];
  if (forwarded) return forwarded.split(',')[0].trim();
  return req.connection.remoteAddress || req.ip;
}

// Start endpoint: registers participant. One start per IP allowed.
app.post('/api/start', (req, res) => {
  const { name, batch } = req.body;
  if (!name || !batch) return res.status(400).json({ error: 'name and batch required' });
  const ip = getClientIp(req);
  if (data.participants[ip] && data.participants[ip].started) {
    return res.status(403).json({ error: 'This IP already started the contest' });
  }
  const token = Math.random().toString(36).slice(2,10);
  data.participants[ip] = {
    name,
    batch,
    started: true,
    token,
    startTime: Date.now(),
    score: 0,
    solved: {}
  };
  saveData();
  res.json({ token, startTime: data.participants[ip].startTime });
});

// Return problems
app.get('/api/problems', (req, res) => {
  const problems = [
    {
      id: 1,
      title: 'Hello World',
      samples: [{input:'', expected:'Hello World'}],
      template: '#include <stdio.h>\\nint main(){printf("Hello World\\n");return 0;}'
    },
    {
      id: 2,
      title: 'Sum of Two Numbers',
      samples: [{input:'3 5', expected:'8'},{input:'-2 10', expected:'8'}],
      template: '#include <stdio.h>\\nint main(){int a,b; if(scanf("%d %d",&a,&b)==2) printf("%d\\n",a+b); return 0;}'
    },
    {
      id: 3,
      title: 'Leap Year',
      samples: [{input:'2000', expected:'Leap Year'},{input:'1900', expected:'Not Leap Year'},{input:'2004', expected:'Leap Year'}],
      template: '#include <stdio.h>\\nint main(){int y; if(scanf("%d",&y)==1){ if((y%4==0 && y%100!=0) || (y%400==0)) printf("Leap Year\\n"); else printf("Not Leap Year\\n"); } return 0;}'
    }
  ];
  res.json({ problems });
});

// Proxy compile requests to Wandbox to avoid CORS and hide API use
app.post('/api/compile', async (req, res) => {
  const { code, stdin } = req.body;
  if (!code) return res.status(400).json({ error: 'code required' });

  try {
    const response = await fetch('https://wandbox.org/api/compile.json', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ code, compiler: 'gcc-head', options: '-std=c11 -O2', stdin: stdin || '' })
    });
    const dataResp = await response.json();
    res.json(dataResp);
  } catch (err) {
    console.error('Compile proxy error', err);
    res.status(500).json({ error: 'Compile service error' });
  }
});

// Simple submit endpoint to check samples and award points once per problem per participant
app.post('/api/submit', async (req, res) => {
  const { token, problemId, code } = req.body;
  if (!token || !problemId || !code) return res.status(400).json({ error: 'token, problemId and code required' });

  const ip = getClientIp(req);
  const p = data.participants[ip];
  if (!p || p.token !== token) return res.status(403).json({ error: 'Invalid token or not started' });

  // get problem specification
  const problems = (await (await fetch('http://localhost:'+PORT+'/api/problems')).json()).problems;
  const prob = problems.find(x => x.id === problemId);
  if (!prob) return res.status(404).json({ error: 'Problem not found' });

  // run through samples
  try {
    const results = [];
    for (let s of prob.samples) {
      const resp = await fetch('https://wandbox.org/api/compile.json', {
        method: 'POST',
        headers: { 'Content-Type':'application/json' },
        body: JSON.stringify({ code, compiler: 'gcc-head', options: '-std=c11 -O2', stdin: s.input || '' })
      });
      const jr = await resp.json();
      const out = (jr.program_output || '').replace(/\r/g,'').trim();
      results.push({ expected: s.expected.trim(), output: out, status: jr.status });
    }

    const allPassed = results.every(r => r.status == 0 && r.output === r.expected);
    if (allPassed && !p.solved[problemId]) {
      p.solved[problemId] = true;
      p.score = (p.score || 0) + 10;
      saveData();
    }

    res.json({ allPassed, results, score: p.score });
  } catch (err) {
    console.error('Submit error', err);
    res.status(500).json({ error: 'Submit failed' });
  }
});

// Get participant info by token (for client to know score and started state)
app.get('/api/me', (req, res) => {
  const token = req.headers['x-token'];
  const ip = getClientIp(req);
  const p = data.participants[ip];
  if (!p || p.token !== token) return res.status(403).json({ error: 'Invalid token' });
  res.json({ name: p.name, batch: p.batch, startTime: p.startTime, score: p.score, solved: p.solved });
});

// Serve the server
app.listen(PORT, () => {
  console.log('Server running on port', PORT);
});
