// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/cube-rounding/description
// 정육면체 굴리기
// Lv. 12

/*
쉬운 구현 문제
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, x, y, k;
    std::cin >> n >> m >> x >> y >> k;

    std::vector<std::vector<int>> board(n, std::vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> board[i][j];
        }
    }

    int dir; // 동쪽, 서쪽, 북쪽, 남쪽
    int up, down, left, right, front, back;
    up = down = left = right = front = back = 0;
    for (int i = 0; i < k; i++) {
        std::cin >> dir;

        if (dir == 1) {
            if (y + 1 >= m) {
                continue;
            }
            y += 1;

            int temp = up;
            up = left;
            left = down;
            down = right;
            right = temp;
        }
        else if (dir == 2) {
            if (y - 1 < 0) {
                continue;
            }
            y -= 1;

            int temp = up;
            up = right;
            right = down;
            down = left;
            left = temp;
        }
        else if (dir == 3) {
            if (x - 1 < 0) {
                continue;
            }
            x -= 1;

            int temp = up;
            up = front;
            front = down;
            down = back;
            back = temp;
        }
        else {
            if (x + 1 >= n) {
                continue;
            }
            x += 1;

            int temp = up;
            up = back;
            back = down;
            down = front;
            front = temp;
        }

        if (board[x][y] == 0) {
            board[x][y] = down;
        }
        else {
            down = board[x][y];
            board[x][y] = 0;
        }

        std::cout << up << "\n";
    }

    return 0;
}
