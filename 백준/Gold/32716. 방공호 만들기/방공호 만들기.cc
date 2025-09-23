#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    if (N < 4) {
        std::cout << 0;
        return 0;
    }

    constexpr int MAX = 1e7;
    std::vector<long long> seq(MAX + 1);
    seq[4] = seq[5] = 1;
    seq[6] = 2;
    seq[7] = 3;
    for (int i = 8; i <= MAX; i += 4) {
        seq[i] = (i - 4) + seq[i - 4];
        seq[i + 1] = seq[i] + i / 4 - 1;
        seq[i + 2] = seq[i] + i / 4 * 2 - 1;
        seq[i + 3] = seq[i] + i / 4 * 3 - 1;
    }

    std::cout << seq[N];

    return 0;
}