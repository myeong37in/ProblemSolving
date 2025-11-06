/*
전체 누적 합 - 같은 색 누적 합
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> vec(N + 1);
    std::vector<int> all_vec(N + 1), all_psum(N + 1);
    std::vector<std::vector<int>> each_vec(N + 1), each_psum(N + 1);
    int C, S;
    for (int i = 1; i <= N; i++) {
        std::cin >> C >> S;
        vec[i] = {C, S};
        all_vec[i] = S;
        each_vec[C].emplace_back(S);
    }

    for (int i = 1; i <= N; i++) {
        each_vec[i].emplace_back(0);
    }

    std::sort(all_vec.begin(), all_vec.end());
    for (int i = 1; i <= N; i++) {
        std::sort(each_vec[i].begin(), each_vec[i].end());
    }

    for (int i = 1; i <= N; i++) {
        all_psum[i] += all_psum[i - 1] + all_vec[i];
    }

    for (int i = 1; i <= N; i++) {
        int sz = each_vec[i].size();
        each_psum[i].resize(sz);
        for (int j = 1; j < sz; j++) {
            each_psum[i][j] += each_psum[i][j - 1] + each_vec[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        auto [c, s] = vec[i];

        int idx = std::lower_bound(all_vec.begin(), all_vec.end(), s) - all_vec.begin();
        int all = all_psum[idx - 1];
        idx = std::lower_bound(each_vec[c].begin(), each_vec[c].end(), s) - each_vec[c].begin();
        int same_color = each_psum[c][idx - 1];

        std::cout << all - same_color << "\n";
    }

    return 0;
}