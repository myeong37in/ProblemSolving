#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int onboard = 0, best = 0;
    int in, out;
    for (int i = 0; i < 4; i++) {
        std::cin >> out >> in;
        onboard += (in - out);
        best = std::max(best, onboard);
    }

    std::cout << best;

    return 0;
}