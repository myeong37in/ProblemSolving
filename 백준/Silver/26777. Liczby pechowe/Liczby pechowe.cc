/*
digit DP로 함 풀어볼까

N의 문자열 표현을 str이라고 하면

상태
pos: 현재 어느 자리인지
sum: 자릿수 합
prev1: 이전 자릿수가 1인지
has13: "13"이 나왔는지
    prev1으로 결정
tight: 현재 만든 수가 N의 접두사인지
    tight == true면 0에서 str[pos]까지만 올 수 있음
    tight == false면 0에서 9까지 가능

leading zero는 있어도 OK
*/

#include <iostream>
#include <string>

std::string str;
int len;

int ans = 0;

static int backtrack(int pos, int sum, bool prev1, bool has13, bool tight) {
    if (pos == len) {
        return (sum == 13 && has13);
    }

    int ret = 0;

    int digit_limit = (tight ? str[pos] - '0' : 9);

    for (int i = 0; i <= digit_limit; i++) {
        if (sum + i > 13) {
            break;
        }

        bool new_prev1 = (i == 1);
        bool new_has13 = has13 || (prev1 && i == 3);
        bool new_tight = tight && (str[pos] == static_cast<char>(i + '0'));

        ret += backtrack(pos + 1, sum + i, new_prev1, new_has13, new_tight);
    }

    return ret;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long N;
    std::cin >> N;

    str = std::to_string(N);
    len = str.size();

    std::cout << backtrack(0, 0, false, false, true);
    
    return 0;
}