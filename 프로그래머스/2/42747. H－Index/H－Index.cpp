/*
정렬 후 선형 탐색
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int N = citations.size();
    std::sort(citations.begin(), citations.end());
    
    int answer = 0;
    for (int i = 0; i < N; i++) {
        // 인용 수와 해당 수 이상 인용된 논문 수 비교
        answer = std::max(answer, std::min(citations[i], N - i));
    }
    
    return answer;
}