#include <iostream>
//#include<conio.h>
#include <unistd.h>
using namespace std;

class Logic
{
  private:
    static const int counter = 0;

  public:
    Logic();
    char Bool(int);
    void conjunction(int, int, int, bool);
    void disjunction(int, int, int, bool);
    void exclusiveOR(int, int, int, bool);
    void Negation(int, int, int);
    void Conditional(int, int, int);
    ~Logic();
};

Logic::Logic()
{
    cout << "\nProgram begins ...\n";
}

char Logic::Bool(int value)
{
    if (value == 0)
        return 'F';
    else
        return 'T';
}

void Logic ::conjunction(int p, int q, int counter, bool check)
{
    if (Logic::counter <= counter)
    {
        if ((p & q))
        {
            cout << Bool(p) << "   |   " << Bool(q) << "   |   ";
            if (check)
                cout << " T";
            else
                cout << "F";
        }
        else
        {
            cout << Bool(p) << "   |   " << Bool(q) << "   |   ";
            if (check)
                cout << " F";
            else
                cout << "T";
        }
        --counter;

        cout << endl;

        if (counter == 2)
            conjunction(p, ++q, counter, check);
        else if (counter == 1)
            conjunction(++p, --q, counter, check);
        else
            conjunction(p, ++q, counter, check);
    }
}

void Logic ::disjunction(int p, int q, int counter, bool check)
{
    if (Logic::counter <= counter)
    {
        if ((p | q))
        {
            cout << Bool(p) << "   |   " << Bool(q) << "   |   ";
            if (check)
                cout << " T";
            else
                cout << "F";
        }
        else
        {
            cout << Bool(p) << "   |   " << Bool(q) << "   |   ";
            if (check)
                cout << " F";
            else
                cout << "T";
        }
        --counter;

        cout << endl;

        if (counter == 2)
            disjunction(p, ++q, counter, check);
        else if (counter == 1)
            disjunction(++p, --q, counter, check);
        else
            disjunction(p, ++q, counter, check);
    }
}

void Logic::Negation(int p, int q, int counter)
{
    if (Logic::counter <= counter)
    {
        cout << Bool(p) << "   |   " << Bool(q) << "   |   " << Bool(!p) << "   |   " << Bool(!q);
        --counter;

        cout << endl;

        if (counter == 2)
            Negation(p, ++q, counter);
        else if (counter == 1)
            Negation(++p, --q, counter);
        else
            Negation(p, ++q, counter);
    }
}

void Logic ::exclusiveOR(int p, int q, int counter, bool check)
{
    if (Logic::counter <= counter)
    {
        if ((p ^ q))
        {
            cout << Bool(p) << "   |   " << Bool(q) << "   |   ";
            if (check)
                cout << " T";
            else
                cout << "F";
        }
        else
        {
            cout << Bool(p) << "   |   " << Bool(q) << "   |   ";
            if (check)
                cout << " F";
            else
                cout << "T";
        }
        --counter;

        cout << endl;

        if (counter == 2)
            exclusiveOR(p, ++q, counter, check);
        else if (counter == 1)
            exclusiveOR(++p, --q, counter, check);
        else
            exclusiveOR(p, ++q, counter, check);
    }
}

void Logic ::Conditional(int p, int q, int counter)
{
    if (Logic::counter <= counter)
    {
        if (((!p) | q))

            cout << Bool(p) << "   |   " << Bool(q) << "   |   "
                 << " T";
        else
            cout << Bool(p) << "   |   " << Bool(q) << "   |   "
                 << " F";

        --counter;
        cout << endl;

        if (counter == 2)
            Conditional(p, ++q, counter);
        else if (counter == 1)
            Conditional(++p, --q, counter);
        else
            Conditional(p, ++q, counter);
    }
}

Logic::~Logic()
{
    cout << "\nProgram ends here ...\n";
}

int main()
{
    int choice;
    Logic object;
start:
    cout << "====MENU====";
    cout << "\n 1.Conjunction";
    cout << "\n 2.Disjunction";
    cout << "\n 3.Exclusive OR";
    cout << "\n 4.Exclusive NOR";
    cout << "\n 5.Negation";
    cout << "\n 6.NAND";
    cout << "\n 7.NOR";
    cout << "\n 8.Conditional";
    cout << "\n 9.Biconditional";
    cout << "\n 10.Exit the code...";
    cout << "\nEnter your choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   "
             << "p&q"
             << "\n";
        cout << "====================\n";
        object.conjunction(0, 0, 3, true);
    }
    break;

    case 2:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   "
             << "p|q"
             << "\n";
        cout << "====================\n";
        object.disjunction(0, 0, 3, true);
    }
    break;
    case 3:
    case 9:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   ";
        if (choice == 3)
            cout << "p^q\n";
        else
            cout << "p<->q\n";
        cout << "====================\n";
        object.exclusiveOR(0, 0, 3, true);
    }
    break;
    case 4:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   "
             << "!(p^q)"
             << "\n";
        cout << "====================\n";
        object.exclusiveOR(0, 0, 3, false);
    }
    break;
    case 5:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   "
             << "~p   |   "
             << "~q   |   "
             << "\n";
        cout << "===============================\n";
        object.Negation(0, 0, 3);
    }
    break;
    case 6:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   "
             << "pNANDq"
             << "\n";
        cout << "====================\n";
        object.conjunction(0, 0, 3, false);
    }
    break;
    case 7:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   "
             << "pNORq"
             << "\n";
        cout << "====================\n";
        object.disjunction(0, 0, 3, false);
    }
    break;

    case 8:
    {
        cout << endl;
        cout << "p   |   "
             << "q   |   "
             << "p->q"
             << "\n";
        cout << "====================\n";
        object.Conditional(0, 0, 3);
    }
    break;
    case 10:
        return 0;
    default:
        cout << "Invalid input!";
    }
    cout << "\nWant to try more options(y/n):";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        goto start;
    //getch();
    sleep(1);
    return 0;
}