/** 
* 46. Majority Element
* Difficulty
* Easy
* 
* Description
* Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.
* 
* Notice
* You may assume that the array is non-empty and the majority number always exist in the array.
* 
* Example
* Example 1
* Input: [1, 1, 1, 1, 2, 2, 2]
* Output: 1
* 
* Example 2
* Input: [1, 1, 1, 2, 2, 2, 2]
* Output: 2
* 
* Challenge
* O(n) time and O(1) extra space
*
* Related Problems 
* 84. Single Number III
* 83. Single Number II
* 82. Single Number
* 48. Majority Number III
* 47. Majority Element II
* 3. Digit Counts
*/

/**
 * Challenge: O(n) time and O(1) extra space
 * Running Time:  778ms
 */
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        if (nums.size() == 0) {
            return -1;
        }
        int count = 0;
        int major = nums[0];
        for (vector<int>::size_type i = 0; i < nums.size(); i++) {
            if (major == nums[i]) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                major = nums[i];
                count++;
            }
        }
        //for (int i = 0; i < nums.size(); i++) {
        //    if (major == nums[i]) {
        //        count++;
        //    }
        //}
        //if (count > nums.size() / 2) {
        //    return major;
        //}
        //return -1;
        return major;
    }
};