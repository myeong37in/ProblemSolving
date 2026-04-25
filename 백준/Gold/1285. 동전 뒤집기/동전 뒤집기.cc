/*
행을 다 뒤집어 본다고 생각해 봅시다.

하나의 상태에 대해 각 열마다 최적의 상태는 독립적으로 계산됨

각 열마다 T의 개수 세기

1) 각 열에 대해 T를 우선 두고 각 행에 대해 그 행이 뒤집혀 있으면 뒤집어 세기
2) 현재 경우에서 최소 T의 개수 갱신
    이 과정을 행을 뒤집는 모든 경우에 대해 탐색

2^20 * 20 * 20. 대충 4억
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string board[20];

    for (int i = 0; i < N; i++) {
        std::cin >> board[i];
    }

    int ans = 2e9;

    for (int mask = 0; mask < (1 << N); mask++) {
        int total_tail = 0;

        // 각 열마다 최적 선택
        for (int col = 0; col < N; col++) {
            int tail_cnt = 0;

            for (int row = 0; row < N; row++) {
                char coin = board[row][col];

                // row번째 행을 뒤집는 경우
                if (mask & (1 << row)) {
                    coin = (coin == 'H') ? 'T' : 'H';
                }

                if (coin == 'T') {
                    tail_cnt++;
                }
            }

            // 이 열을 안 뒤집는 경우와 안 뒤집는 경우
            total_tail += std::min(tail_cnt, N - tail_cnt);
        }

        ans = std::min(ans, total_tail);
    }

    std::cout << ans << '\n';



    return 0;
}

