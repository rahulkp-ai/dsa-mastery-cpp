/**
 * Recursion Patterns - C++20
 * ===========================
 */
#include <iostream>
#include <vector>
#include <functional>

namespace dsa {

// Fibonacci with memoization
long long fib(int n, std::vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1, memo) + fib(n-2, memo);
}

// Generate all subsets
void subsets(std::vector<int>& nums, int start,
             std::vector<int>& path,
             std::vector<std::vector<int>>& result) {
    result.push_back(path);
    for (int i = start; i < (int)nums.size(); ++i) {
        path.push_back(nums[i]);
        subsets(nums, i + 1, path, result);
        path.pop_back();
    }
}

// N-Queens
void nQueens(int n, int row, std::vector<int>& queens,
             std::vector<std::vector<std::string>>& result) {
    if (row == n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        for (int i = 0; i < n; ++i) board[i][queens[i]] = 'Q';
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        bool valid = true;
        for (int r = 0; r < row && valid; ++r) {
            if (queens[r] == col ||
                queens[r] - col == r - row ||
                queens[r] - col == row - r) valid = false;
        }
        if (valid) {
            queens[row] = col;
            nQueens(n, row + 1, queens, result);
        }
    }
}

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    std::vector<long long> memo(50, -1);
    std::cout << "fib(10) = " << dsa::fib(10, memo) << "\n"; // 55

    std::vector<int> nums = {1, 2, 3};
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    dsa::subsets(nums, 0, path, result);
    std::cout << "Subsets count: " << result.size() << "\n"; // 8

    std::vector<int> queens(8);
    std::vector<std::vector<std::string>> solutions;
    dsa::nQueens(8, 0, queens, solutions);
    std::cout << "8-Queens solutions: " << solutions.size() << "\n"; // 92

    return 0;
}
#endif // UNIT_TESTING
