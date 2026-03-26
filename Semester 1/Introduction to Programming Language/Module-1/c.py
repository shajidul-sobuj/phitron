"""
Bulleya Lyrics Player (no lyrics included)

- Requires: pygame (pip install pygame)
- Put your audio file in the same folder (default: 'bulleya.mp3')
- Put your lyrics in 'lyrics.txt' (plain text) OR
  use 'lyrics_sync.txt' with lines like: 00:12    Line of lyric (tab or 4 spaces)
  for timestamp-synced display.

This script provides:
 - Play / Pause / Stop controls
 - A canvas where lyrics scroll upward (auto-scroll)
 - Optional timestamp-synced highlighting mode (if lyrics_sync.txt exists)
"""

import tkinter as tk
from tkinter import filedialog, messagebox
import pygame
import time
import threading
import os
import re

AUDIO_DEFAULT = "bulleya.mp3"
LYRICS_FILE = "lyrics.txt"
LYRICS_SYNC_FILE = "lyrics_sync.txt"

# --------- Player + GUI ---------
class LyricsPlayer:
    def __init__(self, root):
        self.root = root
        root.title("Lyrics Player - Bulleya (you supply audio & lyrics)")
        root.geometry("700x500")

        # Initialize Pygame mixer
        pygame.mixer.init()
        self.playing = False
        self.paused = False
        self.start_time = None
        self.pause_time = 0  # accumulated paused duration
        self.offset_when_paused = 0

        # UI: Buttons
        btn_frame = tk.Frame(root)
        btn_frame.pack(side=tk.TOP, pady=6)

        self.play_btn = tk.Button(btn_frame, text="Play", command=self.play)
        self.play_btn.pack(side=tk.LEFT, padx=4)

        self.pause_btn = tk.Button(btn_frame, text="Pause", command=self.toggle_pause, state=tk.DISABLED)
        self.pause_btn.pack(side=tk.LEFT, padx=4)

        self.stop_btn = tk.Button(btn_frame, text="Stop", command=self.stop, state=tk.DISABLED)
        self.stop_btn.pack(side=tk.LEFT, padx=4)

        tk.Button(btn_frame, text="Load Audio...", command=self.load_audio).pack(side=tk.LEFT, padx=8)
        tk.Button(btn_frame, text="Load Lyrics...", command=self.load_lyrics_file).pack(side=tk.LEFT, padx=8)

        # Canvas for scrolling lyrics
        self.canvas = tk.Canvas(root, bg="black")
        self.canvas.pack(fill=tk.BOTH, expand=True)
        self.canvas.bind("<Configure>", self._on_canvas_resize)

        # Status bar
        self.status = tk.Label(root, text="Ready. Place audio file and lyrics in the script folder or use Load buttons.", bd=1, relief=tk.SUNKEN, anchor=tk.W)
        self.status.pack(side=tk.BOTTOM, fill=tk.X)

        # lyric storage
        self.lyrics_lines = []  # for plain auto-scroll
        self.sync_lines = []    # for (time_in_seconds, text) tuples
        self.current_text_id = None
        self.scroll_speed = 1  # pixels per update
        self.scroll_delay = 30  # ms between scroll updates

        self.canvas_width = 600
        self.canvas_height = 300

        # Load defaults if available
        if os.path.exists(AUDIO_DEFAULT):
            self.audio_path = AUDIO_DEFAULT
            self.status.config(text=f"Loaded audio: {AUDIO_DEFAULT}")
        else:
            self.audio_path = None

        # Try to load lyrics automatically if present
        if os.path.exists(LYRICS_SYNC_FILE):
            self._load_sync_file(LYRICS_SYNC_FILE)
            self.mode = "sync"
            self.status.config(text=f"Loaded timestamped lyrics from {LYRICS_SYNC_FILE}")
        elif os.path.exists(LYRICS_FILE):
            self._load_plain_file(LYRICS_FILE)
            self.mode = "auto"
            self.status.config(text=f"Loaded lyrics from {LYRICS_FILE}")
        else:
            self.mode = "auto"

        # For scrolling text item
        self.text_y = None
        self.text_id = None
        self.text_lines_joined = ""

        # Background scroll thread control
        self._stop_scroll = False

        # Start Tk periodic updater
        self.root.after(100, self._update_ui)

    # ----- File loading -----
    def load_audio(self):
        path = filedialog.askopenfilename(title="Select audio file", filetypes=[("MP3 Files", "*.mp3"), ("All files", "*.*")])
        if path:
            self.audio_path = path
            self.status.config(text=f"Loaded audio: {os.path.basename(path)}")

    def load_lyrics_file(self):
        path = filedialog.askopenfilename(title="Select lyrics file", filetypes=[("Text files", "*.txt"), ("All files", "*.*")])
        if path:
            # detect if it's timestamped (contains mm:ss patterns)
            with open(path, "r", encoding="utf-8") as f:
                sample = f.read(1024)
            if re.search(r"\b\d{1,2}:\d{2}\b", sample):
                self._load_sync_file(path)
                self.mode = "sync"
                self.status.config(text=f"Loaded timestamped lyrics: {os.path.basename(path)}")
            else:
                self._load_plain_file(path)
                self.mode = "auto"
                self.status.config(text=f"Loaded lyrics: {os.path.basename(path)}")

    def _load_plain_file(self, path):
        with open(path, "r", encoding="utf-8") as f:
            lines = [ln.rstrip("\n") for ln in f.readlines() if ln.strip() != ""]
        self.lyrics_lines = lines
        self.text_lines_joined = "\n".join(self.lyrics_lines)
        self._prepare_canvas_text()
        self.mode = "auto"

    def _load_sync_file(self, path):
        parsed = []
        with open(path, "r", encoding="utf-8") as f:
            for raw in f:
                raw = raw.strip()
                if not raw:
                    continue
                # expect: MM:SS <tab> lyric or MM:SS lyric
                m = re.match(r"(\d{1,2}):(\d{2})\s+(.+)", raw)
                if m:
                    mm = int(m.group(1)); ss = int(m.group(2)); text = m.group(3)
                    parsed.append((mm*60 + ss, text))
                else:
                    # try just append as no-timestamp line
                    parsed.append((None, raw))
        # Filter out None timestamps for sync mode
        self.sync_lines = [(t, txt) for (t, txt) in parsed if t is not None]
        if not self.sync_lines:
            messagebox.showwarning("No timestamps", "File doesn't contain recognizable timestamps. Loading as plain lyrics.")
            self._load_plain_file(path)
            return
        self.mode = "sync"

    # ----- Playback controls -----
    def play(self):
        if not self.audio_path:
            messagebox.showerror("No audio", "Please load an audio file first (bulleya.mp3 or use Load Audio).")
            return
        try:
            pygame.mixer.music.load(self.audio_path)
        except Exception as e:
            messagebox.showerror("Audio load error", f"Could not load audio:\n{e}")
            return

        pygame.mixer.music.play()
        self.playing = True
        self.paused = False
        self.start_time = time.time()
        self.pause_time = 0
        self.pause_btn.config(state=tk.NORMAL)
        self.stop_btn.config(state=tk.NORMAL)
        self.play_btn.config(state=tk.DISABLED)
        self._stop_scroll = False

        # Start scrolling depending on mode
        if self.mode == "auto":
            self._start_auto_scroll()
        elif self.mode == "sync":
            self._start_sync_highlight()

    def toggle_pause(self):
        if not self.playing:
            return
        if not self.paused:
            pygame.mixer.music.pause()
            self.paused = True
            self.pause_btn.config(text="Resume")
            # record time paused
            self.offset_when_paused = pygame.mixer.music.get_pos() / 1000.0
        else:
            pygame.mixer.music.unpause()
            self.paused = False
            self.pause_btn.config(text="Pause")

    def stop(self):
        pygame.mixer.music.stop()
        self.playing = False
        self.paused = False
        self.play_btn.config(state=tk.NORMAL)
        self.pause_btn.config(state=tk.DISABLED, text="Pause")
        self.stop_btn.config(state=tk.DISABLED)
        self._stop_scroll = True

    # ----- Scrolling: Auto mode -----
    def _prepare_canvas_text(self):
        # Clear previous
        self.canvas.delete("all")
        self.canvas.update_idletasks()
        w = self.canvas.winfo_width() or self.canvas_width
        # create text block centered horizontally, starting below the bottom (so it scrolls up)
        self.text_lines_joined = "\n\n".join(self.lyrics_lines)
        self.text_id = self.canvas.create_text(w//2, self.canvas.winfo_height() + 20,
                                               text=self.text_lines_joined,
                                               font=("Helvetica", 18),
                                               anchor="n",
                                               width=int(w*0.9),
                                               fill="white")
        # store current y
        bbox = self.canvas.bbox(self.text_id)
        self.text_y = bbox[1] if bbox else (self.canvas.winfo_height() + 20)

    def _start_auto_scroll(self):
        # if no lines loaded, show a message
        if not self.lyrics_lines:
            messagebox.showinfo("No lyrics", "No lyrics found. Please load lyrics.txt.")
            return
        # prepare text
        self._prepare_canvas_text()
        self._auto_scroll_loop()

    def _auto_scroll_loop(self):
        if self._stop_scroll:
            return
        # move text upward
        self.canvas.move(self.text_id, 0, -self.scroll_speed)
        # check if off-screen (completely scrolled)
        bbox = self.canvas.bbox(self.text_id)
        if bbox and bbox[3] < 0:
            # reached end
            return
        self.root.after(self.scroll_delay, self._auto_scroll_loop)

    # ----- Scrolling: Sync mode -----
    def _start_sync_highlight(self):
        if not self.sync_lines:
            messagebox.showinfo("No timestamped lyrics", "No timestamped lyrics loaded. Please load a timestamped file.")
            return
        # Build a full text showing all lines, and we will highlight the current line
        combined_text = "\n".join([t for _, t in self.sync_lines])
        self.canvas.delete("all")
        w = self.canvas.winfo_width() or self.canvas_width
        self.text_id = self.canvas.create_text(10, 10, text=combined_text,
                                               font=("Helvetica", 18),
                                               anchor="nw",
                                               width=int(w*0.9),
                                               fill="white")
        # create a rect for highlighting current line
        self.highlight_rect = None
        # Start sync loop in background thread to avoid blocking (uses pygame.get_pos)
        self._stop_scroll = False
        threading.Thread(target=self._sync_loop, daemon=True).start()

    def _sync_loop(self):
        last_index = -1
        while not self._stop_scroll and pygame.mixer.music.get_busy():
            if self.paused:
                time.sleep(0.2)
                continue
            pos_ms = pygame.mixer.music.get_pos()
            if pos_ms < 0:
                # fallback measure using system clock since we started play;
                pos = time.time() - (self.start_time or time.time())
            else:
                pos = pos_ms / 1000.0
            # find last index with timestamp <= pos
            idx = -1
            for i, (t, txt) in enumerate(self.sync_lines):
                if pos + 0.15 >= t:  # small epsilon
                    idx = i
                else:
                    break
            if idx != last_index:
                last_index = idx
                # redraw highlighted view on main thread
                self.root.after(0, lambda i=idx: self._highlight_sync_line(i))
            time.sleep(0.12)
        # finished playing
        self.root.after(0, self.stop)

    def _highlight_sync_line(self, idx):
        # Clear canvas and re-render with highlight on the idx-th line
        self.canvas.delete("all")
        w = self.canvas.winfo_width() or self.canvas_width
        lines = [t for _, t in self.sync_lines]
        y = 10
        line_height = 28
        for i, line in enumerate(lines):
            x = 10
            if i == idx:
                # draw a rectangle then text in bold
                rect = self.canvas.create_rectangle(5, y-2, w-5, y + line_height - 6, fill="gray20", outline="")
                self.canvas.create_text(x+4, y, anchor="nw", text=line, font=("Helvetica", 20, "bold"), width=int(w*0.9), fill="white")
            else:
                self.canvas.create_text(x+4, y, anchor="nw", text=line, font=("Helvetica", 16), width=int(w*0.9), fill="white")
            y += line_height
        # Optionally, scroll the canvas so highlighted line is centered
        # Compute y of highlighted approximate and scroll:
        target_y = max(0, idx * line_height - (self.canvas.winfo_height() // 2))
        self.canvas.yview_moveto(target_y / max(1, y))

    # ----- Helpers -----
    def _on_canvas_resize(self, event):
        # recompute text width if in auto mode
        if self.mode == "auto" and self.lyrics_lines:
            self._prepare_canvas_text()

    def _update_ui(self):
        # update play status in status bar
        if self.playing:
            if self.paused:
                s = "Paused"
            else:
                # try to get pos
                pos_ms = pygame.mixer.music.get_pos()
                if pos_ms >= 0:
                    s = f"Playing — {pos_ms//1000}s"
                else:
                    s = "Playing"
        else:
            s = "Stopped"
        # append mode info
        s = f"{s} | Mode: {self.mode.upper()}"
        self.status.config(text=s)
        self.root.after(500, self._update_ui)

# ----- Run App -----
def main():
    root = tk.Tk()
    app = LyricsPlayer(root)
    root.mainloop()

if __name__ == "__main__":
    main()
