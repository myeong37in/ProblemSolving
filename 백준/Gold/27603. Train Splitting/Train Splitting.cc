/*
구상

mesh형이 아닐 때
    연결된 노선의 수가 n - 1이 아닌(모든 도시를 연결하지 않는) 도시 x에 속한 모든 간선을 회사 1에, 나머지를 회사 2에 주기
    회사 1은 연결되지 않은 도시가 최소 1개 있고 회사 2는 도시 x에 연결 안 됨

mesh형일 때
    회사 3개를 잡고 임의 도시 y를 잡아서 y와 연결되는 노선 n - 2개는 회사 1에, 나머지 하나는 회사 2에 주고 그 외의 모든 노선을 회사 3에 준다.
    어느 회사 단독으로는 모든 도시 연결 불가능
    mesh형이므로 임의의 두 회사 합치면 모든 도시 연결
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::pair<int, int>> edges(m);
        std::vector<int> degrees(n + 1);

        int s, e;
        for (int i = 0; i < m; i++) {
            std::cin >> s >> e;
            if (s > e) { // 편의성
                std::swap(s, e);
            }

            edges[i] = {s, e};
            degrees[s]++;
            degrees[e]++;
        }

        bool is_mesh = true;
        int city = -1;
        for (int i = 1; i <= n; i++) {
            if (degrees[i] != n - 1) {
                is_mesh = false;
                city = i;
                break;
            }
        }

        int k;
        if (is_mesh) {
            std::cout << "3\n";

            // 1번 도시가 기준, 1-(n이 아닌 도시) 간선은 1번 회사에, 1-n 간선은 2번 회사에, 나머지는 3번 회사에
            for (auto& [s, e] : edges) {
                if (s == 1) {
                    if (e != n) {
                        std::cout << "1 ";
                    }
                    else {
                        std::cout << "2 ";
                    }
                }
                else {
                    std::cout << "3 ";
                }
            }
        }
        else {
            std::cout << "2\n";
            for (auto& [s, e] : edges) {
                if (s == city || e == city) {
                    std::cout << "1 ";
                }
                else {
                    std::cout << "2 ";
                }
            }
        }
        std::cout << "\n";
    }
    
    return 0;
}