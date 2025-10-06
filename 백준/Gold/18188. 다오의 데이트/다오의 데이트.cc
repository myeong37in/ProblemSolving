/*
결국 2^20이네

역추적은 까다롭긴 해
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct State {
    int r, c, d;
};

struct Parent {
    int pr, pc, pd;
    int dir;
};

std::vector<std::vector<char>> board;

std::vector<std::vector<int>> forced_moves;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

std::string path;

int bfs(int sr, int sc, int er, int ec, int N) {
    int H = board.size();
    int W = board[0].size();

    std::vector<std::vector<std::vector<Parent>>> parent(H, std::vector<std::vector<Parent>> (W, std::vector<Parent> (N + 1)));

    std::queue<State> q;
    q.push({sr, sc, 0});

    int ans_dist = -1;
    while (!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();

        if (r == er && c == ec) {
            ans_dist = d;
            break;
        }

        if (d >= N) {
            continue;
        }

        for (int dir = 0; dir < 2; dir++) {
            int nr = r + dr[forced_moves[d][dir]];
            int nc = c + dc[forced_moves[d][dir]];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W || board[nr][nc] == '@') {
                continue;
            }

            parent[nr][nc][d + 1] = {r, c, d, forced_moves[d][dir]};
            q.push({nr, nc, d + 1});
        }
    }

    if (ans_dist == -1) {
        return -1;
    }

    std::vector<int> rev_dirs;
    int r = er;
    int c = ec;
    int d = ans_dist;
    while (d > 0) {
        const Parent &p = parent[r][c][d];

        rev_dirs.emplace_back(p.dir);
        r = p.pr;
        c = p.pc;
        d = p.pd;
    }

    for (int i = rev_dirs.size() - 1; i >= 0; i--) {
        int dir = rev_dirs[i];
        if (dir == 0) {
            path += 'W';
        }
        else if (dir == 1) {
            path += 'S';
        }
        else if (dir == 2) {
            path += 'A';
        }
        else {
            path += 'D';
        }
    }

    return ans_dist;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    std::cin >> H >> W;

    board.assign(H, std::vector<char> (W));
    std::string line;
    int sr, sc, er, ec;
    for (int i = 0; i < H; i++) {
        std::cin >> line;
        for (int j = 0; j < W; j++) {
            board[i][j] = line[j];
            
            if (board[i][j] == 'D') {
                sr = i;
                sc = j;
            }
            else if (board[i][j] == 'Z') {
                er = i;
                ec = j;
            }
        }
    }

    int N;
    std::cin >> N;
    
    forced_moves.assign(N, std::vector<int> (2));
    char first, second;
    for (int i = 0; i < N; i++) {
        std::cin >> first >> second;
        if (first == 'A') {
            forced_moves[i][0] = 2;
        }
        else if (first == 'W') {
            forced_moves[i][0] = 0;
        }
        else if (first == 'S') {
            forced_moves[i][0] = 1;
        }
        else {
            forced_moves[i][0] = 3;
        }
        
        if (second == 'A') {
            forced_moves[i][1] = 2;
        }
        else if (second == 'W') {
            forced_moves[i][1] = 0;
        }
        else if (second == 'S') {
            forced_moves[i][1] = 1;
        }
        else {
            forced_moves[i][1] = 3;
        }
    }

    int ans = bfs(sr, sc, er, ec, N);

    if (ans == -1) {
        std::cout << "NO";
        return 0;
    }
    
    std::cout << "YES\n" << path;

    return 0;
}