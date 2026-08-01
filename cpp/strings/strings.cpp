/**
 * String Algorithms - C++20
 * ==========================
 * Common string operations and pattern matching.
 *
 * Time: O(n) for most operations, O(n+m) for KMP
 * Space: O(n)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

namespace dsa {

// Check if string is palindrome - O(n)
bool isPalindrome(const std::string& s) {
    int left = 0, right = static_cast<int>(s.size()) - 1;
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

// KMP string matching - O(n + m)
std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    int n = text.size(), m = pattern.size();
    std::vector<int> lps(m, 0);

    // Build LPS (Longest Proper Prefix which is also Suffix)
    for (int i = 1, len = 0; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    std::vector<int> matches;
    for (int i = 0, j = 0; i < n; ) {
        if (text[i] == pattern[j]) {
            ++i; ++j;
        }
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            j ? (j = lps[j - 1]) : ++i;
        }
    }
    return matches;
}

// Anagram check - O(n)
bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    int count[26] = {};
    for (char c : s) ++count[c - 'a'];
    for (char c : t) --count[c - 'a'];
    for (int x : count) if (x != 0) return false;
    return true;
}

// Longest palindromic substring (expand around center) - O(n²)
std::string longestPalindrome(const std::string& s) {
    int n = s.size(), start = 0, maxLen = 1;

    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) { --l; ++r; }
        if (r - l - 1 > maxLen) {
            maxLen = r - l - 1;
            start = l + 1;
        }
    };

    for (int i = 0; i < n; ++i) {
        expand(i, i);     // Odd length
        expand(i, i + 1); // Even length
    }
    return s.substr(start, maxLen);
}

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    std::cout << std::boolalpha;
    std::cout << "isPalindrome(racecar): " << dsa::isPalindrome("racecar") << "\n";
    std::cout << "isAnagram(anagram,nagaram): " << dsa::isAnagram("anagram","nagaram") << "\n";

    auto matches = dsa::kmpSearch("AABAACAADAABAABA", "AABA");
    std::cout << "KMP matches at: ";
    for (int idx : matches) std::cout << idx << " ";
    std::cout << "\n";

    std::cout << "Longest palindrome in 'babad': "
              << dsa::longestPalindrome("babad") << "\n";
    return 0;
}
#endif // UNIT_TESTING
