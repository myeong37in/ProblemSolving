#include <iostream>
#include <vector>
#include <algorithm>

struct Participant {
    std::vector<int> solved;
    int score;
    int id;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, T, P;
    std::cin >> N >> T >> P;

    std::vector<Participant> vec(N);
    std::vector<int> scores(T, N);
    int n;
    for (int i = 0; i < N; i++) {
        vec[i].id = i + 1;
        for (int j = 0; j < T; j++) {
            std::cin >> n;
            if (n == 1) {
                vec[i].solved.emplace_back(j);
                scores[j]--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int prob : vec[i].solved) {
            vec[i].score += scores[prob];
        }
    }

    std::sort(vec.begin(), vec.end(), [](const Participant& a, const Participant& b) {
        if (a.score == b.score) {
            if (a.solved.size() == b.solved.size()) {
                return a.id < b.id;
            }
            return a.solved.size() > b.solved.size();
        }
        return a.score > b.score;
    });

    for (int i = 0; i < N; i++) {
        if (vec[i].id == P) {
            std::cout << vec[i].score << " " << i + 1;
        }
    }
    
    return 0;
}