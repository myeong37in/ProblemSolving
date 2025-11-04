/*
이건 trie같은데

길이가 최대 20이니 해싱으로도 풀 수 있겠다.
*/

#include <string>
#include <vector>

struct TrieNode {
    int child[10];
    bool is_end;
    
    TrieNode() {
        std::fill(child, child + 10, -1);
        is_end = false;
    }
};

std::vector<TrieNode> trie;

void Init() {
    trie.clear();
    trie.emplace_back();
}

void Insert(std::string str) {
    int node = 0;
    for (const char& ch : str) {
        int c = ch - '0';
        
        if (trie[node].child[c] == -1) {
            trie[node].child[c] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].child[c];
    }
    trie[node].is_end = true;
}

// true: 접두어가 아님
bool Search(std::string str) {
    int node = 0;
    for (const char& ch : str) {
        int c = ch - '0';
        node = trie[node].child[c];
    }
    
    for (int i = 0; i < 10; i++) {
        if (trie[node].child[i] != -1) { // 뒤로 더 있으면 접두어임
            return true;
        }
    }
    
    return false;
}

using namespace std;

bool solution(vector<string> phone_book) {
    Init();
    
    for (const auto& s : phone_book) {
        Insert(s);
    }
    
    for (const auto& s : phone_book) {
        if (Search(s)) {
            return false;
        }
    }
    
    return true;
}