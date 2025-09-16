/*
std::multiset은 값을 오름차순으로 기본 정렬하면서 중복을 허용하는 STL container이다.
오름차순이므로 최솟값 제거(D -1)는 가장 앞의 요소를 제거, 최댓값 제거(D 1)는 가장 뒤의 요소를 제거한다.
*/

#include <iostream>
#include <set>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        std::multiset<int> mtset;
        int k;
        std::cin >> k;

        char op;
        int n;
        while (k--) {
            std::cin >> op >> n;

            if (op == 'I') {
                mtset.insert(n);
            }
            else {
                if (mtset.empty()) {
                    continue;
                }
                if (n == -1) {
                    mtset.erase(mtset.begin());
                }
                else {
                    mtset.erase(std::prev(mtset.end())); // 마지막 요소 제거
                }
            }
        }

        if (mtset.empty()) {
            std::cout << "EMPTY\n";
        }
        else {
            std::cout << *std::prev(mtset.end()) << " " << *mtset.begin() << "\n";
        }
    }

    return 0;
}