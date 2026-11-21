#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    int kr, kc, sr, sc;
    std::string pos;

    std::cin >> pos;
    kc = pos[0] - 'A';
    kr = pos[1] - '1';

    std::cin >> pos;
    sc = pos[0] - 'A';
    sr = pos[1] - '1';

    int N;
    std::cin >> N;

    std::string move;
    int dr, dc;
    for (int i = 0; i < N; i++) {
        dr = 0, dc = 0;
        std::cin >> move;

        if (move == "R") {
            dc = 1;
        }
        else if (move == "L") {
            dc = -1;
        }
        else if (move == "B") {
            dr = -1;
        }
        else if (move == "T") {
            dr = 1;
        }
        else if (move == "RT") {
            dr = 1;
            dc = 1;
        }
        else if (move == "LT") {
            dr = 1;
            dc = -1;
        }
        else if (move == "RB") {
            dr = -1;
            dc = 1;
        }
        else if (move == "LB") {
            dr = -1;
            dc = -1;
        }

        int nkr = kr + dr;
        int nkc = kc + dc;

        if (nkr < 0 || nkr > 7 || nkc < 0 || nkc > 7) { // 킹 이동 불가
            continue;
        }

        if ((nkr == sr) && (nkc == sc)) { // 겹침
            if ((sr + dr < 0) || (sr + dr > 7) || (sc + dc < 0) || (sc + dc > 7)) { // 돌 이동 불가
                continue;
            }
            kr = nkr, kc = nkc, sr += dr, sc += dc; // 킹, 돌 이동
        }
        else { // 안 겹침
            kr = nkr, kc = nkc; // 킹 이동
        }
    }

    std::cout << static_cast<char>(kc + 'A') << kr + 1 << "\n" << static_cast<char>(sc + 'A') << sr + 1;

    return 0;
}