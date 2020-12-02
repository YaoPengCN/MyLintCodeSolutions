/** 
 * 267. minimum rest days
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Due to the excellent performance, the company gave Xiao Q a leave of n days. 
 * As a workaholic, Xiao Q intends to work, exercise or rest during the holidays. 
 * He has a strange habit: he will not work or exercise for two consecutive days. 
 * Only when the company is in business, can Xiao Q go to work, and only when the gym is in business, can Xiao Q go to fitness. 
 * Xiao Q can only do one thing a day. 
 * Give the business situation of the company and the gym during the holiday, and ask Q to take at least a few days of rest.
 * 
 * Clarification
 * 1 for business and 0 for Closed.
 * 
 * Example
 * Example 1
 * Input: company=[1,1,0,0], gym=[0,1,1,0]
 * Output:2
 * Explanation:Xiao Q can work on the first day, exercise on the second or third day, and have a minimum of 2 days of rest.
 * 
 * Related Problems
 * 1310. Product of Array Except Self 
 * 1142. Non-negative Integers without Consecutive Ones
 * 866. Coin Path
 * 535. House Robber III
 * 534. House Robber II
 * 516. Paint House II
 * 515. Paint House
 * 514. Paint Fence
 * 392. House Robber
 * 366. Fibonacci
 * 362. Sliding Window Maximum
 * 50. Product of Array Exclude Itself
 */

/**
 * Dynamic programming
 * Ref[1]: https://www.jiuzhang.com/problem/minimum-rest-days/
 *
 * Running Time: 50ms
 */
class Solution
{
public:
    /**
     * @param company: Company business
     * @param gym: Gym business
     * @return: Find the shortest rest day
     */
    int minimumRestDays(vector<int> &company, vector<int> &gym)
    {
        if (company.empty() || gym.empty() || (company.size() != gym.size()))
            return -1;

        // dp size: (n, 3)
        // dp[i][0] for the minimum rest days if work in the i-th day
        // dp[i][1] for the minimum rest days if exercise in the i-th day
        // dp[i][2] for the minimum rest days if rest in the i-th day
        vector<vector<int>> dp(2);
        for (vector<vector<int>>::size_type i = 0; i != 2; i++)
            for (vector<int>::size_type j = 0; j != 3; j++)
                dp[i].push_back(INT_MAX);

        if (company[0] == 1)
        {
            dp[0][0] = 0;
            dp[1][0] = 0;
        }
        if (gym[0] == 1)
        {
            dp[0][1] = 0;
            dp[1][1] = 0;
        }

        dp[0][2] = 1;
        dp[1][2] = 1;

        for (vector<vector<int>>::size_type i = 1; i != company.size(); i++)
        {
            for (vector<int>::size_type j = 0; j != 3; j++)
                dp[1][j] = INT_MAX;

            if (company[i] == 1)
            {
                dp[1][0] = min(dp[0][1], dp[0][2]);
            }
            if (gym[i] == 1)
            {
                dp[1][1] = min(dp[0][0], dp[0][2]);
            }
            dp[1][2] = min(min(dp[0][0], dp[0][1]), dp[0][2]) + 1;

            for (vector<int>::size_type j = 0; j != 3; j++)
                dp[0][j] = dp[1][j];
        }

        return min(min(dp[1][0], dp[1][1]), dp[1][2]);
    }
};

// /**
//  * Dynamic programming
//  * Ref[1]: https://www.jiuzhang.com/problem/minimum-rest-days/
//  *
//  * Running Time: 100ms
//  */
// class Solution
// {
// public:
//     /**
//      * @param company: Company business
//      * @param gym: Gym business
//      * @return: Find the shortest rest day
//      */
//     int minimumRestDays(vector<int> &company, vector<int> &gym)
//     {
//         if (company.empty() || gym.empty() || (company.size() != gym.size()))
//             return -1;

//         // dp size: (n, 3)
//         // dp[i][0] for the minimum rest days if work in the i-th day
//         // dp[i][1] for the minimum rest days if exercise in the i-th day
//         // dp[i][2] for the minimum rest days if rest in the i-th day
//         vector<vector<int>> dp(company.size());
//         for (vector<vector<int>>::size_type i = 0; i != company.size(); i++)
//             for (vector<int>::size_type j = 0; j != 3; j++)
//                 dp[i].push_back(INT_MAX);

//         if (company[0] == 1)
//         {
//             dp[0][0] = 0;
//         }
//         if (gym[0] == 1)
//         {
//             dp[0][1] = 0;
//         }

//         dp[0][2] = 1;

//         for (vector<vector<int>>::size_type i = 1; i != company.size(); i++)
//         {
//             if (company[i] == 1)
//             {
//                 dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
//             }
//             if (gym[i] == 1)
//             {
//                 dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
//             }
//             dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1;
//         }

//         return min(min(dp[company.size() - 1][0], dp[company.size() - 1][1]), dp[company.size() - 1][2]);
//     }
// };
