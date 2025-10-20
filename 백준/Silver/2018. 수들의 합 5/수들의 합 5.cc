/*
1000만일 때 최대 4471개의 연속된 자연수

길이에 대해 완전 탐색
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    int psum = 0; // 1에서 길이(len)까지의 누적 합
    int cnt = 0;
    for (int len = 1; len <= 4471; len++) {
        psum += len;
        if (psum > N) {
            break;
        }

        // N에서 1 + 2 + ... + len까지의 누적 합을 뺀 수가 len으로 나누어 떨어지면 모든 수에 그 몫을 더해서 N을 만들 수 있음
        if ((N - psum) % len == 0) {
            cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}