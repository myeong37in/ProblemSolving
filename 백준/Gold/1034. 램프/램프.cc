/*
어떤 행을 켜진 상태로 만들면 초기에 그것과 같은 상태였던 행이 모두 켜진 상태가 됨

기본적으로 최초에 상태가 중복되는 행 중 최대 개수가 답

그러나 그 행을 켜짐 상태로 만드는 데 필요한 횟수 cnt가 K보다 크거나 둘의 홀짝성이 맞지 않으면 불가능
*/

#include <iostream>
#include <map>
#include <string>

int main(int argc, char* argv[]) {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   
   std::map<std::string, int> mp;
   
   int N, M;
   std::cin >> N >> M;
   
   std::string line;
   for (int i = 0; i < N; i++) {
        std::cin >> line;
        mp[line]++;
   }
   
   int K;
   std::cin >> K;
   
   int best = 0;
   auto it = mp.begin();
   for (; it != mp.end(); it++) {
        std::string cur = it->first;
        int cnt = it->second;
        
        int zero_cnt = 0;
        for (const char& ch : cur) {
            if (ch == '0') {
                zero_cnt++;
            }
        }
        
        if (zero_cnt <= K && (((zero_cnt ^ K) & 1) == 0)) {
            best = std::max(best, cnt);
        }
   }
   
   std::cout << best;
    
    return 0;
}