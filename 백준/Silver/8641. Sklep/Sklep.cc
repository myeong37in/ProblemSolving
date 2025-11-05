/*
순서 보장
*/

#include <iostream>
#include <vector>
#include <unordered_map>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq;
    std::unordered_map<int, int> um;

    int A, S;
    for (int i = 0; i < N; i++) {
        std::cin >> A >> S;
        seq.emplace_back(A);
        um[A] += S;
    }

    std::cout << um.size() << "\n";

    // 이러면 되긴 하는데
    for (int i = 0; i < N; i++) {
        int cur = seq[i];
        if (um.find(cur) == um.end()) {
            continue;
        }
        
        std::cout << cur << " " << um[cur] << "\n";
        um.erase(cur);
    }

    return 0;
}