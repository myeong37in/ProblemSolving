/*
괄호의 개수는 많아야 5개

dp[i][0]: i번 정수까지, 현재 정수에서 괄호가 끝나지 않을 때 최댓값, 최솟값 쌍
dp[i][1]: i번 정수까지, 현재 정수에서 괄호가 끝날 때 최댓값, 최솟값 쌍

초기화
dp[0][0] = 첫 수
dp[1][0] = dp[1][1] = (첫 두 수의 연산 결과)

점화식
dp[i][0] = max(dp[i - 1][0]에 현재 연산자를 적용한 결과, dp[i - 1][1]에 현재 연산자를 적용한 결과)
dp[i][1] = max(dp[i - 2][0]에 괄호를 열고 두 개의 연산자를 적용한 결과, dp[i - 2][1]에 괄호를 열고 두 개의 연산자를 적용한 결과)

음수끼리 곱하면 양수가 되므로 각 상태마다 최댓값, 최솟값을 모두 저장해야
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int Calc(const int& a, const int& b, const char& op) {
    int res = a;
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        return a * b;
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string str;
    std::cin >> N >> str;

    if (N == 1) {
        std::cout << str[0];
        return 0;
    }

    std::vector<std::vector<std::pair<int, int>>> dp((N + 1) / 2, std::vector<std::pair<int, int>> (2)); // 정수의 개수는 (N + 1)/2개
    std::vector<int> numbers((N + 1) / 2);
    std::vector<char> ops((N - 1) / 2);
    for (int i = 0; i < (N + 1) / 2; i++) {
        numbers[i] = str[i * 2] - '0';
    }
    for (int i = 0; i < (N - 1) / 2; i++) {
        ops[i] = str[i * 2 + 1];
    }

    dp[0][0] = {numbers[0], numbers[0]};
    dp[1][0] = dp[1][1] = {Calc(numbers[0], numbers[1], ops[0]), Calc(numbers[0], numbers[1], ops[0])};
    
    for (int i = 2; i < (N + 1) / 2; i++) {
        std::vector<int> res0 = {Calc(dp[i - 1][0].first, numbers[i], ops[i - 1]),
                                Calc(dp[i - 1][1].first, numbers[i], ops[i - 1]), 
                                Calc(dp[i - 1][0].second, numbers[i], ops[i - 1]),
                                Calc(dp[i - 1][1].second, numbers[i], ops[i - 1])};

        dp[i][0] = {*std::max_element(res0.begin(), res0.end()), *std::min_element(res0.begin(), res0.end())};

        if (i == 2) { // dp[0][1]은 쓸 수 없음
            dp[2][1] = {Calc(dp[0][0].first, Calc(numbers[1], numbers[2], ops[1]), ops[0]), Calc(dp[0][0].second, Calc(numbers[1], numbers[2], ops[1]), ops[0])}; 
            continue;
        }

        std::vector<int> res1 = {Calc(dp[i - 2][0].first, Calc(numbers[i - 1], numbers[i], ops[i - 1]), ops[i - 2]),
                                 Calc(dp[i - 2][0].second, Calc(numbers[i - 1], numbers[i], ops[i - 1]), ops[i - 2]), 
                                 Calc(dp[i - 2][1].first, Calc(numbers[i - 1], numbers[i], ops[i - 1]), ops[i - 2]),
                                 Calc(dp[i - 2][1].second, Calc(numbers[i - 1], numbers[i], ops[i - 1]), ops[i - 2])};
        dp[i][1] = {*std::max_element(res1.begin(), res1.end()), *std::min_element(res1.begin(), res1.end())};
    }
    
    std::cout << std::max(dp.back()[0].first, std::max(dp.back()[0].second, std::max(dp.back()[1].first, dp.back()[1].second)));

    return 0;
}