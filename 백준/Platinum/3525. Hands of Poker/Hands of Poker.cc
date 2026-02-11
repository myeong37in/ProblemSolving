/*
각 족보에 속하는 점수의 개수를 세고 입력 카드의 족보를 구한 후 그 안에서 타이브레이커 순위 얻기

하면 될 듯?

straight flush: 10개
    A 2 3 4 5 ~ T J Q K A

four of a kind: 156개
    포카드를 이루는 카드가 13장, 각 카드마다 나머지 12장

full house: 156개
    트리플 이루는 카드가 13장, 페어를 이루는 카드가 나머지 12장

flush: 1,277개
    C(13, 5)
    - 10(straight flush와 겹치는 경우)

straight: 10개
    A 2 3 4 5 ~ T J Q K A

three of a kind: 858개
    트리플 이루는 카드가 13장, 나머지 2장을 서로 다른 rank로 이루는(같으면 full house) 조합이 C(12, 2)장

two pairs: 858개
    페어를 이루는 서로 다른 rank의 카드 2장을 뽑는 것으로 C(13, 2)장, 나머지 1장을 이루는 카드가 11장

one pair: 2,860개
    페어를 이루는 카드가 13장, 나머지 3장을 이루는 카드가 C(12, 3)장

high card: 1,277개
    13개의 rank에서 순서 없이 C(13, 5)장
    - 10(straight와 겹치는 경우)

합쳐서 7,462개
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static inline bool IsStraight(std::vector<int> ranks) {
    // A 2 3 4 5
    if (ranks[0] == 2 && ranks[1] == 3 && ranks[2] == 4 && ranks[3] == 5 && ranks[4] == 14) {
        return true;
    }

    for (int i = 1; i < 5; i++) {
        if (ranks[i] != ranks[i - 1] + 1) {
            return false;
        }
    }

    return true;
}

static inline int C(int n, int k) {
    int res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }

    return res;
}

// a < b일 때 (b, a) 조합의 약한 조합부터 0으로 배정한 랭크
static inline int GetRankLex(int a, int b) {
    return C(b, 2) + C(a, 1);
}

// a < b < c : (c, b, a) 조합 랭크
static inline int GetRankLex(int a, int b, int c) {
    // max < c 인 개수 = C(c,3)
    // max = c 고정에서 second < b 인 개수 = C(b,2)
    // (c,b) 고정에서 a는 0..a-1
    return C(c, 3) + C(b, 2) + C(a, 1);
}

// a < b < c < d < e : (e, d, c, b, a) 조합 랭크
static inline int GetRankLex(int a, int b, int c, int d, int e) {
    return C(e, 5) + C(d, 4) + C(c, 3) + C(b, 2) + C(a, 1);
}

// four of a kind, full house
static int CalcIndex(int tb1, int tb2) {
    int idx = tb1 - 2;

    std::vector<int> avail(12); // tb1을 제외한 12장의 카드에서 tiebreaker들의 순위(오름차순)
    int p = 0;
    for (int i = 2; i <= 14; i++) {
        if (i == tb1) {
            continue;
        }
        avail[p++] = i;
    }

    int a;
    for (int i = 0; i < 12; i++) {
        if (avail[i] == tb2) {
            a = i;
        }
    }

    return idx * 12 + a;
}

// three of a kind
static int CalcIndexTrips(int tb1, int tb2, int tb3) {
    int idx = tb1 - 2;
    
    std::vector<int> avail(12); 
    int p = 0;
    for (int i = 2; i <= 14; i++) {
        if (i == tb1) {
            continue;
        }
        avail[p++] = i;
    }

    int a, b;
    for (int i = 0; i < 12; i++) {
        if (avail[i] == tb2) {
            a = i; // a: tb2의 순위(약한 것부터 0번에서 12번까지)
        }
        else if (avail[i] == tb3) {
            b = i; // b: tb1의 순위.
        }
    }

    if (a > b) { // a < b 보장
        std::swap(a, b);
    }

    // 하나의 idx마다 C(12, 2) = 66개의 순위 분포
    // 66개 안에서 0-65는 다음과 같이 계산
    // 0: (avail[0], avail[1]), 65: (avail[10], avail[11])
    return idx * 66 + GetRankLex(a, b);
}

static int CalcIndexTwoPairs(int tb1, int tb2, int tb3) {
    int hi = std::max(tb1, tb2);
    int lo = std::min(tb1, tb2);

    // (hi, lo) 순번: hi가 우선(약->강: 작은 hi 먼저), 같은 hi면 lo가 작은 게 먼저
    // hi는 3..14, lo는 2..hi-1
    // hi_idx = hi-2 (1..12)
    int hi_idx = hi - 2;
    int lo_idx = lo - 2;
    int pair_rank = (hi_idx - 1) * hi_idx / 2 + lo_idx;

    int a = 0;
    for (int i = 2; i <= 14; i++) {
        if (i == hi || i == lo) {
            continue;
        }
        
        if (i == tb3) {
            break;
        }
        a++;
    }

    return pair_rank * 11 + a;
}

// one pair
static int CalcIndex(int tb1, int tb2, int tb3, int tb4) {
    int idx = tb1 - 2;
    
    std::vector<int> avail(12); // k를 제외한 12장의 카드에서의 tiebreaker들의 순위(오름차순)
    int p = 0;
    for (int i = 2; i <= 14; i++) {
        if (i == tb1) {
            continue;
        }
        avail[p++] = i;
    }

    std::vector<int> tb_idx(3);
    for (int i = 0; i < 12; i++) {
        if (avail[i] == tb2) {
            tb_idx[0] = i; // tb2의 순위(약한 것부터 0번에서 12번까지)
        }
        else if (avail[i] == tb3) {
            tb_idx[1] = i; // tb3의 순위
        }
        else if (avail[i] == tb4) {
            tb_idx[2] = i; // tb4의 순위.
        }
    }

    std::sort(tb_idx.begin(), tb_idx.end());

    // 하나의 idx마다 C(12, 3) = 220개의 순위 분포
    // 220개 안에서 0-219는 다음과 같이 계산
    // 0: (avail[0], avail[1], avail[2]), 219: (avail[9], avail[10], avail[11])
    int comb_rank = GetRankLex(tb_idx[0], tb_idx[1], tb_idx[2]);
    return idx * 220 + comb_rank;
}

std::vector<int> straight_comb_ranks(10);
static void CalcStraightCombRanks() {
    // straight들의 인덱스. A 2 3 4 5부터 10 J Q K A까지 10개
    std::vector<std::vector<int>> straights = {{0, 1, 2, 3, 12}, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7},
                                               {4, 5, 6, 7, 8}, {5, 6, 7, 8, 9}, {6, 7, 8, 9, 10}, {7, 8, 9, 10, 11}, {8, 9, 10, 11, 12}};

    for (int i = 0; i < 10; i++) {
        straight_comb_ranks[i] = GetRankLex(straights[i][0], straights[i][1], straights[i][2], straights[i][3], straights[i][4]);
    }

    std::sort(straight_comb_ranks.begin(), straight_comb_ranks.end());
}

// flush, high card
static int CalcIndex(int tb1, int tb2, int tb3, int tb4, int tb5) {
    std::vector<int> tbs = {tb1, tb2, tb3, tb4, tb5};
    std::sort(tbs.begin(), tbs.end());

    int res = GetRankLex(tbs[0] - 2, tbs[1] - 2, tbs[2] - 2, tbs[3] - 2, tbs[4] - 2); // 랭크 -> 인덱스로 변환해 넣기. 0 - 1286. 13개 수 전부 사용 가능

    // 이 앞에 straight가 몇 개 있는지 계산하여 추가적으로 빼서 보정
    int k = std::lower_bound(straight_comb_ranks.begin(), straight_comb_ranks.end(), res) - straight_comb_ranks.begin();

    return res - k; // 0 - 1276
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> ranks(5);
    char suit = '0';
    bool flush = true;
    std::string card;
    for (int i = 0; i < 5; i++) {
        std::cin >> card;
        if (card[0] <= '9') {
            ranks[i] = card[0] - '0';
        }
        else {
            if (card[0] == 'A') {
                ranks[i] = 14;
            }
            else if (card[0] == 'T') {
                ranks[i] = 10;
            }
            else if (card[0] == 'J') {
                ranks[i] = 11;
            }
            else if (card[0] == 'Q') {
                ranks[i] = 12;
            }
            else {
                ranks[i] = 13;
            }
        }

        if (card[1] != suit) {
            if (suit == '0') {
                suit = card[1];
            }
            else {
                flush = false;
            }
        }
    }

    std::sort(ranks.begin(), ranks.end());
    bool straight = IsStraight(ranks);
    
    int ans = 7462;

    // straight flush
    if (straight && flush) {
        // A 2 3 4 5
        if (ranks[0] == 2 && ranks[4] == 14) {
            std::cout << 7453;
        }
        else {
            std::cout << ans - (10 - ranks[0]); // 2일 때 7454, 10일 때 7462
        }
        return 0;
    }

    ans -= 10; // straight flush 제외

    std::vector<int> cnts(15); // rank 개수 DAT
    for (int n : ranks) {
        cnts[n]++;
    }

    bool four_of_a_kind = false, three_of_a_kind = false;
    int pair_cnt = 0;
    for (int n : cnts) {
        if (n == 4) {
            four_of_a_kind = true;
            break;
        }
        else if (n == 3) {
            three_of_a_kind = true;
        }
        else if (n == 2) {
            pair_cnt++;
        }
    }

    // four of a kind
    if (four_of_a_kind) {
        int tb1; // four of a kind를 이루는 랭크
        int tb2; 
        if (ranks[0] == ranks[1]) { // 가장 큰 수가 다른 수
            tb1 = ranks[0];
            tb2 = ranks[4];
        }
        else { // 가장 작은 수가 다른 수
            tb1 = ranks[1];
            tb2 = ranks[0];
        }

        // ans 계산
        ans = ans - 156 + CalcIndex(tb1, tb2) + 1;

        std::cout << ans;
        return 0;
    }

    ans -= 156; // four of a kind 제외

    // full house
    if (three_of_a_kind && pair_cnt) {
        int tb1, tb2;
        for (int i = 1; i <= 14; i++) {
            if (cnts[i] == 3) {
                tb1 = i;
            }
            else if (cnts[i] == 2) {
                tb2 = i;
            }
        }

        // ans 계산
        ans = ans - 156 + CalcIndex(tb1, tb2) + 1;
        
        std::cout << ans;
        return 0;
    }

    ans -= 156; // full house 제외

    CalcStraightCombRanks();

    // flush
    if (flush) {
        // ans 계산
        ans = ans - 1277 + CalcIndex(ranks[0], ranks[1], ranks[2], ranks[3], ranks[4]) + 1;

        std::cout << ans;
        return 0;
    }

    ans -= 1277; // flush 제외

    // straight
    if (straight) {
        if (ranks[0] == 2 && ranks[4] == 14) { // A 2 3 4 5 최하위
            ans -= 9;
        }
        else {
            ans -= (14 - ranks[4]);
        }

        std::cout << ans;
        return 0;
    }

    ans -= 10; // straight 제외

    // three of a kind
    if (three_of_a_kind) {
        int tb1 = 0, tb2 = 0, tb3 = 0;
        for (int i = 1; i <= 14; i++) {
            if (cnts[i] == 3) {
                tb1 = i;
            }
            else if (cnts[i]) {
                // 작은 수가 먼저 나오는 것 고려
                tb3 = tb2;
                tb2 = i;
            }
        }

        // ans 계산
        ans = ans - 858 + CalcIndexTrips(tb1, tb2, tb3) + 1;

        std::cout << ans;
        return 0;
    }

    ans -= 858; // three of a kind 제외

    // two pairs
    if (pair_cnt == 2) {
        int tb1 = 0, tb2 = 0, tb3 = 0;
        for (int i = 1; i <= 14; i++) {
            if (cnts[i] == 2) {
                tb2 = tb1;
                tb1 = i;
            }
            else if (cnts[i]) {
                tb3 = i;
            }
        }

        // ans 계산
        ans = ans - 858 + CalcIndexTwoPairs(tb1, tb2, tb3) + 1;

        std::cout << ans;
        return 0;
    }

    ans -= 858; // two pairs 제외

    // one pair
    if (pair_cnt == 1) {
        int tb1 = 0;
        std::vector<int> tbs;
        for (int i = 1; i <= 14; i++) {
            if (cnts[i] == 2) {
                tb1 = i;
            }
            else if (cnts[i]) {
                tbs.emplace_back(i);
            }
        }

        std::sort(tbs.begin(), tbs.end(), std::greater<int>());
        
        // ans 계산
        ans = ans - 2860 + CalcIndex(tb1, tbs[0], tbs[1], tbs[2]) + 1;

        std::cout << ans;
        return 0;
    }

    ans -= 2860; // one pair 제외

    // high card
    // ans 계산
    ans = ans - 1277 + CalcIndex(ranks[0], ranks[1], ranks[2], ranks[3], ranks[4]) + 1;
    
    std::cout << ans;
    
    return 0;
}