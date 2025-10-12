/*
S(k)의 길이를 L(k)라고 하면 

L(k) = L(k - 1) + (k + 3) + L(k - 1) (k >= 1)
L(0) = 3

N <= 3이면 L(0)으로 답 도출
아니면 마지막 k부터 범위를 확인
*/

#include <iostream>
#include <vector>

void Solve(int N) {
    std::vector<long long> len(1, 3); // len[0] = 3

    while (len.back() <= N) {
        long long next = len.back() * 2 + (len.size() + 3);
        len.emplace_back(next);
    }

    int k = len.size() - 1;
    while (true) {
        if (k == 0) {
            if (N == 1) {
                std::cout << 'm';
            }
            else {
                std::cout << 'o';
            }

            break;
        }

        int left = len[k - 1];
        int mid = k + 3;
        if (N <= left) { // 왼쪽
            k--;
        }
        else if (N <= left + mid) { // 가운데 
            if (N == left + 1) {
                std::cout << 'm';
            }
            else {
                std::cout << 'o';
            }

            break;
        }
        else { // 오른쪽
            N -= left + mid;
            k--;
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N <= 3) {
        if (N == 1) {
            std::cout << 'm';
        }
        else {
            std::cout << 'o';
        }

        return 0;
    }

    Solve(N);

    return 0;
}