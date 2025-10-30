/*
평범하군요
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string first;
    std::cin >> first;

    std::vector<int> first_alpha(26);
    for (const char& ch : first) {
        first_alpha[ch - 'A']++;
    }

    std::string str;
    int cnt = 0;
    for (int t = 0; t < N - 1; t++) {
        std::cin >> str;

        std::vector<int> alpha(26);
        for (const char& ch : str) {
            alpha[ch - 'A']++;
        }

        bool all_same = true;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] != first_alpha[i]) {
                all_same = false;
                break;
            }
        }

        // 같은 구성
        if (all_same) {
            cnt++;
            continue;
        }

        // 글자 하나를 더해 같은 구성이 되는지 확인
        bool found = false;
        for (int c = 0; c < 26; c++) {
            alpha[c]++;
            bool okay = true;
            for (int i = 0; i < 26; i++) {
                if (alpha[i] != first_alpha[i]) {
                    okay = false;
                    break;
                }
            }

            if (okay) {
                found = true;
                break;
            }

            alpha[c]--; // 원복
        }

        if (found) {
            cnt++;
            continue;
        }

        // 글자 하나를 빼 같은 구성이 되는지 확인
        for (int c = 0; c < 26; c++) {
            if (alpha[c] == 0) {
                continue;
            }
            alpha[c]--;

            bool okay = true;
            for (int i = 0; i < 26; i++) {
                if (alpha[i] != first_alpha[i]) {
                    okay = false;
                    break;
                }
            }

            if (okay) {
                found = true;
                break;
            }

            alpha[c]++; // 원복
        }

        if (found) {
            cnt++;
            continue;
        }

        // 글자 하나를 교체해 같은 구성이 되는지 확인
        for (int c = 0; c < 26; c++) {
            if (alpha[c] == 0) {
                continue;
            }
            alpha[c]--;
            
            // 중복 탐색이 있긴 하지만 원체 작으니 괜찮을 것
            bool out_okay = false;
            for (int nc = 0; nc < 26; nc++) {
                if (c == nc) {
                    continue;
                }

                bool in_okay = true;
                alpha[nc]++;
                for (int i = 0; i < 26; i++) {
                    if (alpha[i] != first_alpha[i]) {
                        in_okay = false;
                        break;
                    }
                }

                if (in_okay) {
                    out_okay = true;
                    break;
                }

                alpha[nc]--;
            }

            if (out_okay) {
                found = true;
                break;
            }

            alpha[c]++;
        }

        if (found) {
            cnt++;
            continue;
        }
    }

    std::cout << cnt;

    return 0;
}