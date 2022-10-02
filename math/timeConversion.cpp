#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    string output = s.substr(0, 8);
    string ampm = s.substr(s.size() - 2);
    if(ampm=="PM" && s.substr(0, 2)!="12")
    {
        int hour = stoi(s.substr(0, 2));
        hour = (hour + 12) % 24;

        stringstream ss;
        ss << hour;

        output[0] = ss.str()[0];
        output[1] = ss.str()[1];
    }
    if(ampm=="AM" && s.substr(0, 2)=="12")
    {
        output[0]=output[1]='0';
    }
    return output;

}

int main()
{
    
    string s;
    getline(cin, s);
    string result = timeConversion(s);
    cout << result << "\n";
    return 0;
}

/*
Sample Input 0

07:05:45PM
Sample Output 0

19:05:45

*/
