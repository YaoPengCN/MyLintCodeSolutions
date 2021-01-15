/** 
 * 61. Search for a Range
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a sorted array of n integers, find the starting and ending position of a given target value.
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example
 * Example 1
 * Input:
 * []
 * 9
 * Output:
 * [-1,-1]
 * 
 * Example 2
 * Input:
 * [5, 7, 7, 8, 8, 10]
 * 8
 * Output:
 * [3, 4]
 *
 * Challenge
 * O(log n) time.
 * 
 * Related Problems
 * 665. Range Sum Query 2D - Immutable
 * 462. Total Occurrence of Target
 * */

/**
 * Challenge
 * O(log n) time.
 * 
 * Ref: https://www.jiuzhang.com/problem/search-for-a-range/
 * 
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target)
    {
        int left = lower_bound(A, target);

        if (left == A.size() || A[left] != target)
        {
            return {-1, -1};
        }

        int right = lower_bound(A, target + 1) - 1;
        return {left, right};
    }

private:
    // find the first index such that A[index] >= target
    // three ways to implement the binary search
    // 1, left + 1 < right, check left/right before return
    // 2, left <= right, index keep track of best possible solution, => general
    // 3, mid = left + (right - left + 1) / 2
    int lower_bound(vector<int> &A, int target)
    {
        int left = 0, right = A.size() - 1;
        int index = A.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target)
            {
                index = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return index;
    }
};