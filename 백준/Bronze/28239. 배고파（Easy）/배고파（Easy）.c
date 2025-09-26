#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define ll long long
ll N, M;

int main(void) {
    scanf("%d", &N);
    for (int t = 0; t < N; ++t) {
        scanf("%lld", &M);
        int x = 0, y = 0;
        ll xv = 2, yv = 2;
        int flag = 0;
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 64; ++j) {
                xv = (1LL << i);
                yv = (1LL << j);
                if (xv + yv == M) {
                    printf("%d %d\n", i, j);
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
    }

    return 0;
}