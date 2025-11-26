/*
L_i의 합이 T보다 크거나 R_i의 합이 T보다 작으면 불가능

S를 고정하면 어떤 사람이 받을 수 있는 술은 L_i <= 술 <= min(R_i, S)

최댓값을 합해서 T 이상이면 가능

초기 최솟값은 max L_i, 최댓값은 max R_i
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, T;
    std::cin >> N >> T;

    int lsum = 0, rsum = 0, lmax = 0, rmax = 0;
    std::vector<std::pair<int, int>> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i].first >> seq[i].second;

        lsum += seq[i].first;
        rsum += seq[i].second;
        lmax = std::max(lmax, seq[i].first);
        rmax = std::max(rmax, seq[i].second);
    }

    if (lsum > T || rsum < T) {
        std::cout << -1;
        return 0;
    }

    int lo = lmax;
    int hi = rmax;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int sum = 0;

        for (const auto& [l, r] : seq) {
            sum += std::min(r, mid);
        }

        if (sum >= T) { // ㄱㄴ
            hi = mid;
        }
        else { // ㅂㄱㄴ
            lo = mid + 1;
        }
    }

    std::cout << lo;

    return 0;
}