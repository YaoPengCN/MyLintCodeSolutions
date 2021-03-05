/** 
 * 181. Flip Bits
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Determine the number of bits required to flip if you want to convert integer n to integer m.
 * 
 * Clarification
 * Both n and m are 32-bit integers.
 * 
 * Example
 * Example 1
 * Input: n = 31, m = 14	
 * Output: 2
 * Explanation:	
 * (11111) -> (01110) there are two different bits.
 * 
 * Example 2:
 * Input: n = 1, m = 7	
 * Output: 2	
 * Explanation:	
 * (001) -> (111) will change two bits.
 * 
 * Related Problems 
 * 723. Rotate Bits - Left
 * 666. Guess Number Higher or Lower II
 */

/**
 * n = n & (n-1) could remove the rightest 1 toward right
 * Running Time: 61ms
 */

class Solution
{
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b)
    {
        int n = a ^ b;
        int res = 0;
        while (n != 0)
        {
            // n = n & (n-1) could remove the rightest 1 toward right
            n &= (n - 1);
            res++;
        }

        return res;
    }
};