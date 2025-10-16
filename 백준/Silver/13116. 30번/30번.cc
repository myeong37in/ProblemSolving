/*
어떤 수의 자식은 x2, x2 + 1

거꾸로 올라가면 짝수는 /2, 홀수는 -1 후 /2

같아질 때까지 LSB를 하나씩 제거하면 되겠군
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    int a, b;
    while (T--) {
        std::cin >> a >> b;

        while (a != b) {
            if (a > b) {
                a >>= 1;
            }
            else {
                b >>= 1;
            }
        }

        std::cout << a * 10 << "\n";
    }

    return 0;
}