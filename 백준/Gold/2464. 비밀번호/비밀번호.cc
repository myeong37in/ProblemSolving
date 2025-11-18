/*
1의 개수가 고정, 이전 수, 다음 수라면?

이진수 표현이 111일 때 1011을 정상적으로 얻으려면 MSB에 0을 하나 붙여주면 되겠다
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long A;
    std::cin >> A;

    std::vector<int> bits;
    while (A) {
        bits.emplace_back(A & 1);
        A >>= 1;
    }
    
    bits.emplace_back(0); // MSB를 0으로
    std::reverse(bits.begin(), bits.end());
    
    std::vector<int> tmp = bits;
    long long prev = 0;
    if (std::prev_permutation(tmp.begin(), tmp.end())) {
        for (int bit : tmp) {
            prev = (prev << 1) | bit;
        }
    }

    long long nxt = 0;
    tmp = bits;
    std::next_permutation(tmp.begin(), tmp.end());
    for (int bit : tmp) {
        nxt = (nxt << 1) | bit;
    }

    std::cout << prev << " " << nxt;

    return 0;
}