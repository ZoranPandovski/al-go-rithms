#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &a)
{
    int low = 0, mid = 0, high = a.size() - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if (a[mid] == 2)
        {
            swap(a[mid], a[high]);
            high--;
        }
        else
            mid++;
    }
}

int main()
{
    vector<int> v = {1,2,0,0,2,2,1,0};
    sortColors(v);
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}