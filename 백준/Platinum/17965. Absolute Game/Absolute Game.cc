/*
각자 자신의 수를 지우는 것이므로 선택해서 남길 수 있음

결국 Alice의 선택에 대응되는 Bob의 선택이 있을 것이고, max-min하면 될 듯
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a_seq(n), b_seq(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a_seq[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b_seq[i];
    }

    int global_best = 0;
    for (int i = 0; i < n; i++) {
        int a = a_seq[i];
        int cur_best = std::numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            int b = b_seq[j];
            cur_best = std::min(cur_best, std::abs(a - b));
        }

        global_best = std::max(global_best, cur_best);
    }

    std::cout << global_best;

    return 0;
}