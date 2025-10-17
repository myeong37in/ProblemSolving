/*
A = B면 고려하지 않아도 됨

0 <= A < B <= M이면 가는 길이므로 고려하지 않아도 됨

0 <= B < A <= M이면 가장 먼 A에서 가장 가까운 B까지의 거리의 2배(왕복)를 추가로 가야 함

스위핑이군
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> seq;
    int A, B;
    for (int i = 0; i < N; i++) {
        std::cin >> A >> B;
        if (A > B) {
            seq.emplace_back(B, A); // B -> A로 바꿔 생각
        }
    }

    if (seq.empty()) { // 되돌아오는 일 없음
        std::cout << M;
        return 0;
    }

    std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    long long ans = 0;
    int start = seq[0].first;
    int end = seq[0].second;
    int L = seq.size();
    for (int i = 1; i < L; i++) {
        if (seq[i].first <= end) { // 선분이 끊어지지 않고 연장
            end = std::max(end, seq[i].second);
        }
        else { // 선분이 끊어지므로 중간 계산
            ans += end - start;
            start = seq[i].first;
            end = seq[i].second;
        }
    }
    ans += end - start;

    std::cout << M + ans * 2;

    return 0;
}