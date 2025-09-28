/*
답이 되는 모양을 완성했을 때 열끼리 바꾸면
    높이(두 행의 합)는 변하지 않음
    너비도 변하지 않음

첫 행을 비오름차순 정렬했을 때 요소들을 a_1, a_2, ... a_N이라고 하자. (a_1 >= a_2 >= ... >= a_N)

두 번째 행에서 인접합 요소 b_i, b_i+1 (b_i <= b_i+1)에 대해 너비는 max(a_i, b_i) + max(a_i+1, b_i+1).
이때 둘을 교환하면 
max(a_i, b_i) + max(a_i+1, b_i+1) >= max(a_i, b_i+1) + max(a_i+1, b_i).

즉, 두 번째 행도 비오름차순 정렬하는 것이 최선

사각형의 크기 순으로 s_1, s_2, ... s_2N이라고 하면
우선 가장 큰 사각형(s_1)을 첫 번째 행에 배치. 둘째 행의 최대 사각형을 s_k라고 하면 k의 범위는 2 <= k <= N + 1

나머지는 크기 순으로 큰 것과 그 다음으로 큰 것을 같이 묶어야

홀수 번째 사각형 누적합으로 O(1)에 계산 가능

이거 교환 논증 어렵네
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    int M = 2 * N;
    std::vector<long long> squares(M + 1);
    for (int i = 1; i <= M; i++) {
        std::cin >> squares[i];
    }

    std::vector<long long> psum(M + 1), odd_psum(M + 1);
    for (int i = 1; i <= M; i++) {
        psum[i] = psum[i - 1] + squares[i];
        odd_psum[i] = odd_psum[i - 1];
        if (i & 1) {
            odd_psum[i] += squares[i];
        }
    }

    long long best = 9e18;
    for (int k = 1; k <= N; k++) {
        long long height = squares[1] + squares[k + 1];
        long long width = psum[k] + odd_psum[M - 1] - odd_psum[2 * k];
        best = std::min(best, height * width);
    }

    std::cout << best;

    return 0;
}