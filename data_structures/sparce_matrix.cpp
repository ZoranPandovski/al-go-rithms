#include <iostream>
#include <math.h>
using namespace std;

int size, dem;

void addElement(int *arr, int num, int i)
{
    arr[i] = num;
}

void addTrigonal(int *arr, int num, int i, int j)
{
    arr[2 * i + j] = num;
}

void addElement(int *arr, int num, int i, int j)
{
    arr[(i * (i + 1)) / 2 + j] = num;
}

bool search(int *arr, int el)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == el)
            return true;
    return false;
}

void replace(int *arr, int prevEl, int newEl)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == prevEl)
            arr[i] = newEl;
}

void remove(int *arr, int el)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == el)
            arr[i] = 0;
}

void display(int *arr, int a)
{
    int counter = 0;
    cout << "\nmatrix is (0 represents empty cell and n represents invalid cell):";
    for (int i = 0; i < dem; i++)
    {
        cout << "\n";
        for (int j = 0; j < dem; j++)
        {
            if (a == 1)
                (i == j) ? cout << "  " << arr[counter++] : cout << "  n";
            else if (a == 2)
                (i >= j) ? cout << "  " << arr[counter++] : cout << "  n";
            else if (a == 3)
                (j >= i) ? cout << "  " << arr[counter++] : cout << "  n";
            else if (a == 5)
                (abs(i - j) <= 1) ? cout << "  " << arr[counter++] : cout << "  n";
            else
                (i >= j) ? cout << "  " << arr[(i * (i + 1)) / 2 + j] : cout << "  " << arr[(j * (j + 1)) / 2 + i];
        }
    }
    cout << "\n";
}

void p()
{
    cout << "\ninvalid cell";
}

void menu(int *array, int a)
{
    int num, i, j, choice;
    do
    {
        cout << "\nMenu :  \n1. insert\n2. search\n3. delete\n4. replace\n5. display\n\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter the number to be added(except 0) : ";
            cin >> num;
            cout << "\nSpecify cell (i and j) : ";
            cin >> i >> j;

            if (a == 1)
                (i == j) ? addElement(array, num, i) : p();
            else if (a == 2)
                (i >= j) ? addElement(array, num, i, j) : p();
            else if (a == 3)
                (j >= i) ? addElement(array, num, j, i) : p();
            else if (a == 4)
                (j <= i) ? addElement(array, num, i, j) : addElement(array, num, j, i);
            else
                (abs(i - j) <= 1) ? addTrigonal(array, num, i, j) : p();
        }
        break;

        case 2:
        {
            cout << "\nEnter the number to be searched : ";
            cin >> num;
            (search(array, num)) ? cout << "\ndata is  present" : cout << "\ndata is not present";
        }
        break;

        case 3:
        {
            cout << "\nEnter the number to be deleted : ";
            cin >> num;
            remove(array, num);
            cout << "\nall " << num << " are deleted";
        }
        break;

        case 4:
        {
            int prevEl, newEl;
            cout << "\nEnter the number to be replaced and new number : ";
            cin >> prevEl >> newEl;
            replace(array, prevEl, newEl);
            cout << "\nall " << prevEl << " are replaced";
        }
        break;

        case 5:
        {
            display(array, a);
        }
        break;

        default:
            cout << "\nInvalid choice!";
        }

        cout << "\nEnter 0 to exit : ";
        cin >> choice;
    } while (choice != 0);
}

int main()
{
    cout << "\nEnter dimension of matrix : ";
    cin >> dem;
    char ch;
    do
    {
        cout << "\nEnter type of matrix : \n\n1. diagonal matrix\n2. lower triangular matrix\n3 .upper triangular matrix\n4. symmetric matrix\n5. tridiagonal matrix";
        cout << "\n\nEnter your choice : ";
        int choice;
        cin >> choice;

        int *array;
        switch (choice)
        {
        case 1:
        {
            size = dem;
            array = (int *)calloc(size, sizeof(int));
        }
        break;

        case 2:
        case 3:
        case 4:
        {
            size = (dem * dem + dem) / 2;
            array = (int *)calloc(size, sizeof(int));
        }
        break;

        case 5:
        {
            size = 3 * dem - 2;
            array = (int *)calloc(size, sizeof(int));
        }
        break;

        default:
            cout << "\ninvalid choice!";
        }

        menu(array, choice);
        free(array);
        cout << "\ntry another matrix, enter 0 to exit : ";
        cin >> ch;
    } while (ch != 0);
}