/*
2-SAT인데... 완전 탐색이겠죠?
*/

#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> clauses;

static bool backtrack(int num, int selected, int N) {
    if (num == N + 1) {
        bool okay = true;
        for (auto [a, b] : clauses) {
            if (a < 0 && b < 0) {
                okay = !(selected & (1 << (-a))) | !(selected & (1 << (-b)));
            }
            else if (a < 0 && b > 0) {
                okay = !(selected & (1 << (-a))) | (selected & (1 << b));
            }
            else if (a > 0 && b < 0) {
                okay = (selected & (1 << a)) | !(selected & (1 << (-b)));
            }
            else {
                okay = (selected & (1 << a)) | (selected & (1 << b));
            }

            if (okay == false) {
                return false;
            }   
        }

        return true;
    }

    if (backtrack(num + 1, selected | (1 << num), N)) {
        return true;
    }
    
    if (backtrack(num + 1, selected, N)) {
        return true;
    }

    return false;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    clauses.resize(M);
    for (int i = 0; i < M; i++) {
        std::cin >> clauses[i].first >> clauses[i].second;
    }

    if (backtrack(1, 1, N)) { // selected = 1로 놓는 건 그냥.. 디버깅하기 편하라고
        std::cout << 1;
    }
    else {
        std::cout << 0;
    }

    return 0;
}