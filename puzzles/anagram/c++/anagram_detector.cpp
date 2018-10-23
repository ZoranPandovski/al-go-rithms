/*
This is a simple anagram detector in c++.
You can enter any set of strings, separated by a ? mark, and you will see if this is a valid anagram or not.

Run:
g++ anagram_detector.cpp
./a.out
 */

#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
  std::vector<char> al1, al2;
  std::string alliteration;
  std::getline(std::cin, alliteration);
  for (std::string::iterator s = alliteration.begin(); s != alliteration.end(); ++s)
    {
      if (*s != ' ' && *s != '\'' &&
          s - alliteration.begin() < std::find(alliteration.begin(), alliteration.end(), '?') - alliteration.begin())
        {
          al1.push_back(std::tolower(*s));
        }
      else if (*s != ' ' && *s != '\'' &&
               s - alliteration.begin() > std::find(alliteration.begin(), alliteration.end(), '?') - alliteration.begin())
        {
          al2.push_back(std::tolower(*s));
        }
    }
  std::sort(al1.begin(), al1.end());
  std::sort(al2.begin(), al2.end());

  if (al1 == al2)
    {
      std::cout << "is an anagram" << std::endl;
    }
  else
    {
      std::cout << "is NOT an anagram" << std::endl;
    }
}
