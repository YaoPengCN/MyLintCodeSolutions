/** 
 * 83. Single Number II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given 3 * n + 1 numbers, every numbers occurs twice except one, find it.
 * 
 * Example
 * Example 1
 * Input：[1,1,2,3,3,3,2,2,4,1]
 * Output：4
 * Explanation:
 * Only 4 appears once
 * 
 * Example 2
 * Input：[2,1,2,2]
 * Output：1
 * Explanation:
 * Only 1 appears once
 * 
 * Challenge
 * One-pass, constant extra space.
 *
 * Related Problems
 * 824. Single Number IV
 * 633. Find the Duplicate Number
 * 84. Single Number III
 * 82. Single Number
 * 48. Majority Number III
 * 47. Majority Element II
 * 46. Majority Element
 * */

/** 
 * Challenge
 * One-pass, constant extra space.
 * 
 * Ref: https://blog.csdn.net/yutianzuijin/article/details/50597413
 * 
 * truth table (expandable)
 * use 2 bits to count the times of the appearance of an element
 * 00 (0 times) -> 01 (1 times) -> 10 (2 times) -> 00 (3 times)
 * Therefore,
 * lowOutput = ~high & (low ^ input)
 * highOutput = (high & (~low) & (~input)) | (~high & low & input)
 * Moreover,
 * highOutput = ~lowOutput & (high ^ input)
 *  
 * Running Time:  50ms
 */

class Solution
{
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A)
    {
        int low = 0, high = 0;
        for (vector<int>::size_type i = 0; i != A.size(); i++)
        {
            low = ~high & (low ^ A[i]);
            high = ~low & (high ^ A[i]);
        }
        return low;
    }
};

// /**
//  * Challenge
//  * One-pass, constant extra space.
//  *
//  * Ref: https://blog.csdn.net/yutianzuijin/article/details/50597413
//  *
//  * truth table
//  * use 2 bits to count the times of the appearance of an element
//  * 00 (0 times) -> 01 (1 times) -> 10 (2 times) -> 00 (3 times)
//  * Therefore,
//  * lowOutput = ~high & (low ^ input)
//  * highOutput = (high & (~low) & (~input)) | (~high & low & input)
//  *
//  * Running Time:  101ms
//  */

// class Solution
// {
// public:
//     /**
//      * @param A: An integer array
//      * @return: An integer
//      */
//     int singleNumberII(vector<int> &A)
//     {
//         if (A.empty())
//             return -1;

//         int low = 0, high = 0;
//         for (vector<int>::size_type i = 0; i != A.size(); i++)
//         {
//             int lowTemp = ~high & (low ^ A[i]);
//             high = (high & ~low & ~A[i]) | (~high & low & A[i]);
//             low = lowTemp;
//         }
//         return low;
//     }
// };

// /**
//  * Challenge
//  * One-pass, constant extra space.
//  *
//  * Ref: https://blog.csdn.net/yutianzuijin/article/details/50597413
//  *
//  * treat each integer as an array of 32 elements
//  *
//  * Running Time:  151ms
//  */

// class Solution
// {
// public:
//     /**
//      * @param A: An integer array
//      * @return: An integer
//      */
//     int singleNumberII(vector<int> &A)
//     {
//         if (A.empty())
//             return -1;

//         vector<int> count(32);
//         int res = 0;
//         for (vector<int>::size_type i = 0; i != A.size(); i++)
//         {
//             for (vector<int>::size_type j = 0; j != 32; j++)
//             {
//                 count[j] += (A[i] >> j & 0x1);
//             }
//         }

//         for (vector<int>::size_type i = 0; i != 32; i++)
//         {
//             res |= (count[i] % 3 << i);
//         }

//         return res;
//     }
// };