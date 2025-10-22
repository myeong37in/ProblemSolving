/*
완전 탐색으로 테케 수 * C(20, 10)이긴 함. DP가 될 것 같은데 방법이 떠오르지가 않네..

가지치기나 합시다
*/

#include <iostream>

int n, k, s;

int cnt = 0;
static void backtrack(int prev, int sum, int depth) {
    if (depth == k) {
        if (sum == s) {
            cnt++;
        }
        return;
    }

    // prev + 1에서 prev + (k - depth)까지 더하는 것이 최소 합
    int min_sum = (k - depth) * prev + (k - depth) * (k - depth + 1) / 2;
    if (sum + min_sum > s) {
        return;
    }

    // n - (k - depth) + 1에서 n까지 더하는 것이 최대 합
    int max_sum = n * (n + 1) / 2 - (n - (k - depth)) * (n - (k - depth) + 1) / 2;
    if (sum + max_sum < s) {
        return;
    }

    for (int next = prev + 1; next <= n - k + 1 + depth; next++) {
        backtrack(next, sum + next, depth + 1);
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (std::cin >> n >> k >> s) {
        cnt = 0;

        if (n == 0) {
            break;
        }

        if (n < k || (n * (n + 1) / 2) < s) { // 수의 개수, 최소합 조건
            std::cout << 0 << "\n";
            continue;
        }

        for (int start = 1; start <= n - k + 1; start++) {
            backtrack(start, start, 1);
        }

        std::cout << cnt << "\n";
    }

    return 0;
}