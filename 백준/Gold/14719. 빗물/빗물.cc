/*
각 위치에서 좌, 우로 최대 높이 기반 계산
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    std::cin >> H >> W;
    
    std::vector<int> heights(W), left_max(W), right_max(W);
    for (int i = 0; i < W; i++) {
        std::cin >> heights[i];
    }

    left_max[0] = heights[0];
    for (int i = 1; i < W; i++) {
        left_max[i] = std::max(left_max[i - 1], heights[i]);
    }

    right_max[W - 1] = heights[W - 1];
    for (int i = W - 2; i >= 0; i--) {
        right_max[i] = std::max(right_max[i + 1], heights[i]);
    }

    int ans = 0;
    for (int i = 0; i < W; i++) {
        int level = std::min(left_max[i], right_max[i]);
        ans += std::max(0, level - heights[i]);
    }

    std::cout << ans;

    return 0;
}