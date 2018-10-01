#include <iostream>
#include <string>
using namespace std;

const int NUMBEROFDOORS = 100;

int main()
{
    for (int i = 1, next = 1; i <= NUMBEROFDOORS; ++i)
    {
        bool open = next * next == i;
        if (open) {
            ++next;
        }
        cout << "Door " << i << ": is " << (open ? "open" : "closed") << "\n";
    }
}
