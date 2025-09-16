/*
홀수 n: 없는 것들 고르면 일대일 대응됨
짝수 n: 1을 토글하면 일대일 대응됨
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    int n, k;
    while (T--) {
        std::cin >> n >> k;

        std::vector<int> seq(k);
        bool one_exist = false;
        for (int i = 0; i < k; i++) {
            std::cin >> seq[i];
            if (seq[i] == 1) {
                one_exist = true;
            }
        }

        if (n & 1) {
            std::cout << n << " " << n - k << "\n";
            int idx = 0;
            for (int i = 1; i <= n; i++) {
                if (k > idx && seq[idx] == i) {
                    idx++;
                    continue;
                }
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
        else {
            std::cout << n << " ";
            if (one_exist) {
                std::cout << k - 1 << "\n";
                for (int i = 1; i < k; i++) { // 0번이 1이겠지
                    std::cout << seq[i] << " ";
                }
            }
            else {
                std::cout << k + 1 << "\n";
                std::cout << 1 << " ";
                for (int i = 0; i < k; i++) {
                    std::cout << seq[i] << " ";
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}