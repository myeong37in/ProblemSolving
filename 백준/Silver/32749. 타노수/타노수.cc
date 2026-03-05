/*
그리디가 안 되는군요 허허 이런 바보같은
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, T;
    std::string S;
    std::cin >> N >> T >> S;
    
    int len = (1 << N); // S의 길이
    int sz = (1 << (N - T)); // 결과 문자열의 길이
    std::string ans;
    for (int s = 0; s < len; s += sz) {
        ans = std::max(ans, S.substr(s, sz));
    }

    std::cout << ans;
    
    return 0;
}