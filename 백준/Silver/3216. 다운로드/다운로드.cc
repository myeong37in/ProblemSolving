/*
벌어놓은 시간 - 다운로드 시간 < 0이면 그만큼 추가. 0보다 크거나 같으면 빼기
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    int left = 0;
    int ans = 0;
    int D, V;
    for (int i = 0; i < N; i++) {
        std::cin >> D >> V;

        ans += std::max(0, V - left);
        left = std::max(left - V, 0) + D;
    }

    std::cout << ans;

    return 0;
}