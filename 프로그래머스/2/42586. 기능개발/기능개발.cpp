/*
완료되는 날을 덱에 넣어 두고 꺼낼 때 이미 완료된 작업을 모두 꺼내서 개수를 세면 되겠군
*/

#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int N = speeds.size();
    std::deque<int> deq;
    for (int i = 0; i < N; i++) {
        int left = 100 - progresses[i];
        deq.push_back((left + speeds[i] - 1) / speeds[i]);
    }
    
    vector<int> answer;
    while (!deq.empty()) {
        int cnt = 1;
        int time = deq.front();
        deq.pop_front();
        while (!deq.empty() && deq.front() <= time) {
            deq.pop_front();
            cnt++;
        }
        
        answer.emplace_back(cnt);
    }
    
    return answer;
}