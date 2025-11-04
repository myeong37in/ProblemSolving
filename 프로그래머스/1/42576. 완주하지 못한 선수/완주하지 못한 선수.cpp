#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    std::unordered_map<std::string, int> um;
    for (const auto& s : completion) {
        um[s]++;
    }

    string answer = "";
    for (const auto& s : participant) {
        if (um.find(s) == um.end() || um[s] == 0) {
            answer = s;
            break;
        }
        else {
            um[s]--;
        }
    }
    
    return answer;
}