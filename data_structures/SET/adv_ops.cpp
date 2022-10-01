#include <iostream>
#include <stdlib.h>
#include "SET.h"
using namespace std;

int main()
{
    char ch;
    SET s1;
    cout << "\nSET 1:";
    cout << "\n===========";
    s1.input();
    cout << "\nset 1 => ";
    s1.display();
    SET s2;
    cout << "\nSET 2";
    cout << "\n===========";
    s2.input();
    cout << "\nset 2 => ";
    s2.display();
    int d;
    do
    {
        cout << "\nMENU:";
        cout << "\n1.subset";
        cout << "\n2.union";
        cout << "\n3.intersection";
        cout << "\n4.set difference";
        cout << "\n5.cartesian product";
        cout << "\n6.compliment";
        cout << "\n7.symmetric difference";
        cout << "\n8.Exit the program";
        cout << "\nenter your choice:";
        cin >> d;

        switch (d)
        {
        case 1:
        {
            cout << "\nSELECT:";
            cout << "\n1.check whether set1 is a subset of set2 or not";
            cout << "\n2.check whether set2 is a subset of set1 or not";
            cout << "\nenter your option:";
            cin >> d;
            if (d == 1)
            {
                if (s1.subset(s2))
                {
                    cout << "\ns1 is a subset of s2";
                }
                else
                    cout << "\ns1 is not a subset of s2";
            }
            else if (d == 2)
            {
                if (s2.subset(s1))
                {
                    cout << "\ns2 is a subset of s1";
                }
                else
                    cout << "\ns2 is not a subset of s1";
            }

            else
                cout << "\ninvalid choice!";
        }
        break;
        case 2:
        {
            cout << "\nUNION:";
            SET s3;
            s3 = s1.unio(s2);
            s3.display();
        }
        break;

        case 3:
        {
            cout << "\nINTERSECTION:";
            SET s3;
            s3 = s1.intersection(s2);
            s3.display();
        }
        break;
        case 4:
        {
            cout << "\nSet difference:";
            SET s3;
            cout << "\nchoice:";
            cout << "\n1.set1-set2";
            cout << "\n2.set2-set1";
            cout << "\nenter your choice:";
            cin >> d;
            if (d == 1)
            {
                s3 = s1.setdifference(s2);
                s3.display();
            }
            else if (d == 2)
            {
                s3 = s2.setdifference(s1);
                s3.display();
            }
            else
                cout << "\ninvalid choice!";
        }
        break;
        case 5:
        {
            cout << "\nCartesian product:";
            cout << "\nchoice:";
            cout << "\n1.set1Xset2";
            cout << "\n2.set2Xset1";
            cout << "\nenter your choice:";
            cin >> d;
            if (d == 1)
            {
                s1.cartesianproduct(s2);
            }
            else if (d == 2)
            {
                s2.cartesianproduct(s1);
            }
            else
                cout << "\ninvalid choice!";
        }
        break;
        case 6:
        {
            cout << "\ncompliment\n";
            cout << "\nchoice:";
            cout << "\n1.Compliment of set1";
            cout << "\n2.Compliment of set2";
            cout << "\nenter your choice:";
            cin >> d;
            if (d == 1)
            {
                s1.compliment();
            }
            else if (d == 2)
            {
                s2.compliment();
            }
            else
                cout << "\ninvalid choice!";
        }
        break;

        case 7:
        {
            SET s3;
            SET s4;
            SET s5;
            s3 = s1.setdifference(s2);
            s4 = s2.setdifference(s1);
            s5 = s3.unio(s4);
            s5.display();
        }
        break;
        case 8:
            return 0;
        default:
            cout << "\ninvalid choice !";
        }
        cout << "\nwant to select more choices(y/n):";
        cin >> ch;
        cin.ignore();
    } while (ch == 'Y' || ch == 'y');

    int h = s1.cardinality();
    cout << "card" << h;
    s1.freememory();
    s2.freememory();
    return 0;
}
