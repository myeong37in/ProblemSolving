/*
X: 머리의 오른쪽 끝
Y: 가슴의 오른쪽 끝

배 합: psum[N] - psum[Y]
머리 합: psum[X]
-> psum[N] - psum[Y] > psum[X]
-> psum[Y] < psum[N] - psum[X]

가슴 합: psum[Y] - psum[X]
-> psum[Y] - psum[X] > psum[N] - psum[Y]
-> psum[N] + psum[X] < 2 * psum[Y]
-> psum[Y] > (psum[N] + psum[X]) / 2

(psum[N] + psum[X]) / 2 < psum[Y] < psum[N] - psum[X]

X가 증가함에 따라 Y의 최솟값은 엄격 증가, Y의 최댓값은 엄격 감소함

amortized O(N)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, A;
    std::cin >> N;

    std::vector<long long> psum(N + 1);
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1];
        std::cin >> A;
        psum[i] += A;
    }

    long long cnt = 0;
    int chest_left = 2, chest_right = N - 1;
    for (int head_right = 1; head_right <= N - 2; head_right++) {
        if (chest_left < head_right + 1) {
            chest_left = head_right + 1;
        }

        long long inequality_left_term = (psum[N] + psum[head_right]) / 2;
        long long inequality_right_term = psum[N] - psum[head_right];
        while (chest_left <= N - 1 && psum[chest_left] <= inequality_left_term) {
            chest_left++;
        }
        while (chest_right >= head_right + 1 && psum[chest_right] >= inequality_right_term) {
            chest_right--;
        }

        if (chest_left > chest_right) { // 여기까지
            break;   
        }

        cnt += chest_right - chest_left + 1;
    }

    std::cout << cnt;

    return 0;
}