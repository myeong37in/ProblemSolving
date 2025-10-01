#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string target;
    std::cin >> target;

    int N = target.size();
    std::vector<bool> used(N, false); // used[i] = true면 target[i]를 사용함
    std::vector<int> used_idx; // target에서 사용한 인덱스들 벡터

    std::string ans;
    while (ans.size() < N) {
        std::string cur(ans.size() + 1, 'Z'); // 사전 순으로 맨 뒤인 "ZZZZZ...ZZZ"를 만들고 찾기
        int cur_use_idx = -1, best_pos = -1;
        for (int i = 0; i < N; i++) {
            if (used[i] == false) {
                std::string next;
                // 이분 탐색으로 위치 찾아서 넣어보기
                int pos = std::upper_bound(used_idx.begin(), used_idx.end(), i) - used_idx.begin();
                next += ans.substr(0, pos);
                next += target[i];
                next += ans.substr(pos, std::string::npos);

                if (cur >= next) {
                    cur = next;
                    cur_use_idx = i;
                    best_pos = pos;
                }
            }
        }

        ans = cur;
        used[cur_use_idx] = true;
        used_idx.insert(used_idx.begin() + best_pos, cur_use_idx);
        std::cout << ans << "\n";
    }

    return 0;
}