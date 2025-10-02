/*
많은 방법이 떠오르긴 하지만 입력이 입력이니만큼 그냥..
*/

#include <iostream>
#include <vector>
#include <cmath>

double GetDist(std::pair<int, int> src, std::pair<int, int> dst) {
    return std::sqrt((dst.first - src.first) * (dst.first - src.first) + (dst.second - src.second) * (dst.second - src.second));
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::pair<int, int> start;
    std::cin >> start.first >> start.second;

    std::vector<std::pair<int, int>> vec(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> vec[i].first >> vec[i].second;
    }

    double best = 1e9;
    best = std::min(best, GetDist(start, vec[0]) + GetDist(vec[0], vec[1]) + GetDist(vec[1], vec[2]));
    best = std::min(best, GetDist(start, vec[0]) + GetDist(vec[0], vec[2]) + GetDist(vec[2], vec[1]));
    best = std::min(best, GetDist(start, vec[1]) + GetDist(vec[1], vec[0]) + GetDist(vec[0], vec[2]));
    best = std::min(best, GetDist(start, vec[1]) + GetDist(vec[1], vec[2]) + GetDist(vec[2], vec[0]));
    best = std::min(best, GetDist(start, vec[2]) + GetDist(vec[2], vec[0]) + GetDist(vec[0], vec[1]));
    best = std::min(best, GetDist(start, vec[2]) + GetDist(vec[2], vec[1]) + GetDist(vec[1], vec[0]));

    std::cout << static_cast<int>(best);

    return 0;
}