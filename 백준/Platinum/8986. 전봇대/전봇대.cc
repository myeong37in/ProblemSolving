/*
간격이 d면 최종 위치는 0, d, 2d, ... (N - 1)d

입력 들어온 순서대로 앞에서부터 배치하는 게 당연히 최선

따라서 총 이동 거리는 |x_i - id|의 합

|x_i - id|는 d에 대해 볼록 함수, 볼록 함수의 합도 볼록 함수

극솟값을 찾는 문제이므로 삼분 탐색 가능

근데 상한을 어떻게 잡아야 하지? 

일단 최댓값 10억이 들어오는 데이터에서 정답을 내려면 최댓값으로 해볼까
*/

#include <iostream>
#include <vector>

std::vector<int> seq;

static long long CalcSum(int m) {
    long long sum = 0;
    for (long long i = 0; i < seq.size(); i++) {
        sum = sum + std::abs(seq[i] - m * i);
    }

    return sum;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 0;
        return 0;
    }

    seq.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    int lo = 1, hi = seq.back();
    while (lo < hi) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;

        long long m1_sum = CalcSum(m1), m2_sum = CalcSum(m2);
        
        if (m1_sum > m2_sum) { // 아래로 볼록이므로 큰 쪽을 날리기
            lo = m1 + 1;
        }
        else if (m1_sum < m2_sum) {
            hi = m2 - 1;
        }
        else {
            lo = m1 + 1;
            hi = m2 - 1;
        }
    }

    long long ans = CalcSum(lo);
    std::cout << ans;

    return 0;
}