#include <iostream>
using namespace std;
//function to find longest word
int longest_word_length(string str) {
   int length = str.length(); //length of the given string
   
   //intializing with 0
   int temp_length = 0;
   int new_length = 0;

   for (int i = 0; i < length; i++) {
      if (str[i] != ' ') //check of spaces
         new_length++;
      else {
         //if word found store length in temp_length
         temp_length = max(temp_length, new_length);
         //re-initialize new_length with 0 to store new word length
         new_length = 0;
      }
   }
   return max(temp_length, new_length); //return maximum length
}


int main() {
   string s;
   getline(cin , s) ; //input string
   cout <<"Length of the longest word in given sentence is "<<longest_word_length(s);
   return 0;
}