/*
log2 = 0.3010
10^13 = 대충 2^40이고

MSB의 비트 수 + 하위 비트 수 하면 되겠는데
+로 bit 추가, *로 bit left shift

홀수는 2N을 만들고 [/]를 해야 함
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    std::cin >> N;

    bool is_odd = false;
    if (N & 1) {
        is_odd = true;
        N <<= 1;
    }

    std::vector<int> bit_pos;
    while (N) {
        int MSB = 63 - __builtin_clzll(N);
        bit_pos.emplace_back(MSB);
        N &= ~(1LL << MSB);
    }

    std::cout << bit_pos[0] + bit_pos.size() - 1 + (is_odd) << "\n";
    int idx = 0;
    for (int i = bit_pos[0]; i >= 1; i--) {
        if (idx < bit_pos.size() && bit_pos[idx] == i) { // bit가 나오면 [+]로 bit 만들기
            std::cout << "[+] ";
            idx++;
        }

        if (i > 1) { // 항상 left shift
            std::cout << "[*] ";
        }
    }

    if (is_odd) {
        std::cout << "[/]";
    }

    return 0;
}