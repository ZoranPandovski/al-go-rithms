import pynput
from pynput.keyboard import Key, Listener

keys = []


def press(key):
    if (key == Key.esc):
        return
    keys.append(key)


def release(key):
    if key == Key.esc:
        print(keys)
        return


with Listener(on_press=press, on_release=release) as hear:
    hear.join()
