#include <stdio.h>
#include <string.h>

int state = 0;

int main() {
    while (state < 25) {
        // ask user to insert a coin
        printf("Your balance is %d\n", state);
        printf("Please insert a coin (penny, nickle, dime, quarter): ");

        char* coin;
        scanf("%s", coin);

        if (strcmp(coin, "penny") == 0)
            state += 1;
        else if (strcmp(coin, "nickel") == 0)
            state += 5;
        else if (strcmp(coin, "dime") == 0)
            state += 10;
        else if (strcmp(coin, "quarter") == 0)
            state += 25;
        else
            puts("Sorry, this is not a count");
    }
    puts("Thanks, here's your quarter.");
}
