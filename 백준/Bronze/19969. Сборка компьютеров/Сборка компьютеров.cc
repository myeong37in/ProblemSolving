#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a1, a2, a3, b1, b2, b3;
    std::cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    
    int total = a1 + a2 + a3;

    // 어느 쪽에서 더 많이 남는가
    std::cout << total - std::max({0, a1 - (b1 + b3), a2 - (b2 + b3)});
    
    return 0;
}