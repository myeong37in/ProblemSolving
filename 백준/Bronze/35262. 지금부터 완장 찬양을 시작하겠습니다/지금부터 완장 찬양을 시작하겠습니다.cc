#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::string str;
    std::cin >> N >> K >> str;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] == '0') {
            cnt++;

            if (cnt == K) {
                std::cout << 0;
                return 0;
            }
        }
        else {
            cnt = 0;
        }
    }

    std::cout << 1;

    return 0;
}