#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    int bundle_cheapest = 2e9, separate_cheapest = 2e9;
    int bundle, separate;
    for (int i = 0; i < M; i++) {
        std::cin >> bundle >> separate;
        bundle_cheapest = std::min(bundle_cheapest, bundle);
        separate_cheapest = std::min(separate_cheapest, separate);
    }

    if (separate_cheapest * 6 <= bundle_cheapest) { // 낱개가 더 쌈
        std::cout << N * separate_cheapest;
    }
    else {
        // 묶음 + 낱개 vs 묶음
        std::cout << std::min(bundle_cheapest * (N / 6) + separate_cheapest * (N % 6), bundle_cheapest * (1 + (N / 6)));
    }
    
    return 0;
}