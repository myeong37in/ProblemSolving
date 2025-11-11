#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const auto& vec : commands) {
        std::vector<int> tmp = array;
        // std::sort의 범위: [first, last)
        std::sort(tmp.begin() + vec[0] - 1, tmp.begin() + vec[1]);
        answer.emplace_back(tmp[vec[0] + vec[2] - 2]);
    }
    return answer;
}