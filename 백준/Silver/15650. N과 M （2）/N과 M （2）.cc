#include <iostream>
#include <vector>

int N, M;
std::vector<int> sequence;

void backtrack(int num) {
    if (sequence.size() == M) {
        for (int i = 0; i < M; i++) {
            std::cout << sequence[i] << " ";
        }
        std::cout << "\n";

        return;
    }

    for (int i = num; i <= N; i++) {
        sequence.emplace_back(i);
        backtrack(i + 1);
        sequence.pop_back(); // 마지막 숫자 선택 취소 후 다른 경우 탐색
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;

    backtrack(1);

    return 0;
}