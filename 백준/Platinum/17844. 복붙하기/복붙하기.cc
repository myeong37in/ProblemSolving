/*
조건을 만족하는 문자열의 길이는 단조성이 있다. 이분 탐색 가능

문자열의 길이를 N이라 할 때 하한 1, 상한 N/2에 대해 롤링 해시로 O(N) 판정

O(N logN)

그건 그거고 그러니까 이 충돌은... 음... 2^61 - 1이라고 메르센 소수가 하나 있는데 말이죠?
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

constexpr uint64_t MOD = (1ULL << 61) - 1;
constexpr uint64_t BASE = 998244353;

// This does what you think it does
static inline uint64_t ModMul(uint64_t a, uint64_t b) {
    __uint128_t tmp = static_cast<__uint128_t>(a) * b;
    uint64_t lo = static_cast<uint64_t>(tmp) & MOD;
    uint64_t hi = static_cast<uint64_t>(tmp >> 61);

    uint64_t x = lo + hi;
    x = (x & MOD) + (x >> 61);
    if (x >= MOD) {
        x -= MOD;
    }

    return x;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;

    int N = S.size();
    int lo = 1, hi = N / 2;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        bool okay = false;
        // 길이 mid인 문자열에 대해 롤링 해시
        uint64_t power = 1;
        uint64_t hash = 0;
        for (int i = 0; i < mid; i++) {
            long long val = S[i] - 'a' + 1;
            hash = (ModMul(hash, BASE) + val) % MOD;
            if (i + 1 < mid) { // 길이가 mid인 문자열 -> power = BASE^(mid - 1)
                power = ModMul(power, BASE);
            }
        }

        std::unordered_map<uint64_t, int> hash_seen; // {해시, 인덱스} 저장
        hash_seen.insert({hash, 0});
        for (int si = 1; si <= N - mid; si++) { // 시작점
            uint64_t tail = S[si + mid - 1] - 'a' + 1; // 새로 들어온 문자
            uint64_t lead = S[si - 1] - 'a' + 1; // 나가는 문자
            hash = (hash - ModMul(lead, power) + MOD) % MOD;
            hash = (ModMul(hash, BASE) + tail) % MOD;
        
            auto it = hash_seen.find(hash);

            if (it != hash_seen.end()) {
                if (hash_seen[hash] + mid <= si) { // 안 겹치는 경우
                    okay = true;
                    break;
                }
                else { // 겹치는 경우
                    continue;
                }
            }
            else { // 처음 보는 해시값
                hash_seen[hash] = si;
            }
        }

        if (okay) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }


    std::cout << ans;

    return 0;
}