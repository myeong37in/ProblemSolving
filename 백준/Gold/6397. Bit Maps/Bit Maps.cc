/*
형식이 음..

B -> D는 재귀로 쉽게

D -> B도 결국은 재귀로 해야겠군
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

std::string ans;

std::vector<std::vector<char>> board;

void BtoDRecursion(int sr, int sc, int er, int ec) {
    char first = board[sr][sc];
    bool same = true;
    for (int r = sr; r <= er; r++) {
        for (int c = sc; c <= ec; c++) {
            if (board[r][c] != first) {
                same = false;
                break;
            }
        }
    }

    if (same) {
        ans += first;
    }
    else {
        ans += 'D';
        int mr = (sr + er) / 2, mc = (sc + ec) / 2;
        
        if (sr == er) { // 가로로 한 줄
            BtoDRecursion(sr, sc, sr, mc); // 좌
            BtoDRecursion(sr, mc + 1, sr, ec); // 우
        }
        else if (sc == ec) { // 세로로 한 줄
            BtoDRecursion(sr, sc, mr, sc); // 상
            BtoDRecursion(mr + 1, sc, er, sc); // 하
        }
        else { // 최소 2x2
            BtoDRecursion(sr, sc, mr, mc); // 좌상
            BtoDRecursion(sr, mc + 1, mr, ec); // 우상
            BtoDRecursion(mr + 1, sc, er, mc); // 좌하
            BtoDRecursion(mr + 1, mc + 1, er, ec); // 우하
        }
    }
}

// 재귀에서 마지막으로 참조하는 str의 인덱스를 반환해야 다음으로 넘어갈 수 있음
int DtoBRecursion(int sr, int sc, int er, int ec, std::string& str, int idx) {
    if (str[idx] != 'D') {
        for (int r = sr; r <= er; r++) {
            for (int c = sc; c <= ec; c++) {
                board[r][c] = str[idx];
            }
        }

        return idx;
    }

    int mr = (sr + er) / 2, mc = (sc + ec) / 2;
    if (sr == er) { // 가로로 한 줄
        int nxt = DtoBRecursion(sr, sc, sr, mc, str, idx + 1) + 1;
        return DtoBRecursion(sr, mc + 1, sr, ec, str, nxt);
    }
    else if (sc == ec) { // 세로로 한 줄
        int nxt = DtoBRecursion(sr, sc, mr, sc, str, idx + 1) + 1;
        return DtoBRecursion(mr + 1, sc, er, sc, str, nxt);
    }
    else {
        int nxt = DtoBRecursion(sr, sc, mr, mc, str, idx + 1) + 1;
        nxt = DtoBRecursion(sr, mc + 1, mr, ec, str, nxt) + 1;
        nxt = DtoBRecursion(mr + 1, sc, er, mc, str, nxt) + 1;
        return DtoBRecursion(mr + 1, mc + 1, er, ec, str, nxt);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char prev_ch;
    std::cin >> prev_ch;
    while (true) {
        if (prev_ch == '#') {
            break;
        }

        int R, C;
        std::string in;
        std::string str;
        std::cin >> R >> C;

        while (std::cin >> in) {
            // expression이 B나 D로 끝나는 경우는 없으니 B나 D는 테스트 케이스의 시작임
            if (in == "B" || in == "D" || in == "#") {
                break;
            }
            str += in;
        }

        board.assign(R, std::vector<char> (C));
        ans = "";
        if (prev_ch == 'B') {
            for (int r = 0; r < R; r++) {
                std::string line = str.substr(r * C, C);
                for (int c = 0; c < C; c++) {
                    board[r][c] = line[c];
                }
            }
            BtoDRecursion(0, 0, R - 1, C - 1);
            
            std::cout << 'D' << std::setw(4) << R << std::setw(4) << C << "\n";
            // 출력 형식도 50자로 맞춰야 하는군
            for (int i = 0; i < ans.size(); i += 50) {
                std::cout << ans.substr(i, 50) << "\n";
            }
        }
        else if (prev_ch == 'D') {
            DtoBRecursion(0, 0, R - 1, C - 1, str, 0);

            std::cout << 'B' << std::setw(4) << R << std::setw(4) << C << "\n";
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    ans += board[r][c];
                }
            }

            for (int i = 0; i < ans.size(); i += 50) {
                std::cout << ans.substr(i, 50) << "\n";
            }
        }

        prev_ch = in[0];
    }
    
    return 0;
}