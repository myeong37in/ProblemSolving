/*
최종 상태는 LLL...LRRR...R

선형 스캔으로 L이 나올 때마다 왼쪽으로 붙일 때 이동 거리가 악수 횟수

최대 5만 * 5만 = 25억

시간은 어떤 L에 대해 왼쪽의 R 수 + 오른쪽 L 수 - 1의 최댓값
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    long long cnt = 0;

    int R_cnt = 0, L_cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'R') {
            R_cnt++;
        }
        else {
            cnt += R_cnt;
            L_cnt++;
        }
    }

    int time = 0;
    int R_seen = 0;
    int L_seen = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'R') {
            R_seen++;
        }
        else {
            L_seen++;
        }

        int L_suffix = L_cnt - L_seen;
        if (R_seen > 0 && L_suffix > 0) { // 양쪽에 대기열이 있어야 교차가 생김
            time = std::max(time, R_seen + L_suffix - 1);
        }
    }
    std::cout << time << " " << cnt;

    return 0;
}