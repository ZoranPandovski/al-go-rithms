# A simple app to download youtube video using tkinter library in python.
from tkinter import *
from tkinter import ttk
from tkinter import filedialog
import pytube
import random

url = 'https://www.youtube.com/watch?v=rUWxSEwctFU'
path = "C:\\Users\\lakha\\OneDrive\\Desktop\\trash"

try:
    from ctypes import windll

    windll.shcore.SetProcessDpiAwareness(1)
except:
    pass

root = Tk()
bg_color = "grey"
fg_color = "black"

root["background"] = bg_color
root.geometry("700x500")

# variables
url_var = StringVar()
folder_path_var = StringVar()
quality_var = StringVar()

app_slogan = Label(root, text="YouTube video downloader", fg=fg_color, bg=bg_color, font=("Helvetica", 20, "bold"))
app_slogan.grid(row=0, column=0, padx=(100, 0), pady=(20, 50))

url_label = Label(root, text="Url:", fg=fg_color, bg=bg_color, font=("Helvetica", 20, "bold"))
url_entry = ttk.Entry(root, textvariable=url_var, font=("Helvetica", 15, "bold"))

url_label.grid(row=1, column=0, padx=(120, 20), pady=(20, 20), sticky="W")
url_entry.grid(row=1, column=0, padx=(140, 0), pady=(20, 20))

# combobox for quality option
quality_label = Label(root, text="Quality: ", fg=fg_color, bg=bg_color, font=("Helvetica", 20, "bold"))
quality_combo_box = ttk.Combobox(root, width=20, textvariable=quality_var)

quality_label.grid(row=2, column=0, padx=(120, 20), pady=(0, 20), sticky="W")
quality_combo_box.grid(row=2, column=0, padx=(270, 0), pady=(0, 20), sticky="W")

quality_combo_box['values'] = ('High - 1080p',
                               'Medium - 720p',
                               'Low - 480p')


def getting_folder_path():
    folder_path = filedialog.askdirectory()
    folder_path_var.set(folder_path)

def download_success():
    mylabel = Label(root, text="Download Completed .", fg=fg_color, bg=bg_color, font=("Helvetica", 20, "bold"))
    mylabel.grid(row=5, column=0, padx=(50,0), pady=(30, 20))

def download_failed():
    mylabel = Label(root, text="Download Failed.", fg=fg_color, bg=bg_color, font=("Helvetica", 20, "bold"))
    mylabel.grid(row=5, column=0, padx=(50, 0), pady=(30, 20))


def video_downloader_yt():
    url = url_var.get()
    path = folder_path_var.get()
    quality=quality_combo_box.get()
    youtube_vids = pytube.YouTube(url)
    streams_1080p = youtube_vids.streams.get_by_itag(137)
    streams_720p = youtube_vids.streams.get_by_itag(136)
    streams_480p = youtube_vids.streams.get_by_itag(135)

    # to create random file name each time if multiple videos are downloaded it will not overwrite the previous ones
    a = ["z", "b", "c", "r", "e", "q", "g", "1", "9", "2"]
    random.shuffle(a)
    print("almost ready")
    try:
        if quality == "High - 1080p":
            streams_1080p.download(path, filename="Video_1080p_" + "id_" + "".join(a))
        elif quality == "Medium - 720p":
            streams_720p.download(path, filename="Video_720p_" + "id_" + "".join(a))
        elif quality == "Low - 480p":
            streams_480p.download(path, filename="Video_480p_" + "id_" + "".join(a))

        download_success()
    except:
        download_failed()


path_btn = ttk.Button(root, text="Location", command=getting_folder_path)
path_btn.grid(row=1, column=1)

download_btn = ttk.Button(root, text="Download", command=video_downloader_yt)
download_btn.grid(row=4, column=0, padx=(50))



root.mainloop()
