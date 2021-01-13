/** 
 * 31. Partition Array
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array nums of integers and an int k, partition the array (i.e., move the elements in "nums") such that:
 * All elements < k are moved to the left
 * All elements >= k are moved to the right
 * Return the partitioning index, i.e., the first index i nums[i] >= k.
 *
 * Clarification
 * You should do really partition in array nums instead of just counting the numbers of integers smaller than k.
 * If all elements in nums are smaller than k, then return nums.length
 * 
 * Example
 * Input:
 * [],9
 * Output:
 * 0
 * 
 * Example 2:
 * Input:
 * [3,2,2,1],2
 * Output:
 * 1
 * Explanation:
 * the real array is[1,2,2,3].So return 1
 * 
 * Challenge
 * Can you partition the array in-place and in O(n)?
 * 
 * Related Problems
 * 769. Spiral Array
 * 761. Smallest Subset
 * 625. Partition Array II
 * 373. Partition Array by Odd and Even
 * 144. Interleaving Positive and Negative Numbers 
 * 96. Partition List
 */

/** 
 * Challenge
 * Can you partition the array in-place and in O(n)?
 * 
 * Double pointers
 * Ref: https://www.jiuzhang.com/problem/partition-array/#tag-lang-cpp
 * 
 * Running Time: 16ms
 */

class Solution
{
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            while (left <= right and nums[left] < k)
                left++;

            while (left <= right and nums[right] >= k)
                right--;

            if (left <= right)
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        return left;
    }
};