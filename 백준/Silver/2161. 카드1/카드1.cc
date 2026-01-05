#include <iostream>
#include <deque>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::deque<int> deq;
    for (int i = 1; i <= N; i++) {
        deq.push_back(i);
    }

    while (deq.size() >= 2) {
        std::cout << deq.front() << " ";
        deq.pop_front();
        deq.push_back(deq.front());
        deq.pop_front();
    }

    std::cout << deq.front();

    return 0;
}