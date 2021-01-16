/** 
 * 62. Search in Rotated Sorted Array
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. 
 * If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * 
 * Example
 * Example 1
 * Input: [4, 5, 1, 2, 3] and target=1, 
 * Output: 2.
 * 
 * Example 2
 * Input:
 * Input: [4, 5, 1, 2, 3] and target=0, 
 * Output: -1.
 *
 * Challenge
 * O(log n) time.
 * 
 * Related Problems
 * 63. Search in Rotated Sorted Array II
 * 28. Search a 2D Matrix
 * */

/**
 * Challenge
 * O(log n) time.
 * 
 * Ref: https://www.jiuzhang.com/problem/search-in-rotated-sorted-array/
 * 
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target)
    {
        if (A.empty())
            return -1;
        int left = 0;
        int right = A.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (A[mid] > A[left])
            {
                if ((A[left] <= target) && (target < A[mid]))
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            else
            {
                if ((A[mid] < target) && (target <= A[right]))
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
        }
        if (A[left] == target)
            return left;
        if (A[right] == target)
            return right;
        return -1;
    }
};