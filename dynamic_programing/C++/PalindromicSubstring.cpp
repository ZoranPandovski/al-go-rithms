#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll isPalin(string s,ll x,ll y)
{
    ll a=x;
    ll b=y;
    while(a<b)
    {
        if(s[a]!=s[b])
        {
            return -1;
        }
        a++;
        b--;
    }
    return 1;
}

string palindromic(string s,ll i,ll j,vector<vector<ll>> &v)
{
    if(i>=j)
    {
        string ans;
        ans+=s[i];
        return ans;
    }
    else if(s[i]==s[j])
    {
        ll f=0;
        if(v[i][j]!=0)
        {
            if(v[i][j]==1)
            {
                f=1;
            }
            else f=-1;
        }
        if(f==0)
        {
            f=isPalin(s,i+1,j-1);
            v[i][j]=f;
        }
        if(f==1)
        {
            string ans;
            for(int x=i;x<=j;++x)
            {
                ans+=s[x];
            }
            return ans;
        }
        else
        {
            string s1= palindromic(s,i+1,j,v);
            string s2= palindromic(s,i,j-1,v);
            if(s1.length()>=s2.length())
            {
                return s1;
            }
            else return s2;
        }
    }
    else
    {
        string s1= palindromic(s,i+1,j,v);
        string s2= palindromic(s,i,j-1,v);
        if(s1.length()>=s2.length())
        {
            return s1;
        }
        else return s2;
    }
}
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<vector<ll>> v(s.length());
        for(int i=0;i<s.length();++i)
        {
            v[i].resize(s.length(),0);
        }
        string ans=palindromic(s,0,s.length()-1,v);
        cout<<ans<<endl;
    }

	return 0;
}
