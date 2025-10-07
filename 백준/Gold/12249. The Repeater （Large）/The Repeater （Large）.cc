/*
등장 문자와 순서는 다 똑같아야 하고 평균값으로 맞춰주면 되겠는걸
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;

        std::vector<std::string> vec(N);
        for (int i = 0; i < N; i++) {
            std::cin >> vec[i];
        }

        std::vector<std::vector<char>> letters(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                if (letters[i].empty() || letters[i].back() != vec[i][j]) {
                    letters[i].emplace_back(vec[i][j]);
                }
            }
        }

        bool okay = true;
        int sz = letters[0].size();
        // 패턴 길이 검사
        for (int i = 1; i < N; i++) {
            if (letters[i].size() != sz) {
                okay = false;
                break;
            }
        }

        // 패턴 순서 검사
        for (int pos = 0; pos < sz; pos++) {
            for (int j = 1; j < N; j++) {
                if (letters[j][pos] != letters[0][pos]) {
                    okay = false;
                    break;
                }
            }

            if (!okay) {
                break;
            }
        }

        if (!okay) {
            std::cout << "Case #" << tc << ": Fegla Won\n";
            continue;
        }

        // 각 문자열에서 run length 추출
        std::vector<std::vector<int>> runs(N);
        for (int i = 0; i < N; i++) {
            const std::string& s = vec[i];
            std::vector<int> lens;
            int cnt = 1;

            for (int k = 1; k < s.size(); k++) {
                if (s[k] == s[k - 1]) {
                    cnt++;
                }
                else {
                    lens.push_back(cnt);
                    cnt = 1;
                }
            }

            lens.push_back(cnt);
            runs[i] = std::move(lens);
        }

        // 각 위치별로 중앙값에 맞추는 비용 합산
        int ans = 0;
        for (int pos = 0; pos < sz; pos++) {
            std::vector<int> col;
            for (int i = 0; i < N; i++) {
                col.push_back(runs[i][pos]);
            }

            std::sort(col.begin(), col.end());
            int med = col[N / 2];
            int cost = 0;
            for (const int& n : col) {
                cost += std::abs(n - med);
            }

            ans += cost;
        }

        std::cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}