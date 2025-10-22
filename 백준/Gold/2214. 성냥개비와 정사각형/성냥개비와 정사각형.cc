/*
입력 잘 받고 1x1부터 최대 크기까지 보면 되겠군
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, c;
    while (std::cin >> r >> c) {
        if (r == 0) {
            break;
        }

        std::vector<std::vector<int>> horizontal(r + 1, std::vector<int> (c));
        std::vector<std::vector<int>> vertical(r, std::vector<int> (c + 1));
        char ch;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cin >> ch;
                if (ch == '-') {
                    horizontal[i][j] = 1;
                }
            }
            for (int j = 0; j < c + 1; j++) {
                std::cin >> ch;
                if (ch == '|') {
                    vertical[i][j] = 1;
                }
            }
        }
        for (int j = 0; j < c; j++) {
            std::cin >> ch;
            if (ch == '-') {
                horizontal[r][j] = 1;
            }
        }


        int max_size = std::min(r, c);
        int ans = 0;
        for (int size = 1; size <= max_size; size++) {
            for (int sr = 0; sr < r - size + 1; sr++) {
                for (int sc = 0; sc < c - size + 1; sc++) {
                    bool okay = true;
                    // 상변, 하변이 다 있는지
                    for (int cc = sc; cc < sc + size; cc++) {
                        if (!horizontal[sr][cc] || !horizontal[sr + size][cc]) {
                            okay = false;
                        }
                    }
                    // 좌변, 우변이 다 있는지
                    for (int cr = sr; cr < sr + size; cr++) {
                        if (!vertical[cr][sc] || !vertical[cr][sc + size]) {
                            okay = false;
                        }
                    }

                    if (okay) {
                        ans++;
                    }
                }
            }
        }

        std::cout << ans << " squares\n";
    }

    return 0;
}