/*
1000원을 다 먹고 4000원씩 더 먹으면 된다. 인정?
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, X;
    std::cin >> N >> X;

    std::vector<int> vec(N);
    int ans = 0;
    int five_cheon_won, cheon_won;
    for (int i = 0; i < N; i++) {
        std::cin >> five_cheon_won >> cheon_won;
        ans += cheon_won;
        vec[i] = five_cheon_won - cheon_won;
        X -= 1000;
    }

    std::sort(vec.begin(), vec.end(), std::greater<int>());
    for (const int& n : vec) {
        if (n <= 0) { // 5천원을 먹는 게 손해면 끝
            break;
        }

        if (X >= 4000) {
            X -= 4000;
            ans += n;
        }
        else { // 돈 없어
            break;
        }
    }

    std::cout << ans;

    return 0;
}