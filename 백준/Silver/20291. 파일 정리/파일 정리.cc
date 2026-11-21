#include <iostream>
#include <string>
#include <map>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::map<std::string, int> mp;

    std::string filename;
    for (int i = 0; i < N; i++) {
        std::cin >> filename;
        int pos = filename.find('.');
        mp[filename.substr(pos + 1, std::string::npos)]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        std::cout << it->first << " " << it->second << "\n";
    }

    return 0;
}