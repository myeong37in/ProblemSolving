/*
trie로 풀어 봅시다. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct TrieNode {
    int child[26];
    bool is_end;

    TrieNode() {
        std::fill(child, child + 26, -1);
        is_end = false;
    }
};

std::vector<TrieNode> trie;

void Init() {
    trie.clear();
    trie.emplace_back();
}

static void Insert(const std::string& str) {
    int node = 0;
    for (const char& ch : str) {
        int c = ch - 'a';
        if (trie[node].child[c] == -1) {
            trie[node].child[c] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].child[c];
    }
    trie[node].is_end = true;
}

static bool Search(const std::string& str) {
    int node = 0;
    for (const char& ch : str) {
        int c = ch - 'a';
        if (trie[node].child[c] == -1) {
            return false;
        }
        node = trie[node].child[c];
    }
    return true; // 접두사를 묻는 것이므로 완전 일치(is_end를 검사)할 필요는 없음
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    Init();

    std::string str;
    for (int i = 0; i < N; i++) {
        std::cin >> str;
        Insert(str);
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        std::cin >> str;
        if (Search(str)) {
            ans++;
        }
    }

    std::cout << ans;

    return 0;
}