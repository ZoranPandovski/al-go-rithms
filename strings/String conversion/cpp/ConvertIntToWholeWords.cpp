/*

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

Example 1:
Input: 123
Output: "One Hundred Twenty Three"


Example 2:
Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"


Example 3:
Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


Example 4:
Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/
#include <iostream>
#include <string>
#include <math.h>

std::string get_num(int num_h,int num_t,int num_ones)
{
  std::string word;
  // this check is to see if there is any number in the hundreds tens or ones place fo cases like 1000 or 123000 etc
  if(num_h==0 && num_t==0&& num_ones==0)
  return "";
  // if there is something in those places we parse them
  if (num_h!=0)
  {
    switch(num_h)
    {
      case 1: {word+="One Hundred ";break;}
      case 2: {word+="Two Hundred ";break;}
      case 3: {word+="Three Hundred ";break;}
      case 4: {word+="Four Hundred ";break;}
      case 5: {word+="Five Hundred ";break;}
      case 6: {word+="Six Hundred ";break;}
      case 7: {word+="Seven Hundred ";break;}
      case 8: {word+="Eight Hundred ";break;}
      case 9: {word+="Nine Hundred ";break;}
    }
  }
  //words are different for 10 - 19
  if(num_t==1)
  {
    switch(num_ones)
    {
      case 0: {word+="Ten ";break;}
      case 1: {word+="Eleven ";break;}
      case 2: {word+="Twelve ";break;}
      case 3: {word+="Thirteen ";break;}
      case 4: {word+="Fourteen ";break;}
      case 5: {word+="Fifteen ";break;}
      case 6: {word+="Sixteen ";break;}
      case 7: {word+="Seventeen ";break;}
      case 8: {word+="Eighteen ";break;}
      case 9: {word+="Nineteen ";break;}
    }
    return word;
  }
  if(num_t>1)
  {
    switch(num_t)
    {
      case 2: {word+="Twenty ";break;}
      case 3: {word+="Thirty ";break;}
      case 4: {word+="Forty ";break;}
      case 5: {word+="Fifty ";break;}
      case 6: {word+="Sixty ";break;}
      case 7: {word+="Seventy ";break;}
      case 8: {word+="Eighty ";break;}
      case 9: {word+="Ninety ";break;}
    }
  }

  switch(num_ones)
  {
    case 1: {word+="One ";break;}
    case 2: {word+="Two ";break;}
    case 3: {word+="Three ";break;}
    case 4: {word+="Four ";break;}
    case 5: {word+="Five ";break;}
    case 6: {word+="Six ";break;}
    case 7: {word+="Seven ";break;}
    case 8: {word+="Eight ";break;}
    case 9: {word+="Nine ";break;}
  }
  return word;
}

std::string numberToWords(int num)
{
    std::string words;
    int part[10],prev=0,place;
    // edge case and reduces computation time for this
    if(num==0)
        return"Zero";
    // iterating through the numbers now (10 is max becasue that is the max value we are inputting)
    for(place=10;place>0;place--)
    {
      // converting the int to an array
       part[place-1]=num/(pow(10,place-1));
       num-=part[place-1]*(pow(10,place-1));
    }
    if(part[9]!=0)
    {
      // special Billion case because we cannot have anything avout 2 billion we do not need to parse anything but the ones place for billions
        words+=get_num(0,0,part[9]);
        words+="Billion ";
    }
    for(int i=8;i>1;i-=3)
    {
      //parsing the rest of the string with Hundreds , tens and ones places
        words+=get_num(part[i],part[i-1],part[i-2]);
        if(get_num(part[i],part[i-1],part[i-2])!="")
        {
            if(i==8)
                words+="Million ";
            if(i==5)
                words+= "Thousand ";
        }
    }
    // erasing the space at the end
    words.erase(words.end()-1);
    return words;
}

int main(int argc, char const *argv[])
{
  int number;
  std::cout << "Enter a number from 1 to 2^31-1" << '\n';
  std::cin >> number;
  std::cout << "The number in words is:" << '\n'<<numberToWords(number)<<"\n";
  return 0;
}
