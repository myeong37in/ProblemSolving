/*
2배 하면 정수형으로 계산 가능하겠군
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L;
    std::cin >> N >> L;

    L *= 2;
    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
        seq[i] *= 2;
    }

    std::sort(seq.begin(), seq.end());

    int tape_end = -1;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (seq[i] + 1 > tape_end) {
            ans++;
            tape_end = seq[i] - 1 + L;
        }
    }

    std::cout << ans;

    return 0;
}