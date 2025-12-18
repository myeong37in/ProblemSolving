/*
정렬 -> 완전 탐색

K = 251일 때도 가능하다면 Infinity
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

struct Record {
    int t, x, y;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, T;
    std::string cows;
    std::cin >> N >> T >> cows;

    int res_cnt = 0;
    for (char ch : cows) {
        if (ch == '1') {
            res_cnt++;
        }
    }

    std::vector<Record> records(T);
    for (int i = 0; i < T; i++) {
        std::cin >> records[i].t >> records[i].x >> records[i].y;
    }

    std::sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
        return a.t < b.t;
    });

    std::unordered_set<int> valid_starts;
    int min_K = 2e9, max_K = 0;
    // 시작 소가 start일 때 가능한 K 범위 확인
    for (int start = 1; start <= N; start++) {
        for (int K = 0; K <= 251; K++) {
            std::vector<bool> infected(N + 1); // 감염 여부
            std::vector<int> active(N + 1); // 전파 가능 횟수
            infected[start] = true;
            active[start] = K;
            
            for (int idx = 0; idx < T; idx++) {
                Record cur = records[idx];
                
                // 둘 다 감염 안 됨
                if (!infected[cur.x] && !infected[cur.y]) {
                    continue;
                }

                // 악수할 때마다 전파 가능 횟수 감소
                bool x_inf = infected[cur.x], y_inf = infected[cur.y];
                bool x_can = x_inf && (active[cur.x] > 0);
                bool y_can = y_inf && (active[cur.y] > 0);

                if (x_can && !y_inf) {
                    infected[cur.y] = true;
                    active[cur.y] = K;
                }

                if (y_can && !x_inf) {
                    infected[cur.x] = true;
                    active[cur.x] = K;
                }

                if (x_inf) {
                    active[cur.x] = std::max(active[cur.x] - 1, 0);
                }
                
                if (y_inf) {
                    active[cur.y] = std::max(active[cur.y] - 1, 0);
                }
            }

            // 불가능 경우
            // 1) 감염 숫자 안 맞음
            int infected_cnt = 0;
            for (int i = 1; i <= N; i++) {
                infected_cnt += infected[i];
            }

            if (infected_cnt > res_cnt) {
                break;
            }

            if (infected_cnt < res_cnt) {
                continue;
            }

            bool okay = true;
            // 2) 잘못된 소 감염
            for (int i = 0; i < cows.size(); i++) {
                if (cows[i] == '1' && !infected[i + 1]) {
                    okay = false;
                    break;
                }
            }

            if (!okay) {
                continue;
            }

            // 가능한 경우
            valid_starts.insert(start);
            min_K = std::min(min_K, K);
            max_K = std::max(max_K, K);
        }
    }

    std::cout << valid_starts.size() << " " << min_K << " ";
    if (max_K == 251) {
        std::cout << "Infinity";
    }
    else {
        std::cout << max_K;
    }

    return 0;
}