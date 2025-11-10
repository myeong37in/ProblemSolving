/*
hash_map으로 정수 변환 + DSU
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> parent, rank, sz;

int Find(int n) {
    if (n == parent[n]) {
        return n;
    }
    return parent[n] = Find(parent[n]);
}

void Merge(int a, int b) {
    int ra = Find(a);
    int rb = Find(b);

    if (ra == rb) {
        return;
    }

    if (rank[ra] < rank[rb]) {
        std::swap(ra, rb);
    }

    parent[rb] = ra;
    sz[ra] += sz[rb];
    if (rank[ra] == rank[rb]) {
        rank[ra]++;
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int F;
        std::cin >> F;

        std::unordered_map<std::string, int> str_to_id;
        parent.assign(F * 2, 0);
        for (int i = 0; i < F * 2; i++) {
            parent[i] = i;
        }
        rank.assign(F * 2, 0);
        sz.assign(F * 2, 1);

        int id = 0;
        std::string s1, s2;
        for (int i = 0; i < F; i++) {
            std::cin >> s1 >> s2;
            if (str_to_id.find(s1) == str_to_id.end()) {
                str_to_id[s1] = id++;
            }
            if (str_to_id.find(s2) == str_to_id.end()) {
                str_to_id[s2] = id++;
            }

            Merge(str_to_id[s1], str_to_id[s2]);
            std::cout << sz[Find(str_to_id[s1])] << "\n";
        }
    }

    return 0;
}