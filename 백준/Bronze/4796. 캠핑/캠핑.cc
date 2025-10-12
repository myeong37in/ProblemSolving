#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int L, P, V;
    int tc = 1;
    while (std::cin >> L >> P >> V) {
        if (L == 0 && P == 0 && V == 0) {
            break;
        }

        int ans = (V / P) * L + std::min(L, V - (V / P) * P);
        std::cout << "Case " << tc << ": " << ans << "\n";

        tc++;
    }

    return 0;
}