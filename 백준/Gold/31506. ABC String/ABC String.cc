/*
푸는 방법이야 뻔한데 이걸 어떻게 잘 구현할 것인가

ABC가 하나로 묶임. 

특정 글자까지 A, B, C의 등장 횟수를 a, b, c라고 하면 최대로 많이 등장한 문자 수 max(a, b, c)에서 최소로 등장한 문자 만큼의 부분 문자열이 필요하지만
중간에 ABC로 묶인 문자열은 처음부터 A, B, C를 받을 수 있으므로 min(a, b, c)를 빼주면 되겠다.
*/

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    int a = 0, b = 0, c = 0;
    int ans = 0;
    for (const char& ch : str) {
        if (ch == 'A') {
            a++;
        }
        else if (ch == 'B') {
            b++;
        }
        else {
            c++;
        }

        ans = std::max(ans, std::max({a, b, c}) - std::min({a, b, c}));
    }

    std::cout << ans;

    return 0;
}