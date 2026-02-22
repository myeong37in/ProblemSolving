/*
dists[i]: i에서 시작해 최대 횟수

여긴 음수가 없으니 K까지로 해도 되겠군
*/

#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, K;
    std::cin >> A >> K;

    std::vector<int> dists(K + 1, -1);

    std::queue<int> q;
    q.push(A);
    dists[A] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            std::cout << dists[cur];
            return 0;
        }

        if (cur + 1 <= K && dists[cur + 1] == -1) {
            dists[cur + 1] = dists[cur] + 1;
            q.push(cur + 1);
        }

        if (cur * 2 <= K &&  dists[cur * 2] == -1) {
            dists[cur * 2] = dists[cur] + 1;
            q.push(cur * 2);
        }
    }

    return 0;
}