/*
시뮬레이션
*/

#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    std::deque<std::pair<int, int>> deq; // {트럭 인덱스, 다 건너는 시간}
    int N = truck_weights.size();
    int time = 1;
    int in_deq = 0;
    int idx = 0;
    while (true) {
        if (!deq.empty() && deq.front().second <= time) { // 건넌 트럭 빼기
            in_deq -= truck_weights[deq.front().first];
            deq.pop_front();
        }
        
        if (idx < N && in_deq + truck_weights[idx] <= weight && deq.size() < bridge_length) { // 다리에 넣기
            deq.push_back({idx, time + bridge_length});
            in_deq += truck_weights[idx];
            idx++;
        }
        
        if (idx == N && deq.empty()) { // 끝
            break;
        }
        
        time++;
    }
    
    return time;
}