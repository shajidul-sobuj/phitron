// Client-side app for contest page
(async function(){
  const token = localStorage.getItem('contestToken');
  if (!token) { window.location.href = '/'; return; }

  // Fetch participant info
  async function me() {
    const res = await fetch('/api/me', { headers: { 'x-token': token } });
    if (!res.ok) throw new Error('Not authorized');
    return res.json();
  }

  const participant = await me();
  document.getElementById('participantName').textContent = participant.name + ' — Batch ' + participant.batch;
  document.getElementById('scoreDisplay').textContent = participant.score || 0;

  // Load problems
  const pRes = await fetch('/api/problems');
  const pJson = await pRes.json();
  const problems = pJson.problems;

  const app = document.getElementById('app');

  // Build UI similar to previous single-file but powered by server
  function buildProblemHtml(idx, prob) {
    return `
      <div class="problem-box mb-3">
        <h3 class="h6">Problem ${prob.id} — ${prob.title}</h3>
        <p class="mb-1"><strong>Samples:</strong></p>
        ${prob.samples.map(s => `<pre>${s.input}</pre>`).join('')}
        <div class="mb-3">
          <label class="form-label">C Code</label>
          <textarea id="editor-${idx}" class="form-control editor" rows="8">${prob.template}</textarea>
        </div>
        <div class="d-flex gap-2 mb-3">
          <button class="btn btn-primary" id="run-${idx}">Run</button>
          <button class="btn btn-success" id="submit-${idx}">Submit</button>
          <div id="status-${idx}" class="ms-3 align-self-center"></div>
        </div>
        <div id="result-${idx}"></div>
      </div>
    `;
  }

  app.innerHTML = `
    <div class="row">
      <div class="col-lg-9">
        ${problems.map((p,i) => buildProblemHtml(i,p)).join('')}
      </div>
      <div class="col-lg-3">
        <div class="problem-box">
          <h6>Contest Info</h6>
          <p class="small-muted mb-0">Title: HSC C Programming Practice Contest</p>
          <p class="small-muted mb-0">Duration: 30 minutes</p>
          <p class="small-muted mb-0">Scoring: 10 points per solved problem</p>
        </div>
      </div>
    </div>
  `;

  // Timer (read start time from server participant.startTime)
  const startTS = participant.startTime || Date.now();
  const duration = 30*60*1000; // 30 minutes
  let endTS = startTS + duration;
  function updateTimer() {
    const left = Math.max(0, endTS - Date.now());
    const mm = String(Math.floor(left/60000)).padStart(2,'0');
    const ss = String(Math.floor((left%60000)/1000)).padStart(2,'0');
    document.getElementById('timerDisplay').textContent = mm + ':' + ss;
    if (left === 0) {
      // disable buttons
      problems.forEach((p,i) => { document.getElementById('run-'+i).disabled = true; document.getElementById('submit-'+i).disabled = true; });
      clearInterval(timerInt);
      alert('Time is up.');
    }
  }
  const timerInt = setInterval(updateTimer, 1000);
  updateTimer();

  // Attach run/submit handlers
  problems.forEach((p, idx) => {
    document.getElementById('run-'+idx).addEventListener('click', async () => {
      const code = document.getElementById('editor-'+idx).value;
      const status = document.getElementById('status-'+idx);
      status.innerHTML = 'Running...';
      try {
        const r = await fetch('/api/compile', { method:'POST', headers:{'Content-Type':'application/json'}, body: JSON.stringify({ code, stdin: p.samples[0].input }) });
        const jr = await r.json();
        const out = jr.program_output || jr.program_message || '';
        document.getElementById('result-'+idx).innerHTML = `<div class="mb-2">Output:</div><pre class="output">${escapeHtml(out)}</pre>`;
        status.innerHTML = 'Done';
      } catch (err) {
        status.innerHTML = 'Error';
        document.getElementById('result-'+idx).innerHTML = `<div class="text-danger">${escapeHtml(String(err))}</div>`;
      }
    });

    document.getElementById('submit-'+idx).addEventListener('click', async () => {
      const code = document.getElementById('editor-'+idx).value;
      const status = document.getElementById('status-'+idx);
      status.innerHTML = 'Submitting...';
      try {
        const r = await fetch('/api/submit', { method:'POST', headers:{'Content-Type':'application/json'}, body: JSON.stringify({ token, problemId: p.id, code }) });
        const jr = await r.json();
        if (!r.ok) { status.innerHTML = 'Failed'; document.getElementById('result-'+idx).innerHTML = `<div class="text-danger">${escapeHtml(jr.error||'Submit failed')}</div>`; return; }
        document.getElementById('scoreDisplay').textContent = jr.score;
        status.innerHTML = jr.allPassed ? '<span class="passed">Solved</span>' : '<span class="failed">Not all tests passed</span>';
        document.getElementById('result-'+idx).innerHTML = `<pre class="output">${escapeHtml(JSON.stringify(jr.results, null, 2))}</pre>`;
      } catch (err) {
        status.innerHTML = 'Error';
        document.getElementById('result-'+idx).innerHTML = `<div class="text-danger">${escapeHtml(String(err))}</div>`;
      }
    });
  });

  function escapeHtml(s) { return String(s).replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/>/g,'&gt;'); }

})();
