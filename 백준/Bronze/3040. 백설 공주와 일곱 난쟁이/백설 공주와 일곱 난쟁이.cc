#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> seq(9);
    for (int i = 0; i < 9; i++) {
        std::cin >> seq[i];
    }

    std::vector<int> selected(9);
    for (int i = 8; i > 1; i--) {
        selected[i] = 1;
    }

    do {
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            sum += seq[i] * selected[i];
        }

        if (sum == 100) {
            for (int i = 0; i < 9; i++) {
                if (selected[i]) {
                    std::cout << seq[i] << "\n";
                }
            }
            
            break;
        }
    } while(std::next_permutation(selected.begin(), selected.end()));

    return 0;
}