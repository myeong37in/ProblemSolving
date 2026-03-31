/*
거리를 다 구해놓는 건 쉽다.

각 지점을 번호로 두면 대충 Floyd-Warshall로 인접 행렬로 표현 가능

약간 12850번 과인 것 같은데

두 미하일을 각각 A, B라고 놓으면

dp_t[i][j]: 출발 t초 후 A, B가 각각 i, j에 있는 경우의 수

dp_t[i][j]는 가능한 모든 x, y 조합에 대해 dp_t-1[x][y]의 합인데, 거리 배열을 adj라고 하면

adj[x][i] = adj[i][x] = 1
adj[y][j] = adj[j][y] = 1

t-1초에서의 위치 (x y)에서 t초에 (i, j)로 이동하는 것

그리고 조건에 의해 adj[x][y] = adj[y][x] >= 3이어야 함.

그러면 가능한 모든 (i, j) 조합에 대해 dp_n[i][j]의 합이 답인데,

행렬로 이렇게 나타내야겠군.

14^2 = 196. 196x196 행렬로, 행렬곱 계산

왼쪽 위부터 오른쪽 아래까지 y좌표 순으로 0번부터 13번 부여

최초 위치는 (3, 8)

M[(다음 상태)][(이전 상태)]

v = M^n * v0

열벡터로 하니까 더 헷갈린다;
*/

#include <iostream>
#include <vector>

static inline int Flatten(int a, int b) {
    return a * 14 + b;
}

constexpr int INF = 1e9;

constexpr int MOD = 1e9 + 7;

std::vector<std::vector<int>> adj(14, std::vector<int> (14, INF));

std::vector<std::vector<int>> v0(196, std::vector<int> (1));
std::vector<std::vector<int>> M(196, std::vector<int> (196));

// 196x196 행렬에 196x1 행렬을 곱하여 196x1 행렬 얻는 함수
static std::vector<std::vector<int>> MatMult196x196by196x1(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    std::vector<std::vector<int>> res(196, std::vector<int> (1));

    for (int i = 0; i < 196; i++) {
        for (int j = 0; j < 196; j++) {
            res[i][0] = (res[i][0] + (1LL * a[i][j] * b[j][0]) % MOD) % MOD;
        }
    }

    return res;
}

// 196x196 행렬끼리 행렬곱 계산하는 함수
static std::vector<std::vector<int>> MatMult196x196by196x196(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    std::vector<std::vector<int>> res(196, std::vector<int> (196));

    for (int i = 0; i < 196; i++) {
        for (int j = 0; j < 196; j++) {
            for (int k = 0; k < 196; k++) {
                res[i][j] = (res[i][j] + (1LL * a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }

    return res;
}

// 196x196 행렬 M을 n제곱한 행렬을 반환하는 함수
static std::vector<std::vector<int>> Calc(int n) {
    if (n == 1) {
        return M;
    }

    std::vector<std::vector<int>> half = Calc(n / 2);
    if (n & 1) {
        return MatMult196x196by196x196(half, MatMult196x196by196x196(half, M));
    }
    else {
        return MatMult196x196by196x196(half, half);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    // 최초 위치
    v0[Flatten(3, 8)][0] = 1;

    // 메이플 맵을 이렇게 집중해서 보는 날이 올 줄이야
    adj[0][5] = 1;
    adj[1][3] = 1;
    adj[2][4] = 1;
    adj[3][0] = adj[3][5] = adj[3][10] = 1;
    adj[4][1] = 1;
    adj[5][0] = adj[5][9] = 1;
    adj[6][2] = adj[6][4] = 1;
    adj[7][3] = adj[7][4] = adj[7][8] = adj[7][11] = adj[7][12] = 1;
    adj[8][4] = adj[8][6] = 1;
    adj[9][10] = 1;
    adj[10][7] = adj[10][11] = 1;
    adj[11][12] = 1;
    adj[12][8] = adj[12][13] = 1;
    adj[13][6] = 1;

    for (int i = 0; i < 14; i++) {
        adj[i][i] = 0;
    }

    for (int m = 0; m < 14; m++) {
        for (int s = 0; s < 14; s++) {
            for (int e = 0; e < 14; e++) {
                if (adj[s][e] > adj[s][m] + adj[m][e]) {
                    adj[s][e] = adj[s][m] + adj[m][e];
                }
            }
        }
    }

    // (pa, pb) -> (na, nb)
    for (int pa = 0; pa < 14; pa++) {
        for (int pb = 0; pb < 14; pb++) {
            for (int na = 0; na < 14; na++) {
                for (int nb = 0; nb < 14; nb++) {
                    // 한 칸 이동 조건
                    if (adj[pa][na] != 1 || adj[pb][nb] != 1) {
                        continue;
                    }

                    // 최소 거리 3 조건
                    if (adj[pa][pb] < 3 || adj[pb][pa] < 3 || adj[na][nb] < 3 || adj[nb][na] < 3) {
                        continue;
                    }

                    M[Flatten(na, nb)][Flatten(pa, pb)] = 1;
                }
            }
        }
    }

    std::vector<std::vector<int>> ans(196, std::vector<int> (1));
    ans = MatMult196x196by196x1(Calc(n), v0);

    int total = 0;
    for (int i = 0; i < 196; i++) {
        total = (total + ans[i][0]) % MOD;
    }

    std::cout << total;
    
    return 0;
}