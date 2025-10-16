/*
내림차순 정렬했을 때
앞에서부터 현재 위치에 대해 가장 큰 수부터 넣을 수 있으면 넣는 것이 최적
못 넣으면 다음으로 큰 수
반복
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::vector<int> sorted(seq.begin(), seq.end());
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());

    int S;
    std::cin >> S;

    int target_idx = 0;
    while (target_idx < N && S) {
        for (int i = 0; i < N; i++) {
            int biggest = sorted[i]; // 스왑을 해볼 수
            int biggest_idx;
            for (int j = 0; j < N; j++) {
                if (seq[j] == biggest) {
                    biggest_idx = j;
                    break;
                }
            }

            if (seq[target_idx] >= biggest) { // 이미 최적이면 다음 위치로
                target_idx++;
                break;
            }

            if (biggest_idx <= target_idx) { // 이 수가 이미 정렬된 상태는 다음으로 큰 수 확인
                continue;
            }

            if (biggest_idx - target_idx <= S) { // 남은 횟수로 가능하면
                for (int j = biggest_idx; j > target_idx; j--) { // 한 칸씩 밀기
                    seq[j] = seq[j - 1];
                }
                seq[target_idx] = biggest;
                S -= biggest_idx - target_idx;
                target_idx++;
                break;
            }
            else { // 아니면 다음으로 큰 수 확인
                continue;
            }
        }
    }

    for (const int& n : seq) {
        std::cout << n << " ";
    }

    return 0;
}