/*
정렬했을 때 2개씩 봐서 차이가 D 이하여야 하는 그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, D;
    std::cin >> N >> D;

    std::vector<int> seq(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    for (int i = 0; i < N; i++) {
        int first = seq[i * 2];
        int second = seq[i * 2 + 1];

        if (second - first > D) {
            std::cout << "No";
            return 0;
        }
    }

    std::cout << "Yes";

    return 0;
}