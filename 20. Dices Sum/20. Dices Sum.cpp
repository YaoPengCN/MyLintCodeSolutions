/** 
 * 20. Dices Sum
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Throw n dices, the sum of the dices' faces is S. Given n, find the all possible value of S along with its probability.
 * 
 * Clarification
 * You do not care about the accuracy of the result, we will help you to output results.
 * 
 * Example
 * Example 1
 * Input: 
 * n = 1
 * Output: 
 * [[1, 0.17], [2, 0.17], [3, 0.17], [4, 0.17], [5, 0.17], [6, 0.17]]
 * Explanation: 
 * Throw a dice, the sum of the numbers facing up may be 1, 2, 3, 4, 5, 6, and the probability of each result is 0.17.
 * 
 * Example 2
 * Input: 
 * n = 2
 * Output: 
 * [[2,0.03],[3,0.06],[4,0.08],[5,0.11],[6,0.14],[7,0.17],[8,0.14],[9,0.11],[10,0.08],[11,0.06],[12,0.03]]
 * Explanation: 
 * Throw two dices, the sum of the numbers facing up may be in [2,12], and the probability of each result is different.
 * */

/**
 * Dynamic programming
 * Ref: https://www.jiuzhang.com/problem/dices-sum/#tag-lang-cpp
 * Running Time: 540ms
 */

class Solution
{
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n)
    {
        vector<map<int, double>> dp(n + 1);
        dp[1] = {{1, 1 / 6.0}, {2, 1 / 6.0}, {3, 1 / 6.0}, {4, 1 / 6.0}, {5, 1 / 6.0}, {6, 1 / 6.0}};
        for (int i = 2; i <= n; i++)
            for (auto a1 : dp[i - 1])
                for (auto a2 : dp[1])
                    dp[i][a1.first + a2.first] += a1.second * a2.second;

        vector<pair<int, double>> res;

        for (auto a : dp[n])
            res.push_back({a.first, a.second});
        return res;
    }
};