/*
길이 k 구간에 대해 무슨 초밥이 있는지 유지

c번 초밥이 있으면 가짓수 그대로, 없으면 +1

sliding window O(N)

최댓값 확인
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, d, k, c;
    std::cin >> N >> d >> k >> c;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    for (int i = 0; i < k; i++) { // 최소 k - 1개를 더 추가하여 원형 구조 구현
        seq.emplace_back(seq[i]);
    }

    std::vector<int> dat(d + 1);
    int kind = 0;
    for (int i = 0; i < k; i++) {
        dat[seq[i]]++;
        if (dat[seq[i]] == 1) {
            kind++;
        }
    }

    int best = kind;
    if (dat[c] == 0) {
        best++;
    }
    for (int s = 1; s < N; s++) {
        dat[seq[s - 1]]--;
        if (dat[seq[s - 1]] == 0) { // 없어짐
            kind--;
        }
        
        dat[seq[s + k - 1]]++;
        if (dat[seq[s + k - 1]] == 1) { // 새로 생김
            kind++;
        }

        if (dat[c] == 0) {
            best = std::max(best, kind + 1);
        }
        else {
            best = std::max(best, kind);
        }
    }

    std::cout << best;

    return 0;
}