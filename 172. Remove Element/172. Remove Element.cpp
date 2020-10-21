/** 
 * 172. Remove Element
 * Difficulty
 * Easy
 * 
 * Description
 * Given an array and a value, remove all occurrences of that value in place and return the new length.
 * The order of elements can be changed, and the elements after the new length don't matter.
 *  
 * Example
 * Example 1:
 * Input: [], value = 0
 * Output: 0
 * 
 * Example 2:
 * Input:  [0,4,4,0,0,2,4,4], value = 4
 * Output: 4
 * Explanation: 
 * the array after remove is [0,0,0,2]
 * 
 * Related Problems 
 * 539. Move Zeroes
 * 101. Remove Duplicates from Sorted Array II
 * 100. Remove Duplicates from Sorted Array
 * */

/**
 * Two pointers
 * Ref[1]: https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ
 * Ref[2]: https://www.jiuzhang.com/problem/minimum-depth-of-binary-tree/
 * Running Time: 366ms
 */

class Solution
{
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem)
    {
        if (A.size() == 0)
            return 0;

        vector<int>::size_type fast = 0, slow = 0;
        while (fast != A.size())
        {
            if (A[fast] != elem)
            {
                A[slow++] = A[fast];
            }
            fast++;
        }
        return slow;
    }
};

// /**
//  * Two pointers
//  * Ref[1]: https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ
//  * Ref[2]: https://www.jiuzhang.com/problem/minimum-depth-of-binary-tree/
//  * Running Time: 600ms
//  */

// class Solution
// {
// public:
//     /*
//      * @param A: A list of integers
//      * @param elem: An integer
//      * @return: The new length after remove
//      */
//     int removeElement(vector<int> &A, int elem)
//     {
//         if (A.size() == 0)
//             return 0;

//         vector<int>::size_type indexHead = 0, indexTail = A.size() - 1;
//         while (indexHead <= indexTail)
//         {
//             if (A[indexHead] == elem)
//             {
//                 while (A[indexTail] == elem && indexTail > 0)
//                 {
//                     indexTail--;
//                 }
//                 if (indexTail == 0)
//                     return 0;
//                 if (indexHead >= indexTail)
//                     if (A[indexHead] == elem)
//                         return indexHead;
//                     else
//                         return indexHead + 1;
//                 swap(A[indexHead], A[indexTail]);
//             }
//             indexHead++;
//         }
//         if (A[indexHead] == elem)
//             return indexHead;
//         else
//             return indexHead + 1;
//     }
// };