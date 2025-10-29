/*
입장, 퇴장 시각 기준 정렬 후 스위핑

최대 개수를 만나면 그 구간이 끝날 때 끝부분 확정
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    
    int sz = 2 * N;
    std::vector<std::pair<int, int>> seq(sz);
    int s, e;
    for (int i = 0; i < N; i++) {
        std::cin >> s >> e;
        seq[2 * i] = {s, 1}; // 입장은 1
        seq[2 * i + 1] = {e, -1}; // 퇴장은 -1
    }

    std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    int cnt = 0, best = 0, t_em = 0, t_xm = 0;
    bool is_best = false;
    for (int i = 0; i < sz;) {
        int j = i;
        while (j < sz && seq[j].first == seq[i].first) { // 같은 시각 모두 처리
            cnt += seq[j].second;
            j++;
        }

        if (best < cnt) {
            best = cnt;
            t_em = seq[i].first; // 시작점 갱신
            is_best = true;
        }

        if (is_best && cnt < best) { // 최대 구간 끝
            t_xm = seq[i].first; // 끝점 확정
            is_best = false;
        }

        i = j;
    }

    std::cout << best << "\n" << t_em << " " <<  t_xm;

    return 0;
}