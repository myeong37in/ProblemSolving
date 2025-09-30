/*
다행히도 factorization을 완전 탐색으로 할 수 있다.

격자를 행부터 채우고 정방향으로 읽으면 될 듯
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;
    
    int N = str.size();

    int R = 1, C = N;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            R = i;
            C = N / i;
        }
    }

    std::vector<std::vector<char>> msg(R, std::vector<char> (C));
    for (int c = 0; c < C; c++) {
        for (int r = 0; r < R; r++) {
            msg[r][c] = str[R * c + r];
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            std::cout << msg[r][c];
        }
    }

    return 0;
}