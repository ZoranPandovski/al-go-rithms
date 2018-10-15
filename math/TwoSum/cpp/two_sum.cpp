#include <iostream>
#include <algorithm>
#include <string.h>
#include<stdio.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> s;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        int tmp = target - nums[i];
        if(s.find(tmp) != s.end()) {
            return vector<int>{s[tmp], i};
        } else {
            s[nums[i]] = i;
        }
    }
    return vector<int>{};
}

int main() {
    vector<int> v = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(v, target);
    for(int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
