/*
.5나 .0이 아닌 수는 못 만듦

2배로 하면 정수 연산 가능할 듯

+ 18단위, +14단위, +9단위, -4단위로 2N에 도달하는 최소 횟수

각각 p, q, r, s번 사용한다고 하면

2N = 18p + 14q + 9r - 4s. 이때 p + q + r + s 최소화

18 - 4 = 14이므로 p와 s가 한 번씩 나오면 그건 q 한 번으로 대체 가능

따라서 최적해에서 p = 0 or s = 0

r이 2번 나오면 p 한 번으로 대체 가능.

따라서 최적해에서 r <= 1

18 * 7 = 14 * 9이므로 q가 9번 나오면 p 7번으로 대체 가능

따라서 최적해에서 q <= 8

조건들을 생각했을 때 최적해에서

2N = 18p + 14q + 9r - 4s (0 <= q <= 8, r = 0 or r = 1, p = 0 or s = 0) <= 18p + 14 * 8 + 9 = 18p + 121

p 없이 만들 수 있는 최대 수는 121임.

따라서 2N >= 122일 때 p가 반드시 들어가야 하므로 s = 0으로 고정.
q = 0, 1, ..., 8과 r = 0, 1일 때로 총 18개의 경우에 대해
18p = 2N - 14q - 9r을 만족하는 정수 p 중 p + q + r이 최소가 되는 경우를 고르면 됨

2N <= 121일 때
0에서 시작해서 +18, +14, +9, -4를 하여 2N을 만드는 BFS 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str;
    std::cin >> str;

    // double N = std::stod(str); // 이거 제대로 안 나오네.. 문자열 파싱해야 할 듯
    int pos = str.find('.');
    if (str[pos + 1] != '0' && str[pos + 1] != '5') {
        std::cout << -1;
        return 0;
    }

    long long times_ten = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            continue;
        }
        times_ten *= 10;
        times_ten += str[i] - '0';
    }

    long long target = static_cast<long long>(times_ten / 5);

    if (target >= 122) {
        long long best = 9e18;
        for (int q = 0; q <= 8; q++) {
            for (int r = 0; r <= 1; r++) {
                long long rem = target - 14 * q - 9 * r;
                if (rem % 18 == 0) {
                    best = std::min(best, rem / 18 + q + r);
                }
            }
        }

        if (best != 9e18) {
            std::cout << best;
            return 0;
        }
    }
    else {
        std::vector<bool> visited(122);
        std::queue<std::pair<int, int>> q; // {숫자, 횟수}
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [num, cnt] = q.front();
            q.pop();

            if (num == target) {
                std::cout << cnt;
                return 0;
            }

            if (num + 18 <= 121 && !visited[num + 18]) {
                q.push({num + 18, cnt + 1});
                visited[num + 18] = true;
            }

            if (num + 14 <= 121 && !visited[num + 14]) {
                q.push({num + 14, cnt + 1});
                visited[num + 14] = true;
            }

            if (num + 9 <= 121 && !visited[num + 9]) {
                q.push({num + 9, cnt + 1});
                visited[num + 9] = true;
            }

            if (num - 4 >= 0 && !visited[num - 4]) {
                q.push({num - 4, cnt + 1});
                visited[num - 4] = true;
            }
        }
    }

    std::cout << -1;
    
    return 0;
}