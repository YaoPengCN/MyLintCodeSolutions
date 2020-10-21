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
 * Running Time: 6ms
 */
class Solution {
public:
	/**
	 * @param A: sorted integer array A
	 * @param B: sorted integer array B
	 * @return: A new sorted integer array
	 */
	// use binary search for the case when one array is very large and the other.
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		//write your code here
		vector<int> result, source;
		vector<int>::size_type ix = 0, position = 0;
		vector<int>::iterator iter;

		if (A.empty())
			return B;
		if (B.empty())
			return A;

		if (A.size() > B.size()){
			result = A;
			source = B;
		}
		else {
			result = B;
			source = A;
		}
		while (ix != source.size()) {
			position = binarySearch(result, position, source[ix]);
			iter = result.begin();
			result.insert(iter+position, source[ix++]);
		}
		return result;
	}
private:
	vector<int>::size_type binarySearch(vector<int> &Temp, vector<int>::size_type left, int target){
		vector<int>::size_type right;
		right = Temp.size() - 1;
		while (left <= right) {
			vector<int>::size_type mid = left + (right - left) / 2;
			if (Temp[mid] == target)
				return mid;
			if (target < Temp[mid])
				if (mid != 0)
					right = mid - 1;
				else
					return mid;
			else
				left = mid + 1;
		}
		return left;
	}
};

///**
// * Running Time: 6ms
// */
//class Solution {
//public:
//	/**
//	 * @param A: sorted integer array A
//	 * @param B: sorted integer array B
//	 * @return: A new sorted integer array
//	 */
//	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
//		//write your code here
//		vector<int> result;
//		vector<int>::size_type ix = 0, jx = 0;
//		while (ix != A.size() && jx != B.size()) {
//			if (A[ix] < B[jx]) {
//				result.push_back(A[ix++]);
//			}
//			else {
//				result.push_back(B[jx++]);
//			}
//		}
//		if (ix != A.size()) {
//			result.insert(result.end(), A.begin() + ix, A.end());
//		}
//		else if (jx != B.size()) {
//			result.insert(result.end(), B.begin() + jx, B.end());
//		}
//		return result;
//	}
//};