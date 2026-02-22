#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    int V, E;
    while (T--) {
        std::cin >> V >> E;
        std::cout << 2 - V + E << "\n";
    }

    return 0;
}