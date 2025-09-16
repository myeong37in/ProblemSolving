#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int map[8][8];

typedef struct CCTV {
	int y, x;
	int type;
} CCTTV;

CCTTV CCTVs[64];

int check(int last[8][8]) {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 0 && last[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void right(int y, int x, int current_checked[8][8]) {
	for (int i = x; i < M; ++i) {
		if (map[y][i] == 6) break;
		current_checked[y][i] = 1;
	}
}

void left(int y, int x, int current_checked[8][8]) {
	for (int i = x; i >= 0; --i) {
		if (map[y][i] == 6) break;
		current_checked[y][i] = 1;
	}
}

void up(int y, int x, int current_checked[8][8]) {
	for (int i = y; i >= 0; --i) {
		if (map[i][x] == 6) break;
		current_checked[i][x] = 1;
	}
}

void down(int y, int x, int current_checked[8][8]) {
	for (int i = y; i < N; ++i) {
		if (map[i][x] == 6) break;
		current_checked[i][x] = 1;
	}
}

int ans = 10e8;
void recursive(int cnt, int max, int parent_checked[8][8]) {
	if (cnt == max) {
		int tmp = check(parent_checked);
		if (tmp < ans) ans = tmp;
		return;
	}

	CCTTV cur = CCTVs[cnt];
	int temp_checked[8][8];

	if (cur.type == 1) {
		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		right(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		left(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		up(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);
	}
	else if (cur.type == 2) {
		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		right(cur.y, cur.x, temp_checked);
		left(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		up(cur.y, cur.x, temp_checked);
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);
	}
	else if (cur.type == 3) {
		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		right(cur.y, cur.x, temp_checked);
		up(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		right(cur.y, cur.x, temp_checked);
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		left(cur.y, cur.x, temp_checked);
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		left(cur.y, cur.x, temp_checked);
		up(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);
	}
	else if (cur.type == 4) {
		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		left(cur.y, cur.x, temp_checked);
		right(cur.y, cur.x, temp_checked);
		up(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		right(cur.y, cur.x, temp_checked);
		left(cur.y, cur.x, temp_checked);
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		left(cur.y, cur.x, temp_checked);
		up(cur.y, cur.x, temp_checked);
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);

		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		right(cur.y, cur.x, temp_checked);
		up(cur.y, cur.x, temp_checked);
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);
	}
	else if (cur.type == 5) {
		memcpy(temp_checked, parent_checked, sizeof(temp_checked));
		left(cur.y, cur.x, temp_checked);
		right(cur.y, cur.x, temp_checked);
		up(cur.y, cur.x, temp_checked);
		down(cur.y, cur.x, temp_checked);
		recursive(cnt + 1, max, temp_checked);
	}
}

int main(int argc, char* argv[]) {
	scanf("%d %d", &N, &M);

	int initial_checked[8][8] = { 0, };
	int cidx = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				CCTTV cc = {i, j, map[i][j]};
				CCTVs[cidx++] = cc;
			}
		}
	}

	recursive(0, cidx, initial_checked);

	printf("%d", ans);

	return 0;
}