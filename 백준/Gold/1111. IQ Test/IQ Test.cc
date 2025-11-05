/*
행렬 계산 시 x0, x1, x2에 대해 인접한 x0, x1이 다르면 a = (x1 - x2) / (x0 - x1), b = (-x1^2 + x0x2) / (x0 - x1)

유일하게 결정되는 a, b가 모두 맞으면 답 있음
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    if (N == 1) {
        std::cout << "A";
        return 0;
    }
    else if (N == 2) {
        if (seq[0] == seq[1]) {
            std::cout << seq[0];
        }
        else {
            std::cout << "A";
        }
        return 0;
    }

    int a = -2e9, b = -2e9;
    if (seq[0] == seq[1]) { // 처음 2개 같으면
        for (int i = 2; i < N; i++) {
            if (seq[i] != seq[0]) { // 다른 수가 나오면 불가능
                std::cout << "B";
                return 0;
            }
        }

        std::cout << seq[0]; // 모두 같으면 유일
        return 0;
    }

    for (int i = 2; i < N; i++) {
        int x0 = seq[i - 2];
        int x1 = seq[i - 1];
        int x2 = seq[i];

        if (x0 == x1) {
            continue;
        }

        a = (x1 - x2) / (x0 - x1);
        b = (-x1 * x1 + x0 *  x2) / (x0 - x1);
        break;
    }

    if (a == -2e9) { // 모두 같으면 유일
        std::cout << seq[0];
        return 0;
    }

    int prev = seq[0];
    for (int i = 1; i < N; i++) {
        int cur = seq[i];
        if (prev * a + b != cur) {
            std::cout << "B";
            return 0;
        }

        prev = cur;
    }

    std::cout << seq[N - 1] * a + b;

    return 0;
}