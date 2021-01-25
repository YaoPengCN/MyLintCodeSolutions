/** 
 * 25. Print X

 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a positive integer N, you need to return a list string like this.
 *
 * Example
 * Example 1
 * Input: 
 *  1
 * Output:
 *  [
 *   "X"
 *  ]
 * 
 * Example 2
 * Input: 
 *  2
 * Output: 
 *  [
 *   "XX",
 *   "XX"
 *  ]
 * 
 * Example 3
 * Input:
 *  3
 * Output:
 *  [
 *   "X X",
 *   " X ",
 *   "X X"
 *  ]
 * 
 * Example 4
 * Input:
 *  4
 * Output:
 *  [
 *   "X  X",
 *   " XX ",
 *   " XX ",
 *   "X  X"
 *  ]
 * Example 5
 * Input:
 *  5
 * Output:
 *  [
 *   "X   X",
 *   " X X ",
 *   "  X  ",
 *   " X X ",
 *   "X   X"
 *  ]
 * */

/**
 * Running Time: 151ms
 */

class Solution
{
public:
    /**
     * @param n: An integer.
     * @return: A string list.
     */
    vector<string> printX(int n)
    {
        if (n <= 0)
        {
            return {};
        }

        vector<string> res(n);
        for (vector<string>::size_type i = 0; i != n / 2; i++)
        {
            string temp;
            for (string::size_type j = 0; j != n; j++)
            {
                if (j == i || j == n - i - 1)
                {
                    temp.push_back('X');
                }
                else
                {
                    temp.push_back(' ');
                }
            }
            res[i] = temp;
            res[n - i - 1] = temp;
        }

        if (n & 0x1 == 1)
        {
            string temp;
            for (string::size_type j = 0; j != n; j++)
            {
                if (j == n / 2)
                {
                    temp.push_back('X');
                }
                else
                {
                    temp.push_back(' ');
                }
            }
            res[n / 2] = temp;
        }

        return res;
    }
};