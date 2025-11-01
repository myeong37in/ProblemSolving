/*
일대일 매칭이니까 정렬하고 차례대로 매칭 시도 그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N;
        std::cin >> N;

        std::vector<int> hope(N);
        for (int i = 0; i < N; i++) {
            std::cin >> hope[i];
        }

        std::vector<int> hats(N);
        for (int i = 0; i < N; i++) {
            std::cin >> hats[i];
        }

        std::sort(hope.begin(), hope.end());
        std::sort(hats.begin(), hats.end());

        int i = 0;
        int j = 0;

        int count = 0;
        while (i < N && j < N) {
            if (hope[i] > hats[j] + 3) { // 원하는 사이즈가 더 크면 모자 사이즈 업
                j++;
            }
            else if (hope[i] + 3 < hats[j]) { // 모자 사이즈가 더 크면 원하는 사이즈 업
                i++;
            }
            else {
                count++;
                i++;
                j++;
            }
        }

        std::cout << "#" << t << " " << count << "\n";
    }

    return 0;
}