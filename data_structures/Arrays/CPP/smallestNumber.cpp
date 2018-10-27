#include<bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  for (int i = 2; i < sqrt(n); i++) {
    if (n % i == 0) {
      return false;
      break; //never reach this
    } 
  }
  return true;
}
int main(){
	int t,n,flag,i,j;
	cin >> t;
	while(t--){
		flag = 1;
		cin >> n;
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=2;i<=1000000;i++){
			if(!isprime(i))
				continue;
		    flag = 1;
			for(j=0;j<n;j++){
				if(__gcd(i,a[j]) != 1){
					flag = 0;
					break;
				}
			}
			if(flag == 1)
				break;
		}
		if(flag == 1)
            printf("%d\n",i);
        else 
            printf("-1\n");
	}
}

