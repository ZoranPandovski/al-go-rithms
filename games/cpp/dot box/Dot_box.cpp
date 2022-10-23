void game()
{
    int key = 0, i, j, x, y;
    int margin = 4; /* margin for clicking around the dots */
	int LEFTMOUSE = 1, RIGHTMOUSE = 2;

    while (key != 1)
    {
        while (!kbhit())
        {
            get_mouse_pos();
            if (mousebutton == LEFTMOUSE)
            {
                for (i = 0, x = START_X; i < ROWS - 1; i++, x += BOX_WIDTH)
                {
                    for (j = 0, y = START_Y; j < ROWS; j++, y += BOX_HEIGHT)
                    {
                        if (mousex >= x - margin && mousex <= x + margin && mousey >= y - margin && mousey <= y + margin)
                        {
                            if (matrix_h[j][i] != 1)
                            {
                                matrix_h[j][i] = 1;
                                line(x, y, x + BOX_WIDTH, y);
                                player_lines[PLAYER - 1]++;
                            }
                        }
                    }
                }
            }
            if (mousebutton == RIGHTMOUSE)
            {
                for (i = 0, x = START_X; i < ROWS; i++, x += BOX_WIDTH)
                {
                    for (j = 0, y = START_Y; j < ROWS - 1; j++, y += BOX_HEIGHT)
                    {
                        if (mousex >= x - margin && mousex <= x + margin && mousey >= y - margin && mousey <= y + margin)
                        {
                            if (matrix_v[j][i] != 1)
                            {
                                matrix_v[j][i] = 1;
                                line(x, y, x, y + BOX_HEIGHT);
                                player_lines[PLAYER - 1]++;
                            }
                        }
                    }
                }
            }
        }
        ii.h.ah = 0;
        int86(22, &ii, &oo);
        key = oo.h.ah;
    }
}