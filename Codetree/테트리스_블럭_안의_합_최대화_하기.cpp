// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/max-sum-of-tetris-block/description
// 테트리스 블럭 안의 합 최대화 하기
// Lv. 12

/*
다섯 종류의 테트리스를 전부 덮는 4x4 크기의 사각형 중 적힌 수의 합이 가장 큰 사각형을 누적 합으로 구하고 거기에 테트리스를 넣어보면 될 듯

-> 아님. 생각해 보니 반례가 있음.
*/

#include <iostream>
#include <vector>

int main(int argc, char* arvg[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> board(N + 1, std::vector<int> (M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> board[i][j];
        }
    }

    // 모든 회전은 시계 방향
    // 뒤집기는 상하반전
    // 시작점은 좌상단 기준. 죄상단이 모두 가장 작은 칸이 없다면 상단 좌표가 작은 칸이 우선
    int max_val = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            // 4x1 블록 정방향
            if (c + 3 <= M) {
                max_val = std::max(max_val, (board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r][c + 3]));
            }

            // 4x1 블록 90도 회전
            if (r + 3 <= N) {
                max_val = std::max(max_val, (board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 3][c]));
            }

            // 2x2 블록
            if (r + 1 <= N && c + 1 <= M) {
                max_val = std::max(max_val, (board[r][c] + board[r + 1][c] + board[r][c + 1] + board[r + 1][c + 1]));
            }

            // 'ㄴ'자 블록 정방향
            if (r + 2 <= N && c + 1 <= M) {
                max_val = std::max(max_val, (board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 2][c + 1]));
            }

            // 'ㄴ'자 블록 90도 회전
            if (r + 1 <= N && c + 2 <= M) {
                max_val = std::max(max_val, (board[r][c] + board[r + 1][c] + board[r][c + 1] + board[r][c + 2]));
            }

            // 'ㄴ'자 블록 180도 회전
            if (r + 2 <= N && c + 1 <= M) {
                max_val = std::max(max_val, (board[r][c] + board[r][c + 1] + board[r + 1][c + 1] + board[r + 2][c + 1]));
            }

            // 'ㄴ'자 불록 270도 회전
            if (r + 1 <= N && c - 2 >= 1) {
                max_val = std::max(max_val, (board[r][c] + board[r + 1][c] + board[r + 1][c - 1] + board[r + 1][c - 2]));
            }

            // 뒤집은 'ㄴ'자 블록 정방향
            if (r + 2 <= N && c + 1 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r][c + 1]);
            }
            
            // 뒤집은 'ㄴ'자 블록 90도 회전
            if (r + 1 <= N && c + 2 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r + 1][c + 2]);
            }

            // 뒤집은 'ㄴ'자 블록 180도 회전
            if (r + 2 <= N && c - 1 >= 1) {
                max_val = std::max(max_val, (board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 2][c - 1]));
            }

            // 뒤집은 'ㄴ'자 불록 270도 회전
            if (r + 1 <= N && c + 2 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r + 1][c] + board[r + 1][c + 1] + board[r + 1][c + 2]);
            }

            // 날일자 블록 정방향
            if (r + 2 <= N && c + 1 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r + 1][c] + board[r + 1][c + 1] + board[r + 2][c + 1]);
            }

            // 날일자 블록 90도 회전
            if (r + 1 <= N && c + 1 <= M && c - 1 >= 1) {
                max_val = std::max(max_val, board[r][c] + board[r][c + 1] + board[r + 1][c] + board[r + 1][c - 1]);
            }

            // 뒤집은 날일자 블록 정방향
            if (r + 2 <= N && c - 1 >= 1) {
                max_val = std::max(max_val, board[r][c] + board[r + 1][c] + board[r + 1][c - 1] + board[r + 2][c - 1]);
            }

            // 뒤집은 날일자 블록 90도 회전
            if (r + 1 <= N && c + 2 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r][c + 1] + board[r + 1][c + 1] + board[r + 1][c + 2]);
            }

            // 'ㅏ'자 블록 정방향
            if (r + 2 <= N && c + 1 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r + 1][c] + board[r + 1][c + 1] + board[r + 2][c]);
            }

            // 'ㅏ'자 블록 90도 회전
            if (r + 1 <= N && c + 2 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r][c + 1] + board[r + 1][c + 1] + board[r][c + 2]);
            }

            // 'ㅏ'자 블록 180도 회전
            if (r + 2 <= N && c - 1 >= 1) {
                max_val = std::max(max_val, board[r][c] + board[r + 1][c] + board[r + 1][c - 1] + board[r + 2][c]);
            }

            // 'ㅏ'자 블록 270도 회전
            if (r + 1 <= N && c - 1 >= 1 && c + 1 <= M) {
                max_val = std::max(max_val, board[r][c] + board[r + 1][c] + board[r + 1][c - 1] + board[r + 1][c + 1]);
            }
        }
    }

    std::cout << max_val;

    return 0;
}
