/*
unordered_map으로 장르 -> 인덱스 매칭

정렬 기준에 따라 장르 간, 장르 내 정렬
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Genre {
    int total_played;
    std::vector<std::pair<int, int>> songs; // {고유 번호, 재생 횟수}
};

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    int N = genres.size();
    std::unordered_map<std::string, int> um;
    std::vector<Genre> vec(N); // 최대 N개
    for (int i = 0; i < N; i++) {
        std::string genre = genres[i];
        int play = plays[i];
        
        int idx;
        if (um.find(genre) == um.end()) {
            idx = um.size();
            um[genre] = idx;
        }
        else {
            idx = um[genre];
        }
        
        vec[idx].total_played += play;
        vec[idx].songs.emplace_back(i, plays[i]);
    }
    
    // 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
    std::sort(vec.begin(), vec.end(), [](const Genre& a, const Genre& b) {
        return a.total_played > b.total_played; 
    });
    
    for (int i = 0; i < N; i++) {
        auto& songs = vec[i].songs;
        if (songs.empty()) {
            continue;
        }
        
        std::sort(songs.begin(), songs.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                return a.first < b.first; // 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다. 
            } 
            return a.second > b.second; // 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
        });
    }
    
    vector<int> answer;
    for (int i = 0; i < N; i++) {
        auto& songs = vec[i].songs;
        if (songs.empty()) {
            continue;
        }
        
        answer.emplace_back(songs[0].first);
        if (songs.size() >= 2) {
            answer.emplace_back(songs[1].first);
        }
    }
    
    return answer;
}