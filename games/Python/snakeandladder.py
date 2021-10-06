import random
def play(psn):
    snake_begin=-1
    snake_end=-1
    while(snake_begin<=snake_end):
        snake_begin=random.randint(1,99)
        snake_end=random.randint(1,99)
    ladder_begin=-1
    ladder_end=-1
    while(ladder_end <= ladder_begin):
        ladder_begin=random.randint(1,99)
        ladder_end=random.randint(1,99)
    play1(psn,snake_begin,snake_end,ladder_begin,ladder_end)
    
