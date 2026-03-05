/*
두 개미가 서로 마주칠 때는 아무 일도 일어나지 않는다고 봐도 됨.
서로 원라 갸아 할 길을 가는 대신에 상대의 길을 대신 가주는 것이고 여기서는 끝점에 도착하는 개미의 마릿수만 세면 되므로 ㅇㅇ

예외는 중심점에서 만날 때.
중심에서 만나는 개미는 원래 가야 할 끝점이 아닌 자신이 왔던 삼거리의 끝점으로 목적지가 바뀜

각 개미가 중심에 도착하는 시간과 끝점에 도착하는 시간을 각각 계산
    이때 중심 방향(0)이면 도착 끝점은 자신의 위치에 따라 A -> B, B -> C, C -> A
    끝점 방향(1)이면 도착 끝점을 자신의 위치로 유지. 중심에 도착하는 시간 없음

중심에 도착하는 시간 기준으로 정렬하고 시간이 겹치는 개미는 끝점을 자신의 위치로 바꿈 

대충 O(N logN)
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct State {
    char pos;
    long long midpoint_eta;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    long long L;
    std::cin >> N >> L;

    std::vector<State> ants;
    long long time_sum = 0;
    std::vector<int> endpoints(3); // 각각 A, B, C에 도착하는 개미 수

    char pos;
    long long dist;
    int dir;
    for (int i = 0; i < N; i++) {
        std::cin >> pos >> dist >> dir;
        // 끝점을 향하는 경우 이 개미에 대한 답이 바로 정해짐
        if (dir == 1) {
            time_sum += L - dist;
            endpoints[pos - 'A']++;
            continue;
        }

        ants.emplace_back(State {pos, dist});
    }

    std::sort(ants.begin(), ants.end(), [](const State& a, const State& b) {
        return a.midpoint_eta < b.midpoint_eta;
    });

    int sz = ants.size();
    for (int i = 0; i < sz; i++) {
        auto& [pos, midpoint_eta] = ants[i];
        int nxt = i + 1;
        while (nxt < sz && ants[nxt].midpoint_eta == midpoint_eta) {
            nxt++;
        }

        if (nxt - i == 1) {
            // i번 개미가 다른 개미와 중심에서 만나지 않는 경우 우회전하고 L만큼 더 가서 끝
            time_sum += ants[i].midpoint_eta + L;
            if (pos == 'A') {
                endpoints[1]++;
            }
            else if (pos == 'B') {
                endpoints[2]++;
            }
            else {
                endpoints[0]++;
            } 
        }
        else {
            // i번부터 nxt - 1번 개미까지 중심점에서 만남
            // 중심점에서 끝점으로 L만큼 더 가서 끝
            for (int idx = i; idx < nxt; idx++) {
                time_sum += ants[idx].midpoint_eta + L;
                endpoints[ants[idx].pos - 'A']++;
            }

            i = nxt - 1; // nxt번 개미부터 다시
        }
    }

    std::cout << time_sum << "\n" << endpoints[0] << " " << endpoints[1] << " " << endpoints[2];
    
    return 0;
}