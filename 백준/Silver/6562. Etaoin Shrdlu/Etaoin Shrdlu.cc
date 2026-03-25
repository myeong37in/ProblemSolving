/*
요구하는 게 많음
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iomanip>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        std::cin.ignore();

        std::unordered_map<std::string, int> um;
        std::string line;
        std::string sample;
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, line);
            sample += line;
        }

        
        for (int i = 0; i < sample.size() - 1; i++) {
            um[sample.substr(i, 2)]++;
        }
            
        int total = sample.size() - 1; // 쌍 개수

        std::vector<std::pair<std::string, int>> seq(um.begin(), um.end());
        std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                // 사전 순
                return a.first < b.first;
            }
            // 빈도 순
            return a.second > b.second;
        });

        for (int i = 0; i < 5; i++) {
            if (seq.size() <= i) {
                break;
            }
            std::cout << seq[i].first << " " << seq[i].second << " " << std::fixed << std::setprecision(6) << static_cast<double>(seq[i].second) / total << "\n";
        }

        std::cout << "\n";
    }
    
    return 0;
}