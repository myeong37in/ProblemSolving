/*
특정 시간 t가 경과했을 때 각 놀이기구에 대해 운행 시간이 M_i라면
그 놀이기구를 이용하는 인원은 최대 t / M_i + 1명(0분에 운행 시작)

모든 놀이기구에 대한 이 값의 합이 N이랑 같은 최소 시간 t_min을 구하면
그때 t_min까지 이용한 이용객 수에서 t_min을 배수로 갖는 놀이기구들(그 시간에 빈 놀이기구)에 한 명씩 넣어보면 될 것.
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, M;
    std::cin >> N >> M;

    std::vector<long long> seq(M);
    for (int i = 0; i < M; i++) {
        std::cin >> seq[i];
    }

    long long left = 0, right = 1e15;
    while (left < right) {
        long long mid = (left + right) / 2;
        long long max_ride = 0;
        for (const long long& n : seq) {
            max_ride += mid / n + 1;
        }

        if (max_ride >= N) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    long long cur_sum = 0;
    for (const long long& n : seq) {
        cur_sum += (left + n - 1) / n;
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (left % seq[i] == 0) {
            cur_sum++;
        }

        if (cur_sum >= N) {
            ans = i + 1;
            break;
        }
    }

    std::cout << ans;

    return 0;
}