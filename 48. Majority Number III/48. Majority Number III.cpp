/** 
 * 48. Majority Number III
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
 * Find it.
 * 
 * Clarification
 * There is only one majority number in the array.
 * 
 * Example
 * Example 1
 * Input: [3,1,2,3,2,3,3,4,4,4] and k=3, 
 * Output: 3.
 * 
 * Example 2
 * Input: [1,1,2] and k=3, 
 * Output: 1.
 * 
 * Challenge
 * O(n) time and O(k) extra space
 *
 * Related Problems 
 * 84. Single Number III
 * 83. Single Number II
 * 82. Single Number
 * 47. Majority Number II
 * 46. Majority Element
 * */

/**
 * Challenge:
 * O(n) time and O(k) extra space
 * 
 * Moore majority vote algorithm or Hashmap
 * Ref[1]: https://blog.csdn.net/tfcy694/article/details/82717808
 * Ref[2]: https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
 * 
 * Running Time:  50ms
 */

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, int k)
    {
        if (nums.empty() || k > nums.size())
            return -1;

        int n = nums.size();
        int x = n / k;
        unordered_map<int, int> freq;

        for (int i = 0; i != n; i++)
        {
            freq[nums[i]]++;
        }

        for (auto i : freq)
        {

            // Checking if value of a key-value pair is greater than x (where x=n/k)
            if (i.second > x)
            {

                // Print the key of whose value is greater than x
                return i.first;
            }
        }
    }
};
