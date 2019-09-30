#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


int main() {
    int T, N;
    scanf("%d", &T);
    string S;
    for (;T--;) {
	cin>>S;
	N=S.size();
	
	if (N%2==0) {
	    int a[26]={}, ans=0;
	    for (int i=0; i*2<N; i++) a[S[i]-'a']++;
	    for (int i=N/2; i<N; i++) a[S[i]-'a']--;
	    for (int i=0; i<26; i++) ans += abs(a[i]);
	    printf("%d\n", ans/2);
	} else {
	    puts("-1");
	}
    }	    
    return 0;
}
