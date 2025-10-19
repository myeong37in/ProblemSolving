/*
진짜 안 풀고 싶다

vector는 MLE라니..
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct Node {
    int m, n, o, p, q, r, s, t, u, v, w;
};

struct State {
    int m, n, o, p, q, r, s, t, u, v, w;
    int dist;
};

// m, n, o, p, q, r, s, t, u, v, w
std::vector<int> dir_m = {-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_n = {0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_o = {0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_p = {0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_q = {0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_r = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_s = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_t = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0};
std::vector<int> dir_u = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0};
std::vector<int> dir_v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0};
std::vector<int> dir_w = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n, o, p, q, r, s, t, u, v, w;
    std::cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
    
    // 11차원(...) 보드, 방문, 거리 배열
    int board[m][n][o][p][q][r][s][t][u][v][w];
    int dists[m][n][o][p][q][r][s][t][u][v][w];
    bool visited[m][n][o][p][q][r][s][t][u][v][w];

    std::memset(visited, false, sizeof(visited));
    std::memset(dists, 0, sizeof(dists));

    // board.assign(m, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>>>>> 
    //     (n, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>>>> 
    //         (o, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>>> 
    //             (p, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>> 
    //                 (q, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>> 
    //                     (r, std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> 
    //                         (s, std::vector<std::vector<std::vector<std::vector<int>>>> 
    //                             (t, std::vector<std::vector<std::vector<int>>> 
    //                                 (u, std::vector<std::vector<int>> 
    //                                     (v, std::vector<int> 
    //                                         (w)))))))))));

    // dists.assign(m, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>>>>> 
    //     (n, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>>>> 
    //         (o, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>>> 
    //             (p, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>> 
    //                 (q, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>> 
    //                     (r, std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> 
    //                         (s, std::vector<std::vector<std::vector<std::vector<int>>>> 
    //                             (t, std::vector<std::vector<std::vector<int>>> 
    //                                 (u, std::vector<std::vector<int>> 
    //                                     (v, std::vector<int> 
    //                                         (w)))))))))));

    // visited.assign(m, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<bool>>>>>>>>>> 
    //     (n, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<bool>>>>>>>>> 
    //         (o, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<bool>>>>>>>> 
    //             (p, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<bool>>>>>>> 
    //                 (q, std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<bool>>>>>> 
    //                     (r, std::vector<std::vector<std::vector<std::vector<std::vector<bool>>>>> 
    //                         (s, std::vector<std::vector<std::vector<std::vector<bool>>>> 
    //                             (t, std::vector<std::vector<std::vector<bool>>> 
    //                                 (u, std::vector<std::vector<bool>> 
    //                                     (v, std::vector<bool> 
    //                                         (w)))))))))));

    std::vector<Node> starts;
    for (int k = 0; k < w; k++) {
        for (int j = 0; j < v; j++) {
            for (int i = 0; i < u; i++) {
                for (int h = 0; h < t; h++) {
                    for (int g = 0; g < s; g++) {
                        for (int f = 0; f < r; f++) {
                            for (int e = 0; e < q; e++) {
                                for (int d = 0; d < p; d++) {
                                    for (int c = 0; c < o; c++) {
                                        for (int b = 0; b < n; b++) {
                                            for (int a = 0; a < m; a++) {
                                                std::cin >> board[a][b][c][d][e][f][g][h][i][j][k];

                                                if (board[a][b][c][d][e][f][g][h][i][j][k] == 1) {
                                                    starts.emplace_back(Node {a, b, c, d, e, f, g, h, i, j, k});
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::queue<State> que;

    for (const auto& start : starts) {
        auto [sm, sn, so, sp, sq, sr, ss, st, su, sv, sw] = start;
        visited[sm][sn][so][sp][sq][sr][ss][st][su][sv][sw] = true;
        dists[sm][sn][so][sp][sq][sr][ss][st][su][sv][sw] = 0;
        que.push({sm, sn, so, sp, sq, sr, ss, st, su, sv, sw, 0});
    }

    while (!que.empty()) {
        auto [cm, cn, co, cp, cq, cr, cs, ct, cu, cv, cw, dist] = que.front();
        que.pop();

        for (int i = 0; i < 22; i++) {
            int nm = cm + dir_m[i];
            int nn = cn + dir_n[i];
            int no = co + dir_o[i];
            int np = cp + dir_p[i];
            int nq = cq + dir_q[i];
            int nr = cr + dir_r[i];
            int ns = cs + dir_s[i];
            int nt = ct + dir_t[i];
            int nu = cu + dir_u[i];
            int nv = cv + dir_v[i];
            int nw = cw + dir_w[i];

            if (nm < 0 || nm >= m ||
                nn < 0 || nn >= n ||
                no < 0 || no >= o ||
                np < 0 || np >= p ||
                nq < 0 || nq >= q ||
                nr < 0 || nr >= r ||
                ns < 0 || ns >= s ||
                nt < 0 || nt >= t ||
                nu < 0 || nu >= u ||
                nv < 0 || nv >= v ||
                nw < 0 || nw >= w) {
                continue;
            }
            
            if (visited[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw]) {
                continue;
            }

            if (board[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] == -1) {
                continue;
            }

            visited[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] = true;
            que.push({nm, nn, no, np, nq, nr, ns, nt, nu, nv, nw, dist + 1});
            dists[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] = dist + 1;
        }
    }

    bool okay = true;
    int max_dist = 0;
    for (int k = 0; k < w; k++) {
        for (int j = 0; j < v; j++) {
            for (int i = 0; i < u; i++) {
                for (int h = 0; h < t; h++) {
                    for (int g = 0; g < s; g++) {
                        for (int f = 0; f < r; f++) {
                            for (int e = 0; e < q; e++) {
                                for (int d = 0; d < p; d++) {
                                    for (int c = 0; c < o; c++) {
                                        for (int b = 0; b < n; b++) {
                                            for (int a = 0; a < m; a++) {
                                                if (board[a][b][c][d][e][f][g][h][i][j][k] != -1 && visited[a][b][c][d][e][f][g][h][i][j][k] == false) {
                                                    okay = false;
                                                    break;
                                                }

                                                max_dist = std::max(max_dist, dists[a][b][c][d][e][f][g][h][i][j][k]);
                                            }
                                            if (!okay) {
                                                break;
                                            }
                                        }
                                        if (!okay) {
                                            break;
                                        }
                                    }
                                    if (!okay) {
                                        break;
                                    }
                                }
                                if (!okay) {
                                    break;
                                }
                            }
                            if (!okay) {
                                break;
                            }
                        }
                        if (!okay) {
                            break;
                        }
                    }
                    if (!okay) {
                        break;
                    }
                }
                if (!okay) {
                    break;
                }
            }
            if (!okay) {
                break;
            }
        }
        if (!okay) {
            break;
        }
    }

    if (okay) {
        std::cout << max_dist;
    }
    else {
        std::cout << -1;
    }

    return 0;
}