/*
-15부터 시작해서 연속한 k개의 누적 합이 n보다 크거나 같아질 때의 시작점이 최솟값, 끝점이 최댓값
*/

#include <iostream>
#include <vector>

int n, k;

void backtrack(int cur, std::vector<int>& selected, int psum, int s, int e) {
    if (selected.size() == k) {
        if (psum == n) {
            std::cout << selected.front();
            for (int i = 1; i < selected.size(); i++) {
                if (selected[i] < 0) {
                    std::cout << selected[i];
                }
                else {
                    std::cout << "+" << selected[i];
                }
            }
            std::cout << "\n";
        }

        return;
    }

    // 대충 가지치기
    if (cur > s) {
        selected.emplace_back(cur - 1);
        backtrack(cur - 1, selected, psum + cur - 1, s, e);
        selected.pop_back();
    }

    selected.emplace_back(cur);
    backtrack(cur, selected, psum + cur, s, e);
    selected.pop_back();

    if (cur < e) {
        selected.emplace_back(cur + 1);
        backtrack(cur + 1, selected, psum + cur + 1, s, e);
        selected.pop_back();
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;

    int s, e;
    for (s = -15; s <= 15; s++) {
        int psum = 0;
        for (int i = s; i < s + k; i++) {
            psum += i;
        }

        if (psum >= n) {
            e = s + k - 1;
            break;
        }
    }

    for (int i = s; i <= e; i++) {
        std::vector<int> selected = {i};
        backtrack(i, selected, i, s, e);
    }

    return 0;
}