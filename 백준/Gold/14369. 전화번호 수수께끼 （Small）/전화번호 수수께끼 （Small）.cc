/*
...예?

ZERO
ONE
TWO 
THREE
FOUR
FIVE
SIX
SEVEN
EIGHT
NINE

EIGHT
NINE

1) 알파벳이 나온 횟수를 센다
2) 각 숫자에 대해 유일하게 들어가는 알파벳과 그 개수를 찾아 전체 개수에서 뺀다
    ZERO: 유일하게 Z
    TWO: 유일하게 W
    FOUR: 유일하게 U
    SIX: 유일하게 X
3) 이제 나머지도 제할 수 있다
    ONE: 유일하게 O
    FIVE: 유일하게 F
    SEVEN: 유일하게 V
    THREE: 유일하게 R
    EIGHT: 유일하게 G
    NINE: 나머지 ㅇㅇ
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    for (int tc = 1; tc <= N; tc++) {
        std::string str;
        std::cin >> str;

        std::vector<int> alpha(26);
        std::vector<int> cnt(10); // 0-9
        for (char ch : str) {
            alpha[ch - 'A']++;
        }

        // ZERO 빼기
        cnt[0] += alpha[25];
        alpha[4] -= alpha[25];
        alpha[17] -= alpha[25];
        alpha[14] -= alpha[25];
        alpha[25] = 0;

        // TWO 빼기
        cnt[2] += alpha[22];
        alpha[19] -= alpha[22];
        alpha[14] -= alpha[22];
        alpha[22] = 0;

        // FOUR 빼기
        cnt[4] += alpha[20];
        alpha[5] -= alpha[20];
        alpha[14] -= alpha[20];
        alpha[17] -= alpha[20];
        alpha[20] = 0;

        // SIX 빼기
        cnt[6] += alpha[23];
        alpha[18] -= alpha[23];
        alpha[8] -= alpha[23];
        alpha[23] = 0;

        // ONE 빼기
        cnt[1] += alpha[14];
        alpha[13] -= alpha[14];
        alpha[4] -= alpha[14];
        alpha[14] = 0;

        // FIVE 빼기
        cnt[5] += alpha[5];
        alpha[8] -= alpha[5];
        alpha[21] -= alpha[5];
        alpha[4] -= alpha[5];
        alpha[5] = 0;

        // SEVEN 빼기
        cnt[7] += alpha[21];
        alpha[18] -= alpha[21];
        alpha[4] -= 2 * alpha[21]; // E는 두 개임
        alpha[13] -= alpha[21];
        alpha[21] = 0;

        // THREE 빼기
        cnt[3] += alpha[17];
        alpha[19] -= alpha[17];
        alpha[7] -= alpha[17];
        alpha[4] -= 2 * alpha[17]; // E는 두 개임
        alpha[17] = 0;

        // EIGHT 빼기
        cnt[8] += alpha[6];
        alpha[4] -= alpha[6];
        alpha[8] -= alpha[6];
        alpha[7] -= alpha[6];
        alpha[19] -= alpha[6];
        alpha[6] = 0;

        // NINE
        cnt[9] += alpha[4];
        alpha[13] -= 2 * alpha[4]; // N은 두 개임
        alpha[8] -= alpha[4];
        alpha[4] = 0;

        std::cout << "Case #" << tc << ": ";
        for (int i = 0; i <= 9; i++) {
            std::cout << std::string(cnt[i], i + '0');
        }
        std::cout << "\n";
    }
    
    return 0;
}