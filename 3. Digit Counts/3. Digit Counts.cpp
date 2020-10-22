/** 
 * 3. Digit Counts
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Count the number of k's between 0 and n. k can be 0 - 9.
 *
 * Example
 * Example 1
 * Input:
 * k = 1, n = 1
 * Output:
 * 1
 * Explanation:
 * In [0, 1], we found that 1 appeared once (1).
 * 
 * Example 2
 * Input:
 * k = 1, n = 12
 * Output:
 * 5
 * Explanation:
 * In [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we found that one appeared five times (1, 10, 11, 12)(Note that there are two 1 in 11).
 * 
 * Related Problems
 * 46. Majority Element
 * */

/**
 * Running Time: 12ms
 */

class Solution
{
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n)
    {
        int count = 0;
        if (k == 0)
            count += 1;
        for (int i = 1; i <= n; i++)
        {
            int temp = i;
            while (temp > 0)
            {
                if (temp % 10 == k)
                    count++;
                temp /= 10;
            }
        }
        return count;
    }
};