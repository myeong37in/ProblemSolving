/*
세 수가 삼각형의 변의 길이가 되려면

x <= y <= z에 대해
x + y > z여야 함

어떤 구간에 대해 모든 쌍에서 삼각형이 안 생기려면
a, b, c, d, ..., y, z, ... 에서 
a + b <= c
b + c <= d
c + d <= e
이렇게 되어야 함

따라서 정렬했을 때 피보나치 수열(혹은 그 이상 폭으로)로 커져야 한다는 것인데,

1, 1, 2, 3, 5, ... 이렇게 커지는 피보나치 수열은 45번째 수에서 10억을 넘음

따라서 구간 길이가 45 이상이면 반드시 가능

구간 길이가 44 이하면 정렬해서 인접한 세 수를 보면 최대 쿼리마다 44번 연산
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    int p;
    std::cin >> p;

    int a, b;
    while (p--) {
        std::cin >> a >> b;

        if (b - a < 2) {
            std::cout << "NIE\n";
            continue;
        }

        if (b - a + 1 >= 45) {
            std::cout << "TAK\n";
            continue;
        }

        std::vector<int> subseq(seq.begin() + a, seq.begin() + b + 1);
        std::sort(subseq.begin(), subseq.end());
        
        int L = subseq.size();
        bool found = false;
        for (int i = 0; i < L - 2; i++) {
            if (subseq[i] + subseq[i + 1] > subseq[i + 2]) {
                found = true;
                break;
            }
        }

        std::cout << (found ? "TAK\n" : "NIE\n");
    }

    return 0;
}