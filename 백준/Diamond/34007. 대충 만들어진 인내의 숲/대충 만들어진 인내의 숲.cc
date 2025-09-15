/*
결국 돌고 돌아 이 문제로..
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Platform {
    int x, y, compressed_x;
};

constexpr int INF = 2e9;

int leaf_idx = 1;
std::vector<std::pair<int, int>> tree; // 세그 트리 노드 (y, id)

std::pair<int, int> Merge(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.first <= b.first) {
        return a;
    }
    else {
        return b;
    }
}

void Init(int n) {
    leaf_idx = 1;
    while (leaf_idx < n) {
        leaf_idx <<= 1;
    }
    tree.assign(2 * leaf_idx, {INF, -1});
}

void SetLeaf(int i, const std::pair<int, int>& val) { // 리프 설정, 올라가면서 갱신
    int node = i + leaf_idx;
    tree[node] = val;
    for (node >>= 1; node; node >>= 1) {
        tree[node] = Merge(tree[node * 2], tree[node * 2 + 1]);
    }
}

std::pair<int, int> Query(int left, int right) { // 구간 [left, right]에서 최소 (y, id) 쿼리
    if (left > right) {
        return {INF, -1};
    }
    left += leaf_idx;
    right += leaf_idx;

    std::pair<int, int> L = {INF, -1};
    std::pair<int, int> R = {INF, -1};

    while (left <= right) {
        if (left & 1) {
            L = Merge(L, tree[left++]);
        }
        if (!(right & 1)) {
            R = Merge(tree[right--], R);
        }
        left >>= 1; right >>= 1;
    }

    return Merge(L, R);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N, a, b;
        std::cin >> N >> a >> b;

        std::vector<Platform> platforms(N);
        std::vector<int> original_x_coords;
        for (int i = 0; i < N; i++) {
            std::cin >> platforms[i].x >> platforms[i].y;
            original_x_coords.emplace_back(platforms[i].x);
        }

        std::sort(original_x_coords.begin(), original_x_coords.end());
        original_x_coords.erase(std::unique(original_x_coords.begin(), original_x_coords.end()), original_x_coords.end());

        // 일단 x 좌표 압축을 하고
        for (int i = 0; i < N; i++) {
            platforms[i].compressed_x = std::lower_bound(original_x_coords.begin(), original_x_coords.end(), platforms[i].x) - original_x_coords.begin();
        }

        // y 오름차순 인덱스 정렬
        std::vector<int> ord(N);
        for (int i = 0; i < N; i++) {
            ord[i] = i;
        }

        std::sort(ord.begin(), ord.end(), [&](const int& a, const int& b) {
            if (platforms[a].y == platforms[b].y) {
                return platforms[a].x < platforms[b].x;
            }
            return platforms[a].y < platforms[b].y;
        });

        int sz = original_x_coords.size();
        std::vector<std::vector<int>> bucket(sz); // x 별로 활성화된 리스트
        std::vector<int> head(sz);
        
        Init(sz);

        auto leaf_val = [&](int cx) -> std::pair<int, int> {
            if (head[cx] < bucket[cx].size()) {
                int id = bucket[cx][head[cx]];
                return {platforms[id].y, id};
            }
            return {INF, -1};
        };

        for (int cx = 0; cx < sz; cx++) {
            SetLeaf(cx, {INF, -1});
        }

        int boundary_ptr = 0;
        
        std::vector<bool> visited(N + 1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

        auto activate_until_y = [&](int y) {
            // ord[ptr].y <= Y 까지 활성화
            while (boundary_ptr < N && platforms[ord[boundary_ptr]].y <= y) {
                int id = ord[boundary_ptr++];
                int cx = platforms[id].compressed_x;
                
                bucket[cx].emplace_back(id);
                SetLeaf(cx, leaf_val(cx));
            }
        };

        activate_until_y(b); // y <= b 활성화, 방문
        bool okay = false;
        while (true) {
            auto [y_min, id] = Query(0, sz - 1);

            if (y_min > b) {
                break;
            }

            int cx = platforms[id].compressed_x;
            ++head[cx];

            SetLeaf(cx, leaf_val(cx));
            if (!visited[id]) {
                visited[id] = true;
                if (id == N - 1) {
                    std::cout << "YES\n";
                    okay = true;
                    break;
                }

                pq.push({platforms[id].y, id});
            }
        }

        if (okay) {
            continue;
        }

        while (!pq.empty()) {
            auto [yi, i] = pq.top();
            pq.pop();
            if (i == N - 1) {
                std::cout << "YES\n";
                okay = true;
                break;
            }

            // 이 정점에서 도달 가능한 y 상한까지 활성화
            activate_until_y(platforms[i].y + b);

            int x_left = platforms[i].x - a;
            int x_right = platforms[i].x + a;
            int L = std::lower_bound(original_x_coords.begin(), original_x_coords.end(), x_left) - original_x_coords.begin();
            int R = std::upper_bound(original_x_coords.begin(), original_x_coords.end(), x_right) - original_x_coords.begin() - 1; // 폐구간임

            if (L <= R) {
                while (true) {
                    auto [y_min, id] = Query(L, R);
                    if (y_min > platforms[i].y + b) {
                        break;
                    }

                    int cx = platforms[id].compressed_x;
                    ++head[cx];

                    SetLeaf(cx, leaf_val(cx));
                    if (!visited[id]) {
                        visited[id] = true;
                        if (id == N - 1) {
                            std::cout << "YES\n";
                            okay = true;
                            break;
                        }
                        pq.push({platforms[id].y, id});
                    }
                }
            }
        }

        if (!okay) {
            std::cout << "NO\n";
        }
    }

    return 0;
}