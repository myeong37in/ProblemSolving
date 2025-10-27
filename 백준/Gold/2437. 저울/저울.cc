/*
정렬

seen: 볼 수 있는 최대 수
seq[i]: 다음 무게추

(1에서 seen) + seq[i]는 모두 볼 수 있음

seen + 1보다 seq[i]가 크면 seen + 1를 못 봄
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    int seen = 0;
    for (int i = 0; i < N; i++) {
        if (seq[i] > seen + 1) {
            break;
        }
        seen += seq[i];
    }

    std::cout << seen + 1;

    return 0;
}