/*
시뮬레이션이겠죠?

int로 될 것이고
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, v, d, t;
    std::cin >> n >> v >> d >> t;

    std::vector<int> pos(n), speed(n);
    // 문제에서 말하는 first car는 n - 1번 인덱스의 차임
    for (int i = 0; i < n; i++) {
        pos[i] = i * d;
    }
    speed[n - 1] = v;

    if (n == 1) {
        std::cout << t * v * 5; // Aㅏ
        return 0;
    }

    while (t--) {
        // 이동
        for (int i = n - 1; i >= 0; i--) {
            pos[i] += 5 * speed[i];
        }

        // 속도 변경
        // first car
        int gap = pos[n - 1] - pos[n - 2];
        if (gap > 100) {
            speed[n - 1] = std::max(0, speed[n - 1] - 5);
        }
        else if (gap < 80) {
            speed[n - 1] += 5;
        }
        
        // 나머지
        for (int i = n - 2; i >= 0; i--) {
            gap = pos[i + 1] - pos[i];

             if (gap > 100) {
                speed[i] += 5;
            }
            else if (gap < 80) {
                speed[i] = std::max(0, speed[i] - 5);
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            if (pos[i] - pos[i - 1] <= 0) {
                std::cout << -1;
                return 0;
            }
        }
    }

    std::cout << pos[n - 1] - d * (n - 1); // 최초 위치 빼기
    
    return 0;
}