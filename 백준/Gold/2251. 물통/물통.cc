/*
대충 BFS로 풀면 될 듯
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

struct State {
    int a, b, c;
};

std::set<int> ans;

static void bfs(int A, int B, int C) {
    std::vector<std::vector<std::vector<bool>>> visited(A + 1, std::vector<std::vector<bool>> (B + 1, std::vector<bool> (C + 1)));
    visited[0][0][C] = true;
    ans.insert(C);
    std::queue<State> q;
    q.push({0, 0, C});

    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();

        // A에서 B나 C로 이동
        if (a) {
            if (b < B) {
                int move = std::min(a, B - b);
                if (!visited[a - move][b + move][c]) {
                    visited[a - move][b + move][c] = true;
                    q.push({a - move, b + move, c});

                    if (a - move == 0) {
                        ans.insert(c);
                    }
                }
            }
            if (c < C) {
                int move = std::min(a, C - c);
                if (!visited[a - move][b][c + move]) {
                    visited[a - move][b][c + move] = true;
                    q.push({a - move, b, c + move});

                    if (a - move == 0) {
                        ans.insert(c + move);
                    }
                }
            }
        }

        // B에서 A나 C로 이동
        if (b) {
            if (a < A) {
                int move = std::min(b, A - a);
                if (!visited[a + move][b - move][c]) {
                    visited[a + move][b - move][c] = true;
                    q.push({a + move, b - move, c});

                    if (a + move == 0) {
                        ans.insert(c);
                    }
                }
            }
            if (c < C) {
                int move = std::min(b, C - c);
                if (!visited[a][b - move][c + move]) {
                    visited[a][b - move][c + move] = true;
                    q.push({a, b - move, c + move});

                    if (a == 0) {
                        ans.insert(c + move);
                    }
                }
            }
        }

        // C에서 A나 B로 이동
        if (c) {
            if (a < A) {
                int move = std::min(c, A - a);
                if (!visited[a + move][b][c - move]) {
                    visited[a + move][b][c - move] = true;
                    q.push({a + move, b, c - move});

                    if (a + move == 0) {
                        ans.insert(c - move);
                    }
                }
            }
            if (b < B) {
                int move = std::min(c, B - b);
                if (!visited[a][b + move][c - move]) {
                    visited[a][b + move][c - move] = true;
                    q.push({a, b + move, c - move});
                    
                    if (a == 0) {
                        ans.insert(c - move);
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int A, B, C;
    std::cin >> A >> B >> C;

    bfs(A, B, C);

    for (int n : ans) {
        std::cout << n << " ";
    }
    
    return 0;
}