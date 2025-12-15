/*
이전 값만큼 건너뛰기
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::vector<int> ans(N);
    int cnt = 1;
    int from = 0;
    ans[0] = seq[0];
    while (cnt < N) {
        from = (from + seq[cnt - 1]) % N;
        while (ans[from] != 0) {
            from = (from + 1) % N;
            continue;
        }
        
        ans[from] = seq[cnt++];
    }

    std::cout << N << "\n";
    for (int n : ans) {
        std::cout << n << " ";
    }

    return 0;
}