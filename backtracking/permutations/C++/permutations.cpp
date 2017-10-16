#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void swap(string &s, int i, int j) {
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
 
void permute(string &s, int level, int &num) {
	if(level == s.size()) {
		cout<<num<<". "<<s<<endl;
		num++;
	}
	else {
		for(int j=level;j<s.size();j++) {
			swap(s,level,j);
			permute(s,level+1,num);
			swap(s,level,j);
		}
	}
}

int main() {
	string s; int c = 1;
	cin>>s;
	sort(s.begin(),s.end());
	permute(s,0,c);
}