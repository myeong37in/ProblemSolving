/*
방문 상태는 어떻게 되는가 하면,
행
열
방향

근데 사이클이 이게.. 같은 상태에 다시 왔을 때 먹은 먼지가 없으면 끝

마지막으로 먼지를 먹었을 때의 이동 횟수를 기록했다가 + 1해서 끝내면 될 듯
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> A, B, board;

std::vector<std::vector<std::vector<int>>> visited; // 해당 상태에 방문했을 때 먼지의를 먹었을 때의 이동 횟수 저장

std::vector<int> dr = {-1, 0, 1, 0};
std::vector<int> dc = {0, 1, 0, -1};

int Sim(int sr, int sc, int sdir, int H, int W) {
    int moves = 0;
    int cr = sr;
    int cc = sc;
    int cdir = sdir;
    int last_eat = 0;
    while (true) {
        if (board[cr][cc]) {
            last_eat = moves;
            board[cr][cc] = 0;
            cdir = (cdir + A[cr][cc]) % 4;

            cr += dr[cdir];
            cc += dc[cdir];
            if (cr < 0 || cr >= H || cc < 0 || cc >= W) {
                break;
            }

            visited[cr][cc][cdir] = last_eat;
        }
        else {
            cdir = (cdir + B[cr][cc]) % 4;

            cr += dr[cdir];
            cc += dc[cdir];
            if (cr < 0 || cr >= H || cc < 0 || cc >= W) {
                break;
            }

            if (visited[cr][cc][cdir] == last_eat) { // 같은 상태로 돌아왔지만 먼지를 못 먹었으면 컷
                break;
            }
            visited[cr][cc][cdir] = last_eat;
        }

        moves++;
    }

    return last_eat + 1;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, R, C, D;
    std::cin >> H >> W >> R >> C >> D;

    A.assign(H, std::vector<int> (W));
    B.assign(H, std::vector<int> (W));
    board.assign(H, std::vector<int> (W, 1));

    std::string line;
    for (int i = 0; i < H; i++) {
        std::cin >> line;
        for (int j = 0; j < W; j++) {
            A[i][j] = line[j] - '0';
        }
    }

    for (int i = 0; i < H; i++) {
        std::cin >> line;
        for (int j = 0; j < W; j++) {
            B[i][j] = line[j] - '0';
        }
    }

    visited.assign(H, std::vector<std::vector<int>> (W, std::vector<int> (4)));

    int ans = Sim(R, C, D, H, W);
    std::cout << ans;

    return 0;
}