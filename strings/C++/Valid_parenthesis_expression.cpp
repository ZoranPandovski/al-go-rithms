#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> open, star;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') open.push(i); // keeping track of where open brackets are.
            else if (s[i] == '*') star.push(i); // and stars
            else { // s[i]==')'
                if (!open.empty()) open.pop(); // if open exists
                else if (!star.empty()) star.pop(); // if star exists
                else return false; // if none then invalid
            }
        }
        // stack not empty meaning open parenthesis not closed
        while (!open.empty()) {
            if (star.empty()) return false; // no way to validate
            else {
                if (open.top() > star.top()) return false; // if star happened before open bracket
                else {
                    // star can be used as close
                    star.pop();
                    open.pop();
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string input = "(*))";
    bool isValid = solution.checkValidString(input);
    if (isValid) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    return 0;
}
