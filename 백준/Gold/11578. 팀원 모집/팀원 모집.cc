/*
간단한 문제
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> students(M);
    int O, P;
    for (int i = 0; i < M; i++) {
        std::cin >> O;
        for (int j = 0; j < O; j++) {
            std::cin >> P;
            students[i] |= (1 << (P - 1));
        }
    }

    bool okay = false;
    int cnt = 1;
    for (; cnt <= M; cnt++) {
        std::vector<int> indices(M);
        for (int i = M - 1; i >= M - cnt; i--) {
            indices[i] = 1;
        }

        do {
            int comb = 0;
            for (int i = 0; i < M; i++) {
                if (indices[i]) {
                    comb |= students[i];
                }
            }

            if (comb + 1 == (1 << N)) { // 모두 가능
                okay = true;
                break;
            }
        } while (std::next_permutation(indices.begin(), indices.end()));

        if (okay) {
            break;
        }
    }

    std::cout << (okay ? cnt : -1);

    return 0;
}