/*
합이 크거나 같아야 하고 합과 차의 합이 짝수여야 함
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sum, diff;
    std::cin >> sum >> diff;

    if (diff > sum || (sum - diff) & 1) {
        std::cout << -1;
        return 0;
    }

    int big = (sum + diff) / 2;
    int small = sum - big;
    std::cout << big << " " << small;

    return 0;
}