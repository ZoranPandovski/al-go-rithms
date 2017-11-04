#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int Q;
    cin>>Q;
    while(Q>0){
        string s;
        cin>>s;
        int len = s.length(),i,j;
        sort(s.begin(),s.end());
        while(true){
            cout<<s<<endl;
            for(i=len-2;i>=0;i--){
                if(s[i]<s[i+1])
                    break;
            }
            if(i==-1)
                break;
            for(j=len-1;j>i;j--){
                if(s[j]>s[i])
                    break;
            }
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            int k = i+1, l = len-1;
            while(k<l){
                char t = s[k];
                s[k] = s[l];
                s[l] = t;
                k++;
                l--;
            }
        }
        Q--;
    }
    return 1;
}
