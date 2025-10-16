/*
재귀로 풀면 되겠지.

반복 횟수(문자열)이 나오기 전 문자열 길이 + 재귀 호출(반복 횟수, 문자열)

문자열 길이 반환
*/

#include <iostream>
#include <string>

int Recursion(int rep, std::string& str) {
    int cnt = 0;
    int L = str.size();
    for (int i = 0; i < L; i++) {
        if (str[i] != '(') {
            cnt++;
        }
        else {
            cnt--;
            int next_rep = str[i - 1] - '0';

            // 열리는 괄호의 개수만큼 닫기
            int open_cnt = 1;
            int end;
            for (end = i + 1; end < L; end++) {
                if (str[end] == '(') {
                    open_cnt++;
                }
                else if (str[end] == ')') {
                    open_cnt--;
                    if (open_cnt == 0) {
                        break;
                    }
                }
            }
            std::string next_str = str.substr(i + 1, end - i - 1);

            cnt += Recursion(next_rep, next_str);
            i += next_str.size() + 1; // ')' 다음으로
        }
    }

    return cnt * rep;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;

    int ans = Recursion(1, S); // 전체 문자열을 1번 반복하는 것과 동일

    std::cout << ans;

    return 0;
}