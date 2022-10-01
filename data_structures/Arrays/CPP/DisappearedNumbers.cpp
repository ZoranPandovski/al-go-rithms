/*

https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]

*/

#include <vector>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h> // for INT_MAX . we can remove this and remove the INT_MAX references

std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
     for(int i=0;i<nums.size();i++)
     {
         if(nums[abs(nums[i])-1]>0)
         {
             nums[abs(nums[i])-1] = -1 * nums[abs(nums[i])-1]; // this is how we keep track of what numbers are there.
         }
     }
    std::vector<int> result;
    for(int i=0;i<nums.size();i++)
     {
         if(nums[i] > 0)
         {
             result.push_back(i+1);
         }
     }
    return result;
}

int main(int argc, char const *argv[])
{
  std::vector<int> numbers,result;
  int input;
  std::string line;
  std::cout << "Enter a vector of size n numbers between 1 and n" << '\n';
  std::getline(std::cin, line);
  std::istringstream stream(line);
    while (stream >> input && numbers.size()<=INT_MAX)
      if(input <=INT_MAX && input>=1)
        numbers.push_back(input);
  result = findDisappearedNumbers(numbers);
  std::cout << "the Disappeared Numbers are" << '\n';
  for (int i=0;i<result.size();i++)
  {
    std::cout << result[i]<<' ';
  }
  std::cout << '\n';
  return 0;
}

/* The solution is 88 ms and beats 96.74% of the solutions*/
