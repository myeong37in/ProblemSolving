/*
메모리 풀 방식의 양방향 원형 연결 리스트 구현을 연습해 봅시다.
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    constexpr int MAX = 1e6;
    std::vector<int> nxt(MAX + 1), prv(MAX + 1);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> orig(N);
    for (int i = 0; i < N; i++) {
        std::cin >> orig[i];
    }

    for (int i = 0; i < N; i++) {
        nxt[orig[i]] = orig[(i + 1) % N];
        prv[orig[i]] = orig[(i - 1 + N) % N];
    }

    std::string op;
    int a, b;   
    for (int i = 0; i < M; i++) {
        std::cin >> op;
        if (op == "BN") {
            std::cin >> a >> b;
            int c = nxt[a];
            std::cout << c << "\n";
            
            // a - b - c 연결
            nxt[a] = b; prv[b] = a;
            nxt[b] = c; prv[c] = b;
        }
        else if (op == "BP") {
            std::cin >> a >> b;
            int c = prv[a];
            std::cout << c << "\n";

            // c - b - a 연결
            prv[a] = b; nxt[b] = a;
            prv[b] = c; nxt[c] = b;
        }
        else if (op == "CN") {
            std::cin >> a;
            int b = nxt[a];
            std::cout << b << "\n";
            int c = nxt[b];

            // a - b - c -> a - c
            nxt[a] = c; prv[c] = a;
        }
        else {
            std::cin >> a;
            int b = prv[a];
            std::cout << b << "\n";
            int c = prv[b];

            // c - b - a -> c - a
            prv[a] = c; nxt[c] = a;
        }
    }
    
    return 0;
}