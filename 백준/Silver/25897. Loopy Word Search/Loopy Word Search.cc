#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    std::vector<int> dr = {-1, 1, 0, 0};
    std::vector<int> dc = {0, 0, -1, 1};

    for (int tc = 1; tc <= T; tc++) {
        int R, C;
        std::cin >> R >> C;

        std::vector<std::vector<char>> board(R, std::vector<char> (C));
        std::string line;
        for (int r = 0; r < R; r++) {
            std::cin >> line;
            for (int c = 0; c < C; c++) {
                board[r][c] = line[c];
            }
        }

        int cnt;
        std::cin >> cnt;

        std::vector<std::string> words(cnt);
        for (int i = 0; i < cnt; i++) {
            std::cin >> words[i];
        }

        std::cout << "Word search puzzle #" << tc << ":\n";

        for (int idx = 0; idx < cnt; idx++) {
            std::string target = words[idx];
            bool found = false;
            int ans_r = 0, ans_c = 0, ans_dir = 0;

            for (int sr = 0; sr < R; sr++) {
                for (int sc = 0; sc < C; sc++) {
                    if (board[sr][sc] != target[0]) {
                        continue;
                    }

                    for (int dir = 0; dir < 4; dir++) {
                        int pos = 1;
                        int cr = sr;
                        int cc = sc;

                        while (true) {
                            if (pos == target.size()) {
                                found = true;
                                ans_r = sr;
                                ans_c = sc;
                                ans_dir = dir;
                                break;
                            }

                            int nr = (cr + dr[dir] + R) % R;
                            int nc = (cc + dc[dir] + C) % C;

                            if (board[nr][nc] != target[pos]) {
                                break;
                            }

                            cr = nr;
                            cc = nc;
                            pos++;
                        }

                        if (found) {
                            break;
                        }
                    }

                    if (found) {
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }

            if (found) {
                if (ans_dir == 0) {
                    std::cout << "U ";
                }
                else if (ans_dir == 1) {
                    std::cout << "D ";
                }
                else if (ans_dir == 2) {
                    std::cout << "L ";
                }
                else {
                    std::cout << "R ";
                }

                std::cout << ans_r + 1 << " " << ans_c + 1 << " " << target << "\n"; 
            }
        }
        std::cout << "\n";
    }

    return 0;
}