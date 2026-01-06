/*
홀수와 짝수는 최초 동일한 개수만큼 있음

홀수 = 짝수 + 홀수
짝수 = 짝수 + 짝수 / 홀수 + 홀수

홀수 결과는 짝홀을 하나씩 소모하므로 홀수 결과의 개수만큼 전체 짝홀 개수에서 각각 제함

N에서 홀수 결과의 개수를 뺐을 때 남는 수가 홀수면 짝수 쌍, 홀수 쌍으로 모두 짝수 결과를 만들 수 없으므로 NO

나머지는 뭐.. 최소 짝수, 홀수 유지하면서 홀수 결과면 짝 + 홀로 주고 짝수 결과면 짝과 홀 중 작은 거 주면 되겠지 
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::string parities;
        std::cin >> N >> parities;

        int odd_cnt = 0;
        for (char ch : parities) {
            if (ch == 'O') {
                odd_cnt++;
            }
        }

        if ((N - odd_cnt) & 1) {
            std::cout << "NO\n";
            continue;
        }
        else {
            std::cout << "YES\n";
        }

        int min_odd = 1, min_even = 2;
        for (char ch : parities) {
            if (ch == 'O') {
                std::cout << min_odd << " " << min_even << "\n";
                min_odd += 2;
                min_even += 2;
            }
            else {
                if (min_odd >= 2 * N - 1) { // 홀수 하나 남음(짝 + 짝 강제)
                    std::cout << min_even << " " << min_even + 2 << "\n";
                    min_even += 4;
                }
                else if (min_even >= 2 * N) { // 짝수 하나 남음(홀 + 홀 강제)
                    std::cout << min_odd << " " << min_odd + 2 << "\n";
                    min_odd += 4;
                }
                else if (min_odd > min_even) { // 짝 + 짝
                    std::cout << min_even << " " << min_even + 2 << "\n";
                    min_even += 4;
                }
                else { // 홀 + 홀
                    std::cout << min_odd << " " << min_odd + 2 << "\n";
                    min_odd += 4;
                }
            }
        }
    }
    
    return 0;
}