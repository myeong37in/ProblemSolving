#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, V;
    std::cin >> N >> M >> V;

    std::vector<int> in_cycle(N - V + 1); // 사이클에 포함되는 수
    std::vector<int> out_of_cycle(V - 1); // 루트 포함 사이클 바깥의 수

    for (int i = 0; i < V - 1; i++) {
        std::cin >> out_of_cycle[i];
    }
    for (int i = 0; i < N - V + 1; i++) {
        std::cin >> in_cycle[i];
    }

    int K;
    for (int i = 0; i < M; i++) {
        std::cin >> K;

        if (K <= V - 2) { // 사이클 안 들어감
            std::cout << out_of_cycle[K] << "\n";
        }
        else {
            int moves = K - V + 1;
            std::cout << in_cycle[moves % (N - V + 1)] << "\n"; 
        }
    }

    return 0;
}