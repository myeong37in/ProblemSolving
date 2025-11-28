/*
pq 2개
현재 리스트에 있는 문제의 번호를 저장하는 unordered_set 'in_list'
번호 -> 난이도로 매칭되는 unordered_map 'id_to_rank'

recommend: pq에서 꺼내기
    in_list에 해당 번호가 있는지 확인
        번호가 없으면 해결된 문제이므로 있을 때까지 pop
        번호가 있으면 난이도를 확인
            난이도가 다르면 꺼낸 문제는 해결됐고 다른 난이도로 문제가 다시 들어온 것이므로 pop
            난이도가 같으면 번호 출력
add: pq에 넣기, in_list에 넣기, id_to_rank 갱신
solved: in_list에서 빼기
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

struct Problem {
    int id, rank;
};

auto hard_cmp = [](const Problem& a, const Problem& b) {
    if (a.rank == b.rank) {
        return a.id < b.id;
    }
    return a.rank < b.rank;
};

auto easy_cmp = [](const Problem& a, const Problem& b) {
    if (a.rank == b.rank) {
        return a.id > b.id;
    }
    return a.rank > b.rank;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::priority_queue<Problem, std::vector<Problem>, decltype(hard_cmp)> hard(hard_cmp);
    std::priority_queue<Problem, std::vector<Problem>, decltype(easy_cmp)> easy(easy_cmp);
    std::unordered_set<int> in_list;
    std::unordered_map<int, int> id_to_rank;

    int id, rank;
    for (int i = 0; i < N; i++) {
        std::cin >> id >> rank;
        hard.push({id, rank});
        easy.push({id, rank});
        in_list.insert(id);
        id_to_rank[id] = rank;
    }

    int M;
    std::cin >> M;
    
    std::string op;
    int x;
    for (int i = 0; i < M; i++) {
        std::cin >> op;
        if (op == "recommend") {
            std::cin >> x;

            if (x == 1) {
                while (true) {
                    auto [id, rank] = hard.top();
                    if (in_list.find(id) == in_list.end() || id_to_rank[id] != rank) {
                        hard.pop();
                        continue;
                    }
                    
                    std::cout << id << "\n";
                    break;
                }
            }
            else if (x == -1) {
                while (true) {
                    auto [id, rank] = easy.top();
                    if (in_list.find(id) == in_list.end() || id_to_rank[id] != rank) {
                        easy.pop();
                        continue;
                    }
                    
                    std::cout << id << "\n";
                    break;
                }
            }
        }
        else if (op == "add") {
            std::cin >> id >> rank;
            in_list.insert(id);
            id_to_rank[id] = rank;
            hard.push({id, rank});
            easy.push({id, rank});
        }
        else if (op == "solved") {
            std::cin >> id;
            in_list.erase(id);
        }
    }

    return 0;
}