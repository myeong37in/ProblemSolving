#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    if (N == 1) {
        std::cout << seq[0];
        return 0;
    }

    std::sort(seq.begin(), seq.end());

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < N - 2; i++) {
        pq.push(seq[i]);
    }
    
    std::cout << seq[N - 2] << "\n";
    while (pq.size() > 1) {
        int min = pq.top();
        pq.pop();
        int mid = pq.top();
        pq.pop();
        int max = pq.top();
        pq.pop();

        std::cout << min << " " << mid << " " << max << "\n";

        pq.push(mid);
    }

    std::cout << pq.top() << " " << seq[N - 2] << " " << seq[N - 1];

    return 0;
}