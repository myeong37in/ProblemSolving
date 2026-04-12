/*
LCM!
*/

#include <iostream>
#include <numeric>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long a, b;
    while (n--) {
        std::cin >> a >> b;
        
        std::cout << std::lcm(a, b) << "\n";
    }

    return 0;
}