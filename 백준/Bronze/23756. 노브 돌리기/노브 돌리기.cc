#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    int angle;
    std::cin >> angle;

    int nxt;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> nxt;
        
        int left, right;
        if (nxt >= angle) {
            right = nxt - angle;
            left = angle + (360 - nxt);
        }
        else if (nxt < angle) {
            right = (360 - angle) + nxt;
            left = angle - nxt;
        }

        if (right > left) {
            ans += left;
        }
        else {
            ans += right;
        }

        angle = nxt;
    }

    std::cout << ans;
    
    return 0;
}