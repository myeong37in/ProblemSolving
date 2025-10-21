/*
map이 문자열을 key로 받으면 lexicographical compare해준다고
*/

#include <iostream>
#include <map>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::map<std::string, int> mp;
    std::string book;
    for (int i = 0; i < N; i++) {
        std::cin >> book;
        mp[book]++;
    }

    int best_cnt = 0;
    std::string best_str;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > best_cnt) {
            best_cnt = it->second;
            best_str = it->first;
        }
    }

    std::cout << best_str;

    return 0;
}