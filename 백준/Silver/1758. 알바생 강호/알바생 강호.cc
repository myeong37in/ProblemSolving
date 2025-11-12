#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end(), std::greater<int>());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += std::max(0, seq[i] - i);
    }

    std::cout << ans;

    return 0;
}