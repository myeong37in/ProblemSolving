#include <iostream>
#include <vector>

/*
small to large로 O((N + M) log N)에 될 것 같은데
*/

constexpr int MAX = 3e5;

// 30만 개의 버킷 DAT
std::vector<std::vector<int>> buckets;
std::vector<int> idx_bucket; // idx_bucket[i]: 수열의 i번 index가 속한 버킷 index
std::vector<int> actual_values; // actual_values[i]: 버킷의 i번 인덱스가 표현하는 실제 값
std::vector<int> val_to_bucket_idx; // 값 -> 버킷 index

void Merge(int x, int y) {
    if (x == y) {
        return;
    }

    int x_bucket_idx = val_to_bucket_idx[x];
    if (x_bucket_idx == 0) { // x 값 없음
        return;
    }

    int y_bucket_idx = val_to_bucket_idx[y];
    if (y_bucket_idx == 0) { // y 버킷이 없으면 x 버킷이 향하는 목표만 바꾸기
        val_to_bucket_idx[y] = x_bucket_idx;
        val_to_bucket_idx[x] = 0;
        actual_values[x_bucket_idx] = y;

        return;
    }

    // small to large
    int big = x_bucket_idx;
    int small = y_bucket_idx;
    if (buckets[big].size() < buckets[small].size()) {
        std::swap(big, small);
    }

    for (int idx : buckets[small]) {
        idx_bucket[idx] = big;
        buckets[big].emplace_back(idx);
    }
    buckets[small].clear();

    actual_values[big] = y;
    val_to_bucket_idx[y] = big;
    val_to_bucket_idx[x] = 0;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    int M;
    std::cin >> M;

    buckets.resize(MAX + 1);
    idx_bucket.resize(N + 1);
    actual_values.resize(MAX + 1, 0);
    val_to_bucket_idx.resize(MAX + 1, 0);

    for (int i = 1; i <= N; i++) {
        int v = seq[i];
        if (val_to_bucket_idx[v] == 0) {
            val_to_bucket_idx[v] = v;
            actual_values[v] = v;
        }

        int idx = val_to_bucket_idx[v];
        buckets[idx].emplace_back(i);
        idx_bucket[i] = idx;
    }

    int op, x, y, z;
    while (M--) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y;
            Merge(x, y);
        }
        else {
            std::cin >> z;
            int idx = idx_bucket[z];

            std::cout << actual_values[idx] << "\n";
        }
    }

    return 0;
}
