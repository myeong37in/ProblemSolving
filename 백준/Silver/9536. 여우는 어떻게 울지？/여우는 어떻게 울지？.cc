/*
딱히 unordered_set보다 나은 풀이가 떠오르지 않음

파싱이 주제인 문제인 듯
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        std::cin.ignore();
        std::string line;
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::vector<std::string> vec;
        std::string str;
        while (ss >> str) {
            vec.emplace_back(str);
        }        

        std::string animal, goes, sound, dummy;
        std::unordered_set<std::string> us;
        while (std::cin >> animal >> goes >> sound) {
            if (animal == "what") {
                std::cin >> dummy >> dummy; // fox say?
                break;
            }
            us.insert(sound);
        }

        for (const auto& s : vec) {
            if (us.find(s) == us.end()) {
                std::cout << s << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}