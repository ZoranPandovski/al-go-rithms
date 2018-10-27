#include <iostream>
using namespace std;

bool isPerfect(int);

int main()
{
    int num;
    cin >> num;
    cout << (isPerfect(num) ? "Perfect!" : "No!");

    return 0;
}

bool isPerfect(int num) {
    int sumDiv = 0;
    for (int i = 1; i <= num/2; i++) if (num % i == 0) sumDiv += i;
    return sumDiv == num;
}
