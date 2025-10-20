#include <iostream>
#include <unordered_set>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        
        std::unordered_set<int> us;
        int n;
        for (int i = 0; i < N; i++) {
            std::cin >> n;
            us.insert(n);
        }

        int M;
        std::cin >> M;
        for (int i = 0; i < M; i++) {
            std::cin >> n;
            std::cout << (us.find(n) != us.end()) << "\n";
        }
    }

    return 0;
}