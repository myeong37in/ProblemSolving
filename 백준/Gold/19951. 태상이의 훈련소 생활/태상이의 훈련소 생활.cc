/*
lazy가 아니었네
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> seq(N + 1), diff(N + 2);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }
    
    int a, b, k;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b >> k;
        diff[a] += k;
        diff[b + 1] -= k;
    }

    std::vector<int> diff_psum(N + 1);
    for (int i = 1; i <= N; i++) {
        diff_psum[i] = diff_psum[i - 1] + diff[i];
        std::cout << seq[i] + diff_psum[i] << " ";
    }

    return 0;
}