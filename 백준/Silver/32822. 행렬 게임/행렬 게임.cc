/*
열이 확정이므로 1번부터 N번 행까지 두 행렬값의 차이가 가장 큰 값을 선택

않이 문제 똑바로 안 읽나.. O(NM) 안 되잖음
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> mat1(N + 1, std::vector<int> (N + 1));
    std::vector<std::vector<int>> mat2(N + 1, std::vector<int> (N + 1));
    
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            std::cin >> mat1[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            std::cin >> mat2[r][c];
        }
    }

    std::vector<int> col_diff_max(N + 1, -1);
    for (int c = 1; c <= N; c++) {
        for (int r = 1; r <= N; r++) {
            col_diff_max[c] = std::max(col_diff_max[c], std::abs(mat1[r][c] - mat2[r][c]));
        }
    }

    int ans = 0;
    int c;
    for (int i = 0; i < M; i++) {
        std::cin >> c;
        ans += col_diff_max[c];
    }

    std::cout << ans;

    return 0;
}