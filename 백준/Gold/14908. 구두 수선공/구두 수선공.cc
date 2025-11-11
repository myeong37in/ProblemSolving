/*
a, b 작업을 비교. 각각 T_a, S_a, T_b, S_b
a를 선택하면 지불 비용 T_a * S_b, b를 선택하면 T_b * S_a 작은 쪽 선택
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    long long time, money;
    int idx;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Task> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i].time >> seq[i].money;
        seq[i].idx = i + 1;
    }

    std::sort(seq.begin(), seq.end(), [](const Task& a, const Task& b) {
        long long a_choose = a.time * b.money;
        long long b_choose = b.time * a.money;
        if (a_choose == b_choose) {
            return a.idx < b.idx;
        }
        return a_choose < b_choose;
    });

    for (int i = 0; i < N; i++) {
        std::cout << seq[i].idx << " ";
    }

    return 0;
}