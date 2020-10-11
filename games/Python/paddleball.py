from tkinter import *
import random
import time

class Ball:
    def __init__(self, canvas, paddle, score, color):  #function saved as __init__ in it to create oval.  Takes parameters canvas and color
        self.canvas = canvas  #saves canvas var as "Canvas" to make values of canvas(tk, height=400, width=50, bd(border)= 0 and highlightthickness = 0(to make look like "Game")(see at line 26)
        self.paddle = paddle
        self.score = score
        self.id = canvas.create_oval(10, 10, 25, 25, fill=color)
        self.canvas.move(self.id, 245, 100)#self.id = identifier for oval if in oval class and __init__ function(oval or rect)
        starts = [-3, -2, -1, 1, 2, 3]
        random.shuffle(starts)
        self.x = starts[0]#changing direction
        self.y = -3
        self.canvas_height = self.canvas.winfo_height()
        self.canvas_width = self.canvas.winfo_width()
        self.hit_bottom = False

    def hit_paddle(self, pos):
        paddle_pos = self.canvas.coords(self.paddle.id)
        if pos[2] >= paddle_pos[0] and pos[0] <= paddle_pos[2]:
            if pos[3] >= paddle_pos[1] and pos[3] <= paddle_pos[3]:
                self.score.hit()
                self.x += self.paddle.x
                return True
            
        return False
    
    def draw(self):
        self.canvas.move(self.id, self.x, self.y)
        pos = self.canvas.coords(self.id)  #pos is var and coords is function of tkinter(current cooordinates of (self.id(identifier(red oval)))
        if pos[1] <= 0:  #changes 'y' depending on coords
            self.y = 3
        if pos[3] >= self.canvas_height: 
            self.hit_bottom = True
        if self.hit_paddle(pos) == True:
            self.y = -3
        if pos[0] <= 0:
            self.x = 3
        if pos[2] >= self.canvas_width:
            self.x = -3

class Paddle:
    """This is the user controlled paddle class."""

    def __init__(self, canvas, color):
        self.canvas = canvas  #canvas = var with functions inside
        self.id = canvas.create_rectangle(0, 0, 100, 10, fill=color)  #creating paddle
        self.canvas.move(self.id, 200, 300)
        self.x = 0
        self.canvas_width = self.canvas.winfo_width()
        self.started = False
        self.canvas.bind_all('<KeyPress-Left>', self.turn_left)  #sensing whether right of left key pressed and go in that direction by calling function turn_left or turn_right.
        self.canvas.bind_all('<KeyRelease-Left>', self.stop_left)#Senses when key released and stops
        self.canvas.bind_all('<KeyPress-Right>', self.turn_right)#to turn right when right key pressed
        self.canvas.bind_all('<KeyRelease-Right>', self.stop_right)#stops when released
        self.canvas.bind_all('<Button-1>', self.start_game) #game starts when canvas is clicked

   
    def draw(self):
        self.canvas.move(self.id, self.x, 0)
        pos = self.canvas.coords(self.id)
        if pos[0] <= 0:
            self.x = 0
        elif pos[2] >= self.canvas_width:
            self.x = 0

    def turn_left(self, evt):
        pos = self.canvas.coords(self.id)
        if pos[0] <= 0:
            self.x = 0
        else:
            self.x = -3
        

    def stop_left(self, evt):
        self.x = 0

    def turn_right(self, evt):
        pos = self.canvas.coords(self.id)
        if pos[2] >= 500:
            self.x = 0
        else:
            self.x = 3
            
    def stop_right(self, evt):
        self.x = 0
        
    def start_game(self, evt):
        self.started = True

class Score:
    def __init__(self, canvas, color):
        self.score = 0
        self.canvas = canvas
        self.id = canvas.create_text(450, 40, text=self.score, fill=color, font=('Courier', 40))

    def hit(self):
        self.score += 1
        self.canvas.itemconfig(self.id, text=self.score)

tk = Tk()
tk.title("Game")
tk.resizable(0,0)
tk.wm_attributes("-topmost", 1)  #putting "game" as topmost tab
canvas = Canvas(tk, width=500, height=400, bd=0, highlightthickness=0)
canvas.pack()
tk.update()

canvas.create_text(340, 40, text="SCORE:", fill='green', font=('Courier', 40))
score = Score(canvas, 'green')
paddle = Paddle(canvas, 'blue')
ball = Ball(canvas, paddle, score, 'red')
game_over_text = canvas.create_text(250, 200, text='GAME OVER', font=('Georgia', 60),state='hidden')

while 1:
    if ball.hit_bottom == False and paddle.started == True:
        ball.draw()
        paddle.draw()
    if ball.hit_bottom == True:
        time.sleep(1)
        canvas.itemconfig(game_over_text, state='normal')
        break
    tk.update_idletasks()
    tk.update()
    time.sleep(0.01)  #constantly updating canvas(loops as True(can't be false))




