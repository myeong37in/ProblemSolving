/*
LIS의 길이를 구하면 됨. 근데 슬라이딩이 가능하므로 O(N logN) 방법으로 O(N^2 logN)으로 구현하면 될 듯.

아닌가? O(N^3) 되나? 될 것으로 보이지만 연습 삼아 
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> seq_A(N), seq_B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq_A[i];
    }
    
    for (int i = 0; i < N; i++) {
        std::cin >> seq_B[i];
    }

    int A_best = 0, B_best = 0;
    for (int i = 0; i < N; i++) {
        std::vector<int> tail;
        for (int n : seq_A) {
            auto it = std::lower_bound(tail.begin(), tail.end(), n);
            if (it == tail.end()) {
                tail.emplace_back(n);
            }
            else {
                *it = n;
            }
        }

        A_best = std::max(A_best, static_cast<int>(tail.size()));
        std::rotate(seq_A.begin(), seq_A.begin() + 1, seq_A.end()); // 그냥 돌려
    }

    for (int i = 0; i < N; i++) {
        std::vector<int> tail;
        for (int n : seq_B) {
            auto it = std::lower_bound(tail.begin(), tail.end(), n);
            if (it == tail.end()) {
                tail.emplace_back(n);
            }
            else {
                *it = n;
            }
        }

        B_best = std::max(B_best, static_cast<int>(tail.size()));
        std::rotate(seq_B.begin(), seq_B.begin() + 1, seq_B.end());
    }

    if (A_best > B_best) {
        std::cout << "YJ Win!";
    }
    else if (A_best < B_best) {
        std::cout << "HG Win!";
    }
    else {
        std::cout << "Both Win!";
    }
    
    return 0;
}