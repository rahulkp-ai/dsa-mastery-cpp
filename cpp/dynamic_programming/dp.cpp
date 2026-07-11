/**
 * Dynamic Programming - C++20
 * ============================
 * Classic DP patterns.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

namespace dsa
{

    // Coin Change - O(amount * n)
    int coinChange(const std::vector<int> &coins, int amount)
    {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a)
        {
            for (int coin : coins)
            {
                if (coin <= a && dp[a - coin] != INT_MAX)
                {
                    dp[a] = std::min(dp[a], dp[a - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

    // LCS - O(m*n)
    int longestCommonSubsequence(const std::string &s1, const std::string &s2)
    {
        int m = s1.size(), n = s2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }

    // 0/1 Knapsack - O(n * W)
    int knapsack(const std::vector<int> &w, const std::vector<int> &v, int W)
    {
        int n = w.size();
        std::vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            for (int cap = W; cap >= w[i]; --cap)
            {
                dp[cap] = std::max(dp[cap], dp[cap - w[i]] + v[i]);
            }
        }
        return dp[W];
    }

} // namespace dsa

#if !defined(UNIT_TESTING)
int main()
{
    std::cout << dsa::coinChange({1, 5, 11}, 15) << "\n";               // 3
    std::cout << dsa::longestCommonSubsequence("abcde", "ace") << "\n"; // 3
    std::cout << dsa::knapsack({1, 3, 4, 5}, {1, 4, 5, 7}, 7) << "\n";  // 9
    return 0;
}
#endif // UNIT_TESTING
