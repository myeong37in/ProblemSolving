/*
Siuuuuuuuuuuu mulation
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    std::cin >> R >> C;

    constexpr int OFFSET = 101;

    std::vector<std::vector<char>> board(R, std::vector<char> (C));
    std::unordered_set<int> arduinos;
    int jr, jc;
    std::string line;
    for (int r = 0; r < R; r++) {
        std::cin >> line;
        for (int c = 0; c < C; c++) {
            board[r][c] = line[c];
            
            if (board[r][c] == 'I') {
                jr = r;
                jc = c;
            }
            else if (board[r][c] == 'R') {
                arduinos.insert(r * OFFSET + c);
            }
        }
    }

    std::string commands;
    std::cin >> commands;

    std::vector<int> dr = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
    std::vector<int> dc = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

    int moves = 0;
    bool over = false;
    int sz = commands.size();
    for (int i = 0; i < sz; i++) {
        int dir = commands[i] - '0';
        std::vector<std::vector<char>> next_board(R, std::vector<char> (C, '.'));
        std::unordered_set<int> next_arduinos;
        
        int nr = jr + dr[dir];
        int nc = jc + dc[dir];
        moves++;

        if (board[nr][nc] == 'R') {
            over = true;
            break;
        }
        next_board[nr][nc] = 'I';

        std::unordered_set<int> boom; // 터지는 좌표
        for (const int& pos : arduinos) {
            int r = pos / OFFSET;
            int c = pos % OFFSET;

            int best_dist = 2e9;
            int best_dir = -1;
            for (int d = 1; d <= 9; d++) {
                if (d == 5) { // 반드시 이동
                    continue;
                }

                int dist = std::abs(nr - (r + dr[d])) + std::abs(nc - (c + dc[d]));
                if (best_dist > dist) {
                    best_dist = dist;
                    best_dir = d;
                }
            }

            r += dr[best_dir];
            c += dc[best_dir];

            if (next_board[r][c] == 'I') {
                over = true;
                break;
            }

            if (next_arduinos.insert(r * OFFSET + c).second == false) {
                boom.insert(r * OFFSET + c);
            }
        }

        if (over) {
            break;
        }

        for (const int& n : boom) {
            next_arduinos.erase(n);
        }

        for (const int& pos : next_arduinos) {
            int r = pos / OFFSET;
            int c = pos % OFFSET;

            next_board[r][c] = 'R';
        }

        jr = nr;
        jc = nc;
        std::swap(board, next_board);
        std::swap(arduinos, next_arduinos);
    }

    if (over) {
        std::cout << "kraj " << moves;
    }
    else {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                std::cout << board[r][c];
            }
            std::cout << "\n";
        }
    }

    return 0;
}