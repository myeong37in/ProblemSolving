/*
완탐이 아니었다니

어떤 수가 네 번 나올 수가 없네. 인정
*/

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // int N;
    // std::cin >> N;

    // std::string seq = "1";
    // for (int i = 0; i < N - 1; i++) {
    //     std::string next;
    //     int len = seq.size();
    //     char prev = '1'; // 첫 번째 항은 항상 1
    //     int cnt = 1;
    //     for (int j = 1; j < len; j++) {
    //         if (seq[j] == prev) {
    //             cnt++;
    //         }
    //         else {
    //             next += prev;
    //             next += cnt + '0';

    //             cnt = 1;
    //         }
    //         prev = seq[j];
    //     }

    //     // 마지막 문자 반영
    //     next += seq[len - 1];
    //     next += cnt + '0';

    //     std::swap(seq, next);
    // }

    // std::cout << *std::max_element(seq.begin(), seq.end()) - '0';

    int N;
    std::cin >> N;

    if (N <= 2) {
        std::cout << 1;
    }
    else if (N <= 5) {
        std::cout << 2;
    }
    else {
        std::cout << 3;
    }

    return 0;
}