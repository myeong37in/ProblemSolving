#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    for (const int& n : scoville) {
        pq.push(n);
    }
    
    int answer = 0;
    while (pq.size() >= 2 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        pq.push(first + 2 * second);
        answer++;
    }
    
    if (pq.top() < K) {
        return -1;
    }
    
    return answer;
}