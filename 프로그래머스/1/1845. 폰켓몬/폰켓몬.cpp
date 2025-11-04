#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{   
    int N = nums.size();
    std::unordered_set<int> us(nums.begin(), nums.end());
    
    // N/2종보다 많이 있으면 N/2, 그게 아니면 종류 수
    int answer = std::min(N / 2, static_cast<int>(us.size()));
    return answer;
}