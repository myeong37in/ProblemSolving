/*
다음 사각형의 높이가 더 크거나 같으면 거기까지는 다각형의 모양이 확정

0번과 마지막은 항상 확정

deque
사각형의 높이가 커지면 크거나 같은 높이의 사각형, 또는 다각형을 이루는 것이 확정인 사각형이 나올 때까지 이전에 들어온 사각형 빼기. 그리고 넣기
작아지면 그냥 넣기

대충 흐름
deque
0
0 1
0 1 2
0 1 3
0 1 3 4
0 1 3 5
0 1 3 6

0, 1, 3, 6번 사각형이 다각형을 이룬다.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i].first >> vec[i].second;
    }

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    std::vector<int> is_fixed(N, false); // is_fixed[i] = true면 i번 사각형은 다각형에 포함됨이 확정
    std::deque<int> deq;
    is_fixed[0] = true;
    deq.push_back(0);

    for (int i = 1; i < N; i++) {
        while (!deq.empty() && vec[deq.back()].second < vec[i].second && is_fixed[deq.back()] == false) {
            deq.pop_back();
        }

        if (vec[deq.back()].second <= vec[i].second && is_fixed[deq.back()] == true) {
            is_fixed[i] = true;
        }
        deq.push_back(i);
    }



    int cx = vec[deq.front()].first;
    int cy = vec[deq.front()].second;
    int ans = 0;
    for (int i = 1; i < deq.size(); i++) {
        auto [nx, ny] = vec[deq[i]];

        if (ny > cy) { // 현재 기둥을 기준으로 넓이 계산
            ans += (nx - cx) * cy;
        }
        else { // 현재 기둥의 넓이만 계산하고 다음 기둥을 기준으로 넓이 계산
            ans += cy;
            ans += (nx - 1 - cx) * ny;
        }

        cx = nx;
        cy = ny;
    }

    ans += cy; // 마지막 기둥

    std::cout << ans;

    return 0;
}