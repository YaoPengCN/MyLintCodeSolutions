/** 
* 39. Recover Rotated Sorted Array
* Difficulty
* Easy
* 
* Description
* Given a rotated sorted array, recover it to sorted array in-place.（Ascending）
* 
* Clarification
* What is rotated array?
* · For example, the original array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
* 
* Example
* Example 1
* [4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]
* 
* Example 2
* [6,8,9,1,2] -> [1,2,6,8,9]
*
* Challenge
* In-place, O(1) extra space and O(n) time.
*
* Related Problems 
* 1790. Rotate String II
* 148. Sort Colors
* 8. Rotate String
*/

/**
 * Challenge: In-place, O(1) extra space and O(n) time.
 * Running Time:  51ms
 */
class Solution
{
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums)
    {
        if ((nums.size() == 0) || (nums.size() == 1))
        {
            return;
        }
        vector<int>::size_type offset = nums.size() - 1;
        vector<int>::size_type index = 0;
        while ((index < nums.size() - 1) && (nums[index] <= nums[index + 1]))
            ++index;
        offset = index;
        if (offset == nums.size() - 1)
        {
            return;
        }

        rotate(nums.begin(), nums.begin() + offset + 1, nums.end());
        /* ref [1]: "The Annotated STL Sources (using SGI STL)"
         * the realization 1 of rotate() in STL:
         * reverse(nums.begin(), nums.begin() + offset + 1);
         * reverse(nums.begin() + offset + 1, nums.end());
         * reverse(nums.begin(), nums.end());
         *
         * the realization 2 of rotate() in STL:
         * using gcd()
         */

        return;
    }
};

// ref [1]: "The Annotated STL Sources (using SGI STL)"
// ref [2]: https://www.jiuzhang.com/problem/recover-rotated-sorted-array/#tag-lang-ALL
// class Solution {
// public:
//     //辗转相除法求最大公约数
//     int getGCD(int a, int b) {
//         if (a % b == 0) {
//             return b;
//         }    
//         return getGCD(b, a % b);
//     }
    
//     void recoverRotatedSortedArray(vector<int> &nums) {
//         int offset = 0;
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i - 1] > nums[i]) {
//                 offset = i;
//             }
//         }
//         if (offset == 0) {
//             return;
//         }
//         offset = nums.size() - offset;
        
//         int gcd = getGCD(offset, nums.size());
//         for (int i = 0; i < gcd; i++) {
//             int next = (i + offset) % nums.size();
//             //将每个数放到它们应该在的位置
//             while (next != i) {
//                 int temp = nums[i]; nums[i] = nums[next]; nums[next] = temp;
//                 next = (next + offset) % nums.size();
//             }
//         }
//     }
// };