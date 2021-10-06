Rules:
   The game consists of a snake and food displayed on random position.
   Our aim is to make snake eat the food and grow it as big as possible.
   The food is displayed in red colour at random position.
   Each time snake eats food score increases by 10 and the body of the snake grows by one segment.
   The game ends if the snake head touches its own body or hits the sides of the window.
import turtle

import time

import random

delay = 0.1
# score

score = 0
high_score = 0

wn = turtle.Screen()
wn.title(" SNAKE GAME - BY SIRI")
wn.bgcolor("orange")
wn.setup(width = 600, height = 600)
wn.tracer(0) 
# turns off screen updates

# snake head
head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("black")
head.penup()
head.goto(0, 0)
head.direction = "right"

# snake food
food = turtle.Turtle()
food.speed(0)
food.shape("circle")
food.color("red")
food.penup()
food.goto(0, 100)

segments = [] # body

# create a pen to wrute the score..
pen = turtle.Turtle()
pen.speed(0)
pen.shape("circle")
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0, 260)
pen.write("Score : 0  High Score : 0",align = "center", font = ("Courier", 24, "normal"))

# Functions
def go_up():
    if head.direction != "down":
        head.direction = "up"

def go_down():
    if head.direction != "up":
        head.direction = "down"

def go_left():
    if head.direction != "right":
        head.direction = "left"

def go_right():
    if head.direction != "right":
        head.direction = "right"


# Keyboard bindings
wn.listen()
wn.onkeypress(go_up, "Up")
wn.onkeypress(go_down, "Down")
wn.onkeypress(go_right, "Right")
wn.onkeypress(go_left, "Left")

def move():
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)
    if head.direction == "down":
        y = head.ycor()
        head.sety(y - 20)
    if head.direction == "left":
        x = head.xcor()
        head.setx(x - 20)
    if head.direction == "right":
        x = head.xcor()
        head.setx(x + 20)



# main GAME

while True:
    wn.update()

   
    x = head.xcor()
    y = head.ycor()

    if  not(-290 < x < 290) or not(-290 < y < 290):
        time.sleep(1)
        head.goto(0, 0)
        head.direction = "stop"

        # hide the segments

        for segment in segments:
            segment.goto(1000, 1000)

        # clear the segments list
        segments.clear()

        score = 0

        pen.clear()

        pen.write("Score : {}  High Score : {}".format(score, high_score),align = "center", font = ("Courier", 24, "normal"))






    #Check for a collision for food
    if head.distance(food) < 20 :
        # Move food to random spot on screen
        x = random.randint(-290, 290)
        y = random.randint(-290, 290)

        food.goto(x, y)
        # Add a segments

        new_segment = turtle.Turtle()
        new_segment.speed(0)
        new_segment.shape("square")
        new_segment.color("grey")
        new_segment.penup()
        segments.append(new_segment)

        # Shorten the delay
        delay -= 0.001
        # increase the score
        score += 10

        if score > high_score:
            high_score = score
        # clear the previous score
        pen.clear()

        # write score on Screen
        pen.write("Score : {}  High Score : {}".format(score, high_score),align = "center", font = ("Courier", 24, "normal"))


    # Move the end segments first in reverse order
    for index in range(len(segments) - 1, 0, -1):
        x = segments[index - 1].xcor()
        y = segments[index - 1].ycor()
        segments[index].goto(x, y)

    # Move segment 0 to where the head is
    if len(segments) > 0:
        x = head.xcor()
        y = head.ycor()
        segments[0].goto(x, y)



    move()

    #check for head collision with the body
    for segment in segments:
        if segment.distance(head) < 20:
            time.sleep(1)
            head.goto(0, 0)
            head.direction = "stop"

            for segment in segments:
                segment.goto(1000, 1000)

            # clear the segments list
            segments.clear()
            # reset the Score
            score = 0

            pen.clear()

            pen.write("Score : {}  High Score : {}".format(score, high_score),align = "center", font = ("Courier", 24, "normal"))





    time.sleep(delay)


wn.mainloop()
