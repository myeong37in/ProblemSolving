/*
시간을 줄이고 늘리는 것에 심사할 수 있는 인원이 비례하니까 이분 탐색을 하면 될 것 같은데
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<long long> times(N);
    for (int i = 0; i < N; i++) {
        std::cin >> times[i];
    }

    long long left = 1;
    long long right = 4e18; // 최대 10^9 * 10^9 = 10^18
    while (left < right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += mid / times[i];

            if (cnt >= M) {
                break;
            }
        }

        if (cnt >= M) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    std::cout << left;

    return 0;
}