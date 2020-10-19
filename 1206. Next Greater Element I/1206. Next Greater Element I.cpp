/** 
 * 1206. Next Greater Element I
 * Difficulty
 * Easy
 * 
 * Description
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
 * Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
 * 
 * 
 * Clarification
 * 1.All elements in nums1 and nums2 are unique.
 * 2.The length of both nums1 and nums2 would not exceed 1000.
 *
 * Example
 * Example1
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 * For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 * For number 1 in the first array, the next greater number for it in the second array is 3.
 * For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 * 
 * Example2 
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 * For number 2 in the first array, the next greater number for it in the second array is 3.
 * For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 * 
 * Related Problems 
 * 1201. Next Greater Element II
 * 1174. Next Greater Element III
 * */

/**
 * Run Time: 50ms
 */
class Solution
{
public:
	/**
     * @param nums1: an array
     * @param nums2: an array
     * @return:  find all the next greater numbers for nums1's elements in the corresponding places of nums2
     */
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> result;
		for (vector<int>::size_type i = 0; i != nums1.size(); i++)
		{
			bool flag = false;
			vector<int>::iterator iter = find(nums2.begin(), nums2.end(), nums1[i]);
			int index = distance(nums2.begin(), iter);
			for (int j = index; j != nums2.size(); j++)
			{
				if (nums1[i] < nums2[j])
				{
					flag = true;
					index = j;
					break;
				}
			}
			if (flag)
				result.push_back(nums2[index]);
			else
			{
				result.push_back(-1);
			}
		}
		return result;
	}
};