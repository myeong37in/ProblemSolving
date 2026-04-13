/*
지그재그 횟수 세면 되지 뭐
*/

#include <iostream>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int k, prev;
    bool increasing = false;
    int ans = 1;
    
    // 최초 증감 찾기
    std::cin >> prev;

    while (std::cin >> k) {
        if (k == prev) {
            continue;
        }
        else if (k > prev) {
            increasing = true;
        }
        else if (k < prev) {
            increasing = false;
        }
        ans++;
        prev = k;
        break;
    }

    while (std::cin >> k) {
        if (k == prev) {
            continue;
        }
        else if (k < prev && increasing) {
            increasing = false;
            ans++;
        }
        else if (k > prev && !increasing) {
            increasing = true;
            ans++;
        }
        prev = k;
    }

    std::cout << ans;
    
    return 0;
}