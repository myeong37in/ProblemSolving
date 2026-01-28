#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string c, s;
    std::cin >> c >> s;

    int L = c.size();
    int idx = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c[idx]) {
            idx++;
        }

        if (idx == L) {
            idx = 0;
            cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}