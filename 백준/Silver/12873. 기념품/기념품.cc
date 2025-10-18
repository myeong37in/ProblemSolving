/*
뺄 사람을 모듈러로 계산해서 시뮬레이션하면 되겠군
*/

#include <iostream>
#include <deque>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 1;
        return 0;
    }

    std::deque<int> deq;
    for (int i = 1; i <= N; i++) {
        deq.push_back(i);
    }

    long long turn = 1;
    while (deq.size() >= 2) {
        int nxt = (turn * turn * turn) % deq.size(); // nxt - 1 = front()에서 추가로 몇 칸을 가야 하는가
        if (nxt == 0) {
            nxt = deq.size();
        }

        for (int i = 0; i < nxt - 1; i++) {
            deq.push_back(deq.front());
            deq.pop_front();
        }
        deq.pop_front();
        turn++;
    }

    std::cout << deq.front();

    return 0;
}