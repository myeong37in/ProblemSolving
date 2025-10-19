/*
개미굴이네
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct TrieNode {
    std::map<std::string, int> child;
};

std::vector<TrieNode> trie;

static inline void Init() {
    trie.clear();
    trie.emplace_back();
}

static std::vector<std::string> Tokenize(const std::string& str) {
    int prev = 0, idx = 0;
    int L = str.size();
    std::vector<std::string> tokens;
    while (true) {
        while (idx < L && str[idx] != '\\') {
            idx++;
        }

        tokens.emplace_back(str.substr(prev, idx - prev));
        prev = idx + 1;
        if (idx == L) {
            break;
        }
        idx++;
    }

    return tokens;
}

static void Insert(const std::string& str) {
    std::vector<std::string> tokens = Tokenize(str);
    int node = 0;
    for (const std::string& token : tokens) {
        if (trie[node].child.find(token) == trie[node].child.end()) {
            trie[node].child[token] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].child[token];
    }
}

static void PrintTrie(int depth, int node) {
    for (const auto& [str, nxt] : trie[node].child) {
        for (int i = 0; i < depth; i++) {
            std::cout << " ";
        }
        std::cout << str << "\n";
        PrintTrie(depth + 1, nxt);
    }
}

int main(int argc, char* argv[]){
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

    PrintTrie(0, 0);

    return 0;
}