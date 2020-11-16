/** 
 * 569. Add Digits
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * Example
 * Example 1
 * Input:
 * num=38
 * Output:
 * 2
 * Explanation:
 * The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return 2.
 * 
 * Example 2
 * Input:
 * num=9
 * Output:
 * 9
 * Explanation:
 * 9<10,return 9.
 * 
 * Challenge
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * Related Problems
 * 488. Happy Number
 * */

/**
 * Challenge
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * Ref[1]: https://www.lintcode.com/problem/add-digits/note?ordering=-like_count
 * Running Time: 51ms
 */

class Solution
{
public:
    /**
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num)
    {
        if (num < 10)
            return num;

        // num = a0 + a1 * 10 + a2 * 100 + ... + ak * 10^k = (a0 + a1 + ... + ak) + 9(a1 + a2 + ... + ak) + 99(a2 + ... + ak) + ... + (10^k - 1)ak
        // Let num1 = a0 + a1 + ... + ak, num = num1 + 9 * x1, where x1 = (a1 + a2 + ... + ak) + 11 (a2 + ... + ak) + ...
        // Similarly, num1 = num2 + 9 * x2 ... until numl < 10
        // Therefore, num = numl + 9 * x_numl 
        // numl = num % 9 is the result
        return num % 9 == 0 ? 9 : num % 9;
    }
};

// /**
//  * Running Time: 50ms
//  */

// class Solution
// {
// public:
//     /**
//      * @param num: a non-negative integer
//      * @return: one digit
//      */
//     int addDigits(int num)
//     {
//         if (num < 10)
//             return num;

//         while (num >= 10)
//         {
//             int cur = 0;
//             while (num > 0)
//             {
//                 int digit = num % 10;
//                 cur += digit;
//                 num /= 10;
//             }
//             num = cur;
//             if (num < 10)
//                 break;
//         }
//         return num;
//     }
// };