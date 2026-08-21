#include "test_common.hpp"
#include "../../cpp/strings/strings.cpp"

int main()
{
    CHECK(dsa::isPalindrome("racecar"));
    CHECK_EQ((dsa::kmpSearch("AABAACAADAABAABA", "AABA")), (std::vector<int>{0, 9, 10}));
    CHECK(dsa::isAnagram("anagram", "nagaram"));
    auto pal = dsa::longestPalindrome("babad");
    CHECK(pal == "bab" || pal == "aba");
    return 0;
}
