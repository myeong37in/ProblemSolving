/*
재귀적으로 픽셀의 색을 확인하면 될 듯
*/

#include <iostream>
#include <vector>
#include <string>

void FillQuadtree(std::vector<std::vector<int>>& board, std::string str, int& idx, int sr, int sc, int len) {
    char ch = str[idx++];
    if (ch == 'p') {
        int half = len / 2;
        FillQuadtree(board, str, idx, sr, sc + half, half);
        FillQuadtree(board, str, idx, sr, sc, half);
        FillQuadtree(board, str, idx, sr + half, sc, half);
        FillQuadtree(board, str, idx, sr + half, sc + half, half);
    }
    else {
        if (ch == 'f') {
            for (int r = sr; r < sr + len; r++) {
                for (int c = sc; c < sc + len; c++) {
                    board[r][c] = 1;
                }
            }
        }
    }

    return;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        std::vector<std::vector<int>> board1(32, std::vector<int> (32)), board2(32, std::vector<int> (32));

        std::string str;
        std::cin >> str;
        int idx1 = 0;
        FillQuadtree(board1, str, idx1, 0, 0, 32);
        
        std::cin >> str;
        int idx2 = 0;
        FillQuadtree(board2, str, idx2, 0, 0, 32);

        int cnt = 0;
        for (int r = 0; r < 32; r++) {
            for (int c = 0; c < 32; c++) {
                if (board1[r][c] || board2[r][c]) {
                    cnt++;
                }
            }
        }

        std::cout << "There are " << cnt << " black pixels.\n";
    }
    
    return 0;
}