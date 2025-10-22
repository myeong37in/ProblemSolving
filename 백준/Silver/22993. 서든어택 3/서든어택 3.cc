/*
min heap에 다 넣고 준원이 공격력이랑 비교해
*/

#include <iostream>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    long long junwon;
    std::cin >> junwon;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    long long n;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> n;
        pq.push(n);
    }

    while (!pq.empty()) {
        long long cur = pq.top();
        pq.pop();
        if (junwon > cur) {
            junwon += cur;
        }
        else {
            std::cout << "No";
            return 0;
        }
    }

    std::cout << "Yes";

    return 0;
}