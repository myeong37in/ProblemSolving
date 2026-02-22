/*
보이는 그대로 구현하면 될 듯
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

static inline int ParseTime(std::string& t) {
    int hh = (t[0] - '0') * 10 + (t[1] - '0');
    int mm = (t[3] - '0') * 10 + (t[4] - '0');

    return hh * 60 + mm;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    int W = M / 7;
    std::vector<std::vector<int>> cnts(100, std::vector<int> (W)), sums(100, std::vector<int> (W)); // 각 번호의 방송인마다, 주마다 방송 횟수와 시간 합 저장
    std::vector<std::string> names; // 고유 번호 -> 이름
    std::unordered_map<std::string, int> ids; // 이름 -> 고유 번호

    std::string name, start, end;
    int day;
    for (int i = 0; i < N; i++) {
        std::cin >> name >> day >> start >> end;
        
        if (ids.find(name) == ids.end()) {
            int id = names.size();
            ids[name] = id;
            names.emplace_back(name);
        }

        int id = ids[name];
        int week = (day - 1) / 7;
        int duration = ParseTime(end) - ParseTime(start);

        cnts[id][week]++;
        sums[id][week] += duration;
    }

    // "사전 순으로 한 줄에 하나씩 출력하시오".. 문제를 잘 읽읍시다.
    std::vector<std::string> ans;
    for (int id = 0; id < names.size(); id++) {
        bool ok = true;
        for (int week = 0; week < W; week++) {
            if (cnts[id][week] < 5 || sums[id][week] < 3600) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans.emplace_back(names[id]);
        }
    }

    std::sort(ans.begin(), ans.end());
    if (ans.empty()) {
        std::cout << -1;
    }
    else {
        for (std::string& s : ans) {
            std::cout << s << "\n";
        }
    }

    return 0;
}