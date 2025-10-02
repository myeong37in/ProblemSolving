/*
deque 그리디

exchange argument긴 한데 엄밀한 증명은 생략하고
첫 자리 숫자는 앞에서부터 K + 1개 중 최댓값이어야 함
모든 접미사에 대해 동일한 논리 성립

monotone decreasing sequence가 만들어지고, 지워야 할 수가 남으면 뒤에서부터 지우면 끝
*/

#include <iostream>
#include <deque>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::string str;
    std::cin >> N >> K >> str;

    std::deque<char> deq;
    int remove_cnt = 0;
    for (const char& ch : str) {
        while (remove_cnt < K && !deq.empty() && deq.back() < ch) {
            deq.pop_back();
            remove_cnt++;
        }
        deq.push_back(ch);
    }

    while (K - remove_cnt) {
        deq.pop_back();
        remove_cnt++;
    }

    for (const char& ch : deq) {
        std::cout << ch;
    }

    return 0;
}