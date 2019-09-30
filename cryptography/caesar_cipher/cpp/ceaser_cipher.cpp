#include <iostream>
using namespace std;

string ceaser(string toCipher, int shift){
	for(int i=0;i<toCipher.size();i++){
	if(islower(toCipher[i]))
		toCipher[i] = 'a' +((toCipher[i]-'a')+shift)%26;
	if(isupper(toCipher[i]))
		toCipher[i] = 'A'+((toCipher[i]-'A')+shift)%26;
	}
	return toCipher;
}
void test(){
	cout<<ceaser("Hello",3)<<endl;
	cout<<ceaser("Hello",4)<<endl;
	cout<<ceaser("mySsstrghv",6)<<endl;
}
int main(){
	test();
}