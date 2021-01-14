/** 
 * 59. 3Sum Closest
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers.
 *
 * Clarification
 * You may assume that each input would have exactly one solution.
 * 
 * Example
 * Example 1
 * Input:[2,7,11,15],3
 * Output:20
 * Explanation:
 * 2+7+11=20
 * 
 * Example 2
 * Input:[-1,2,1,-4],1
 * Output:2
 * Explanation:
 * -1+2+1=2
 *
 * Challenge
 * O(n^2) time, O(1) extra space
 * 
 * Related Problems
 * 918. 3Sum Smaller
 * 533. Two Sum - Closest to Target
 * 57. 3Sum
 * 56. Two Sum
 * */

/**
 * Challenge
 * O(n^2) time, O(1) extra space
 * 
 * double pointers 
 * Ref: https://www.jiuzhang.com/problem/3sum-closest/
 * 
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target)
    {
        if (numbers.empty())
            return -1;

        sort(numbers.begin(), numbers.end());

        int nearest = INT_MAX;

        for (int i = 0; i != numbers.size() - 2; i++)
        {

            // pruning 1
            if (i > 0 && numbers[i] == numbers[i - 1])
            {
                continue;
            }

            // double pointers
            int left = i + 1;
            int right = numbers.size() - 1;

            while (left < right)
            {
                int curr = numbers[i] + numbers[left] + numbers[right];

                //  the sum == target
                if (curr == target)
                {
                    return target;
                }

                // update nearest
                if (abs(curr - target) < abs(nearest - target))
                {
                    nearest = curr;
                }

                // move the double pointers
                if (curr > target)
                {
                    right--;

                    // pruning 2
                    while (right >= 0 && numbers[right] == numbers[right + 1])
                    {
                        right--;
                    }
                }
                else
                {
                    left++;

                    // pruning 3
                    while (left < numbers.size() && numbers[left] == numbers[left - 1])
                    {
                        left++;
                    }
                }
            }
        }
        return nearest;
    }
};
