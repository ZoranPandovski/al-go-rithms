/*
Given a string, we have to find the longest word in the input string and then display that word also the length of that word.

Eg:
Input  : A computer science portal for geeks
Output : The longest word in a sentence is computer having length 8
*/

#include <iostream>
#include <string>

using namespace std;
string longest_word(string s)
{
    int len = s.length();

    // we are taking four pointers starting for denoting start & end for denoting end and maxlen & max_starting for taking account of starting of max_length word with its length.
    int starting = 0, end = 0, max_len = 0, max_starting = 0;

    // Loop till full string is not traversed
    while (end <= len)
    {
        if (end < len and s[end] != ' ') // If char is not space then increase the end pointer
        {
            end++;
        }
        else
        {
            int curr_length = end - starting; // Finding the length of the word that is traversed

            if (curr_length > max_len) // If word length is greater than the max length that stored then change max_len and starting of max len word.
            {
                max_len = curr_length;
                max_starting = starting;
            }
            end++;
            starting = end;
        }
    }
    return s.substr(max_starting, max_len); // Simply return that longest word or string in the sentence.
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    getline(cin, s); // Getting Line as a input.

    string ans = longest_word(s);
    cout << "The longest word in a sentence is " << ans << " having length " << ans.length();

    return 0;
}

/*
Input :- This is sample code based on string for GSSOC'22
Output:- The longest word in a sentence is GSSOC'22 having length 8
*/
