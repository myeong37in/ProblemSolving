/*
C(100, 50)이 1e29네

int128_t 쓰면 될 듯
*/

#include <iostream>
#include <string>

static inline __int128_t GetComb(int n, int m) {
    __int128_t res = 1;
    for (int i = m + 1; i <= n; i++) {
        res *= i;
        res /= (i - m);
    }

    return res;
}

static inline void PrintRes(__int128_t num) {
    std::string str;
    while (num) {
        str += '0' + num % 10;
        num /= 10;
    }

    for (int i = str.size() - 1; i >= 0; i--) {
        std::cout << str[i];
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    __int128_t res = GetComb(n, m);

    PrintRes(res);

    return 0;
}