#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, U, V;
    std::cin >> N >> M >> U >> V;

    std::vector<std::vector<char>> board(N, std::vector<char> (M)), texture(U, std::vector<char> (V));
    std::string line;
    for (int i = 0; i < U; i++) {
        std::cin >> line;
        for (int j = 0; j < V; j++) {
            texture[i][j] = line[j];
        }
    }

    for (int i = 0; i < std::min(N, U); i++) {
        for (int j = 0; j < std::min(M, V); j++) {
            board[i][j] = texture[i][j];
        }
    }

    std::string op;
    std::cin >> op;
    if (op == "clamp-to-edge") {
        if (N > U) {
            // 행 채우기
            for (int r = U; r < N; r++) {
                for (int c = 0; c < std::min(M, V); c++) {
                    board[r][c] = texture[U - 1][c];
                }
            }
        }
        if (M > V) {
            for (int c = V; c < M; c++) {
                for (int r = 0; r < std::min(N, U); r++) {
                    board[r][c] = texture[r][V - 1];
                }
            }
        }

        if (N > U && M > V) {
            char cell = texture[U - 1][V - 1];
            for (int r = U; r < N; r++) {
                for (int c = V; c < M; c++) {
                    board[r][c] = cell;
                }
            }
        }
    }
    else if (op == "repeat") {
        for (int sr = 0; sr < N; sr += U) {
            for (int sc = 0; sc < M; sc += V) {
                for (int r = sr; r < std::min(N, sr + U); r++) {
                    for (int c = sc; c < std::min(M, sc + V); c++) {
                        board[r][c] = texture[r - sr][c - sc];
                    }
                }
            }
        }
    }
    else {
        for (int sr = 0; sr < N; sr += U) {
            for (int sc = 0; sc < M; sc += V) {
                bool horizontal_flip = false, vertical_flip = false;
                if ((sr / U) & 1) {
                    horizontal_flip = true;
                }
                if ((sc / V) & 1) {
                    vertical_flip = true;
                }
                for (int r = sr; r < std::min(N, sr + U); r++) {
                    for (int c = sc; c < std::min(M, sc + V); c++) {
                        if (horizontal_flip && vertical_flip) {
                            board[r][c] = texture[U + sr - r - 1][V + sc - c - 1];
                        }
                        else if (horizontal_flip) {
                            board[r][c] = texture[U + sr - r - 1][c - sc];
                        }
                        else if (vertical_flip) {
                            board[r][c] = texture[r - sr][V + sc - c - 1];
                        }
                        else {
                            board[r][c] = texture[r - sr][c - sc];
                        }
                    }
                }
            }
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            std::cout << board[r][c];
        }
        std::cout << "\n";
    }

    return 0;
}