#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int C, V;
        std::cin >> C >> V;

        std::vector<std::vector<int>> voters(V, std::vector<int> (C));
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < C; j++) {
                std::cin >> voters[i][j];
            }
        }

        std::vector<int> first_vote(C + 1);
        for (int i = 0; i < V; i++) {
            first_vote[voters[i][0]]++;
        }

        int p1 = -1, p2 = -1, p1_gain = -1, p2_gain = -1;
        for (int i = 1; i <= C; i++) {
            if (first_vote[i] >= p1_gain) {
                p2 = p1;
                p2_gain = p1_gain; // 밀어내기
                p1 = i;
                p1_gain = first_vote[i];
            }
            else if (first_vote[i] >= p2_gain) {
                p2 = i;
                p2_gain = first_vote[i];
            }
        }

        if (p1_gain > V / 2) {
            std::cout << p1 << " 1\n";
            continue;
        }

        p1_gain = p2_gain = 0;
        for (int i = 0; i < V; i++) {
            auto p1_pos = std::find(voters[i].begin(), voters[i].end(), p1);
            auto p2_pos = std::find(voters[i].begin(), voters[i].end(), p2);

            if (p1_pos < p2_pos) {
                p1_gain++;
            }
            else {
                p2_gain++;
            }
        }

        if (p1_gain > p2_gain) {
            std::cout << p1 << " 2\n";
        }
        else {
            std::cout << p2 << " 2\n";
        }
    }

    return 0;
}