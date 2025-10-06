/*
힌트 없었으면 난이도를 좀 더 쳐줬을 듯

2's complement의 세계는 넓다
*/

#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Q;
    std::cin >> Q;

    int a;
    while (Q--) {
        std::cin >> a;

        if ((a & (-a)) == a) {
            std::cout << "1\n";
        }
        else {
            std::cout << "0\n";
        }
    }

    return 0;
}