#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    std::cin >> R >> C;

    std::vector<std::vector<char>> board(R, std::vector<char> (C));
    std::vector<std::vector<bool>> visited(R, std::vector<bool> (C));

    std::string line;
    for (int r = 0; r < R; r++) {
        std::cin >> line;
        for (int c = 0; c < C; c++) {
            board[r][c] = line[c];
        }
    }

    int r = 0, c = 0;
    while (true) {
        if (visited[r][c]) {
            std::cout << "cykel";
            return 0;
        }

        visited[r][c] = true;

        char ch = board[r][c];
        if (ch == 'A') {
            std::cout << "sushi";
            return 0;
        }
        else if (ch == 'B') {
            std::cout << "samuraj";
            return 0;
        }
        else if (ch == '<') {
            c -= 1;
        }
        else if (ch == '>') {
            c += 1;
        }
        else if (ch == 'v') {
            r += 1;
        }
        else if (ch == '^') {
            r -= 1;
        }
    }

    return 0;
}