import sys, os, subprocess
from lackey import Key, click, wait, type, paste

waitTime = 60

process = subprocess.Popen("C:\\Notes\\Build\\Notes\\debug\\Notes.exe")

wait("wait_vb.png",waitTime)
click("ok_vb.png")

# wait("open.png", waitTime)
click("add_vb.png")
# click("note_1.png")
# click("rename_note_1.png")
# type("a", Key.CTRL)
# paste("My_note")
# click("save_note.png")
click("exit_vb.png")
