/** 
 * 534. House Robber II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * This is an extension of problem 392. House Robber.
 * After robbing those houses on that street, 
 * the thief has found himself a new place for his thievery so that he will not get too much attention. 
 * This time, all houses at this place are arranged in a circle. 
 * That means the first house is the neighbor of the last one. 
 * Meanwhile, the security system for these houses remain the same as for those in the previous street.
 * Given a list of non-negative integers representing the amount of money of each house, 
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Example
 * Example 1
 * Input: nums = [3,6,4]
 * Output: 6
 * Explanation: Just rob the second house.
 * 
 * Example 2:
 * Input: nums = [2,3,2,3]
 * Output: 6
 * Explanation: Rob the second and the last house.
 *  
 * Related Problems 
 * 1142. Non-negative Integers without Consecutive Ones
 * 866. Coin Path
 * 535. House Robber III
 * 534. House Robber II
 * 515. Paint House
 * 514. Paint Fence
 * 392. House Robber
 * 366. Fibonacci
 */

/** 
 * Dynamic programming
 * Ref[1]: https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw
 * Ref[2]: https://www.jiuzhang.com/problem/house-robber-ii/#tag-lang-cpp
 * Running Time: 101ms
 */
class Solution
{
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return nums[0];

        
        // The first and the last elements of nums could not be selected simultaneously.
        // dpLeft for nums[i], i=0 to n-2.
        // dpRight for nums[i], i=1 to n-1.
        vector<int> dpLeft(2), dpRight(2);
        for (vector<int>::size_type i = 0; i != nums.size(); i++)
        {
            if (i != nums.size() - 1)
            {
                int tmpLeft = max(dpLeft[0], dpLeft[1]);
                dpLeft[1] = dpLeft[0] + nums[i];
                dpLeft[0] = tmpLeft;
            }

            if (i != 0)
            {
                int tmpRight = max(dpRight[0], dpRight[1]);
                dpRight[1] = dpRight[0] + nums[i];
                dpRight[0] = tmpRight;
            }
        }
        return max(max(dpLeft[0], dpLeft[1]), max(dpRight[0], dpRight[1]));
    }
};
