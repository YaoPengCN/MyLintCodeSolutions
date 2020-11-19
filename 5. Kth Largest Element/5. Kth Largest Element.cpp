/** 
 * 5. Kth Largest Element
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Find K-th largest element in an array.
 * 
 * Clarification
 * You can swap elements in the array.
 * 
 * Example
 * Example 1
 * Input:
 * n = 1, nums = [1,3,4,2]
 * k = 1
 * Output:
 * 4
 * 
 * Example 2
 * Input:
 * n = 3, nums = [9,3,2,4,8]
 * k = 2
 * Output:
 * 4
 * 
 * Challenge
 * O(n) time, O(1) extra memory.
 *
 * Related Problems
 * 1281. Top K Frequent Elements
 * 606. Kth Largest Element II
 * 507. Wiggle Sort II
 * 461. Kth Smallest Number in Unsorted Array
 * 401. Kth Smallest Number in Sorted Matrix 
 * 80. Median
 * */

/**
 * Running Time:  201ms
 */
class Solution
{
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums)
    {
        sort(nums.rbegin(), nums.rend());
        return nums[n - 1];
    }
};