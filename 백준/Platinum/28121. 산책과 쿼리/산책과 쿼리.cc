/*
직관적으로, 어떤 정점이 길이가 홀수인 사이클을 포함하는 연결 요소에 들어 있으면 가능임

사이클의 길이가 홀수 -> 이분 그래프가 아니라는 것

연결 요소가 이분 그래프인지 어떻게 관리함?

https://justicehui.github.io/medium-algorithm/2024/02/04/union-find-application/

아하..

정점을 분할하고 짝수 시간에 정점에 방문하는 상태의 size를 1로 초기화, (a, b) 병합은 a0과 b1, b0와 a1의 병합
*/

#include <iostream>
#include <vector>

std::vector<int> parent, rank, sz;

int N;
int sum = 0;

int Find(int n) {
    if (n == parent[n]) {
        return n;
    }

    return parent[n] = Find(parent[n]);
}

int Neg(int a) {
    return (a > N ? a - N : a + N);
}

void Merge(int a, int b) {
    int ra = Find(a);
    int rb = Find(b);
    
    if (ra == rb) {
        return;
    }

    // 다시 더해주기 전에 기존 기여분 빼기
    if (ra == Find(Neg(ra))) {
        sum -= sz[ra];
    }
    if (rb == Find(Neg(rb))) {
        sum -= sz[rb];
    }

    if (rank[ra] < rank[rb]) {
        std::swap(ra, rb);
    }

    parent[rb] = ra;
    sz[ra] += sz[rb];
    
    if (ra == Find(Neg(ra))) {
        sum += sz[ra];
    }

    if (rank[ra] == rank[rb]) {
        rank[ra]++;
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Q;
    std::cin >> N >> Q;

    parent.resize(2 * N + 1);
    rank.resize(2 * N + 1);
    sz.resize(2 * N + 1);

    for (int i = 1; i <= 2 * N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        sz[i] = 1;
    }

    int a, b;
    for (int i = 0; i < Q; i++) {
        std::cin >> a >> b;

        Merge(a, Neg(b));
        Merge(b, Neg(a));

        std::cout << sum << "\n";
    }

    return 0;
}