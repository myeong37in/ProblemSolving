/*
실시간 처리가 아님 

시작에서 +1, 끝에서 -1, 누적 합

86,399 * 100,000 

int 넘네..
*/

#include <iostream>
#include <vector>

static inline int GetTimeSec(std::string timestamp) {
    return ((timestamp[0] - '0') * 10 + (timestamp[1] - '0')) * 3600 + \
           ((timestamp[3] - '0') * 10 + (timestamp[4] - '0')) * 60 + \
           ((timestamp[6] - '0') * 10 + (timestamp[7] - '0'));
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    

    constexpr int cnt = 24 * 60 * 60;
    std::vector<int> diffs(cnt);
    std::vector<long long> psum(cnt);

    int n;
    std::cin >> n;

    int type;
    bool type1_end = false;
    std::string stime, etime;
    for (int i = 0; i < n; i++) {
        std::cin >> type >> stime >> etime;
        
        int stime_int = GetTimeSec(stime);
        int etime_int = GetTimeSec(etime);
        int diff = 0; // 현재 시각에서 변화량

        if (type == 1) {
            diffs[stime_int]++;
            diffs[etime_int]--;
        }
        else {
            // 1번 유형의 쿼리 끝. 계산
            if (type1_end == false) {
                for (int i = 0; i < cnt - 1; i++) {
                    diff += diffs[i];
                    psum[i + 1] = psum[i] + diff;
                }
                type1_end = true;
            }

            std::cout << psum[etime_int] - psum[stime_int] << "\n";
        }
    }
    
    return 0;
}