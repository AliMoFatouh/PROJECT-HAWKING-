from serial_listener import SerialListener
import sound
import time
import tkinter as tk
 
 
listener = SerialListener()
 
morse = ""
text = ""
 
MAX_CHARS_PER_LINE = 25
MAX_LINES = 2
 
 
def update_display():
    global text
 
    lines = []
 
    # Split text into lines of MAX_CHARS_PER_LINE characters
    for i in range(0, len(text), MAX_CHARS_PER_LINE):
        lines.append(text[i:i + MAX_CHARS_PER_LINE])
 
    # Keep only two lines
    if len(lines) > MAX_LINES:
        text = text[-MAX_CHARS_PER_LINE:]
        lines = [text]
 
    text_label.config(
        text="\n".join(lines)
    )
 
    morse_label.config(
        text=morse
    )
 
 
def delete_last_word():
    global text
 
    text = text.rstrip()
 
    if ' ' in text:
        # Keep the space after the previous word (+1) so the next
        # word you type doesn't merge into it
        text = text[:text.rfind(' ') + 1]
    else:
        text = ""
 
    update_display()
 
 
def exit_program():
    sound.stop()
    root.destroy()
 
 
def receive_data():
    global morse
    global text
 
    data = listener.receive()
 
    if data == '.':
        morse += '.'
 
    elif data == '-':
        morse += '-'
 
    elif data == '1':
        sound.play_tone(550, 5)
 
    elif data == '0':
        time.sleep(0.1)
        sound.stop()
 
    elif data == '2' or data == '3':
 
        # Error:
        # Kill only the current Morse character.
        morse = ""
 
        sound.play_tone(1200, 100)
        sound.play_tone(800, 100)
        sound.play_tone(1200, 100)
        sound.play_tone(800, 100)
        sound.stop()
 
    elif data == ' ':
 
        text += ' '
        morse = ""
 
    elif data != "":
 
        # Add decoded character
        text += data
        morse = ""
 
    update_display()
 
    root.after(10, receive_data)
 
 
# --------------------------------------------------
# GUI
# --------------------------------------------------
 
root = tk.Tk()
 
root.title("HAWKING Morse Interpreter")
root.geometry("600x450")
 
 
title_label = tk.Label(
    root,
    text="HAWKING",
    font=("Arial", 24)
)
 
title_label.pack(pady=20)
 
 
morse_title = tk.Label(
    root,
    text="Current Morse:",
    font=("Arial", 16)
)
 
morse_title.pack()
 
 
morse_label = tk.Label(
    root,
    text="",
    font=("Arial", 30)
)
 
morse_label.pack(pady=10)
 
 
text_title = tk.Label(
    root,
    text="Decoded Text:",
    font=("Arial", 16)
)
 
text_title.pack()
 
 
text_label = tk.Label(
    root,
    text="",
    font=("Arial", 24),
    justify="center",
    anchor="center"
)
 
text_label.pack(
    pady=10,
    padx=20,
    fill="x"
)
 
 
button_frame = tk.Frame(root)
 
button_frame.pack(pady=30)
 
 
delete_button = tk.Button(
    button_frame,
    text="Delete Last Word",
    font=("Arial", 14),
    bg="gray",
    fg="white",
    command=delete_last_word
)
 
delete_button.pack(
    side=tk.LEFT,
    padx=10
)
 
 
exit_button = tk.Button(
    button_frame,
    text="Exit",
    font=("Arial", 14),
    bg="red",
    fg="white",
    command=exit_program
)
 
exit_button.pack(
    side=tk.LEFT,
    padx=10
)
 
 
root.after(10, receive_data)
 
 
try:
    root.mainloop()
 
except KeyboardInterrupt:
    sound.stop()
    root.destroy()
