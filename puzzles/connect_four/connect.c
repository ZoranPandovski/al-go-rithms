/*ex10
 * Jogo connect four
 * matriz 6x7 */

#include<stdio.h>
#include<stdlib.h>

#define HEIGHT 6
#define WIDTH 7
#define BUFF 64

typedef struct st_player
{
    char val;
    int l, c;
} t_player;

/*prototypes*/
void init_game(char tab[HEIGHT][WIDTH]);
void print_map(char tab[HEIGHT][WIDTH]);
int play(char tab[HEIGHT][WIDTH], t_player player);
int winner(char tab[HEIGHT][WIDTH], t_player player);
int verify_width(char tab[HEIGHT][WIDTH], t_player player);
int verify_height(char tab[HEIGHT][WIDTH], t_player player);
int verify_diagonal(char tab[HEIGHT][WIDTH], t_player player);

int main(void)
{
    char tab[HEIGHT][WIDTH];
    t_player hum, comp;
    hum.val = 'x';
    comp.val = 'o';

    printf("The game starts with 'x'\n");

    init_game(tab);
    print_map(tab);

    while(1)
    {
        play(tab, hum);
        print_map(tab);
        play(tab, comp);
        print_map(tab);
    }

    return EXIT_SUCCESS;
}

/* Function in which the player chooses which width wants to play*/
int play(char tab[HEIGHT][WIDTH], t_player player)
{
    int i, c;
    char s[3]={};

    printf("%c turn\n", player.val);
    fgets(s, BUFF, stdin);

    while(s[0] < 48 || s[0] > 54)
    {
        printf("only width from 0 to 6\n");
        fgets(s, BUFF, stdin);
    }

    c = atoi(s);

    for(i=HEIGHT; i>=0; i--)
        if(tab[i][c] == '.')
        {
            tab[i][c] = player.val;
            player.l = i;
            player.c = c;
            if(winner(tab, player))
            {
                printf("\nwinner winner chicken dinner!!");
                print_map(tab);
                exit(1);
            }
            break;
        }

    return 0;

}

/*Function that verifies from the last played position whether the player wins or not
 * return 0 if not won
 * returns 1 if it was the winning move*/
int winner(char tab[HEIGHT][WIDTH], t_player player)
{
    if(verify_width(tab, player))
        return 1;
    
    if(verify_height(tab, player))
        return 1;

    if(verify_diagonal(tab, player))
        return 1;

    return 0;

}

/*Verify if wins on diagonal*/
int verify_diagonal(char tab[HEIGHT][WIDTH], t_player player)
{
    int i, count=0;
    int c = player.c;
    int l = player.l;

    if(c+3 <= WIDTH && l+3 <= HEIGHT)
    {
        for(i=0, count=0; i<4; i++)
            if(tab[l+i][c+i] == player.val)
                count++;
        if(count == 4)
            return 1;
    }

    if(c-3 >= 0 && l+3 <= HEIGHT)
    {
        for(i=0, count=0; i<4; i++)
            if(tab[l+i][c-i] == player.val)
                count++;
        if(count == 4)
            return 1;
    }
        
    if(c-3 >= 0 && l-3 >= 0)
    {
        for(i=0, count=0; i<4; i++)
            if(tab[l-i][c-i] == player.val)
                count++;
        if(count == 4)
            return 1;
    }
        
    if(c+3 <= WIDTH && l-3 >= 0)
    {
        for(i=0, count=0; i<4; i++)
            if(tab[l-i][c+i] == player.val)
                count++;
        if(count == 4)
            return 1;
    }

    return 0;
}

/*Verify if wins on width*/
int verify_width(char tab[HEIGHT][WIDTH], t_player player)
{
    int i, count=0;
    int c = player.c;
    int l = player.l;

    if(c-3 >= 0)
    {
        count=0;
        for(i=c-3; i<=c; i++)
            if(tab[l][i] == player.val)
                count++;
        if(count == 4)
            return 1;
    }

    if(c+3 <= WIDTH)
    {
        count=0;
        for(i=c+3; i>=c; i--)
            if(tab[l][i] == player.val)
                count++;
        if(count == 4)
            return 1;
    }
    return 0;
}

/*Verify if wins on height*/
int verify_height(char tab[HEIGHT][WIDTH], t_player player)
{
    int i, count=0;
    int c = player.c;
    int l = player.l;

    if(l-3 >= 0)
    {
        count=0;
        for(i=l-3; i<=l; i++)
            if(tab[i][c] == player.val)
                count++;
        if(count == 4)
            return 1;
    }

    if(l+3 <= HEIGHT)
    {
        count=0;
        for(i=l+3; i>=l; i--)
            if(tab[i][c] == player.val)
                count++;
        if(count == 4)
            return 1;
    }

    return 0;
}


void print_map(char tab[HEIGHT][WIDTH])
{
    int l, c;

    printf("\n0 1 2 3 4 5 6 \n");
    for(l=0; l<HEIGHT; l++)
    {
        for(c=0; c<WIDTH; c++)
        {
            printf("%c ", tab[l][c]);
        }
        printf("\n");
    }

}


void init_game(char tab[HEIGHT][WIDTH])
{
    int l, c;

    for(l=0; l<HEIGHT; l++)
        for(c=0; c<WIDTH; c++)
            tab[l][c] = '.';
}


