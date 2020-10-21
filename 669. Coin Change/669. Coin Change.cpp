/** 
* 669. Coin Change
* Difficulty
* Medium
* 
* Description
* You are given coins of different denominations and a total amount of money amount. 
* Write a function to compute the fewest number of coins that you need to make up that amount. 
* If that amount of money cannot be made up by any combination of the coins, return -1.
*
* Clarification
* You may assume that you have an infinite number of each kind of coin.
* It is guaranteed that the num of money will not exceed 10000.
* And the num of coins wii not exceed 500.
* And the denomination of each coin will not exceed 100.
* 
* Example
* Example 1
* Input:
* [1, 2, 5]
* 11
* Output:
* 3
* Explanation: 11 = 5 + 5 + 1.
* 
* Example 2:
* Input: 
* [2]
* 3
* Output:
* -1
* 
* Related Problems
* 749. John's backyard garden
* 564. Combination Sum IV
* 563. Backpack V
* 562. Backpack IV
* 440. Backpack III
* 125. Backpack II 
* 92. Backpack
*/

/**
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/dong-tai-gui-hua-xiang-jie-jin-jie
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i != dp.size(); i++)
        {
            for (int coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
