/*
well-known greedy

여기도 "0"이 있는 건가
*/

#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(vector<int> numbers) {
    int N = numbers.size();
    std::vector<std::string> vec(N);
    bool all_zero = true;
    for (int i = 0; i < N; i++) {
        if (numbers[i] != 0) {
            all_zero = false;
        }
        vec[i] = std::to_string(numbers[i]);
    }
    
    if (all_zero) {
        return "0";
    }
    
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        std::string ab = a + b;
        std::string ba = b + a;
        return ab > ba;
    });
    
    string answer = "";
    for (const auto& s : vec) {
        answer += s;
    }
    
    return answer;
}