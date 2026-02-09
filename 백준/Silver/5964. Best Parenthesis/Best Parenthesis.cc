/*
)가 나오면 스택에 그때까지의 합을 넣어

아니 합의 모듈러가 0이 되는 경우가 있다고?
*/

#include <iostream>
#include <deque>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    constexpr long long MOD = 12345678910;
    
    std::deque<long long> deq;
    int n;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        if (n == 0) {
            deq.push_back(-1);
        }
        else {
            long long prev_sum = 0;
            bool num = false;
            while (!deq.empty() && deq.back() != -1) {
                prev_sum = (prev_sum + deq.back()) % MOD;
                num = true;
                deq.pop_back();
            }
            
            deq.pop_back(); // ( 제거

            if (!num) { // ()
                deq.push_back(1);
            }
            else {
                deq.push_back((prev_sum << 1) % MOD);
            }
        }
    }

    long long ans = 0;
    while (!deq.empty()) {
        ans = (ans + deq.back()) % MOD;
        deq.pop_back();
    }

    std::cout << ans;
    
    return 0;
}