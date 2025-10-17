/*
누-적-합
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> seq(N + 1, std::vector<int> (M + 1)), psum(N + 1, std::vector<int> (M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> seq[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            psum[i + 1][j + 1] = psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + seq[i + 1][j + 1];
        }
    }

    int K;
    std::cin >> K;
    int i, j, x, y;
    while (K--) {
        std::cin >> i >> j >> x >> y;
        std::cout << psum[x][y] - psum[x][j - 1] - psum[i - 1][y] + psum[i - 1][j - 1] << "\n";
    }

    return 0;
}