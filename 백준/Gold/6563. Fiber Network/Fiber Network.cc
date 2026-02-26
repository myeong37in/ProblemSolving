/*
최대 26개의 그래프에 대해 floyd-warshall하면 26 * 200^3인데,

각 회사를 하나의 bit로 보면 1->3일 때 1->2와 2->3의 간선 값을 AND 연산하면 1->3이 되는 회사 목록 나옴

각 경로에 대해 결과를 OR하면 되겠군. O(n^3)
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    while (true) {
        int n;
        std::cin >> n;

        if (n == 0) {
            break;
        }

        std::vector<std::vector<int>> adj(n + 1, std::vector<int> (n + 1));
        int u, v;
        std::string companies;
        while (true) {
            std::cin >> u >> v;
            if (u == 0 && v == 0) {
                break;
            }
            std::cin >> companies;

            int mask = 0;
            for (char ch : companies) {
                mask |= (1 << (ch - 'a'));
            }

            adj[u][v] = mask;
        }

        for (int m = 1; m <= n; m++) {
            for (int s = 1; s <= n; s++) {
                for (int e = 1; e <= n; e++) {
                    adj[s][e] = adj[s][e] | (adj[s][m] & adj[m][e]);
                }
            }
        }

        while (true) {
            std::cin >> u >> v;
            if (u == 0 && v == 0) {
                break;
            }

            int mask = adj[u][v];
            if (mask == 0) {
                std::cout << "-\n";
                continue;
            }

            for (int pos = 0; pos < 26; pos++) {
                if (mask & (1 << pos)) {
                    std::cout << static_cast<char>(pos + 'a');
                }
            }
            std::cout << "\n";
        }

        std::cout << "\n";
    }
    
    return 0;
}