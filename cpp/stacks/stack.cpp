/**
 * Stack & Monotonic Stack — C++20
 * ==================================
 * Time: O(1) push/pop/top
 * Space: O(n)
 */
#include <iostream>
#include <stack>
#include <vector>
#include <string>

namespace dsa {

bool validParentheses(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') { st.push(c); }
        else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) return false;
        }
    }
    return st.empty();
}

std::vector<int> nextGreaterElement(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> st; // stores indices
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    std::cout << std::boolalpha;
    std::cout << dsa::validParentheses("()[]{}") << "\n"; // true
    std::cout << dsa::validParentheses("([)]") << "\n";   // false

    auto nge = dsa::nextGreaterElement({2,1,2,4,3});
    for (int x : nge) std::cout << x << " "; // 4 2 4 -1 -1
    std::cout << "\n";
    return 0;
}
#endif // UNIT_TESTING
