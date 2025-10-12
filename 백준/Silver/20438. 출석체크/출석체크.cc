/*
입력 처리 후 간단한 누적합인 듯
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K, Q, M;
    std::cin >> N >> K >> Q >> M;
    
    std::vector<bool> students(N + 3, false), sleeping(N + 3, false);

    int n;
    for (int i = 0; i < K; i++) {
        std::cin >> n;
        sleeping[n] = true;
    }

    for (int i = 0; i < Q; i++) {
        std::cin >> n;
        if (sleeping[n]) { // 최초 받은 학생이 졸면 컷
            continue;
        }

        for (int j = n; j <= N + 2; j += n) {
            if (!sleeping[j]) {
                students[j] = true;
            }
        }
    }

    std::vector<int> psum(N + 3);
    for (int i = 3; i <= N + 2; i++) {
        psum[i] = psum[i - 1] + !students[i];
    }

    int s, e;
    for (int i = 0; i < M; i++) {
        std::cin >> s >> e;
        std::cout << psum[e] - psum[s - 1] << "\n";
    }

    return 0;
}