#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Algorithm {
    std::string name;
    int difficulty;
};

struct Member {
    std::string name, algo1, algo2;
    int tier;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<Algorithm> algorithms(N);
    for (int i = 0; i < N; i++) {
        std::cin >> algorithms[i].name >> algorithms[i].difficulty;
    }

    int M;
    std::cin >> M;

    std::vector<Member> members(M);
    for (int i = 0; i < M; i++) {
        std::cin >> members[i].name >> members[i].tier;
    }

    for (auto& member : members) {
        int tier = member.tier;
        std::sort(algorithms.begin(), algorithms.end(), [&](const auto& a, const auto& b) {
            int dif_a = std::abs(a.difficulty - tier);
            int dif_b = std::abs(b.difficulty - tier);

            if (dif_a == dif_b) {
                return a.name < b.name;
            }
            return dif_a < dif_b;
        });
        member.algo1 = algorithms[0].name;
        member.algo2 = algorithms[1].name;
    }

    int Q;
    std::cin >> Q;

    std::string query;
    std::string s1, s2;
    std::string cur_member;
    while (Q--) {
        std::cin >> query >> s1 >> s2;

        // 뭐지 이건가?
        if (s2 == "suki?") {
            int idx = std::find_if(members.begin(), members.end(), [&](const auto& a) { return a.name == cur_member; }) - members.begin();
            std::cout << members[idx].algo2 << " yori mo " << members[idx].algo1 << "\n";
        }
        else {
            cur_member = query;
            std::cout << "hai!\n";
        }
    }

    return 0;
}