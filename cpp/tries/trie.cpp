/**
 * Trie (Prefix Tree) — C++20
 * =============================
 * Time: O(m) insert/search/prefix (m = word length)
 * Space: O(ALPHA * m * n) total
 */
#include <iostream>
#include <array>
#include <memory>
#include <string>
#include <vector>

namespace dsa {

struct TrieNode {
    std::array<std::unique_ptr<TrieNode>, 26> children;
    bool isEnd = false;
};

class Trie {
    std::unique_ptr<TrieNode> root;
public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string& word) {
        TrieNode* node = root.get();
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = std::make_unique<TrieNode>();
            node = node->children[idx].get();
        }
        node->isEnd = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root.get();
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx].get();
        }
        return node->isEnd;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* node = root.get();
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx].get();
        }
        return true;
    }
};

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    dsa::Trie trie;
    for (const auto& w : {"apple","app","application","apply"})
        trie.insert(w);

    std::cout << std::boolalpha;
    std::cout << trie.search("apple")      << "\n"; // true
    std::cout << trie.search("ap")         << "\n"; // false
    std::cout << trie.startsWith("app")    << "\n"; // true
    return 0;
}
#endif // UNIT_TESTING
