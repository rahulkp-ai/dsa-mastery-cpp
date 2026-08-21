#include "test_common.hpp"
#include "../../cpp/tries/trie.cpp"

int main() {
    dsa::Trie trie;
    trie.insert("apple");
    CHECK(trie.search("apple"));
    CHECK(!trie.search("app"));
    CHECK(trie.startsWith("app"));
    trie.insert("app");
    CHECK(trie.search("app"));
    return 0;
}
