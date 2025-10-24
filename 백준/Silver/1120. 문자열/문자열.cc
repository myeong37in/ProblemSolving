#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string A, B;
    std::cin >> A >> B;

    int A_len = A.size();
    int B_len = B.size();
    int best = 2e9;
    for (int bi = 0; bi < B_len - A_len + 1; bi++) {
        int cur = 0;
        for (int ai = 0; ai < A_len; ai++) {
            if (A[ai] != B[bi + ai]) {
                cur++;
            }
        }

        best = std::min(best, cur);
    }

    std::cout << best;

    return 0;
}