/*
대충 pq 쓰면 O((N + M) log (N + M))일 것이라는 주석
*/

#include <iostream>
#include <queue>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> seq, changed;
    std::vector<int> val(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> val[i];
        seq.push({val[i], i});
    }

    int M, op;
    std::cin >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> op;
        if (op == 1) {
            int i, v;
            std::cin >> i >> v;
            changed.push({val[i], i});
            val[i] = v;
            seq.push({val[i], i});
        }
        else {
            while (!changed.empty() && seq.top() == changed.top()) {
                seq.pop();
                changed.pop();
            }
            std::cout << seq.top().second << "\n";
        }
    }

    return 0;
}