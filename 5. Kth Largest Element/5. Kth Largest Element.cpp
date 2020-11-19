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
 * Challenge
 * O(n) time, O(1) extra memory.
 * 
 * Partition (a variant of quick sort)
 * Ref: https://www.jiuzhang.com/problem/kth-largest-element/#tag-lang-cpp
 * Running Time:  50ms
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
        if (nums.size() == 0 || n < 1 || n > nums.size())
            return -1;
        n = nums.size() - n;
        return partition(nums, 0, nums.size() - 1, n);
    }

private:
    int partition(vector<int> &nums, int start, int end, int k)
    {
        int left = start, right = end;
        int pivot = nums[left];

        while (left <= right)
        {
            while (left <= right && nums[left] < pivot)
            {
                left++;
            }
            while (left <= right && nums[right] > pivot)
            {
                right--;
            }
            if (left <= right)
            {
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }

        if (k <= right)
        {
            return partition(nums, start, right, k);
        }
        if (k >= left)
        {
            return partition(nums, left, end, k);
        }
        return nums[k];
    }
};

// /**
//  * Time complexity: O(nlogn)
//  * Running Time:  201ms
//  */
// class Solution
// {
// public:
//     /**
//      * @param n: An integer
//      * @param nums: An array
//      * @return: the Kth largest element
//      */
//     int kthLargestElement(int n, vector<int> &nums)
//     {
//         sort(nums.rbegin(), nums.rend());
//         return nums[n - 1];
//     }
// };