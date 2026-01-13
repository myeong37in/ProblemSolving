/*
누적 합 이용해서 O(N)
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::string str;
    std::cin >> N >> str;

    std::vector<int> A_pos, N_psum(N);
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            N_psum[i] = N_psum[i - 1];
        }

        if (str[i] == 'A') {
            A_pos.emplace_back(i);
        }
        else if (str[i] == 'N') {
            N_psum[i]++;
        }
    }

    int ans = 0, sz = A_pos.size();
    if (sz <= 1) {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i < sz - 1; i++) {
        // A 사이에 N이 하나만 있으면 됨
        if (N_psum[A_pos[i + 1]] - N_psum[A_pos[i]] == 1) {
            ans++;
        }
    }

    std::cout << ans;
    
    return 0;
}