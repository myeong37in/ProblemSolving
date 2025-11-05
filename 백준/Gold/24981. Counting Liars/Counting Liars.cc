/*
G와 L을 저장한 다음 정렬하고 각 G에 대해 최소 L의 위치를 구하면 몇 개 제거해야 하는지 알 수 있음
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    char ch;
    int pos;
    std::vector<int> ge_vec, le_vec;
    for (int i = 0; i < N; i++) {
        std::cin >> ch >> pos;
        if (ch == 'G') {
            ge_vec.emplace_back(pos);
        }
        else {
            le_vec.emplace_back(pos);
        }
    }

    // GE는 큰 수부터 작은 쪽으로 확장
    // LE는 작은 수부터 큰 쪽으로 확장
    std::sort(ge_vec.begin(), ge_vec.end(), std::greater<int>());
    std::sort(le_vec.begin(), le_vec.end());

    int ge_sz = ge_vec.size();
    int le_sz = le_vec.size();
    int best = ge_sz; // G를 전부 제거할 때의 답에서 시작
    for (int i = 0; i < ge_sz; i++) { // G를 전부 수용하는 상태에서 시작
        int lo = ge_vec[i];
        int le_cnt = std::lower_bound(le_vec.begin(), le_vec.end(), lo) - le_vec.begin();
        best = std::min(best, i + le_cnt);
    }

    std::cout << best;

    return 0;
}