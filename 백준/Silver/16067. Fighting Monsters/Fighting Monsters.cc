/*
다 방법이 있다 아입니까 

마지막에 1 0이 되려면 역순으로
1 0
1 1
2 1
2 3
5 3
5 8
13 8
13 21
34 21
34 55
...

두 수가 인접한 피보나치 수를 이루면 된다 아입니까
공격은 더 작은 수부터 시작

근데 두 수가 인접한 피보나치 수인지 어떻게 빠르게 판정하지? 잘 비교해 보면 될 듯
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<bool> dat(1'000'001);
    std::unordered_map<int, int> num_to_idx;
    int num;
    for (int i = 1; i <= n; i++) {
        std::cin >> num;

        // 1 1인 경우만 중복된 수가 있을 때 답이 있음
        if (num == 1 && dat[num]) {
            std::cout << num_to_idx[num] << " " << i;
            return 0;
        }

        num_to_idx[num] = i;
        dat[num] = true;
    }
    
    int prev = 1, cur = 1;
    while (true) {
        int nxt = prev + cur;
        if (nxt > 1'000'000) {
            break;
        }
        
        if (dat[cur] && dat[nxt]) {
            std::cout << num_to_idx[cur] << " " << num_to_idx[nxt];
            return 0;
        }

        prev = cur;
        cur = nxt;
    }

    std::cout << "impossible";
    
    return 0;
}