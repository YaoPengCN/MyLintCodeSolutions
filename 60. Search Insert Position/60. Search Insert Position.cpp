/** 
* 60. Search Insert Position
* Difficulty
* Easy
* 
* Description
* Given a sorted array and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
*
* Clarification
* You may assume NO duplicates in the array.
* 
* 
* Example
* [1,3,5,6], 5 → 2
* [1,3,5,6], 2 → 1
* [1,3,5,6], 7 → 4
* [1,3,5,6], 0 → 0
* 
* Challenge
* O(log(n)) time
*/

/**
 * Challenge
 * O(log(n)) time
 * 
 * Run Time: 50ms
 */
class Solution
{
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target)
    {
        vector<int>::size_type left, right, middle;

        if (A.size() == 0)
            return 0;

        left = 0;
        right = A.size() - 1;

        while (left < right - 1)
        {
            middle = left + (right - left) / 2;

            if (A[middle] == target)
                return middle;
            else if (A[middle] < target)
            {
                left = middle;
            }
            else
                right = middle;
        }

        if (target <= A[left])
        {
            return left;
        }
        if (target <= A[right])
        {
            return right;
        }
        return A.size();
    }
};