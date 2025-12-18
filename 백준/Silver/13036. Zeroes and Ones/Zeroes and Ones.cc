/*
중간 순서를 바꿔도 각 자리의 문자가 뒤집히는 횟수는 변하지 않으므로 결과는 같음

그러면 앞에서부터 바꾸면 되겠군

1080번이랑 비슷한 문제인 듯?
*/

#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::string first, second;
        std::cin >> n >> first >> second;

        std::unordered_map<char, char> um;
        um['0'] = '1';
        um['1'] = '0';
        
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (first[i] != second[i]) {
                first[i] = um[first[i]];
                first[i + 1] = um[first[i + 1]];
                cnt++;
            }
        }

        if (first[n - 1] != second[n - 1]) {
            std::cout << "-1\n";
        }
        else {
            std::cout << cnt << "\n";
        }
    }

    return 0;
}