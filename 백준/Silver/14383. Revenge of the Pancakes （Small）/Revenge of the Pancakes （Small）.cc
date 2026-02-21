/*
인접이 다르면 뒤집어야 됨.
간단한 그리디인 듯

마지막에 -면 1회 추가
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    std::string S;
    for (int tc = 1; tc <= T; tc++) {
        std::cin >> S;

        int cnt = 0;
        for (int i = 0; i < S.size() - 1; i++) {
            if (S[i] != S[i + 1]) {
                cnt++;
            }
        }

        if (S.back() == '-') {
            cnt++;
        }

        std::cout << "Case #" << tc << ": " << cnt << "\n";
    }

    return 0;
}