#include <iostream>

long long catalan(int n) {
    long long res[32] = {1};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            res[i] += res[j] * res[i - j - 1];
        }
    }
    return res[n];
}

int main() {
    for (int i = 0; i < 30; i++) std::cout << catalan(i) << '\n';
}
