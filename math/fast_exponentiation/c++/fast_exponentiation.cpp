// MOD AUTHOR:  Taylor Hudson
// GITHUB    :  https://github.com/allencompsci
// DATE      :  October 20, 2017
// DESCRITION:  This C++ program implements two fast_exponentations operation in a space efficient, non-recursive manner and works beyond long long


#include<bits/stdc++.h>
// Added string and vector
#include<string> 
#include<vector>
using namespace std;

#define ll long long int
#define MOD 1000000007 /// Why is it MOD 1 billion and 7 as far as I can tell... This is predicated on the divison of exponent by 2 as int 
ll fast_exp(int, int);
bool isEven(string);
bool isEqualTo(string, string);
bool charLess(char, char);
bool isLessthan(string, string);
string add(string,string);
string sub(string,string);
string multi(string,string);
string StringMULT(string,string);
string LongDivision(string,string);
string intDivison(string,string);

int main(){
	ll base=4;
	ll power=10;
	
	while(true){
		cout<< fast_exp_LRG(base, power) << " : ";
		cout<<fast_exp(base++,power++)<<endl;
		
	}
}

string fast_exp_LRG(ll b, ll e) {
	string tmp = "1";
	string base = to_string(b);
	string exp = to_string(e);
	while (exp != "0") {
		if (!isEven(exp)) {
			tmp = StringMULT(tmp, base);
		}
		base = StringMULT(base, base);
		exp = intDivison(exp, "2");
	}
	return tmp;
}

ll fast_exp(int base, int exp) {
    ll res=1; 
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}
bool isEven(string a) {
	return ((int)(a[(int)a.length() - 1]) % 2) == 0;
}
bool isEqualTo(string x, string y) {
	if (x[0] == '-') {
		x = x.substr(1);
		if (y[0] == '-') {
			y = y.substr(1);

		}
		else {
			return false;
		}

	}
	else if (y[0] == '-') {
		y = y.substr(1);
		return false;
	}
	while (x[0] == '0') {
		if (x.length() == 1) {
			break;
		}
		x = x.substr(1);
	}
	while (y[0] == '0') {
		if (y.length() == 1) {
			break;
		}
		y = y.substr(1);
	}

	if (x.length() != y.length())
	{
		return false;
	}
	else {
		int xLen = x.length();
		for (int i = 0; i < xLen; i++) {
			if (x[i] != y[i]) { return false; }

		}
	}
	return true;
}
bool charLess(char x, char y) {
	int xVal = (int)x - 48;
	int yVal = (int)y - 48;
	if (xVal < yVal)
		return true;
	else
		return false;
}
bool isLessthan(string x, string y) {
	if (x[0] == '-') {
		x = x.substr(1);
		if (y[0] == '-') {
			y = y.substr(1);
			return !(isLessthan(x, y));

		}
		else {
			return true;
		}

	}
	else if (y[0] == '-') {
		y = y.substr(1);
		return false;
	}

	while (x[0] == '0') {
		if (x.length() == 1) {
			break;
		}
		x = x.substr(1);
	}
	while (y[0] == '0') {
		if (y.length() == 1) {
			break;
		}
		y = y.substr(1);
	}
	if (isEqualTo(x, y)) {
		return false;
	}
	if (x.length() < y.length()) {
		return true;
	}
	else if (y.length() < x.length()) {
		return false;
	}
	else {
		int xLen = x.length();
		for (int i = 0; i < xLen; i++) {

			if (charLess(x[i], y[i])) {
				return true;
			}
			else if (charLess(y[i], x[i])) {
				return false;
			}

		}

		return false;
	}
}
string add(string a, string b) { // ADDED 
	string temp = "";
	while ((int)a.length() < (int)b.length()) {
		a = "0" + a;
	}
	while ((int)b.length() < (int)a.length()) {
		b = "0" + b;
	}
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		char val = (char)(((a[i] - 48) + (b[i] - 48)) + 48 + carry);
		if (val > 57) {
			carry = 1;
			val -= 10;
		}
		else {
			carry = 0;
		}
		temp = val + temp;
	}
	if (carry != 0) {
		temp = "1" + temp;
	}
	while (temp[0] == '0' && temp.length() != 1) {
		temp = temp.substr(1);
	}
	return temp;
}
string sub(string a, string b) { // ADDED 
	string temp = "";
	while ((int)a.length() < (int)b.length()) {
		a = "0" + a;
	}
	while ((int)b.length() < (int)a.length()) {
		b = "0" + b;
	}
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		char val = (char)(((a[i] - 48) - (b[i] - 48)) + 48 + carry);
		if (val < 48) {
			carry = -1;
			val += 10;
		}
		else {
			carry = 0;
		}
		temp = val + temp;
	}
	while (temp[0] == '0' && temp.length() != 1) {
		temp = temp.substr(1);
	}
	return temp;
}
string multi(string a, string b) { //ADDED
	string temp = a;
	if ((int)a.length() < (int)b.length()) {
		a = b;
		b = temp;

	}
	temp = a;
	while (b != "1") {
		temp = add(temp, a);
		b = sub(b, "1");
	}
	return temp;
}
string StringMULT(string a, string b) {
	if (a[0] == '-') {
		a = a.substr(1);
		if (b[0] == '-') {
			b = b.substr(1);

		}
		else {
			return '-' + StringMULT(a, b);
		}

	}
	else if (b[0] == '-') {
		b = b.substr(1);
		return '-' + StringMULT(a, b);
	}
	int c;
	int count = 0;
	int d;
	char e;
	string RESULT = "0";
	vector<string> line;
	c = a.length();
	d = b.length();
	while (c < d) {
		a = "0" + a;
		c = a.length();
	}
	while (d < c) {
		b = "0" + b;
		d = b.length();
	}

	for (int j = c - 1; j>-1; j--) {
		int carry = 0;
		line.push_back("");
		int TrailingZeros = 0;
		while (TrailingZeros < count) {
			line[count] += "0";
			TrailingZeros++;
		}
		for (int i = d - 1; i>-1; i--) {

			int value = ((a[i] - 48)*(b[j] - 48)) + carry;
			if (value > 9) {
				e = (char)(value % 10 + 48);
				carry = value / 10;
			}
			else {
				e = (char)(value + 48);
				carry = 0;
			}
			line[count] = e + line[count];

		}
		if (carry > 0) {
			line[count] = (char)(carry + 48) + line[count];
		}
		count++;
	}

	for (int i = 0; i<count; i++) {
		//cout<<line[i]<<endl;
	}
	// ADD LINES
	count = 0;
	int size = line.size();
	while (count < (size)) {
		RESULT = add(RESULT, line[count]);
		count++;
	}

	// 	cout << "ALL LEADING ZEROS : " << RESULT << endl;
	while (RESULT[0] == '0' && RESULT != "0") {
		RESULT = RESULT.substr(1);
	}
	return RESULT;
}
string LongDivision(string x, string y) {
	if (x[0] == '-') {
		x = x.substr(1);
		if (y[0] == '-') {
			y = y.substr(1);

		}
		else {
			return '-' + LongDivision(x, y);
		}

	}
	else if (y[0] == '-') {
		y = y.substr(1);
		return '-' + LongDivision(x, y);
	}
	string hold = "";
	string Remainder = " R : ";
	// x divided by y

	while (x[0] == '0') {
		if (x.length() == 1) {
			break;
		}
		x = x.substr(1);
	}
	while (y[0] == '0') {
		if (y.length() == 1) {
			return "Cannot implicitly divide by zero.";
		}
		y = y.substr(1);
	}
	string R = "0";
	string Solution = "";
	int xLen = x.length();
	for (int i = 0; i < xLen; i++) {
		R = R + x[i];
		int count = 0;
		while (isLessthan(y, R)) {
			count++;
			//	cout << "R : " << R << " y : " << y << " = " ;
			R = sub(R, y);
			//	cout << R << endl;
		}
		if (isEqualTo(y, R)) {
			//	cout <<" EqualTo " << endl;
			R = "0";
			count++;
		}
		//	cout << Solution << endl;
		Solution = Solution + (char)(count + 48);
		//	cout << Solution << endl;
	}

	while (Solution[0] == '0') {
		if (Solution.length() == 1) {
			break;
		}
		//	cout << Solution << " : " << Solution.substr(1) << endl;
		Solution = Solution.substr(1);
	}
	while (R[0] == '0') {
		if (R.length() == 0) {
			break;
		}
		else if (R.length() == 1) {
			break;
		}
		R = R.substr(1);
	}


	return Solution + Remainder + R + " / " + y;

}
string intDivison(string a, string b) {
	string tmp = LongDivision(a, b);
	return tmp.substr(0, (int)tmp.find(' '));
}
