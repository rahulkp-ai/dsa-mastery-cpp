/**
 * Backtracking — C++20
 * =======================
 * Pattern: Choose → Explore → Unchoose
 * Time: O(n! or 2^n) — exponential
 * Space: O(n) recursion stack
 */
#include <iostream>
#include <vector>
#include <string>

namespace dsa
{

    void subsetsHelper(const std::vector<int> &nums, int start,
                       std::vector<int> &path,
                       std::vector<std::vector<int>> &result)
    {
        result.push_back(path);
        for (int i = start; i < (int)nums.size(); ++i)
        {
            path.push_back(nums[i]);
            subsetsHelper(nums, i + 1, path, result);
            path.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(const std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        subsetsHelper(nums, 0, path, result);
        return result;
    }

    void nQueensHelper(int n, int row, std::vector<int> &queens,
                       std::vector<std::vector<std::string>> &result)
    {
        if (row == n)
        {
            std::vector<std::string> board(n, std::string(n, '.'));
            for (int i = 0; i < n; ++i)
                board[i][queens[i]] = 'Q';
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col)
        {
            bool valid = true;
            for (int r = 0; r < row && valid; ++r)
                if (queens[r] == col || abs(queens[r] - col) == abs(r - row))
                    valid = false;
            if (valid)
            {
                queens[row] = col;
                nQueensHelper(n, row + 1, queens, result);
            }
        }
    }

    int nQueens(int n)
    {
        std::vector<std::vector<std::string>> result;
        std::vector<int> queens(n, -1);
        nQueensHelper(n, 0, queens, result);
        return result.size();
    }

} // namespace dsa

#if !defined(UNIT_TESTING)
int main()
{
    auto subs = dsa::subsets({1, 2, 3});
    std::cout << "Subsets: " << subs.size() << "\n";                // 8
    std::cout << "8-Queens solutions: " << dsa::nQueens(8) << "\n"; // 92
    return 0;
}
#endif // UNIT_TESTING
