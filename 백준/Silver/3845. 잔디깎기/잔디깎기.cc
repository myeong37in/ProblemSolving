/*
문자열로 받아서 10^8을 곱하면 돼요.. 
그 뒤로는 스위핑이에요..
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

constexpr int MULT = 100'000'000;
constexpr long long X_END = 7'500'000'000;
constexpr long long Y_END = 10'000'000'000;

long long Mult1e8(std::string& str) {
    size_t pos = str.find('.');
    if (pos == std::string::npos) { // 정수형
        return std::stoll(str) * MULT;
    }

    int zero_cnt = 9 - (str.size() - pos);
    str.erase(pos, 1);
    for (int i = 0; i < zero_cnt; i++) {
        str += '0';
    }

    return std::stoll(str);
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nx, ny;
    std::string w_str;
    while (std::cin >> nx >> ny >> w_str) {
        if (w_str == "0.0") {
            break;
        }

        long long w = Mult1e8(w_str);
        std::string xi, yi;
        std::vector<long long> x_coords(nx), y_coords(ny);
        for (int i = 0; i < nx; i++) {
            std::cin >> xi;
            x_coords[i] = Mult1e8(xi);
        }
        for (int i = 0; i < ny; i++) {
            std::cin >> yi;
            y_coords[i] = Mult1e8(yi);
        }

        std::sort(x_coords.begin(), x_coords.end());
        std::sort(y_coords.begin(), y_coords.end());

        long long prev_x = 0;
        bool okay = true;
        for (int i = 0; i < nx; i++) {
            if (x_coords[i] - w / 2 > prev_x) {
                okay = false;
                break;
            }
            else {
                prev_x = x_coords[i] + w / 2; // 단조 증가
            }
        }
        if (!okay || prev_x < X_END) { // 중간에 끊겼거나 끝에 도달하지 못하면 NO
            std::cout << "NO\n";
            continue;
        }

        long long prev_y = 0;
        for (int i = 0; i < ny; i++) {
            if (y_coords[i] - w / 2 > prev_y) {
                okay = false;
                break;
            }
            else {
                prev_y = y_coords[i] + w / 2;
            }
        }
        if (!okay || prev_y < Y_END) {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
    }

    return 0;
}