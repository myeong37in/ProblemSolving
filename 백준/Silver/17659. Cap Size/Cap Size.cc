/*
결과를 저장해 두면 되겠다
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K;
    std::cin >> K;

    for (int tc = 1; tc <= K; tc++) {
        int n, t;
        std::cin >> n >> t;

        std::vector<int> caps(n);
        for (int i = 0; i < n; i++) {
            std::cin >> caps[i];
        }

        bool okay = true;
        int size, res;
        std::vector<int> res_vec(n); // -1: 큼, 0: 미정, 1: 작음, 2: 딱 맞음
        for (int i = 0; i < t; i++) {
            std::cin >> size >> res;

            int idx = std::lower_bound(caps.begin(), caps.end(), size) - caps.begin();
            if (res == 1) { // 더 작으면
                for (int i = 0; i <= idx; i++) { // 얘보다 작거나 같은 모자는 모두 작음
                    if (res_vec[i] == -1 || res_vec[i] == 2) { // 크거나 딱 맞다고 했으면 모순
                        okay = false;
                        break;
                    }
                    res_vec[i] = 1;
                }
            }
            else if (res == 0) { // 맞으면
                for (int i = 0; i < idx; i++) { // 얘보다 작은 모자는 모두 작음
                    if (res_vec[i] == -1 || res_vec[i] == 2) { // 크거나 딱 맞다고 했으면 모순
                        okay = false;
                        break;
                    }
                    res_vec[i] = 1;
                }
                for (int i = idx + 1; i < n; i++) { // 얘보다 큰 모자는 모두 큼
                    if (res_vec[i] == 1 || res_vec[i] == 2) { // 작거나 딱 맞다고 했으면 모순
                        okay = false;
                        break;
                    }
                    res_vec[i] = -1;
                }

                if (res_vec[idx] == -1 || res_vec[idx] == 1) { // 크거나 작다고 했으면 모순
                    okay = false;
                    break;
                }
                res_vec[idx] = 2;
            }
            else {
                for (int i = idx; i < n; i++) { // 얘보다 크거나 같은 모자는 모두 작음
                    if (res_vec[i] == 1 || res_vec[i] == 2) { // 작거나 딱 맞다고 했으면 모순
                        okay = false;
                        break;
                    }
                    res_vec[i] = -1;
                }
            }
        }

        std::cout << "Data Set " << tc << ":\n";
        if (!okay) {
            std::cout << "Inconsistent feedback";
        }
        else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (res_vec[i] == 0 || res_vec[i] == 2) {
                    cnt++;
                }
            }
            std::cout << cnt;
        }
        std::cout << "\n\n";
    }

    return 0;
}