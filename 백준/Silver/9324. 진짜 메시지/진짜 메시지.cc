#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        std::string str;
        std::cin >> str;

        int L = str.size();
        std::vector<int> alpha(26);
        bool ok = true;
        for (int i = 0; i < L; i++) {
            char ch = str[i];
            alpha[ch - 'A']++;

            if (alpha[ch - 'A'] == 3) {
                if (i + 1 >= L || str[i + 1] != ch) {
                    ok = false;
                    break;
                }

                alpha[ch - 'A'] = 0;
                i++;
            }
        }

        std::cout << (ok ? "OK\n" : "FAKE\n");
    }

    return 0;
}