/*
그리디, 카운팅 

unordered_map에 a에 나온 수는 그대로 넣고 b에 나온 수는 음수로 넣으면 중복, 개수 확인 가능할 듯

O(N)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<int> seq_a(N), seq_b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq_a[i];
    }
    
    for (int i = 0; i < N; i++) {
        std::cin >> seq_b[i];
    }

    std::unordered_map<int, int> um;
    for (int i = 0; i < N; i++) {
        if (um.find(-seq_a[i]) != um.end()) {
            if (--um[-seq_a[i]] == 0) {
                um.erase(-seq_a[i]);
            }
        }
        else {
            um[seq_a[i]]++;
        }

        if (um.find(seq_b[i]) != um.end()) {
            if (--um[seq_b[i]] == 0) {
                um.erase(seq_b[i]);
            }
        }
        else {
            um[-seq_b[i]]++;
        }

        std::cout << seq_b[i] << " ";
        if (um.empty() && i != N - 1) {
            std::cout << "# ";
        }
    }
    
    return 0;
}