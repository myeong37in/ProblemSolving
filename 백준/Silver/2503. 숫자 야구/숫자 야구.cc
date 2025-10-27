/*
세 자리니까 111에서 999까지 서로 다른 수 조합
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<bool> candidates(1000, true);
    std::string call_num;
    int call_strikes, call_balls;
    for (int i = 0; i < N; i++) {
        std::cin >> call_num >> call_strikes >> call_balls;

        for (int i = 111; i <= 999; i++) {
            if (i % 10 == 0 || (i / 10) % 10 == 0) { // 0이 포함된 숫자 제거
                candidates[i] = false;
                continue;
            }

            if (candidates[i] == false) {
                continue;
            }

            // '서로 다른 세 개의 숫자'
            std::string num = std::to_string(i);
            int strikes = 0, balls = 0;
            char first = num[0];
            char second = num[1];
            char third = num[2];

            if (first == second || first == third || second == third) {
                candidates[i] = false;
                continue;
            }

            if (first == call_num[0]) {
                strikes++;
            }
            if (first == call_num[1]) {
                balls++;
            }
            if (first == call_num[2]) {
                balls++;
            }

            if (second == call_num[0]) {
                balls++;
            }
            if (second == call_num[1]) {
                strikes++;
            }
            if (second == call_num[2]) {
                balls++;
            }

            if (third == call_num[0]) {
                balls++;
            }
            if (third == call_num[1]) {
                balls++;
            }
            if (third == call_num[2]) {
                strikes++;
            }

            if (strikes != call_strikes || balls != call_balls) {
                candidates[i] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 111; i <= 999; i++) {       
        if (candidates[i]) {
            ans++;
        }
    }

    std::cout << ans;

    return 0;
}