/** 
 * 65. Median of two Sorted Arrays
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays.
 * 
 * Clarification
 * The definition of the median:
 * The median here is equivalent to the median in the mathematical definition.
 * The median is the middle of the sorted array.
 * If there are n numbers in the array and n is an odd number, the median is A[(n-1)/2].
 * If there are n numbers in the array and n is even, the median is (A[n / 2] + A[n / 2 + 1]) / 2.
 * For example, the median of the array A=[1,2,3] is 2, and the median of the array A=[1,19] is 10.
 * 
 * Example
 * Example 1
 * Input:
 * A = [1,2,3,4,5,6]
 * B = [2,3,4,5]
 * Output: 3.5
 * 
 * Example 2
 * Input:
 * A = [1,2,3]
 * B = [4,5]
 * Output: 3
 * 
 * Challenge
 * The overall run time complexity should be O(log (m+n)).
 *
 * Related Problems
 * 931. Median of K Sorted Arrays
 * 81. Find Median from Data Stream
 * 80. Median
 * */

/**
 * Challenge
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Ref: https://www.jiuzhang.com/problem/median-of-two-sorted-arrays/
 * Running Time:  605ms
 */
class Solution
{
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B)
    {
        int m = A.size(), n = B.size();

        // if (m + n) % 2 is odd
        if ((m + n) % 2 == 1)
        {
            return getKth(A, 0, A.size() - 1, B, 0, B.size() - 1, (m + n) / 2 + 1);
        }

        // if (m + n) % 2 is even
        int left = getKth(A, 0, A.size() - 1, B, 0, B.size() - 1, (m + n) / 2);
        int right = getKth(A, 0, A.size() - 1, B, 0, B.size() - 1, (m + n) / 2 + 1);
        return (left + right) / 2.0;
    }

private:
    int getKth(vector<int> &A, int start1, int end1, vector<int> &B, int start2, int end2, int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // let the length of len1 < the length of len2
        if (len1 > len2)
        {
            return getKth(B, start2, end2, A, start1, end1, k);
        }
        // the shorter array has been checked totally
        if (len1 == 0)
        {
            return B[start2 + k - 1];
        }
        // if the k-the element has been found
        if (k == 1)
        {
            return min(A[start1], B[start2]);
        }
        // binary search
        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;

        if (A[i] > B[j])
        {
            return getKth(A, start1, end1, B, j + 1, end2, k - (j - start2 + 1));
        }
        else
        {
            return getKth(A, i + 1, end1, B, start2, end2, k - (i - start1 + 1));
        }
    }
};

// /**
//  * O(m+n)
//  *
//  * Ref: https://www.jiuzhang.com/problem/median-of-two-sorted-arrays/
//  * Running Time:  571ms
//  */
// class Solution
// {
// public:
//     /*
//      * @param A: An integer array
//      * @param B: An integer array
//      * @return: a double whose format is *.5 or *.0
//      */
//     double findMedianSortedArrays(vector<int> &A, vector<int> &B)
//     {
//         vector<int>::size_type m = A.size(), n = B.size();
//         vector<int>::size_type p1 = 0, p2 = 0;
//         int left = -1, right = -1;
//         for (vector<int>::size_type i = 0; i < (m + n) / 2 + 1; i++)
//         {
//             left = right;
//             if (p1 >= A.size() || p2 < B.size() && A[p1] > B[p2])
//             {
//                 right = B[p2++];
//             }
//             else
//             {
//                 right = A[p1++];
//             }
//         }
//         return (m + n) % 2 == 1 ? right : (left + right) / 2.0;
//     }
// };
