import time 
from turtle import Screen, Turtle
from paddle import Paddle
from ball import Ball
from scoreboard import ScoreBoard


screen=Screen()
tim=Turtle()




screen.title("Pong Game")
screen.setup(width=800, height=600)
screen.bgcolor("black")
screen.tracer(0)
tim.pencolor("white")
tim.speed(0)
tim. penup()
tim.goto(0,-300)
tim.seth(90)
for _ in range(1,20):
    tim.pendown()
    tim.fd(20)
    tim.penup()
    tim.fd(20)


r_paddle=Paddle(x_pos=380,y_pos=0)
l_paddle=Paddle(x_pos=-390,y_pos=0)

ball=Ball()

scoreboard=ScoreBoard()

screen.listen()


screen.onkey(key="Up",fun=r_paddle.move_up)
screen.onkey(key="Down",fun=r_paddle.move_down)
screen.onkey(key="w",fun=l_paddle.move_up)
screen.onkey(key="s",fun=l_paddle.move_down)


is_game_on=True

while is_game_on:
    screen.update()
    time.sleep(ball.move_speed)

    ball.ball_move()

#   Detect collision with wall
    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()

#   Detect collision with paddle
    if ball.distance(r_paddle) < 56 and ball.xcor() > 355 or ball.distance(l_paddle) < 56 and ball.xcor() < -365:
        ball.bounce_x()
#   Detection collision with right wall
    if ball.xcor() > 386 : 
        ball.reset_position()
        scoreboard.l_point()
#   Detection collision with left wall    
    if ball.xcor() < -389:
        ball.reset_position()
        scoreboard.r_point()




screen.exitonclick()