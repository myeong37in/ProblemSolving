#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    
    std::vector<int> psum(N + 2); // Yes인 답의 누적 합
    psum[1] = 1;

    int op, x, y;
    for (int i = 2; i <= N + 1; i++) {
        psum[i] = psum[i - 1];
        std::cin >> op >> x >> y;
        int ans = psum[y] - psum[x - 1];
        if (op == 1) {
            if (ans == y - x + 1) {
                std::cout << "Yes\n";
                psum[i]++;
            }
            else {
                std::cout << "No\n";
            }
        }
        else {
            if (ans == 0) {
                std::cout << "Yes\n";
                psum[i]++;
            }
            else {
                std::cout << "No\n";
            }
        }
    }

    return 0;
}