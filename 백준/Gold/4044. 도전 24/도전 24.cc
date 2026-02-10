/*
수 배열: 4!
연산자 배정: 4^3
괄호 배정: 카탈란 수 5개
    (((a ? b) ? c) ? d)
    ((a ? (b ? c)) ? d)
    ((a ? b) ? (c ? d))
    (a ? ((b ? c) ? d))
    (a ? (b ? (c ? d)))
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

constexpr int IMPOSSIBLE = 2e9;

static inline int Calc(int a, char op, int b) {
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else if (op == '*') {
        return a * b;
    }
    else if (b == 0 || a % b) {
        return IMPOSSIBLE;
    }
    else {
        return a / b;
    }
}

std::unordered_set<int> res_us;
static void AssignOperator(std::vector<int>& num, std::vector<char> selected) {
    if (selected.size() == 3) {
        // (((a ? b) ? c) ? d)
        bool invalid = false;
        int res = Calc(num[0], selected[0], num[1]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(res, selected[1], num[2]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(res, selected[2], num[3]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        if (!invalid) {
            res_us.insert(res);
        }

        // ((a ? (b ? c)) ? d)
        invalid = false;
        res = Calc(num[1], selected[1], num[2]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(num[0], selected[0], res);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(res, selected[2], num[3]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        if (!invalid) {
            res_us.insert(res);
        }

        // ((a ? b) ? (c ? d))
        invalid = false;
        int res1 = Calc(num[0], selected[0], num[1]);
        if (res1 == IMPOSSIBLE) {
            invalid = true;
        }
        int res2 = Calc(num[2], selected[2], num[3]);
        if (res2 == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(res1, selected[1], res2);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        if (!invalid) {
            res_us.insert(res);
        }

        // (a ? ((b ? c) ? d))
        invalid = false;
        res = Calc(num[1], selected[1], num[2]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(res, selected[2], num[3]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(num[0], selected[0], res);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        if (!invalid) {
            res_us.insert(res);
        }

        // (a ? (b ? (c ? d)))
        invalid = false;
        res = Calc(num[2], selected[2], num[3]);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(num[1], selected[1], res);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        res = Calc(num[0], selected[0], res);
        if (res == IMPOSSIBLE) {
            invalid = true;
        }
        if (!invalid) {
            res_us.insert(res);
        }
        
        return;
    }

    selected.emplace_back('+');
    AssignOperator(num, selected);
    selected.pop_back();

    selected.emplace_back('-');
    AssignOperator(num, selected);
    selected.pop_back();

    selected.emplace_back('*');
    AssignOperator(num, selected);
    selected.pop_back();

    selected.emplace_back('/');
    AssignOperator(num, selected);
    selected.pop_back();
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc = 1;
    while (true) {
        std::vector<int> num(4);
        for (int i = 0; i < 4; i++) {
            std::cin >> num[i];
        }

        if (num[0] == 0) {
            break;
        }

        std::sort(num.begin(), num.end());
        res_us.clear();

        int best_len = 0, best_max; // 구간 최소, 구간 최대
        do {
            std::vector<char> selected;
            AssignOperator(num, selected);
        } while (std::next_permutation(num.begin(), num.end()));

        std::vector<int> res_vec(res_us.begin(), res_us.end());
        std::sort(res_vec.begin(), res_vec.end());
        
        int len = 0;
        int prev = res_vec[0] - 1;
        for (int n : res_vec) {
            if (n == prev + 1) {
                len++;
            }
            else {
                len = 1;
            }

            if (len >= best_len) {
                best_len = len;
                best_max = n;
            }
            prev = n;
        }

        std::cout << "Case " << tc << ": " << best_max - best_len + 1 << " to " << best_max << "\n";
        tc++;
    }
    
    return 0;
}