/*
정렬하고 two pointers 매칭
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    int left = 0, right = N - 1, ans = 0;
    while (left < right) {
        int val = seq[left] + seq[right];
        if (val <= K) {
            ans++;
            left++;
            right--;
        }
        else {
            right--;
        }
    }

    std::cout << ans;

    return 0;
}