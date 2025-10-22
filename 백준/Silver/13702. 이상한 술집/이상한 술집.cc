/*
이게 parametric search가 아닐 수가 없어요
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, K;
    std::cin >> N >> K;

    if (N == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<long long> cap;
    long long n;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        if (n) {
            cap.emplace_back(n);
        }
    }

    long long lo = 1;
    long long hi = 4e18;
    long long best_cap = 0;
    long long best_rem = 9e18;
    int sz = cap.size();
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long cnt = 0;
        long long rem = 0;
        for (int i = 0; i < sz; i++) {
            cnt += cap[i] / mid;
            rem += cap[i] % mid;

            if (cnt >= K) {
                break;
            }
        }

        if (cnt >= K) {
            if (rem < best_rem) {
                best_cap = std::max(best_cap, mid);
            }
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    std::cout << best_cap;

    return 0;
}
