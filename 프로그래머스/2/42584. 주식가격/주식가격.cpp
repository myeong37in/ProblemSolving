/*
현재 수보다 큰 수가 덱에 있으면 빼면서 시간 기록
마지막에에 덱에 남은 요소들은 끝까지 안 가격이 안 떨어진 것들이므로 초기 인덱스를 기준으로 시간 기록

amortized O(N)
*/

#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    
    vector<int> answer(N);
    std::deque<int> deq;
    for (int i = 0; i < N; i++) {
        int cur = prices[i];
        while (!deq.empty() && prices[deq.back()] > cur) {
            answer[deq.back()] = i - deq.back();
            deq.pop_back();
        }
        
        deq.push_back(i);
    }
    
    for (const int& i : deq) {
        answer[i] = N - 1 - i;
    }
    
    return answer;
}