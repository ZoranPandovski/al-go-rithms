/* Power of 2 can be found by (n&(n-1) == 0
 * Because it will have only one set bit
 * For power of 4 we have to check the even
 * positions for the set bit
 * So we & it with 10101010101010101010101010101010
 * It can also be written as 0xAAAAAAAA
 * If (n & 0xAAAAAAAA) == 0 then n is power of 4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define pb push_back
#define mod 1000000007

bool poweroffour(int n)
{
    return (n && !(n&(n-1)) && !(n & 0xAAAAAAAA));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    if(poweroffour(n))
        cout<<n<<" is a power of 4\n";
    else
        cout<<n<<" is not a power of 4\n";
    return 0;
}
