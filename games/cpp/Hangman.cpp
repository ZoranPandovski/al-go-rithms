// This program is an example of the popular game Hangman, in which one player enters a word, and another tries to guess the word letter by letter.
// An unordered map, which is a data structure from the C++ standard library, is used to keep track of game information.
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

//creates map out of entered word
unordered_map<char, vector<int>> CreateMap(string word)
{
    unordered_map<char, vector<int>> wordMap;
    for (int x = 0; x < word.length(); x++)
    {
        if (wordMap.find(word.at(x)) == wordMap.end())
        {
            //first element of vector keeps track of number of letter in word, second keeps track of index
            vector<int> location{ 1, x };
            wordMap.insert(make_pair(word.at(x), location));
        }
        else
        {
            //add one to letter count
            wordMap[word.at(x)][0]++;

            //push back location
            wordMap[word.at(x)].push_back(x);
        }
    }

    return wordMap;
}

void PrintMan(int wrongCount)
{
    switch (wrongCount)
    {
        case 0:
            cout << endl << endl
                << "   +----+  " << endl
                << "   |    |  " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "  =============" << endl << endl;
            break;
        case 1:
            cout << endl << endl
                << "   +----+  " << endl
                << "   |    |  " << endl
                << "   |    O  " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "  =============" << endl << endl;
            break;
        case 2:
            cout << endl << endl
                << "   +----+  " << endl
                << "   |    |  " << endl
                << "   |    O  " << endl
                << "   |    |  " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "  =============" << endl << endl;
        case 3:
            cout << endl << endl
                << "   +----+  " << endl
                << "   |    |  " << endl
                << "   |    O  " << endl
                << "   |   /|  " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "  =============" << endl << endl;
            break;
        case 4:
            cout << endl << endl
                << "   +----+  " << endl
                << "   |    |  " << endl
                << "   |    O  " << endl
                << "   |   /|\\ " << endl
                << "   |       " << endl
                << "   |       " << endl
                << "  =============" << endl << endl;
            break;
        case 5:
            cout << endl << endl
                << "   +----+  " << endl
                << "   |    |  " << endl
                << "   |    O  " << endl
                << "   |   /|\\ " << endl
                << "   |     \\ " << endl
                << "   |       " << endl
                << "  ============" << endl << endl;
            break;
        case 6:
            cout << endl << endl
                << "   +----+     " << endl
                << "   |    |     " << endl
                << "   |    O     " << endl
                << "   |   /|\\   " << endl
                << "   |   / \\   " << endl
                << "   |Your Dead " << endl
                << "  ============" << endl << endl;
        default:
            break;

    }
       
}

int main()
{
    string word;
    char letter;
    bool gameOver = false;
    int wrongCount = 0;
    cout << "Player 1, please enter a word." << endl;
    cin >> word;
    int lettersLeft = word.size();
    unordered_map<char, vector<int>> wordMap;
    wordMap = CreateMap(word);

    string current = "";
    for (int x = 0; x < word.size(); x++)
    {
        current.push_back('-');
    }


    while (gameOver == false)
    {
        PrintMan(wrongCount);
        cout << current << endl;
        cout << "Player 2, please guess a letter" << endl;
        cin >> letter;

        if (wordMap.find(letter) == wordMap.end())
        {
            wrongCount++;
            if (wrongCount == 6)
            {
                gameOver = true;
                PrintMan(wrongCount);
                cout << "Player 1 Wins!" << endl;
            }
        }
        else
        {
            int index = 1;
            while (wordMap[letter][0] != 0)
            {
                current[wordMap[letter][index]] = letter;
                wordMap[letter][0]--;
                index++;
                lettersLeft--;
            }

            if (lettersLeft == 0)
            {
                gameOver = true;
                PrintMan(wrongCount);
                cout << current << endl;
                cout << "Player 2 Wins" << endl;
            }
        }

        
    }
}