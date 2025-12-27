#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int sum = a + b + c + d;
    std::cout << sum / 60 << "\n" << sum % 60;

    return 0;
}