/*
난 생각하기 귀찮다.
생각하기 귀찮기 때문이다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    constexpr int MAX_TIME = 48 * 60;
    std::vector<int> team1_score(MAX_TIME), team2_score(MAX_TIME); // teamX_score[t]: t분에서 시작하는 1분 동안 그 팀이 보유한 점수
    int team, time;
    std::string time_str;
    for (int i = 0; i < N; i++) {
        std::cin >> team >> time_str;
        time = std::stoi(time_str.substr(0, 2)) * 60 + std::stoi(time_str.substr(3, 2));
        if (team == 1) {
            for (int t = time; t < MAX_TIME; t++) {
                team1_score[t]++;
            }
        }
        else {
            for (int t = time; t < MAX_TIME; t++) {
                team2_score[t]++;
            }
        }
    }

    int team1_sum = 0, team2_sum = 0;
    for (int t = 0; t < MAX_TIME; t++) {
        if (team1_score[t] > team2_score[t]) {
            team1_sum++;
        }
        else if (team1_score[t] < team2_score[t]) {
            team2_sum++;
        }
    }

    std::string team1_mm = std::to_string(team1_sum / 60);
    std::string team1_ss = std::to_string(team1_sum % 60);
    std::string team2_mm = std::to_string(team2_sum / 60);
    std::string team2_ss = std::to_string(team2_sum % 60);
    if (team1_mm.size() == 1) {
        team1_mm = '0' + team1_mm;
    }
    if (team1_ss.size() == 1) {
        team1_ss = '0' + team1_ss;
    }
    if (team2_mm.size() == 1) {
        team2_mm = '0' + team2_mm;
    }
    if (team2_ss.size() == 1) {
        team2_ss = '0' + team2_ss;
    }

    std::cout << team1_mm << ":" << team1_ss << "\n" << team2_mm << ":" << team2_ss;

    return 0;
}