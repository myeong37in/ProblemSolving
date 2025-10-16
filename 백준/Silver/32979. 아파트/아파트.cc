#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, T;
    std::cin >> N >> T;

    std::vector<int> seq(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        std::cin >> seq[i];
    }

    int b;
    int bottom = 0;
    for (int i = 0; i < T; i++) {
        std::cin >> b;

        int next = (bottom + b - 1) % (2 * N);
        std::cout << seq[next] << " ";
        bottom = next;
    }

    return 0;
}