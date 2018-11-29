/** 
* 6. Merge Two Sorted Arrays
* Difficulty
* Easy
* 
* Description
* Merge two given sorted integer array A and B into a new sorted integer array.
*
* Example
* A=[1,2,3,4]
* B=[2,4,5,6]
* return [1,2,2,3,4,4,5,6]
* 
* Challenge
* How can you optimize your algorithm if one array is very large and the other is very small?

* Related Problems 
* 839. Merge Two Sorted Interval Lists
* 548. Intersection of Two Arrats II
* 547. Intersection of Two Arrats
* 165. Merge Two Sorted Lists
* 104. Merge K Sorted Lists
* 64. Merge Sorted Array
*/

/**
 * Challenge: How can you optimize your algorithm if one array is very large and the other is very small?
 * Run Time: 6ms
 */
class Solution {
public:
	/**
	 * @param A: sorted integer array A
	 * @param B: sorted integer array B
	 * @return: A new sorted integer array
	 */
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		//write your code here
		vector<int> result;
		vector<int>::size_type ix = 0, jx = 0;
		while (ix != A.size() && jx != B.size()) {
			if (A[ix] < B[jx]) {
				result.push_back(A[ix++]);
			}
			else {
				result.push_back(B[jx++]);
			}
		}
		if (ix != A.size()) {
			result.insert(result.end(), A.begin() + ix, A.end());
		}
		else if (jx != B.size()) {
			result.insert(result.end(), B.begin() + jx, B.end());
		}
		return result;
	}
};
