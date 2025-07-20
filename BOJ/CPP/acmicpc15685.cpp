// https://www.acmicpc.net/problem/15685
// 드래곤 커브
// 골드 3

/*
+x => -y
-y => -x
-x => +y
+y => +x

0 -> 1
1 -> 2
2 -> 3
3 -> 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int MAX = 100;
    std::vector<std::vector<int>> board(MAX + 1, std::vector<int> (MAX + 1));
    
    int N;
    std::cin >> N;

    std::vector<int> dr = {1, 0, -1, 0};
    std::vector<int> dc = {0, -1, 0, 1};

    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        std::cin >> x >> y >> d >> g;

        std::vector<int> dir = {d};
        std::vector<int> dir_log;
        bool end_reached = false;
        for (int i = 0; i <= g; i++) {
            if (end_reached) {
                break;
            }

            int sz = dir.size();
            for (int j = 0; j < sz; j++) {
                int nx = x + dr[dir[j]];
                int ny = y + dc[dir[j]];

                if (nx >= 0 && nx <= MAX && ny >= 0 && ny <= MAX) {
                    board[x][y] = board[nx][ny] = 1; // 시작점도 찍어줘야 하는데 찍고 시작할 수는 없으니 이렇게 함
                    x = nx;
                    y = ny;
                    dir_log.emplace_back(dir[j]);
                }
                else {
                    end_reached = true;
                    break;
                }
            }
            
            dir.clear();
            for (int j = dir_log.size() - 1; j >= 0; j--) {
                dir.emplace_back((dir_log[j] + 1) % 4); // 역순으로, 방향에 + 1을 더한 방향이 다음 방향이 됨
            }
        }
    }

    int count = 0;
    for (int i = 0; i <= MAX - 1; i++) {
        for (int j = 0; j <= MAX - 1; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
                count++;
            }
        }
    }

    std::cout << count;

    return 0;
}
