/*
주어진 4장을 확인한 다음 카드를 넣어본다 vs 카드를 넣어보고 5장을 확인한다.

후자가 나음. 전자로 스트레이트 판정하려면 벌써 머리가 아파

정렬해 두면 연속은 보기 쉽겠지. overflow도 보려면 13 더해서 이어주기
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Card {
    int suit, rank;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<Card> cards(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> cards[i].suit >> cards[i].rank;
    }

    int hand_flag = 0; // pair 0번 bit부터 straight flush 7번 bit까지, 나오면 켜기. 패가 완성되면 현재까지 나온 가장 좋은 패와 비교 가능
    int ans_s = -1, ans_r = -1;
    for (int s = 0; s <= 3; s++) {
        for (int r = 1; r <= 13; r++) {
            bool okay = true;
            for (Card& c : cards) {
                if (c.suit == s && c.rank == r) { // 중복
                    okay = false;
                    break;
                }
            }

            if (!okay) {
                continue;
            }

            cards.emplace_back(Card {s, r}); // 조커 카드 넣기

            std::vector<Card> temp = cards;
            for (int i = 0; i < 5; i++) {
                temp.emplace_back(Card {cards[i].suit, cards[i].rank + 13});
            }

            std::sort(temp.begin(), temp.end(), [](const Card& a, const Card& b) {
                return a.rank < b.rank;
            });

            bool same_suit = true, sequential = false;
            int sequential_rank_cnt = 1;
            for (int i = 1; i < 10; i++) {
                if (temp[0].suit != temp[i].suit) {
                    same_suit = false;
                }
                
                if (temp[i - 1].rank + 1 == temp[i].rank) {
                    sequential_rank_cnt++;
                }
                else {
                    sequential_rank_cnt = 1;
                }

                if (sequential_rank_cnt >= 5) {
                    sequential = true;
                    break;
                }
            }

            // straight flush
            if (same_suit && sequential) {
                if (hand_flag < (1 << 7)) {
                    hand_flag |= (1 << 7);
                    ans_s = s, ans_r = r;
                }
            }

            // quadruple
            std::vector<int> counts(14);
            for (Card& c : cards) {
                counts[c.rank]++;
            }

            for (int cnt : counts) {
                if (cnt >= 4) {
                    if (hand_flag < (1 << 6)) {
                        hand_flag |= (1 << 6);
                        ans_s = s, ans_r = r;
                    }
                }
            }

            bool triple = false;
            int pair_cnt = 0;
            for (int cnt : counts) {
                if (cnt == 3) {
                    triple = true;
                }
                else if (cnt == 2) {
                    pair_cnt++;
                }
            }

            // full house
            if (triple && pair_cnt) {
                if (hand_flag < (1 << 5)) {
                    hand_flag |= (1 << 5);
                    ans_s = s, ans_r = r;
                }
            }

            // flush
            if (same_suit) {
                if (hand_flag < (1 << 4)) {
                    hand_flag |= (1 << 4);
                    ans_s = s, ans_r = r;
                }
            }

            // straight
            if (sequential) {
                if (hand_flag < (1 << 3)) {
                    hand_flag |= (1 << 3);
                    ans_s = s, ans_r = r;
                }
            }

            if (triple) {
                if (hand_flag < (1 << 2)) {
                    hand_flag |= (1 << 2);
                    ans_s = s, ans_r = r;
                }
            }

            if (pair_cnt >= 2) {
                if (hand_flag < (1 << 1)) {
                    hand_flag |= (1 <<1);
                    ans_s = s, ans_r = r;
                }
            }

            if (pair_cnt) {
                if (hand_flag < (1 << 0)) {
                    hand_flag |= (1 << 0);
                    ans_s = s, ans_r = r;
                }
            }

            cards.pop_back(); // 넣은 조커 카드 빼기
        }
    }

    std::cout << ans_s << " " << ans_r;

    return 0;
}