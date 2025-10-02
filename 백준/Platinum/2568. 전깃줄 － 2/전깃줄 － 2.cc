/*
A 전봇대와 연결되는 전깃줄을 오름차순 정렬
B 전봇대와 연결되는 전깃줄에서 LIS를 구한다. 여기에 포함되지 않는 전깃줄 모두 싹뚝
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> wires(N); // (A에 연결된 전깃줄 위치, B에 연결된 전깃줄 위치)
    for (int i = 0; i < N; i++) {
        std::cin >> wires[i].first >> wires[i].second;
    }

    std::sort(wires.begin(), wires.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    std::vector<int> lis_len = {wires[0].second}; // LIS의 길이
    std::vector<int> lis_idx = {1}; // wires의 원소들이 LIS의 길이에 들어갈 때 그 인덱스를 저장

    for (int i = 1; i < N; i++) {
        if (lis_len.back() < wires[i].second) {
            lis_len.emplace_back(wires[i].second);
            lis_idx.emplace_back(lis_len.size());
        }
        else {
            int pos = std::lower_bound(lis_len.begin(), lis_len.end(), wires[i].second) - lis_len.begin();
            lis_len[pos] = wires[i].second;
            lis_idx.emplace_back(pos + 1);
        }
    }

    std::vector<int> lis; // 실제 LIS
    int target = lis_len.size();
    int search_idx = lis_idx.size() - 1;

    while (target) {
        for (int i = search_idx; i >= 0; i--) {
            if (lis_idx[i] == target) {
                lis.emplace_back(wires[i].second);
                search_idx -= search_idx - i;
                break;
            }
        }
        target--;
    }

    std::vector<int> answer;
    for (int i = 0; i < N; i++) {
        if (std::find(lis.begin(), lis.end(), wires[i].second) == lis.end()) {
            answer.emplace_back(wires[i].first);
        }
    }

    std::sort(answer.begin(), answer.end());

    std::cout << answer.size() << "\n";
    for (const int& num : answer) {
        std::cout << num << "\n";
    }

    return 0;
}