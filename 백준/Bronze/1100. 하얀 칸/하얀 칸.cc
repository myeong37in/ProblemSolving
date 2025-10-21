#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    int cnt = 0;
    for (int r = 0; r < 8; r++) {
        std::cin >> line;
        for (int c = 0; c < 8; c++) {
            if (((r + c) & 1) == 0 && line[c] == 'F') {
                cnt++;
            }
        }
    }

    std::cout << cnt;

    return 0;
}