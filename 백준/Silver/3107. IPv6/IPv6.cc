/*
colon 기본 7개.
::가 있으면 7 - colon 개수 + 1이 :: 사이에 생략된 0000의 개수.
::으로 시작하면 앞에도 생략
::으로 끝나면 뒤에도 생략

우선 생략된 부분 복구를 하고 앞에 0을 채우면 될 듯
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string address;
    std::cin >> address;

    int skip_cnt = 7;
    bool skipped = false;
    size_t prev = 0, pos = 0;
    while ((pos = address.find(':', pos)) != std::string::npos) {
        skip_cnt--;
        if (address[pos + 1] == ':') {
            skip_cnt--;
            skipped = true;
            pos++;
        }
        pos++;
    }

    if (skipped) {
        skip_cnt++;
    }

    address += ':'; // 보조 콜론 추가
    prev = 0, pos = 0;
    std::string temp;
    while ((pos = address.find(':', pos)) != std::string::npos) {
        temp += address.substr(prev, pos - prev + 1);
        if (address[pos + 1] == ':') { // "::"" 발견
            for (int i = 0; i < skip_cnt; i++) {
                temp += "0000:";
            }
            pos++;
        }
        pos++;
        prev = pos;
    }

    if (temp[0] == ':') { // "::"로 시작하는 경우
        temp = "0000" + temp;
    }
    if (temp[temp.size() - 2] == ':' && temp[temp.size() - 1] == ':') { // "::로 끝나는 경우"
        temp.pop_back();
        temp += "0000:";
    }

    prev = 0, pos = 0;
    std::string ans;
    while ((pos = temp.find(':', pos)) != std::string::npos) {
        for (int i = 0; i < prev - pos + 4; i++) {
            ans += '0';
        }
        ans += temp.substr(prev, pos - prev + 1);

        pos++;
        prev = pos;
    }

    ans.pop_back(); // 보조 콜론 제거

    std::cout << ans;

    return 0;
}