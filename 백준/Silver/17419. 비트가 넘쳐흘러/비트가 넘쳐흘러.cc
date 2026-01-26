/*
K-(K&((~K)+1))

비트 반전 후 + 1은 2의 보수이므로 -K를 만듦

K & -K는 1인 가장 하위 bit에 대해 100...을 만듦.

K에서 이 수를 빼면 1인 가장 하위 bit가 꺼짐

그럼 결국 1인 bit의 수가 되겠군. O(N)
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::string str;
    std::cin >> N >> str;

    int cnt = 0;
    for (char ch : str) {
        cnt += ch - '0';
    }

    std::cout << cnt;
    
    return 0;
}