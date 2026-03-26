// app.js - front-end logic to call server endpoints

async function apiFetch(path, opts) {
  const resp = await fetch(path, opts);
  if (!resp.ok) {
    const txt = await resp.text();
    throw new Error(txt || resp.statusText);
  }
  const ctype = resp.headers.get("content-type") || "";
  if (ctype.includes("application/json")) return resp.json();
  return resp.text();
}

async function refreshList() {
  try {
    const data = await apiFetch('/api/contacts');
    const container = document.getElementById('list');
    if (!Array.isArray(data) || data.length === 0) {
      container.innerHTML = '<p class="small">No contacts yet.</p>';
      return;
    }
    let html = '<table><thead><tr><th>#</th><th>Name</th><th>Phone</th><th>Email</th><th>Actions</th></tr></thead><tbody>';
    for (const c of data) {
      html += `<tr>
        <td>${c.index+1}</td>
        <td>${escapeHtml(c.name)}</td>
        <td>${escapeHtml(c.phone)}</td>
        <td>${escapeHtml(c.email || '')}</td>
        <td><button class="editBtn" data-idx="${c.index}">Edit</button></td>
      </tr>`;
    }
    html += '</tbody></table>';
    container.innerHTML = html;
    document.querySelectorAll('.editBtn').forEach(btn => {
      btn.addEventListener('click', onEdit);
    });
  } catch (err) {
    alert('Failed to load contacts: ' + err.message);
  }
}

function escapeHtml(s) {
  if (!s) return '';
  return s.replace(/[&<>"']/g, function(m){ return ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'})[m]; });
}

async function onAdd(e) {
  e.preventDefault();
  const f = e.target;
  const form = new FormData(f);
  const data = new URLSearchParams();
  for (const [k,v] of form.entries()) data.append(k,v);
  try {
    await apiFetch('/api/add', { method: 'POST', headers: {'Content-Type':'application/x-www-form-urlencoded'}, body: data.toString() });
    f.reset();
    await refreshList();
  } catch (err) {
    alert('Add failed: ' + err.message);
  }
}

async function onEdit(e) {
  const idx = parseInt(e.target.getAttribute('data-idx'), 10);
  const name = prompt('New name (leave blank to keep):');
  if (name === null) return;
  const phone = prompt('New phone (leave blank to keep):');
  if (phone === null) return;
  const email = prompt('New email (leave blank to keep):');
  if (email === null) return;
  const payload = { index: idx };
  if (name.trim() !== '') payload.name = name;
  if (phone.trim() !== '') payload.phone = phone;
  if (email.trim() !== '') payload.email = email;
  try {
    await apiFetch('/api/update', { method: 'POST', headers: {'Content-Type':'application/json'}, body: JSON.stringify(payload) });
    await refreshList();
  } catch (err) {
    alert('Update failed: ' + err.message);
  }
}

async function onSave() {
  try {
    await apiFetch('/api/save', { method: 'POST' });
    alert('Saved to server file.');
  } catch (err) {
    alert('Save failed: ' + err.message);
  }
}

async function onLoad() {
  try {
    await apiFetch('/api/load', { method: 'POST' });
    await refreshList();
    alert('Loaded from file.');
  } catch (err) {
    alert('Load failed: ' + err.message);
  }
}

document.addEventListener('DOMContentLoaded', () => {
  document.getElementById('addForm').addEventListener('submit', onAdd);
  document.getElementById('refreshBtn').addEventListener('click', refreshList);
  document.getElementById('saveBtn').addEventListener('click', onSave);
  document.getElementById('loadBtn').addEventListener('click', onLoad);
  refreshList();
});
