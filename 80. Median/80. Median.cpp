/** 
 * 80. Median
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a unsorted array with integers, find the median of it.
 * A median is the middle number of the array after it is sorted.
 * If there are even numbers in the array, return the N/2-th number after sorted.
 * 
 * Clarification
 * The size of array is not exceed 10000
 * 
 * Example
 * Example 1
 * Input:
 * [4, 5, 1, 2, 3]
 * Output:
 * 3
 * Explanation:
 * After sorting，[1,2,3,4,5]，the middle number is 3
 * 
 * Example 2
 * Input:
 * [7, 9, 4, 5]
 * Output:
 * 5
 * Explanation:
 * After sorting，[4,5,7,9]，the second(4/2) number is 5
 * 
 * Challenge
 * O(n) time.
 *
 * Related Problems
 * 81. Find Median from Data Stream
 * 65. Median of two Sorted Arrays
 * 5. Kth Largest Element
 * */

/**
 * Challenge
 * O(n) time.
 * 
 * Priority_queue
 * Ref: https://www.jiuzhang.com/problem/median/#tag-lang-cpp
 * Running Time:  50ms
 */
class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the middle number of the array
     */
    int median(vector<int> &nums)
    {
        priority_queue<int> pq;
        for (vector<int>::size_type i = 0; i != nums.size(); i++)
            pq.push(nums[i]);
        for (vector<int>::size_type i = 0; i != nums.size() / 2; i++)
            pq.pop();
        return pq.top();
    }
};