#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    std::vector<int> psum(N);
    psum[0] = seq[0];
    for (int i = 1; i < N; i++) {
        psum[i] = psum[i - 1] + seq[i];
    }

    int L, R;
    for (int i = 0; i < Q; i++) {
        std::cin >> L >> R;

        if (L != 1) {
            std::cout << psum[R - 1] - psum[L - 2] << "\n";
        }
        else {
            std::cout << psum[R - 1] << "\n";
        }
    }

    return 0;
}