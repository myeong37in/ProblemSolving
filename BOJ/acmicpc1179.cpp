// https://www.acmicpc.net/problem/1179
// 마지막 요세푸스 문제
// 플래티넘 1

/*
기본 요세푸스 문제
J(1, k) = 0, J(n, k) = (J(n-1, k) + k) % n

한 바퀴에서 제거되는 사람 수는 N/k명

원래 i번째 사람이었다면 그 사람 차례가 오기 전까지 i/k명이 사라지므로 한 바퀴를 돈 후의 인덱스는 i - (i/k)

재귀호출 후 N - (N/k)명에 대해 새로운 인덱스를 부여받았다면 원래 번호를 복원하면 된다.

근데 메모리 초과가 발생하는데, 재귀 말고 반복으로 해보자

아 K = 1인 경우가 있어서 그랬네 ㅎ.. RTE: division by zero
*/

#include <iostream>

long long Josephus(const long long& n, const int& k) {
    if (n == 1) {
        return 0;
    }

    if (k > n) { // 한 명씩 그냥 제거
        return (Josephus(n - 1, k) + k) % n;
    }

    long long rem = Josephus(n - n / k, k); // 최종 승자의 바뀐 인덱스
    
    rem -= (n % k); // 시작 지점이 n % k만큼 옮겨가므로 복원

    if (rem < 0) { // 마지막 바퀴
        rem += n;
    }
    else {
        rem += rem / (k - 1);
    }

    return rem;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    int K;
    std::cin >> N >> K;
    
    if (K == 1) {
        std::cout << N;
        return 0;
    }

    long long answer = Josephus(N, K) + 1; // 1-based로
    std::cout << answer;

    return 0;
}