/*
두 번 뒤집는 건 안 뒤집는 것과 같다. 따라서 어떤 3x3 부분 행렬은 최대 한 번 뒤집힌다.
-> 한 번씩 보면 최솟값 됨

앞에서부터 뒤집어 보면서 마지막에 다르면 불가능
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::string line;
    std::vector<std::vector<int>> mat_a(N, std::vector<int> (M)), mat_b(N, std::vector<int> (M));
    for (int i = 0; i < N; i++) {
        std::cin >> line;
        for (int j = 0; j < M; j++) {
            mat_a[i][j] = line[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        std::cin >> line;
        for (int j = 0; j < M; j++) {
            mat_b[i][j] = line[j] - '0';
        }
    }

    if (N <= 2 || M <= 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mat_a[i][j] != mat_b[i][j]) { // 다르면 불가능
                    std::cout << -1;
                    return 0;
                }
            }
        }

        std::cout << 0; // 같으면 0번
        return 0;
    }

    int cnt = 0;
    for (int sr = 0; sr < N - 2; sr++) {
        for (int sc = 0; sc < M - 2; sc++) {
            if (mat_a[sr][sc] != mat_b[sr][sc]) {
                cnt++;
                for (int r = sr; r <= sr + 2; r++) {
                    for (int c = sc; c <= sc + 2; c++) {
                        mat_a[r][c] = !mat_a[r][c];
                    }
                }
            }
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (mat_a[r][c] != mat_b[r][c]) {
                std::cout << -1;
                return 0;
            }
        }
    }

    std::cout << cnt;

    return 0;
}