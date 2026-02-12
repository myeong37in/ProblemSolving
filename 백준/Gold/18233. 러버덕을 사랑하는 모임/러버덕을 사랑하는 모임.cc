/*
C(N, P) 조합 구하고 최소, 최대 합으로 가지치기, 이분 탐색으로 답을 찾아볼까

안 되네. 간단히 생각해 봐도 반례가 있음. 그러면 하한과 상한의 차이는 1이므로 하나씩 조절하면 될 듯
*/

#include <iostream>
#include <vector>

int N, P, E;
std::vector<std::pair<int, int>> vec;

std::vector<int> ans;
bool found = false;
static bool Backtrack(int mask, int start, int cnt) {
    if (cnt == P) {
        std::vector<int> selected;
        for (int i = 0; i < N; i++) { // 순서가 반대로 되긴 하는데 상관없겠지
            if (mask & 1) {
                selected.emplace_back(i);
            }
            mask >>= 1;
        }

        int min_sum = 0, max_sum = 0;
        for (int n : selected) {
            min_sum += vec[n].first;
            max_sum += vec[n].second;
        }

        if (min_sum > E || max_sum < E) {
            return false;
        }

        int lo = 1, hi = 1e6;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int sum = 0;
            for (int n : selected) {
                if (vec[n].first > mid) { // 최솟값 조건에 의해 mid보다 많이 주는 경우
                    sum += vec[n].first;
                }
                else if (vec[n].second < mid) { // 최댓값 조건에 의해 mid보다 적게 주는 경우
                    sum += vec[n].second;
                }
                else {
                    sum += mid;
                }
            }

            if (sum > E) {
                hi = mid - 1;
            }
            else if (sum < E) {
                lo = mid + 1;
            }
            else {
                for (int n : selected) {
                    if (vec[n].first > mid) {
                        ans[n] = vec[n].first;
                    }
                    else if (vec[n].second < mid) {
                        ans[n] = vec[n].second;
                    }
                    else {
                        ans[n] = mid;
                    }
                }
                return true;
            }
        }

        // lo = hi + 1인 상태
        for (int n : selected) {
            ans[n] = hi;
        }

        int sum = 0;
        for (int n : selected) {
            if (vec[n].first > hi) {
                sum += vec[n].first;
            }
            else if (vec[n].second < hi) {
                sum += vec[n].second;
            }
            else {
                sum += hi;
            }
        }

        // E에 맞출 때까지 하나씩 더하기. 최대 P - 1회
        int idx = 0;
        while (sum < E) {
            ans[selected[idx++]]++;
            sum++;
        }

        return true;
    }

    for (int i = start; i < N; i++) {
        if (Backtrack(mask | (1 << i), i + 1, cnt + 1)) {
            return true;
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> P >> E;

    vec.resize(N);
    int x, y;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        vec[i] = {x, y};
    }

    ans.resize(N);
    if (Backtrack(0, 0, 0)) {
        for (int n : ans) {
            std::cout << n << " ";
        }
    }
    else {
        std::cout << -1;
    }
    
    return 0;
}