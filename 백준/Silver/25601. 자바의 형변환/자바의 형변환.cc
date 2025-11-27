/*
단방향 그래프로 두고 경로가 있으면 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> str_to_id;

std::vector<std::vector<int>> graph;

static bool dfs(int cur, int target) {
    if (cur == target) {
        return true;
    }

    for (int next : graph[cur]) {
        if (dfs(next, target)) {
            return true;
        }
    }
    
    return false;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string A, B;

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> A >> B;
        if (str_to_id.find(A) == str_to_id.end()) {
            str_to_id[A] = cnt++;
        }
        if (str_to_id.find(B) == str_to_id.end()) {
            str_to_id[B] = cnt++;
        }
        graph.resize(cnt);

        graph[str_to_id[A]].emplace_back(str_to_id[B]);
    }

    std::cin >> A >> B;
    if (dfs(str_to_id[A], str_to_id[B]) || dfs(str_to_id[B], str_to_id[A])) {
        std::cout << 1;
    }
    else {
        std::cout << 0;
    }

    return 0;
}