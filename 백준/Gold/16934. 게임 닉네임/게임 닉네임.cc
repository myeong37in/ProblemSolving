/*
트라이에다가, 뒤에 숫자 붙이는 건 해시맵으로 하면 되려나
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct TrieNode {
    int child[26];
    bool is_end;

    TrieNode() {
        std::fill(child, child + 26, -1);
        is_end = false;
    }
};

std::vector<TrieNode> trie;

std::unordered_map<std::string, int> user_name;

static void Init() {
    trie.clear();
    trie.emplace_back();
}

static void Insert(std::string str) {
    int node = 0;
    std::string prefix, ans;
    for (char ch : str) {
        prefix += ch;
        int c = ch - 'a';
        // 현재까지 prefix를 접두사로 갖는 문자열 없음.
        if (trie[node].child[c] == -1) {
            trie[node].child[c] = trie.size();
            trie.emplace_back();

            // 최초로 나타날 때 답
            if (ans.empty()) {
                ans = prefix;
            }
        }

        node = trie[node].child[c];
    }
    
    // 못 정했음
    if (ans.empty()) {
        if (user_name.find(str) == user_name.end()) {
            ans = str;
        }        
        else {
            ans = str + std::to_string(user_name[str] + 1);
        }
    }

    user_name[str]++;

    std::cout << ans << "\n";

    return;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    Init();

    std::string str;
    for (int i = 0; i < N; i++) {
        std::cin >> str;
        
        Insert(str);
    }
    
    return 0;
}