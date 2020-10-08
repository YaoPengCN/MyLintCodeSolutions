/** 
* 64. Merge Sorted Array
* Difficulty
* Easy
* 
* Description
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* 
* Clarification
* You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
* The number of elements initialized in A and B are m and n respectively.
*
* Example
* Example 1
* Input：[1, 2, 3] 3  [4,5]  2
* Output：[1,2,3,4,5]
* Explanation:
* After merge, A will be filled as [1, 2, 3, 4, 5]
* 
* Example 2:
* Input：[1,2,5] 3 [3,4] 2
* Output：[1,2,3,4,5]
* Explanation:
* After merge, A will be filled as [1, 2, 3, 4, 5]
* 
* Related Problems 
* 839. Merge Two Sorted Interval Lists
* 212. Space Replacement
* 6. Merge Two Sorted Arrays
*/

/**
 * Ref[1]: https://www.jiuzhang.com/problem/merge-sorted-array/
 * Run Time: 435ms
 */
class Solution
{
public:
	/*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
	void mergeSortedArray(int A[], int m, int B[], int n)
	{
		// 初始化双指针和当前元素应存储在新数组的位置
		int pointA = m - 1, pointB = n - 1, index = m + n - 1;

		while (pointA >= 0 && pointB >= 0)
		{
			// 比较大小，并将其存入新数组
			if (A[pointA] > B[pointB])
			{
				A[index--] = A[pointA--];
			}
			else
			{
				A[index--] = B[pointB--];
			}
		}

		// 若未遍历完毕，继续把相应数组的剩余元素存入新数组
		while (pointA >= 0)
		{
			A[index--] = A[pointA--];
		}
		while (pointB >= 0)
		{
			A[index--] = B[pointB--];
		}
	}
};
