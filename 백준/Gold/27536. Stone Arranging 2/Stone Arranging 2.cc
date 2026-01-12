/*
입력 그대로 저장, 각 수 별로 나오는 인덱스 저장
0번 인덱스에 나오는 수 x에 대해, x가 마지막에 나오는 인덱스까지는 전부 그 수가 됨. 반영
마지막 x의 인덱스 다음 인덱스의 수에 대해 같은 과정 반복
저장은 선형
인덱스가 뒤로만 선형적으로 증가, 마찬가지로 선형
*/

#include <iostream>
#include <unordered_map>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    std::unordered_map<int, std::vector<int>> um;
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
        um[seq[i]].emplace_back(i);
    }

    int idx = 0;
    std::vector<int> ans(N);
    while (idx < N) {
        int num = seq[idx];
        int last = um[num].back();
        for (int i = idx; i <= last; i++) {
            ans[i] = num;
        }
        idx = last + 1;
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << "\n";
    }
    
    return 0;
}