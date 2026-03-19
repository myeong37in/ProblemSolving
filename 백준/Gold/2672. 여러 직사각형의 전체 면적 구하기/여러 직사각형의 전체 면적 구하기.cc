/*
좌표 * 10하면 정수 계산

최대 30개의 직사각형에 대해 스위핑 20,000번 하면 될 듯
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Rectangle {
    int sx, sy, ex, ey;
};

static inline int StrToInt(std::string str) {
    auto pos = str.find('.', 0);
    // 소수점이 없는 경우
    if (pos == std::string::npos) {
        return std::stoi(str) * 10;
    }

    str.erase(pos, 1);
    return std::stoi(str);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<Rectangle> seq(N);
    std::string x, y, w, h;
    int ix, iy, iw, ih;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y >> w >> h;

        ix = StrToInt(x);
        iy = StrToInt(y);
        iw = StrToInt(w);
        ih = StrToInt(h);

        seq[i].sx = ix;
        seq[i].sy = iy;
        seq[i].ex = ix + iw - 1;
        seq[i].ey = iy + ih - 1;
    }

    std::sort(seq.begin(), seq.end(), [](const Rectangle& a, const Rectangle& b) {
        if (a.sx == b.sx) {
            return a.ex < b.ex;
        }
        return a.sx < b.sx;
    });

    constexpr int MAX = 20'000;
    int ans = 0;
    for (int cy = 0; cy < MAX; cy++) {
        int start = 0;
        int end = -1;
        for (auto& [sx, sy, ex, ey] : seq) {
            // 이 영역에 없음
            if (sy > cy || ey < cy) {
                continue;
            }

            if (end < sx) {
                // 새로운 구간
                ans += (end - start + 1);
                start = sx;
                end = ex;
            }
            else {
                // 구간 확장
                end = std::max(end, ex);
            }
        }

        // 마지막 구간 반영
        ans += (end - start + 1);
    }

    // 각 변을 10배했으니 넓이는 100으로 나눠야 함
    if (ans % 100 == 0) {
        std::cout << ans / 100;
    }
    else {
        std::string ans_str = std::to_string(ans);
        int sz = ans_str.size();
        if (ans / 100 == 0) {
            // 0.xx
            std::cout << "0." << ans_str.substr(sz - 2, std::string::npos);
        }
        else {
            std::cout << ans_str.substr(0, sz - 2) << "." << ans_str.substr(sz - 2, std::string::npos);
        }
    }
    
    return 0;
}