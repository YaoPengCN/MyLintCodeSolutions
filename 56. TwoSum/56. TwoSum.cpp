/** 
* 56. TwoSum
* Difficulty
* Easy
* 
* Description
* Given an array of integers, find two numbers such that they add up to a specific target number.
* The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
* Please note that your returned answers (both index1 and index2) are zero-based.
*
* Clarification
* You may assume that each input would have exactly one solution.
* 
* 
* Example
* Example 1
* numbers=[2, 7, 11, 15], target=9
* return [0, 1]
* 
* Example 2
* numbers=[15, 2, 7, 11], target=9
* return [1, 2]
* 
* Challenge
* Either of the following solutions are acceptable:
* · O(n) Space, O(nlogn) Time
* · O(n) Space, O(n) Time
*
* Related Problems
* 1879. Two Sum VII
* 1797. optimalUtilization
* 689. Two Sum IV - Input is a BST
* 610. Two Sum - Difference Equals to Targe
* 609. Two Sum - Less than or Equal to Target
* 608. Two Sum II - Input array is sorted
* 607. Two Sum III - Data structure design
* 587. Two Sum - Unique pairs
* 533. Two Sum - Closest to Target
* 443. Two Sum - Greater than Target
* 382. Triangle Count
* 59. 3Sum Closest
* 58. 4Sum 
* 57. 3Sum
*/

/**
 * Run Time:  50ms
 */
class Solution
{
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        for (vector<int>::size_type i = 0; i != numbers.size() - 1; i++)
        {
            for (vector<int>::size_type j = i + 1; j != numbers.size(); j++)
                if (numbers[i] + numbers[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        }
        return result;
    }
};