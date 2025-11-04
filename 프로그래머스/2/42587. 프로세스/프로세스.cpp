/*
큐 시뮬레이션, 우선순위 최대 힙으로 관리
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int N = priorities.size();
    
    std::priority_queue<int> pq;
    std::queue<int> q;
    for (int i = 0; i < N; i++) {
        pq.push(priorities[i]);
        q.push(priorities[i]);
    }
    
    int answer = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        location--; // 목표 프로세스 위치
        if (pq.top() > cur) { // 우선순위가 더 높은 프로세스 있음
            if (location < 0) {
                location = q.size();
            }
            q.push(cur);
        }
        else {
            answer++;
            pq.pop();

            if (location < 0) {
                break;
            }
        }
    }
    
    return answer;
}