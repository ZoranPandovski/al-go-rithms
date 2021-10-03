#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int createZombie()
{
    if (rand() % 67 < 10)
        return 11;

    else
        return rand() % 10 + 1;
}

int main()
{
    srand(time(NULL));
    char enter;

    // game stats
    int playerAlive = true;
    int playerSkill = 9;
    int playerScore = 1;
    string playerName = "";
    int zombieCount = 0;
    int zombiesKilled = 0;

    // title
    cout << "Welcome to Zombie War." << endl << "Press [ENTER] to start.";
    cin.get();

    // player name
    cout << "Please enter your name: ";
    cin >> playerName;

    // ask how many zombies
    cout << "How many zombies do you wish to fight? ";
    cin >> zombieCount;

    cout << "Get ready to fight for your life, " << playerName << "!" << endl;

    // main game loop
    while (playerAlive && zombiesKilled < zombieCount)
    {
        // create a random zombie
        int zombieSkill = createZombie();

        // battle sequence
        if (zombieSkill > 10)
        {
            cout << endl << "Here comes a huge zombie!" << endl;
        }
        else
        {
            cout << endl << "Here comes zombie " << zombiesKilled + 1 << endl;
        }

        cout << "Fighting..." << endl;
        sleep(2);

        // zombie killed the player
        if (playerSkill < zombieSkill)
        {
            playerAlive = false;
            cout << "You have died." << endl;
        }

        // player killed the zombie
        else
        {
            if (playerSkill - zombieSkill > 7)
            {
                cout << "You wasted the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else if (playerSkill - zombieSkill > 5)
            {
                cout << "You decapitated the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else if (playerSkill - zombieSkill > 0)
            {
                cout << "You killed the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else
            {
                cout << "You killed the zombie, but suffered injuries." << endl;
            }

            zombiesKilled++;
        }

        cout << endl;
        sleep(1);
    }

    // end game
    if (zombiesKilled == zombieCount)
    {
        // victory
        cout << "You have survived the onslaught!" << endl;
    }
    else
    {
        // lost
        cout << "You did not survive the zombie war." << endl;
    }

    cout << "Zombies killed: " << zombiesKilled << endl;
    cout << "Final score: " << playerScore << endl << endl;
}
