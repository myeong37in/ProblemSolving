/*
몇개고? 0의 개수 말이다. (18개임)

0의 개수: N개
1의 개수: 최대 2N개
2의 개수: 최대 2N개
...

K개만 필요한 거면 실제 확장을 하면 될 듯
*/

#include <iostream>
#include <vector>
#include <unordered_set>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long L, N, K;
    std::cin >> L >> N >> K;

    std::unordered_set<long long> seq;
    long long x;
    for (int i = 0; i < N; i++) {
        std::cin >> x;
        seq.insert(x);
    }

    int total = N;
    std::vector<long long> cnts = {N};
    
    std::unordered_set<long long> used;
    while (K > total) {
        std::unordered_set<long long> nxt;
        
        for (auto it = seq.begin(); it != seq.end(); it++) {
            long long x = *it;
            if (x - 1 >= 0 && seq.find(x - 1) == seq.end() && used.find(x - 1) == used.end()) {
                nxt.insert(x - 1);
            }

            if (x + 1 <= L && seq.find(x + 1) == seq.end() && used.find(x + 1) == used.end()) {
                nxt.insert(x + 1);
            }
        }

        used.insert(seq.begin(), seq.end());

        cnts.emplace_back(nxt.size());
        total += nxt.size();

        std::swap(seq, nxt);
    }
    
    for (int i = 0; i < cnts.size(); i++) {
        for (int j = 0; j < cnts[i] && j < K; j++) {
            std::cout << i << "\n";
        }
        K -= cnts[i];
    }
    
    return 0;
}