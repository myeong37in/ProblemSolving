/*
시뮬레이션은 O(R^2 * C^2)이니까 아니고

각 칸마다 방향을 표시할 수 있음. 그럼 역시 하나뿐이군
*/

#include <iostream>
#include <vector>

constexpr int OFFSET = 501; // 2차원 좌표의 1차원 변환용

std::vector<int> parent, size;
std::vector<std::vector<int>> board;

int Find(int n) {
    if (parent[n] == n) {
        return n;
    }

    return parent[n] = Find(parent[n]);
}

void Merge(int a, int b) {
    int ra = Find(a);
    int rb = Find(b);

    if (ra == rb) {
        return;
    }

    // 수가 작은 쪽으로 합치기
    int ar = ra / OFFSET;
    int ac = ra % OFFSET;
    int br = rb / OFFSET;
    int bc = rb % OFFSET;
    if (board[ar][ac] > board[br][bc]) {
        std::swap(ra, rb);
    }

    
    parent[rb] = ra;
    size[ra] += size[rb];
    size[rb] = 0;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    std::cin >> R >> C;

    board.assign(R, std::vector<int> (C));
    parent.resize(R * OFFSET + C);
    size.assign(R * OFFSET + C, 1);
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            std::cin >> board[r][c];
            parent[r * OFFSET + c] = r * OFFSET + c;
        }
    }

    std::vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    std::vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int min_val = board[r][c];
            int min_dir = -1;
            for (int dir = 0; dir < 8; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                    continue;
                }

                if (board[nr][nc] < min_val) {
                    min_val = board[nr][nc];
                    min_dir = dir;
                }
            }

            if (min_dir == -1) { // 현재 칸의 수가 가장 작은 수
                continue;
            }

            int nr = r + dr[min_dir];
            int nc = c + dc[min_dir];
            Merge(r * OFFSET + c, nr * OFFSET + nc);
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            std::cout << size[r * OFFSET + c] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}