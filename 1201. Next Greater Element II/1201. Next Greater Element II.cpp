/** 
 * 1201. Next Greater Element II
 * Difficulty
 * Medium
 * 
 * Description
 * Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. 
 * The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 
 * If it doesn't exist, output -1 for this number.
 * 
 * Clarification
 * The length of given array won't exceed 10000.
 *
 * Example
 * Example 1
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; 
 * The number 2 can't find next greater number; 
 * The second 1's next greater number needs to search circularly, which is also 2.
 * 
 * Example 2 
 * Input: [1]
 * Output: [-1]
 * Explanation:
 * The number 1 can't find next greater number.
 * 
 * Related Problems 
 * 1206. Next Greater Element I
 * 1174. Next Greater Element III
 * */

/**
 * Monotone stack
 * Ref[1]: https://mp.weixin.qq.com/s/KYfjBejo84AmajnPZNs5nA
 * Ref[2]: https://www.jiuzhang.com/problem/next-greater-element-ii/#tag-lang-cpp
 * Run Time: 151ms
 */

class Solution
{
public:
	/**
     * @param nums: an array
     * @return: the Next Greater Number for every element
     */
	vector<int> nextGreaterElements(vector<int> &nums)
	{
		vector<int>::size_type n = nums.size();
		vector<int> result(n, -1);
		stack<int> st;
		for (vector<int>::size_type i = 0; i < n * 2; i++)
		{
			int num = nums[i % n];
			while (!st.empty() && nums[st.top()] < num)
			{
				result[st.top()] = num;
				st.pop();
			}
			if (i < n)
				st.push(i);
		}
		return result;
	}
};

// /**
//  * Run Time: 104ms
//  */
// class Solution
// {
// public:
// 	/**
//      * @param nums: an array
//      * @return: the Next Greater Number for every element
//      */
// 	vector<int> nextGreaterElements(vector<int> &nums)
// 	{
// 		vector<int> result;
// 		for (vector<int>::size_type i = 0; i != nums.size(); i++)
// 		{
// 			bool flag = false;
// 			int index = i;
// 			for (int j = (i + 1) % nums.size(); j != i; j = (j + 1) % nums.size())
// 			{
// 				if (nums[i] < nums[j])
// 				{
// 					flag = true;
// 					index = j;
// 					break;
// 				}
// 			}
// 			if (flag)
// 				result.push_back(nums[index]);
// 			else
// 			{
// 				result.push_back(-1);
// 			}
// 		}
// 		return result;
// 	}
// };