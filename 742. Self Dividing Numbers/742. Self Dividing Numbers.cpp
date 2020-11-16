/** 
 * 742. Self Dividing Numbers
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * A Digit Divide Numbers is a number that is divisible by every digit it contains.
 * For example, 128 is a Digit Divide Numbers because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * Also, Digit Divide Numbers is not allowed to contain the digit zero.
 * Given a lower and upper number bound, output a list of every possible Digit Divide Numbers, including the bounds if possible.
 * 
 * Clarification
 * 0<=L<=R<=2^31-1, R-L<=10^6
 * 
 * Example
 * Example 1
 * Input: 
 * left = 1, right = 22
 * Output: 
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * Example 2
 * Input: 
 * left = 7, right = 22
 * Output: 
 * [7, 8, 9, 11, 12, 15, 22]
 * 
 * Related Problems
 * 776. Strobogrammatic Number II
 * 734. Number of Subsequences of Form a^i b^j c^k
 * 644. Strobogrammatic Number
 * 488. Happy Number
 * */

/**
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param lower: Integer : lower bound
     * @param upper: Integer : upper bound
     * @return: a list of every possible Digit Divide Numbers
     */
    vector<int> digitDivideNums(int lower, int upper)
    {
        vector<int> res;

        if (upper <= 0 || lower > upper)
        {
            res.push_back(-1);
            return res;
        }

        if (lower <= 0)
            lower = 1;

        for (long i = lower; i <= upper; i++)
        // 0<=L<=R<=2^31-1, if int i=2^31-1, then i++ would cause overflow.
        {
            long num = i;
            while (num > 0)
            {
                long digit = num % 10;
                if (digit == 0 || i % digit != 0)
                    break;
                num /= 10;
            }
            if (num == 0)
                res.push_back(i);
        }
        return res;
    }
};