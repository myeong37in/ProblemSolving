/*
좌표는 증가, K는 감소
단조성이 있으므로 DP 가능 

dp[i][j][k]: (i, j)에서 약수가 k일 때 졌는지
300 이하의 자연수에 대해 약수는 240에서 최대 20개이므로 약수의 인덱스로 관리하면 될 듯

이동, 약수 감소로 갈 수 있는 상태 중 패배 상태가 있다면 현재는 필승 상태

우측 아래부터 거꾸로 보면 되겠군
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> divisors;

static void GetDivisors(int K) {
    for (int i = 1; 1LL * i * i <= K; ++i) {
        if (K % i == 0) {
            divisors.emplace_back(i);
            if (i != K / i) {
                divisors.emplace_back(K / i);
            }
        }
    }

    std::sort(divisors.begin(), divisors.end()); // 오름차순
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> board(N, std::vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }

    GetDivisors(K);

    int L = divisors.size();
    std::vector<std::vector<std::vector<int>>> dp(N, std::vector<std::vector<int>> (N, std::vector<int> (L)));
    for (int k = 0; k < L; k++) {
        int cur_K = divisors[k]; // 현재 k보다 인덱스가 작은 divisors 요소가 이동할 수 있는(더 작은) 약수 후보들
        for (int sr = N - 1; sr >= 0; sr--) {
            for (int sc = N - 1; sc >= 0; sc--) {
                if (board[sr][sc]) {
                    continue;
                }

                bool win = false;
                // 행 이동
                for (int dist = 1; dist <= cur_K && sr + dist < N; dist++) {
                    bool wall_exist = false;
                    for (int r = sr + 1; r <= sr + dist; r++) {
                        if (board[r][sc]) {
                            wall_exist = true;
                            break;
                        }
                    }

                    if (wall_exist) { // 벽 있으면 못 감
                        break;
                    }

                    if (dp[sr + dist][sc][k] == 0) { // 상대 턴에서 패배 상태면 현재는 승리 상태
                        win = true;
                        break;
                    }
                }

                if (!win) {
                    // 열 이동
                    for (int dist = 1; dist <= cur_K && sc + dist < N; dist++) {
                        bool wall_exist = false;
                        for (int c = sc + 1; c <= sc + dist; c++) {
                            if (board[sr][c]) {
                                wall_exist = true;
                                break;
                            }
                        }

                        if (wall_exist) {
                            break;
                        }

                        if (dp[sr][sc + dist][k] == 0) {
                            win = true;
                            break;
                        }
                    }
                }

                if (!win) {
                    // K 변경
                    for (int next_k = 0; next_k < k; next_k++) {
                        if ((cur_K % divisors[next_k] == 0) && dp[sr][sc][next_k] == 0) { // 현재 K의 약수여야 함
                            win = true;
                            break;
                        }
                    }
                }

                dp[sr][sc][k] = win;
            }
        }
    }

    std::cout << dp[0][0][L - 1];

    return 0;
}