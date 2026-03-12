/*
D를 B1에 다 넣고 H를 B2에 다 넣으면 서로 0개일 것. 나머지는 개수만 맞춰주면 됨

근데 둘 중 하나가 N개를 넘으면 이게 안 먹힘

KHU를 안 만들어 주면 되잖아.

d > N일 경우 k + u < N이니까

B1에 K, U를 다 넣고 나머지 자리에는 D를 채운다. 이러면 B2에는 D와 H만 들어갈 것. 양쪽 0개

h > N일 경우

B2에 K, U를 다 넣고 나머지 자리에 H를 채운다. 이러면 B1에는 D와 H만 들어갈 것.

NO는 없다
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    int N, d, h, k, u;
    while (T--) {
        std::cin >> N >> d >> h >> k >> u;
        
        int d1, h1, k1, u1, d2, h2, k2, u2; // B1, B2에서 각각 나타나는 횟수
        if (d <= N && h <= N) {
            // B1에 D 몰빵
            d1 = d;
            d2 = 0;

            // B2에 H 몰빵
            h2 = h;
            h1 = 0;

            int b1_sum = d1;
            if (k + b1_sum <= N) {
                // B1에 K를 다 넣을 수 있는 경우
                // B1에 K 몰빵. B2에는 K가 안 들어감
                k1 = k;
                k2 = 0;
            }
            else {
                // B1에 K가 다 안 들어가는 경우
                // B1의 전체 수가 N이 될 때까지 K를 채우고 나머지는 B2에 넣기
                k1 = N - b1_sum;
                k2 = k - k1;
            }

            b1_sum += k1;

            if (u + b1_sum <= N) {
                u1 = u;
                u2 = 0;
            }
            else {
                u1 = N - b1_sum;
                u2 = u - u1;
            }
        }
        else if (d > N) {
            // D가 N개보다 많이 있는 경우

            // B1에 K 몰빵
            k1 = k;
            k2 = 0;
            
            // B1에 U 몰빵
            u1 = u;
            u2 = 0;
            
            // B2에 H 몰빵
            h1 = 0;
            h2 = h;

            // B1의 남은 자리에 D 채우기고 남은 B는 B2로
            d1 = N - k1 - u1;
            d2 = d - d1;
        }
        else if (h > N) {
            k1 = 0;
            k2 = k;
            
            u1 = 0;
            u2 = u;
            
            h2 = N - k2 - u2;
            h1 = h - h2;

            d1 = d;
            d2 = 0;
        }

        std::cout << "YES\n";

        for (int i = 0; i < d1; i++) {
            std::cout << 'D';
        }
        for (int i = 0; i < h1; i++) {
            std::cout << 'H';
        }
        for (int i = 0; i < k1; i++) {
            std::cout << 'K';
        }
        for (int i = 0; i < u1; i++) {
            std::cout << 'U';
        }
        for (int i = 0; i < d2; i++) {
            std::cout << 'D';
        }
        for (int i = 0; i < h2; i++) {
            std::cout << 'H';
        }
        for (int i = 0; i < k2; i++) {
            std::cout << 'K';
        }
        for (int i = 0; i < u2; i++) {
            std::cout << 'U';
        }
        std::cout << "\n";
    }
    
    return 0;
}