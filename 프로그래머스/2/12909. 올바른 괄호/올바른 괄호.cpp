#include <string>
#include <iostream>
#include <deque>

using namespace std;

bool solution(string s)
{
    std::deque<char> deq;
    for (const char& ch : s) {
        if (ch == '(') {
            deq.push_back(ch);
        }
        else {
            if (deq.empty() || deq.back() != '(') {
                return false;
            }
            deq.pop_back();
        }
    }
    
    if (!deq.empty()) {
        return false;
    }

    return true;
}