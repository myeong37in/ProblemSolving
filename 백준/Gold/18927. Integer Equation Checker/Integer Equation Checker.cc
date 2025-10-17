/*
문자열의 왕이 되기 위한 길은 멀고도 험하다
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Ret {
    int num1, num2, num3;
    char op;
};

static const std::string valid_letters = "0123456789+-*/=";

static inline void FormatError() {
    std::cout << "Format Error";
    exit(0);
}

static inline void MathError() {
    std::cout << "Math Error";
    exit(0);
}

static inline void Typo(const std::string& str, const std::string& fixed_str) {
    std::cout << "Typo: " << str << " instead of " << fixed_str;
    exit(0);
}

static bool Check(int num1, char op, int num2, int num3) {
    if (op == '+') {
        return (num1 + num2 == num3);
    }
    else if (op == '-') {
        return (num1 - num2 == num3);
    }
    else if (op == '*') {
        return (static_cast<long long>(num1) * num2 == num3);
    }
    else {
        return ((num1 / num2 == num3) && (num1 % num2 == 0));
    }
}

static Ret Parse(std::string& str) {
    std::string num1_str, num2_str, num3_str;
    char op;
    int idx = 0, prev = 0, L = str.size();
    while (idx < L && std::isdigit(str[idx])) {
        idx++;
    }
    num1_str = str.substr(prev, idx - prev);
    if (num1_str.empty() || num1_str[0] == '0') {
        FormatError();
    }
    
    if (idx == L) {
        FormatError();
    }
    
    op = str[idx++];
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        FormatError();
    }
    prev = idx;

    while (idx < L && std::isdigit(str[idx])) {
        idx++;
    }
    num2_str = str.substr(prev, idx - prev);
    if (num2_str.empty() || num2_str[0] == '0') {
        FormatError();
    }

    if (idx == L) {
        FormatError();
    }

    if (str[idx++] != '=') {
        FormatError();
    }
    prev = idx;

    while (idx < L && std::isdigit(str[idx])) {
        idx++;
    }
    num3_str = str.substr(prev, idx - prev);
    if (num3_str.empty() || num3_str[0] == '0' || idx != L) { // 문자열 끝이 아니면 에러
        FormatError();
    }

    int num1, num2, num3;
    try { // int 범위를 벗어나거나 문제에서 명시된 범위를 벗어나면 std::out_of_range
        num1 = std::stoi(num1_str);
        num2 = std::stoi(num2_str);
        num3 = std::stoi(num3_str);

        if (num1 == 0 || num1 > 1e9 || num2 == 0 || num2 > 1e9 || num3 == 0 || num3 > 1e9) {
            throw std::out_of_range("");
        }
    } catch (const std::out_of_range& e) {
        FormatError();
    }

    return Ret {num1, num2, num3, op};
}

static bool TryParse(std::string& str, Ret& res) {
    std::string num1_str, num2_str, num3_str;
    char op;
    int idx = 0, prev = 0, L = str.size();
    while (idx < L && std::isdigit(str[idx])) {
        idx++;
    }
    num1_str = str.substr(prev, idx - prev);
    if (num1_str.empty() || num1_str[0] == '0') {
        return false;
    }
    
    if (idx == L) {
        return false;
    }
    
    op = str[idx++];
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        return false;
    }
    prev = idx;

    while (idx < L && std::isdigit(str[idx])) {
        idx++;
    }
    num2_str = str.substr(prev, idx - prev);
    if (num2_str.empty() || num2_str[0] == '0') {
        return false;
    }

    if (idx == L) {
        return false;
    }

    if (str[idx++] != '=') {
        return false;
    }
    prev = idx;

    while (idx < L && std::isdigit(str[idx])) {
        idx++;
    }
    num3_str = str.substr(prev, idx - prev);
    if (num3_str.empty() || num3_str[0] == '0' || idx != L) {
        return false;
    }

    int num1, num2, num3;
    try {
        num1 = std::stoi(num1_str);
        num2 = std::stoi(num2_str);
        num3 = std::stoi(num3_str);

        if (num1 == 0 || num1 > 1e9 || num2 == 0 || num2 > 1e9 || num3 == 0 || num3 > 1e9) {
            return false;
        }
    } catch (const std::out_of_range& e) {
        return false;
    }

    res = {num1, num2, num3, op};
    return true;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    auto [num1, num2, num3, op] = Parse(str);

    // 최초 Correct 체크
    if (Check(num1, op, num2, num3)) {
        std::cout << "Correct";
        return 0;
    }

    // 최대 2개 바꿔서 Correct 체크
    int L = str.size();
    // 1글자 치환
    for (int i = 0; i < L; i++) {
        char orig = str[i];
        for (char ch : valid_letters) {
            if (ch == orig) {
                continue;
            }

            std::string fixed_str = str;
            fixed_str[i] = ch;

            Ret res;
            if (TryParse(fixed_str, res) && Check(res.num1, res.op, res.num2, res.num3)) {
                Typo(str, fixed_str);
            }
        }
    }

    // 2글자 치환
    for (int i = 0; i < L - 1; i++) {
        for (int j = i + 1; j < L; j++) {
            char o1 = str[i], o2 = str[j];
            for (char c1 : valid_letters) {
                if (c1 == o1) {
                    continue;
                }
                for (char c2 : valid_letters) {
                    if (c2 == o2) {
                        continue;
                    }

                    std::string fixed_str = str;
                    fixed_str[i] = c1;
                    fixed_str[j] = c2;

                    Ret res;
                    if (TryParse(fixed_str, res) && Check(res.num1, res.op, res.num2, res.num3)) {
                        Typo(str, fixed_str);
                    }
                }
            }
        }
    }

    // 아니면 Math Error
    MathError();

    return 0;
}