// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/mint-choco-milk/description
// 민트 초코 우유
// Lv. 12

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

struct Group {
    std::pair<int, int> daepyo; // 대표의 좌표
    std::string group_food; // 그룹이 신봉하는 음식
    bool spreading = true; // 이번 턴 전파 가능 여부
};

std::vector<std::vector<std::string>> food; // 음식
std::vector<std::vector<int>> belief; // 신앙심
std::vector<std::vector<int>> visited; // BFS 방문 처리
int visit_count = 0; // 탐색을 여러 번 돌려야 할 때 visited 배열을 매번 초기화하지 않는 테크닉

int N;

// 아침 동작
void Morning() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            belief[i][j]++;
        }
    }
}

// 같은 그룹에 속하는 사람들의 좌표를 group에 모으는 BFS
std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};
void bfs(std::vector<std::pair<int, int>>& group, const int& cur_r, const int& cur_c) {
    std::queue<std::pair<int, int>> q;
    q.push({cur_r, cur_c});
    visited[cur_r][cur_c] = visit_count;
    group.emplace_back(cur_r, cur_c);

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }

            if (food[nr][nc] != food[r][c]) {
                continue;
            }

            if (visited[nr][nc] == visit_count) {
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = visit_count;
            group.emplace_back(nr, nc);
        }
    }
}

auto comparator = [](const auto& a, const auto& b) {
    auto [a_r, a_c] = a;
    auto [b_r, b_c] = b;
    if (belief[a_r][a_c] == belief[b_r][b_c]) {
        if (a_r == b_r) {
            return a_c < b_c;
        }
        return a_r < b_r;
    }
    return belief[a_r][a_c] > belief[b_r][b_c];
};

// 그룹 내에서 대표자의 신앙이 증가하고 나머지 그룹원의 신앙이 감소하는 동작
void CalcBeliefInGroup(std::vector<std::pair<int, int>>& group) {
    std::sort(group.begin(), group.end(), comparator);

    auto [daepyo_r, daepyo_c] = group.front();
    belief[daepyo_r][daepyo_c] += group.size() - 1;
    for (int i = 1; i < group.size(); i++) {
        auto [cur_r, cur_c] = group[i];
        belief[cur_r][cur_c]--;
    }
}

// 점심 동작
void Lunch(std::vector<Group>& groups) {
    visit_count++;
    std::vector<std::pair<int, int>> group;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] != visit_count) {
                bfs(group, i, j);

                if (group.size() >= 2) { // 그룹원이 둘 이상이면 대표에게 신앙심 주기
                    CalcBeliefInGroup(group);
                }

                auto [daepyo_r, daepyo_c] = group.front(); // 정렬 후 0번 인덱스의 사람이 대표
                groups.emplace_back(Group {{daepyo_r, daepyo_c}, food[daepyo_r][daepyo_c]});

                group.clear();
            }
        }
    }
}

std::vector<std::string> order = {"T", "C", "M", "CM", "MT", "CT", "CMT"}; // 사전 순으로 저장
// 약한 전파 시 음식 합치기
std::string MergeFood(const std::string& food1, const std::string& food2) {
    std::string res = food1 + food2;

    // 음식을 사전 순으로 저장하면 이렇게 할 수 있음
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end()); 
    return res;
}

void Spread(std::vector<Group>& groups, const int& daepyo_r, const int& daepyo_c, int x) {
    int dir = (x + 1) % 4; // x는 간절함, B = x + 1이 원래 전파 방향에 사용
    int d = 1;
    while (x > 0) {
        int nr = daepyo_r + dr[dir] * d;
        int nc = daepyo_c + dc[dir] * d;
        d++;

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            break;
        }

        // 같은 음식 신봉 시 건너뜀
        if (food[nr][nc] == food[daepyo_r][daepyo_c]) {
            continue;
        }

        // 전파 대상자가 다른 그룹의 대표이면 해당 날에 전파 안 함
        auto it = std::find_if(groups.begin(), groups.end(), [&](const auto& p) { return ((p.daepyo.first == nr) && (p.daepyo.second == nc)); });
        if (it != groups.end()) {
            int idx = it - groups.begin();
            groups[idx].spreading = false;
        }

        int y = belief[nr][nc];
        if (x > y) { // 강한 전파
            x -= y + 1;

            food[nr][nc] = food[daepyo_r][daepyo_c];
            belief[nr][nc]++;
        }
        else { // 약한 전파
            food[nr][nc] = MergeFood(food[nr][nc], food[daepyo_r][daepyo_c]);
            belief[nr][nc] += x;
            break;
        }
    }
}

// 저녁 동작
void Dinner(std::vector<Group> groups) {
    // 전체 그룹을 음식 수 -> 신앙심 -> 행 -> 열로 정렬
    std::sort(groups.begin(), groups.end(), [&](const auto& a, const auto& b) {
        int a_food_count = a.group_food.size();
        int b_food_count = b.group_food.size();

        if (a_food_count == b_food_count) {
            int a_belief = belief[a.daepyo.first][a.daepyo.second];
            int b_belief = belief[b.daepyo.first][b.daepyo.second];
            if (a_belief == b_belief) {
                if (a.daepyo.first == b.daepyo.first) {
                    return a.daepyo.second < b.daepyo.second;
                }
                return a.daepyo.first < b.daepyo.first;
            }
            return a_belief > b_belief;
        }
        return a_food_count < b_food_count;
    });

    for (const auto& group : groups) {
        if (!group.spreading) {
            continue;
        }

        auto [r, c] = group.daepyo;
        int x = belief[r][c] - 1;
        belief[r][c] = 1;
        Spread(groups, r, c, x);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> N >> t;

    food.assign(N, std::vector<std::string> (N));
    belief.assign(N, std::vector<int> (N));
    visited.assign(N, std::vector<int> (N));

    std::string line;
    for (int i = 0; i < N; i++) {
        std::cin >> line;
        for (int j = 0; j < N; j++) {
            food[i][j] += line[j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> belief[i][j];
        }
    }

    while (t--) {
        std::vector<Group> groups;
        Morning();
        Lunch(groups);
        Dinner(groups);

        int CMT, CT, MT, CM, M, C, T;
        CMT = CT = MT = CM = M = C = T = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (food[i][j] == "CMT") {
                    CMT += belief[i][j];
                }
                else if (food[i][j] == "CT") {
                    CT += belief[i][j];
                }
                else if (food[i][j] == "MT") {
                    MT += belief[i][j];
                }
                else if (food[i][j] == "CM") {
                    CM += belief[i][j];
                }
                else if (food[i][j] == "M") {
                    M += belief[i][j];
                }
                else if (food[i][j] == "C") {
                    C += belief[i][j];
                }
                else if (food[i][j] == "T") {
                    T += belief[i][j];
                }
            }
        }

        std::cout << CMT << " " << CT << " " << MT << " " << CM << " " << M << " " << C << " " << T << "\n";
    }

    return 0;
}
