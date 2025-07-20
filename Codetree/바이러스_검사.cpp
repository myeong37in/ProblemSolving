// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/virus-detector/description
// 바이러스 검사
// Lv. 4

/*
간단한 계산 문제
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }

    int leader, member;
    std::cin >> leader >> member;

    long long answer = 0;
    for (const int& n : vec) {
        answer += std::max(1, (n - leader + member - 1) / member + 1);
    }

    std::cout << answer;

    return 0;
}
