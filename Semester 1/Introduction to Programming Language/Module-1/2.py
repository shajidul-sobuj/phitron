import os
import time

# Lyrics for the song "Bulleya" from the movie "Sultan", with timestamps.
# The first number in each tuple is the time in seconds when the line should appear.
TIMED_LYRICS = [
    
     (0.2, "Sar aankhon par hai teri naaraazi"),
    (2.2, "Meri haar mein hai koi raaz tera"),
    (4.7, ""),
    (5.7, "Shayad meri jaan ka sadka"),
    (7.7, "Maange teri judaai"),
    (10.2, "Shayad meri jaan ka sadka"),
    (12.2, "Maange teri judaai"),
    (14.7, ""),
    (15.7, "Tu bole toh ban jaaun"),
    (17.7, "Main Bulleh Shah saudai"),
    (20.2, "Main bhi naachun.."),
    (22.2, "Main bhi naachun manau sohne yaar ko"),
    (24.7, "Chalun main teri raah Bulleya"),
    (27.2, "Main bhi naachun rijhaun sohne yaar ko"),
    (29.2, "Karun na parwah Bulleya"),
]

def clear_screen():
    """Clears the console screen."""
    # For Windows
    if os.name == 'nt':
        _ = os.system('cls')
    # For macOS and Linux
    else:
        _ = os.system('clear')

def play_timed_lyrics(timed_lyrics):
    """
    Displays lyrics line-by-line based on timestamps to sync with a song.

    Args:
        timed_lyrics (list): A list of tuples, where each tuple contains a
                             timestamp (float) and the lyric line (str).
    """
    clear_screen()
    print("--- Bulleya (Sultan) Lyrics ---")
    print("Starting in 3 seconds... Press play on your music player!")
    print("Press Ctrl+C to exit.")
    time.sleep(3)

    # Record the real-world start time
    start_time = time.time()

    try:
        # Loop through the timed lyrics
        for i in range(len(timed_lyrics)):
            timestamp, line_text = timed_lyrics[i]

            # Calculate how long to wait before showing the current line.
            # This is done by checking how much real time has passed since
            # the script started and comparing it to the line's timestamp.
            current_elapsed_time = time.time() - start_time
            wait_duration = timestamp - current_elapsed_time
            
            if wait_duration > 0:
                time.sleep(wait_duration)

            # Display the line
            clear_screen()
            # Add some padding to center the line vertically
            print("\n" * 5)
            print(line_text.center(80))
            print("\n" * 5)
            
    except KeyboardInterrupt:
        print("\n\nExiting lyrics player. Goodbye!")

if __name__ == "__main__":
    # Play the lyrics with the defined timings
    play_timed_lyrics(TIMED_LYRICS)

