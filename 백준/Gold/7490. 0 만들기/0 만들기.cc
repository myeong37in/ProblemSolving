/*
구-현 반드시 라이브러리 없이 
*/

#include <iostream>

int N;

static void Calc(char cur, int idx, char (&ops)[20]) {
    if (static_cast<int>(cur - '0') > N) {
        ops[idx] = '\0';
        
        int res = 0, i = 1, cur = 1; // res: 계산 결과, i: 배열 인덱스, cur: 현재 계산 대상인 수
        bool add = true, sub = false;
        while (i < idx) {
            if (ops[i] == ' ') {
                i++;
                continue;
            }

            if (ops[i] >= '0') {
                cur = cur * 10 + static_cast<int>(ops[i] - '0');
            }
            else {
                // 연산자가 나타나는 경우 cur의 끝
                if (add) {
                    res += cur;
                    add = false;
                }
                else if (sub) {
                    res -= cur;
                    sub = false;
                }
                
                cur = 0;
                
                if (ops[i] == '+') {
                    add = true;
                }
                else if (ops[i] == '-') {
                    sub = true;
                }
            }

            i++;
        }

        // 마지막 남은 수 처리
        if (add) {
            res += cur;
        }
        else if (sub) {
            res -= cur;
        }

        if (res == 0) {
            std::cout << ops << "\n";
        }

        return;
    }

    // 공백
    ops[idx] = ' ';
    ops[idx + 1] = cur;
    Calc(cur + 1, idx + 2, ops);

    // '+'
    ops[idx] = '+';
    ops[idx + 1] = cur;
    Calc(cur + 1, idx + 2, ops);

    // '-'
    ops[idx] = '-';
    ops[idx + 1] = cur;
    Calc(cur + 1, idx + 2, ops);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    while (T--) {
        std::cin >> N;

        char ops[20];
        ops[0] = '1';

        Calc('2', 1, ops);

        std::cout << "\n";
    }
    
    return 0;
}