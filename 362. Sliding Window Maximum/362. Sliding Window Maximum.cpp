/** 
 * 362. Sliding Window Maximum
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Given an array of n integer with duplicate number, and a moving window(size k), 
 * move the window at each iteration from the start of the array, 
 * find the maximum number inside the window at each moving.
 * 
 * Example
 * Example 1
 * Input:
 * [1,2,7,7,8]
 * 3
 * Output:
 * [7,7,8]
 * Explanation:
 * At first the window is at the start of the array like this `[|1, 2, 7| ,7, 8]` , return the maximum `7`;
 * then the window move one step forward.`[1, |2, 7 ,7|, 8]`, return the maximum `7`;
 * then the window move one step forward again.`[1, 2, |7, 7, 8|]`, return the maximum `8`;
 * 
 * Example 2:
 * Input:
 * [1,2,3,1,2,3]
 * 5
 * Output:
 * [3,3]
 * Explanation:
 * At first, the state of the window is as follows: ` [,2,3,1,2,1 | , 3] `, a maximum of ` 3 `;
 * And then the window to the right one. ` [1, | 2,3,1,2,3 |] `, a maximum of ` 3 `;
 *  
 * Challenge
 * O(n) time and O(k) memory
 * 
 * Related Problems
 * 928. Longest Substring with At Most Two Distinct Characters
 * 692. Sliding Window Unique Elements Sum
 * 604. Window Sum
 * 558.  Sliding Window Matrix Maximum
 * 516. Paint House II
 * 360. Sliding Window Median
 */

/**
 * Challenge
 * O(n) time and O(k) memory
 * 
 * Monotonic queue
 * Ref[1]: https://www.jiuzhang.com/problem/sliding-window-maximum/#tag-lang-cpp
 * 
 * Running Time: 1158ms
 */
class Solution
{
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;

        // monotonic queue
        deque<int> qMax;

        for (vector<int>::size_type i = 0; i != nums.size(); i++)
        {
            // keep monotonicity
            while (!qMax.empty() && nums[i] > nums[qMax.back()])
                qMax.pop_back();
            // when the length of sliding window is larger than k, delete the out-range element
            if (!qMax.empty() && i - qMax.front() >= k)
                qMax.pop_front();

            qMax.push_back(i);

            // get answers
            if (i >= k - 1)
            {
                ans.push_back(nums[qMax.front()]);
            }
        }
        return ans;
    }
};