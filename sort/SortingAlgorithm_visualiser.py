from tkinter import *
from tkinter import ttk
import random
from BubbleSort import bubbleSort
from QuickSort import quickSort

'''Now we create a root widget, by calling the Tk().
    This automatically creates a graphical window with the title bar, minimize, maximize and close buttons.
    This handle allows us to put the contents in the window and reconfigure it as necessary.'''

root = Tk()
root.title('Sorting Algorithm Visualiser')
root.geometry('1000x700+200+80')
# Size of the GUI
root.config(bg='#082A46')

data = []


def StartAlgorithm():
    global data
    if not data:
        return

    if algo_menu.get() == 'Quick Sort':
        quickSort(data, 0, len(data) - 1, drawData, speedscale.get())

    elif algo_menu.get() == "Bubble Sort":
        bubbleSort(data, drawData, speedscale.get())


def drawData(data, colorArray):
    canvas.delete("all")
    canvas_height = 550
    canvas_width = 970
    x_width = canvas_width / (len(data) + 1)
    offset = 10
    spacing_bet_rect = 10
    normalised_data = [i / max(data) for i in data]

    for i, height in enumerate(normalised_data):
        x0 = i * x_width + offset + spacing_bet_rect
        y0 = canvas_height - height * 400
        # we have multiplied by 400 because we will normalize our values
        # so that our data doesnt exceed our canvas
        x1 = (i + 1) * x_width
        y1 = canvas_height

        canvas.create_rectangle(x0, y0, x1, y1, fill=colorArray[i])
        canvas.create_text(x0 + 2, y0, anchor=SW, text=str(data[i]), font=("new roman", 15, "italic bold"),fill="orange")

        root.update_idletasks()


def Generate():

    global data
    print("Selected Algorithm: ", selected_algorithm.get())

    # We will take values form our speed scale now

    minivalue = int(minvalue.get())

    maxivalue = int(maxvalue.get())

    sizeevalue = int(sizevalue.get())

    data = []
    for _ in range(sizeevalue):
        data.append(random.randrange(minivalue, maxivalue + 1))
    drawData(data, ['#A90042' for x in range(len(data))])


selected_algorithm = StringVar()

    # StringVar is a  tKinter type, it holds a string; the default value is an empty string ""

    # label, button, speed scale
mainlabel = Label(root, text='Algorithm :', font=("new roman", 16, "italic bold"),bg="#05897A", width=10, fg="black", relief=GROOVE, bd=5)
mainlabel.place(x=0, y=0)

algo_menu = ttk.Combobox(root, width=15, font=("new roman", 19, "italic bold"),textvariable=selected_algorithm,values=['Bubble Sort', 'Quick Sort'])
algo_menu.place(x=145, y=0)
algo_menu.current(0)  # by default bubble sort

random_generate = Button(root, text="Generate", bg="#2DAE9A", font=("arial", 12, "italic bold"),
                                     relief=SUNKEN,
                                     activebackground="#05945B", activeforeground="white", bd=5, width=10,
                                     command=Generate)
random_generate.place(x=750, y=60)

# Size Value GUI elelments

size_value_label = Label(root, text='Size :', font=("new roman", 12, "italic bold"),
                                     bg="#0E6DA5", width=10, fg="black", height=2, relief=GROOVE, bd=5)
size_value_label.place(x=0, y=60)

sizevalue = Scale(root, from_=0, to=35, resolution=1, orient=HORIZONTAL, font=("arial", 12, "italic bold"),
                              relief=GROOVE, bd=2, width=10)
sizevalue.place(x=120, y=60)

# Minimum Value GUI elements

min_value_label = Label(root, text='Min Value :', font=("new roman", 12, "italic bold"),
                                    bg="#0E6DA5", width=10, fg="black", height=2, relief=GROOVE, bd=5)
min_value_label.place(x=250, y=60)

minvalue = Scale(root, from_=0, to=10, resolution=1, orient=HORIZONTAL, font=("arial", 12, "italic bold"),
                             relief=GROOVE, bd=2, width=10)
minvalue.place(x=370, y=60)

# Maximum Value GUI elements

max_value_label = Label(root, text='Max Value :', font=("new roman", 12, "italic bold"),
                                    bg="#0E6DA5", width=10, fg="black", height=2, relief=GROOVE, bd=5)
max_value_label.place(x=500, y=60)

maxvalue = Scale(root, from_=0, to=100, resolution=1, orient=HORIZONTAL, font=("arial", 12, "italic bold"),
                             relief=GROOVE, bd=2, width=10)
maxvalue.place(x=620, y=60)

# Start GUI elements

start = Button(root, text="Start", bg="#C45B09", font=("arial", 12, "italic bold"), relief=SUNKEN,
                           activebackground="#05945B", activeforeground="white", bd=5, width=10, command=StartAlgorithm)
start.place(x=750, y=0)

# Speed GUI elements

speedlabel = Label(root, text='Speed :', font=("new roman", 12, "italic bold"),
                               bg="#0E6DA5", width=10, fg="black", relief=GROOVE, bd=5)
speedlabel.place(x=400, y=0)

speedscale = Scale(root, from_=0.1, to=5.0, resolution=0.2, length=200, digits=2, orient=HORIZONTAL,
                               font=("arial", 12, "italic bold"),
                               relief=GROOVE, bd=2, width=10)
speedscale.place(x=520, y=0)

# Creating a Canvas in root GUI

canvas = Canvas(root, width=970, height=550, bg="black")
canvas.place(x=10, y=130)

root.mainloop()
