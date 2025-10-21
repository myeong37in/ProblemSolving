#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, new_score, P;
    std::cin >> N >> new_score >> P;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    int pos = std::upper_bound(seq.begin(), seq.end(), new_score, std::greater<int>()) - seq.begin(); // 대체될 위치

    if (pos >= P) {
        std::cout << -1;
        return 0;
    }

    seq.insert(seq.begin() + pos, new_score);
    auto it = std::lower_bound(seq.begin(), seq.end(), new_score, std::greater<int>()); // 해당 점수가 처음 나오는 위치(등수 인덱스)
    std::cout << it - seq.begin() + 1;

    return 0;
}