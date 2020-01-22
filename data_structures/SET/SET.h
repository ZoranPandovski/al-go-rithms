#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
class SET
{
    int *arr, n, i, j, size, element, flag, y, s;

  public:
    SET();
    void input();
    void display();
    bool subset(SET);
    SET unio(SET);
    SET intersection(SET);
    SET setdifference(SET);
    void cartesianproduct(SET);
    void compliment();
    int cardinality();
    int subset_string(string);
    int card();
    bool ismember(int);
    void powershow();
    int bin(int);
    void freememory();
};
int SET ::card()
{
    return size;
}

bool SET ::ismember(int x)
{
    for (i = 0; i < size; i++)
    {
        if (x == arr[i])
            return true;
    }
    return false;
}

void SET ::powershow()
{
    int bina[size];
    cout << "{ { },";
    for (int i = 1; i < pow(2, size); i++)
    {
        int out = bin(i);
        for (int j = 0; j < size; j++)
        {
            bina[j] = out % 10;
            out /= 10;
        }
        cout << "{";
        for (int j = 0; j < size; j++)
        {
            if (bina[j] == 1)
            {
                cout << arr[j] << ",";
            }
        }
        cout << "},";
    }
    cout << " }";
}

int SET ::bin(int n)
{
    if (n / 2 == 0)
        return 1;
    else
        return (10 * bin(n / 2) + n % 2);
}

int SET ::cardinality()
{
    return size;
}
SET ::SET()
{
    i = 0;
    j = 0;
    size = 1;
    s = 1;
    flag = 0;
    arr = (int *)malloc(sizeof(int));
}

void SET ::input()
{
    int x;
    cout << "\nEnter the size:";
    cin >> n;

    cout << "Enter the element of set:";
    cin >> arr[0];
    for (i = 1; i < n; i++)
    {
        x = 0;
        cin >> element;
        for (j = 0; j < size; j++)
        {
            if (element != arr[j])
                ++x;
        }

        if (x == size)
        {
            ++s;
            int *memory = (int *)realloc(arr, s * sizeof(int));
            arr = memory;
            memory[size] = element;
            ++size;
        }
    }
}

void SET ::display()
{
    cout << "{";
    for (i = 0; i < size; i++)
        cout << arr[i] << ",";
    cout << "}";
}

bool SET ::subset(SET w)
{
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < w.size; j++)
        {
            if (arr[i] == w.arr[j])
            {
                ++flag;
                break;
            }
        }
    }

    if (flag == size)
        return true;
    else
        return false;
}

SET SET ::unio(SET w)
{
    s = size;
    SET obj;
    int *uni = (int *)realloc(obj.arr, size * sizeof(int));
    uni = arr;
    int *u;
    for (i = 0; i < w.size; i++)
    {
        flag = 0;
        for (j = 0; j < size; j++)
        {
            if (arr[j] == w.arr[i])
                ++flag;
        }
        if (flag == 0)
        {
            u = (int *)realloc(uni, s * sizeof(int));
            u[s] = w.arr[i];
            ++s;
        }
    }
    obj.size = s;
    obj.arr = u;
    //free(uni);
    //free(u);
    return obj;
}

SET SET ::intersection(SET w)
{
    SET ob;
    int *xyz = (int *)malloc(0);
    s = 1;
    flag = 0;
    int *intersec;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < w.size; j++)
        {
            if (arr[i] == w.arr[j])
            {

                intersec = (int *)realloc(xyz, s * sizeof(int));
                xyz = intersec;
                intersec[flag] = arr[i];
                ++flag;
                ++s;
                break;
            }
        }
    }
    ob.size = flag;
    ob.arr = intersec;
    //free(xyz);
    //free(intersec);
    return ob;
}

SET SET ::setdifference(SET w)
{
    SET ob1;
    int *abc = (int *)malloc(0);
    int *setdiff;
    s = 1;
    y = 0;
    for (i = 0; i < size; i++)
    {
        flag = 0;
        for (j = 0; j < w.size; j++)
        {
            if (arr[i] == w.arr[j])
            {
                ++flag;
                break;
            }
        }
        if (flag == 0)
        {
            setdiff = (int *)realloc(abc, s * sizeof(int));
            abc = setdiff;
            setdiff[y] = arr[i];
            ++y;
            ++s;
        }
    }
    ob1.size = y;
    ob1.arr = setdiff;
    //free(abc);
    //free(setdiff);
    return ob1;
}

void SET ::cartesianproduct(SET w)
{
    cout << "{";
    for (i = 0; i < size; i++)
    {

        for (j = 0; j < w.size; j++)
        {
            cout << "(" << arr[i] << "X" << w.arr[j] << "),";
        }
    }
    cout << "}";
}

void SET ::compliment()
{

    cout << "Enter universal set:";
    SET objuni;
    objuni.input();
    cout << "{";

    for (i = 0; i < objuni.size; i++)
    {
        y = 0;
        for (j = 0; j < size; j++)
        {
            if (objuni.arr[i] != arr[j])
                ++y;
        }
        if (y == size)
            cout << objuni.arr[i] << ",";
    }

    cout << "}";
}

int SET ::subset_string(string s)
{
    int q = 0;
    int r = 0;
    for (i = 0; i < s.length(); i++)
    {
        flag = 0;
        if (isdigit(s[i]))
        {
            for (j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                    return 0;
            }
            ++r;
            int a = s[i] - '0';
            for (j = 0; j < size; j++)
            {
                if (a != arr[j])
                {
                    flag++;
                }
            }
            if (flag == size)
            {
                return 0;
            }

            else
                ++q;
        }
    }
    if (q == r)
    {

        return 1;
    }
}
void SET ::freememory()
{
    free(arr);
}
