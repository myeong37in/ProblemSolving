/*
map으로 정렬하고 열 방향으로 탐색하면 초기 B^2번 추가, 이후 N - B + 1번에 걸쳐 B번 추가, B번 제거

대충 최대, 최소 부분 배열 구하는 건 O(N^3 log N)에 동작하는 듯
*/

#include <iostream>
#include <vector>
#include <map>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, B, K;
    std::cin >> N >> B >> K;

    std::vector<std::vector<int>> vec(N + 1, std::vector<int> (N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> vec[i][j];
        }
    }

    // 최댓값 벡터, 최솟값 벡터
    std::vector<std::vector<int>> max_val(N + 1, std::vector<int> (N + 1)), min_val(N + 1, std::vector<int> (N + 1));
    for (int si = 1; si <= N - B + 1; si++) {
        std::map<int, int> mp;
        for (int i = si; i < si + B; i++) {
            for (int j = 1; j <= B; j++) {
                mp[vec[i][j]]++;
            }
        }
        
        max_val[si][1] = std::prev(mp.end())->first;
        min_val[si][1] = mp.begin()->first;

        for (int sj = 2; sj <= N - B + 1; sj++) {
            for (int i = si; i < si + B; i++) {
                if (--mp[vec[i][sj - 1]] == 0) {
                    mp.erase(vec[i][sj - 1]);
                }
                mp[vec[i][sj + B - 1]]++;
            }

            max_val[si][sj] = std::prev(mp.end())->first;
            min_val[si][sj] = mp.begin()->first;
        }
    }

    int si, sj;
    for (int i = 0; i < K; i++) {
        std::cin >> si >> sj;
        std::cout << max_val[si][sj] - min_val[si][sj] << "\n";
    }

    return 0;
}