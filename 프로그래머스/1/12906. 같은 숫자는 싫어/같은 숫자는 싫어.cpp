#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int prev = -1;
    for (const int& n : arr) {
        if (n == prev) {
            continue;
        }
        answer.emplace_back(n);
        prev = n;
    }

    return answer;
}