/*
재귀
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> ans;

std::vector<int> seq;

void Recursion(int left, int right, int depth) {
    ans[depth].emplace_back(seq[(left + right) / 2]);

    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;
    Recursion(left, mid - 1, depth + 1);
    Recursion(mid + 1, right, depth + 1);
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K;
    std::cin >> K;

    int total = (1 << K ) - 1;
    seq.resize(total);
    for (int i = 0; i < total; i++) {
        std::cin >> seq[i];
    }

    ans.resize(K);
    Recursion(0, total - 1, 0);

    for (int i = 0; i < K; i++) {
        for (int n : ans[i]) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }

    return 0;
}