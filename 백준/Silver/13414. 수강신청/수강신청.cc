/*
순서로 정렬되는 (순서, 학번) 쌍 map
순서를 표시하는 (학번, 순서) 쌍 unordered_map
*/

#include <iostream>
#include <map>
#include <unordered_map>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K, L;
    std::cin >> K >> L;

    std::map<int, std::string> order;
    std::unordered_map<std::string, int> id_to_order;
    std::string id;
    for (int i = 1; i <= L; i++) {
        std::cin >> id;
        if (id_to_order.find(id) != id_to_order.end()) { // 이미 신청 -> 제거하고 다시 추가
            order.erase(id_to_order[id]);
        }
        order[i] = id;
        id_to_order[id] = i;
    }

    auto it = order.begin();
    for (int i = 0; i < K && it != order.end(); i++) {
        std::cout << it->second << "\n";
        it++;
    }

    return 0;
}