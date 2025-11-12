/*
사이클의 길이를 다 합쳐도 최대 20만이니 DFS로 보면 될 듯
*/

#include <iostream>
#include <vector>

int N;
long long X;

std::vector<int> seq, prereq;
std::vector<bool> visited;

long long sum = 0;
static bool dfs(int cur) {
    sum += seq[cur];
    visited[cur] = true;

    if (sum > X) {
        return false;
    }

    if (prereq[cur] == -1) { // path 끝
        return true;
    }
    
    if (!visited[prereq[cur]]) {
        return dfs(prereq[cur]);
    }

    return false; // cycle 이루면 불가능
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> X;

    seq.resize(N + 1);
    prereq.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> prereq[i];
    }

    for (int i = N; i >= 1; i--) {
        if (!visited[i]) {
            sum = 0;
            if (dfs(i)) {
                std::cout << i;
                return 0;
            }
            else {
                std::fill(visited.begin(), visited.end(), false);
            }
        }
    }

    std::cout << -1;

    return 0;
}