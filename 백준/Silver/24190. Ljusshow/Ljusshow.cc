/*
개수를 세라는 거겠지
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    std::cin >> R >> C;

    std::string up, right, down, left;
    std::cin >> up >> right >> down >> left;

    std::vector<long long> row_cnts(6), col_cnts(6); // rr, gg, bb, rg, rb, gb
    for (int r = 0; r < R; r++) {
        char left_ch = left[r];
        char right_ch = right[r];

        if (left_ch == 'R' && right_ch == 'R') {
            row_cnts[0]++;
        }
        else if (left_ch == 'G' && right_ch == 'G') {
            row_cnts[1]++;
        }
        else if (left_ch == 'B' && right_ch == 'B') {
            row_cnts[2]++;
        }
        else if ((left_ch == 'R' && right_ch == 'G') || (left_ch == 'G' && right_ch == 'R')) {
            row_cnts[3]++;
        }
        else if ((left_ch == 'R' && right_ch == 'B') || (left_ch == 'B' && right_ch == 'R')) {
            row_cnts[4]++;
        }
        else if ((left_ch == 'B' && right_ch == 'G') || (left_ch == 'G' && right_ch == 'B')) {
            row_cnts[5]++;
        }
    }

    for (int c = 0; c < C; c++) {
        char up_ch = up[c];
        char down_ch = down[c];

        if (up_ch == 'R' && down_ch == 'R') {
            col_cnts[0]++;
        }
        else if (up_ch == 'G' && down_ch == 'G') {
            col_cnts[1]++;
        }
        else if (up_ch == 'B' && down_ch == 'B') {
            col_cnts[2]++;
        }
        else if ((up_ch == 'R' && down_ch == 'G') || (up_ch == 'G' && down_ch == 'R')) {
            col_cnts[3]++;
        }
        else if ((up_ch == 'R' && down_ch == 'B') || (up_ch == 'B' && down_ch == 'R')) {
            col_cnts[4]++;
        }
        else if ((up_ch == 'B' && down_ch == 'G') || (up_ch == 'G' && down_ch == 'B')) {
            col_cnts[5]++;
        }
    }

    // RR + GB
    // GG + RB
    // BB + RG
    // RG + RB
    // RG + GB
    // RG + BB
    // RB + RG
    // RB + GG
    // RB + BG
    // GB + RR
    // GB + GR
    // GB + BR
    long long ans = ((row_cnts[0] * col_cnts[5]) + (row_cnts[1] * col_cnts[4]) + (row_cnts[2] * col_cnts[3]) +
                     (row_cnts[3] * col_cnts[4]) + (row_cnts[3] * col_cnts[5]) + (row_cnts[3] * col_cnts[2]) +
                     (row_cnts[4] * col_cnts[3]) + (row_cnts[4] * col_cnts[1]) + (row_cnts[4] * col_cnts[5]) +
                     (row_cnts[5] * col_cnts[0]) + (row_cnts[5] * col_cnts[3]) + (row_cnts[5] * col_cnts[4]));

    std::cout << ans;

    return 0;
}