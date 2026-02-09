/*
dp[i][j]: i개의 숫자로 선분이 j개일 때 만드는 최소 숫자(문자열로 저장)

i의 최댓값: 입력 수의 길이, j의 최댓값: 7 * i (모두 8로 채우는 경우)

답이 될 수 없는 큰 수로 초기화
dp[1][2] = 1, dp[1][3] = 7, dp[1][4] = 4, dp[1][5] = 2, dp[1][6] = 0, dp[1][7] = 8

cnt[0] = 6, cnt[1] = 2, cnt[2] = cnt[3] = cnt[5] = cnt[9] = 5, cnt[4] = 4, cnt[6] = 6, cnt[7] = 3, cnt[8] = 7
dp[i][j] = min(dp[i - 1][j - cnt[k]] + k) (0 <= k <= 9)

답을 최대 경과 시간(자기 자신으로 돌아오는 10^(입력 수의 길이))로 초기화

초기 숫자가 abcd이고 목표 선분 수가 L일 때

abcx를 가정, abc의 선분 수가 cur_len이라면 x에 0에서 9 대입. cur_len + cnt[x] == L이면 abcx와 abcd의 차이 계산, 답 갱신

abxx를 가정, ab의 선분 수가 cur_len이라면 가장 앞의 x에 0에서 9 대입
cur_len + cnt[x]는 정해진 값이고 나머지 한 자리에 dp[1][L - cur_len - cnt[x]]가 있으면 그 숫자 y를 얻고 abxy와 abcd의 차이 계산, 답 갱신

axxx를 가정, a의 선분 수가 cur_len, 가장 앞의 x에 0에서 9 대입.
나머지 두 자리에 대해 dp[2][L - cur_len - cnt[x]]가 있으면 그 숫자 yz를 얻고 axyz와 abcd의 차이 계산, 답 갱신

xxxx를 가정
가장 앞의 x에 0에서 9 대입
나머지 세 자리에 대해 dp[3][L - cnt[x]]인 세 자리 숫자를 얻고 abcd와 차이 계산, 답 갱신

을 하면 답이 된다. 0에서 9를 넣는 x digit 이하의 수는 dp로 구한 최솟값이니 해를 보장할 것
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main(int argc, char* argv[]) {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    std::string original;
    std::cin >> original;

    std::vector<int> cnt = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
    int target = 0;
    for (const char& ch : original) {
        target += cnt[ch - '0'];
    }

    int N = original.size();
    std::string init = "99999999999999999";
    std::vector<std::vector<std::string>> dp(N + 1, std::vector<std::string> (7 * N + 1, init));
    dp[1][2] = "1";
    dp[1][3] = "7";
    dp[1][4] = "4";
    dp[1][5] = "2";
    dp[1][6] = "0";
    dp[1][7] = "8";

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= target; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j < cnt[k] || dp[i - 1][j - cnt[k]] == "-1") {
                    continue;
                }
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - cnt[k]] + static_cast<char>(k + '0'));
            }
        }
    }

    long long answer = std::pow(10, N);
    const long long max_answer = answer;
    const long long original_num = std::stoll(original);

    // 하나만 지우는 경우는 따로 처리하는 게 쉬울 듯
    for (int removing_digits = 2; removing_digits <= N; removing_digits++) {
        std::string fixed_str = original.substr(0, N - removing_digits);
        int fixed_len = 0;
        for (const char& ch : fixed_str) {
            fixed_len += cnt[ch - '0'];
        }

        for (int x = 0; x <= 9; x++) {
            int cur_len = fixed_len + cnt[x];
            if (cur_len > target) {
                continue;
            }
            std::string cur_str = fixed_str + static_cast<char>(x + '0');

            if (dp[removing_digits - 1][target - cur_len] == init) {
                continue;
            }
            cur_str += dp[removing_digits - 1][target - cur_len];

            long long cur_num = std::stoll(cur_str);
            if (cur_num > original_num) {
                answer = std::min(answer, cur_num - original_num);
            }
            else if (cur_num < original_num) {
                // 원래 수보다 작으면 최댓값을 찍었다가 다시 0부터 시간이 지나야 함
                answer = std::min(answer, max_answer - original_num + cur_num);
            }
        }
    }

    int last_cnt = cnt[original[N - 1] - '0'];
    for (int x = 0; x <= 9; x++) {
        std::string cur_str = original.substr(0, N - 1) + static_cast<char>(x + '0');

        if (cnt[x] != last_cnt) {
            continue;
        }

        long long cur_num = std::stoll(cur_str);
        if (cur_num > original_num) {
            answer = std::min(answer, cur_num - original_num);
        }
        else if (cur_num < original_num) {
            answer = std::min(answer, max_answer - original_num + cur_num);
        }
    }

    std::cout << answer;

    return 0;
}