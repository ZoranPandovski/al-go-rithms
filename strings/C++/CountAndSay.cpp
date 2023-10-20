#include <iostream>
#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string prev = "1";
        for (int i = 2; i <= n; i++) {
            char val = prev[0];
            int count = 1;
            std::string cur = "";
            for (int j = 1; j < prev.length(); j++) {
                if (prev[j] != val) {
                    cur += std::to_string(count) + val;
                    val = prev[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            cur += std::to_string(count) + val;
            prev = cur;
        }
        return prev;
    }
};

int main() {
    int n;
    std::cout << "Enter a value of n: ";
    std::cin >> n;

    Solution solution;
    std::string result = solution.countAndSay(n);

    std::cout << "The " << n << "th term in the count-and-say sequence is: " << result << std::endl;

    return 0;
}
