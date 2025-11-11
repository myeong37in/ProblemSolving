/*
투 포인터로 O(N) 비교인 듯
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seq[i];
    }

    int left = 0, right = 1;
    int best = -1;
    int prev = seq[left];
    while (right < n) {
        if (seq[right] == prev) { // not mountainous
            left = right;
        }
        else if (seq[right] < prev) {
            bool okay = true;
            if (right - left <= 1) {
                left = right;
                prev = seq[right++];
                continue;
            }

            int mirror = right - 2;
            while (mirror >= left && right < n) { // 팰린드롬 체크
                if (seq[mirror] != seq[right]) {
                    okay = false;
                    break;
                }
                mirror--;
                right++;
            }

            right--; // 초과 방지
            if (okay) {
                best = std::max(best, right - left + 1);
            }
            
            left = right;
        }

        prev = seq[right++];
    }

    std::cout << best;

    return 0;
}