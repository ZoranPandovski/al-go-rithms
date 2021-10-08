from turtle import Turtle
HEIGHT=5
WEIDTH=1
class Paddle(Turtle):
    def __init__(self,x_pos,y_pos):
        super().__init__()
        self.penup()
        # self.speed(0)
        self.goto(x=x_pos,y=y_pos)
        self.shape("square")
        self.color("white")
        self.shapesize(stretch_wid=HEIGHT,stretch_len=WEIDTH)

    def move_up(self):
        new_y=self.ycor()+20
        self.goto(x=self.xcor(),y=new_y)
    def move_down(self):
        new_y=self.ycor()-20
        self.goto(x=self.xcor(),y=new_y)