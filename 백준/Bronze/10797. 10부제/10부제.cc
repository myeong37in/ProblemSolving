#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> dat(11);
    int date, n;
    std::cin >> date;

    for (int i = 0; i < 5; i++) {
        std::cin >> n;
        dat[n]++;
    }

    std::cout << dat[date];

    return 0;
}