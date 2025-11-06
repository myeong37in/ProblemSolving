/*
2^31...
*/

#include <iostream>
#include <unordered_map>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::unordered_map<long long, int> um;
        int T;
        std::cin >> T;
        
        for (int tc = 0; tc < T; tc++) {
            long long N;
            std::cin >> N;
            
            um[N]++;
        }

        auto it = um.begin();
        bool found = false;
        for (; it != um.end(); it++) {
            if (it->second * 2 > T) {
                found = true;
                std::cout << it->first << "\n";
                break;
            }
        }

        if (!found) {
            std::cout << "SYJKGW\n";
        }
    }

    return 0;
}