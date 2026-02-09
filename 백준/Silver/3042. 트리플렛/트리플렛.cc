/*
최대 C(26, 3)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<std::vector<char>> board(N, std::vector<char> (N));
    std::string line;
    std::vector<std::pair<int, int>> coords;
    for (int i = 0; i < N; i++) {
        std::cin >> line;
        for (int j = 0; j < N; j++) {
            board[i][j] = line[j];

            if (board[i][j] != '.') {
                coords.emplace_back(i, j);
            }
        }
    }

    int cnt = coords.size();
    if (cnt < 3) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> selected(cnt);
    selected[cnt - 1] = 1;
    selected[cnt - 2] = 1;
    selected[cnt - 3] = 1;

    int ans = 0;
    int a = 0;
    do {
        std::vector<std::pair<int, int>> points;
        for (int i = 0; i < cnt; i++) {
            if (selected[i]) {
                points.emplace_back(coords[i]);
            }
        }

        int dx1 = points[1].first - points[0].first;
        int dy1 = points[1].second - points[0].second;
        int dx2 = points[2].first - points[1].first;
        int dy2 = points[2].second - points[1].second;
        
        if (dx1 * dy2 == dx2 * dy1) { // 기울기 같음
            ans++;   
        }
    } while (std::next_permutation(selected.begin(), selected.end()));

    std::cout << ans;

    return 0;
}