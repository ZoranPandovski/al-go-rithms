#include <iostream>
#include <stdlib.h>
#include "SET.h"
using namespace std;

int main()
{
    SET s1;
    cout << "\nEnter set A in (AUBUC):\n";
    s1.input();
    SET s2;
    cout << "\nEnter set B in (AUBUC):\n";
    s2.input();
    SET s3;
    cout << "\nEnter set C in (AUBUC):\n";
    s3.input();
    int a = s1.card();
    int b = s2.card();
    int c = s3.card();

    SET s4;
    s4 = s1.intersection(s2);
    int d = s4.card();
    SET s5;
    s5 = s2.intersection(s3);
    int e = s5.card();
    SET s6;
    s6 = s1.intersection(s3);
    int f = s6.card();
    SET s7;
    s7 = s4.intersection(s3);
    int g = s7.card();
    int answer = a + b + c - d - e - f + g;
    cout << "n(AUBUC) is : " << answer << "\n";
    return 0;
}