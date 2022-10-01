#include "RELATION.h"

int main()
{
    char ch;
    RELATION obj;
    string s;
    s = obj.input();
    cout << "The relation is :";
    cout << s;
    obj.matrixnotation();
    //string dora = "{(1,1),(1,2),(1,3),(2,2),(2,4)}";
    int choice;
    do
    {
        cout << "\n======MENU======";
        cout << "\n 1.Reflexive";
        cout << "\n 2.Symmetric";
        cout << "\n 3.Asymmetric";
        cout << "\n 4.Anti-Symmetric";
        cout << "\n 5.Transitive";
        cout << "\n 6.Type of relation";
        cout << "\n 7.Domain";
        cout << "\n 8.Range";
        cout << "\n 9.Exit the code";
        cout << "\n Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (obj.reflexive())
                cout << "\nreflexive";
            else
                cout << "\nnot reflexive";
        }
        break;
        case 2:
        {
            if (obj.symmetric())
                cout << "\nsymmetric";
            else
                cout << "\nnot symmetric";
        }
        break;
        case 3:
        {
            if (obj.symmetric())
                cout << "\nnot Asymmetric";
            else if (obj.antisymmetric())
                cout << "\nnot Asymmetric";
            else
                cout << "\nAsymmetric";
        }
        break;
        case 4:
        {
            if (obj.antisymmetric())
                cout << "\nantisymmetric";
            else
                cout << "\nnot antisymmetric";
        }
        break;
        case 5:
        {
            if (obj.transitive())
                cout << "\ntransitive";
            else
                cout << "\nnot transitive";
        }
        break;
        case 6:
        {
            if ((obj.reflexive()) && (obj.symmetric()) && (obj.transitive()))
                cout << "\nIt is a equvivalent relation";
            else if ((obj.reflexive()) && (obj.antisymmetric()) && (obj.transitive()))
                cout << "\nIt is a partial order relation";
            else
                cout << "\nNeither equivalent relation nor partial order";
        }
        break;
        case 7:
            obj.domain(1);
            break;
        case 8:
            obj.range(1);
            break;
        case 9:
            return 0;
        default:
            cout << "\nInvalid choice !";
        }

        cout << "\nWant to try more options(y/n):";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}