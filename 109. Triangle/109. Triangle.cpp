/** 
 * 109. Triangle
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 * 
 * Clarification
 * Bonus point if you are able to do this using only O(n) extra space, 
 * where n is the total number of rows in the triangle.
 * 
 * Example
 * Example 1
 * Input:
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * Output: 11
 * Explanation: 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Example 2:
 * Input: 
 * [
 *      [2],
 *     [3,2],
 *    [6,5,7],
 *   [4,4,8,1]
 * ]
 * Output: 12
 * Explanation: 
 * The minimum path sum from top to bottom is 12 (i.e., 2 + 2 + 7 + 1 = 12).
 *  
 * Related Problems
 * 1682. Minimum Path Sum II
 * 1058. Cherry Pickup
 * 794. Sliding Puzzle II
 * 110. Minimum Path Sum
 * 109. Triangle 
 * 94. Binary Tree Maximum Path Sum
 */

/**
 * Dynamic programming
 * Space complexity: O(N)
 * Running Time: 101ms
 */
class Solution
{
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.empty())
            return 0;
        vector<int> dp(triangle.size());
        dp[0] = triangle[0][0];
        for (int i = 1; i != triangle.size(); i++)
        {
            vector<int> temp(triangle[i].size());

            temp[0] = dp[0] + triangle[i][0];

            for (int j = 1; j != triangle[i].size() - 1; j++)
            {
                temp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }

            temp[i] = dp[i - 1] + triangle[i][i];

            for (vector<int>::size_type j = 0; j != triangle[i].size(); j++)
            {
                dp[j] = temp[j];
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};