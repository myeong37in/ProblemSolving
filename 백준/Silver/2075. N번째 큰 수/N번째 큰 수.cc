/*
각 열들은 사실상 아무런 상관 관계가 없다.
정렬: O(N^2 log N^2) = O(N^2 * 2 * log N)을 했을 때 TLE, 혹은 MLE가 일어나는지 확인해 보자 -> 396ms AC
최소 힙: 최소 힙을 만들어 크기를 N으로 유지하면 top이 답이 된다. O(N^2 log N)

상수로 2배 차이이므로 정렬이 통과되는 것도 이해가 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    // std::vector<int> vec(N * N);
    // for (int i = 0; i < N * N; i++) {
    //     std::cin >> vec[i];
    // }

    // std::sort(vec.begin(), vec.end(), std::greater<int>());

    // std::cout << vec[N - 1];

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    int num;
    for (int i = 0; i < N * N; i++) {
        std::cin >> num;
        pq.push(num);
        if (pq.size() > N) {
            pq.pop();
        }
    }

    std::cout << pq.top();

    return 0;
}