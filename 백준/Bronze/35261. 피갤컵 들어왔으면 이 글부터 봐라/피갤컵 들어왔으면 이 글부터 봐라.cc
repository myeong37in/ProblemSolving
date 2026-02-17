#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string str;

    std::cin >> N >> str;

    std::string target = "eagle";

    int best = 5;
    for (int i = 0; i <= N - 5; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            if (str[i + j] != target[j]) {
                cnt++;
            }
        }

        best = std::min(best, cnt);
    }

    std::cout << best;

    return 0;
}