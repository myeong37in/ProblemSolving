#include <iostream>
#include <vector>

int N;
long long X;

std::vector<int> seq, prereq, state; // 0: 미방문, 1: 방문 중, 2: 완료
std::vector<long long> sumv;
std::vector<bool> okay;

static void dfs(int cur) {
    if (state[cur] == 2) {
        return;
    }

    if (state[cur] == 1) { // 사이클 형성
        okay[cur] = false;
        state[cur] = 2;
        return;
    }

    state[cur] = 1;

    if (prereq[cur] == -1) {
        sumv[cur] = seq[cur];
        okay[cur] = true;
        state[cur] = 2;
        return;
    }

    int nxt = prereq[cur];
    if (state[nxt] == 0) {
        dfs(nxt);
    }

    if (state[nxt] == 1) { // 사이클
        okay[cur] = false;
        state[cur] = 2;
        return;
    }

    if (!okay[nxt]) { // 이미 불가능한 경로
        okay[cur] = false;
        state[cur] = 2;
        return;
    }

    sumv[cur] = sumv[nxt] + seq[cur];
    okay[cur] = true;
    state[cur] = 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> X;

    seq.resize(N + 1);
    prereq.resize(N + 1);
    state.resize(N + 1);
    sumv.assign(N + 1, 0);
    okay.assign(N + 1, true);

    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> prereq[i];
    }

    for (int i = N; i >= 1; --i) {
        if (state[i] == 0) {
            dfs(i);
        }

        if (okay[i] && sumv[i] <= X) {
            std::cout << i << '\n';
            return 0;
        }
    }

    std::cout << -1 << '\n';
    return 0;
}
