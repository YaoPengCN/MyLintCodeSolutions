/** 
 * 1060. Daily Temperatures
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.
 * If there is no future day for which this is possible, put 0 instead.
 * For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * Clarification
 * The length of temperatures will be in the range [1, 30000]. 
 * Each temperature will be an integer in the range [30, 100]
 *
 * Example
 * Example 1
 * Input:  temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
 * Output:  [1, 1, 4, 2, 1, 1, 0, 0]
 * Explanation:
 * Just find the first day after it which has higher temperatures than it.
 * 
 * Example 2 
 * Input: temperatures = [50, 40, 39, 30]
 * Output:  [0,0,0,0]
 * 
 * Related Problems 
 * 1206. Next Greater Element I
 * */

/**
 * Monotone stack
 * Ref[1]: https://mp.weixin.qq.com/s/KYfjBejo84AmajnPZNs5nA
 * Ref[2]: https://www.jiuzhang.com/problem/daily-temperatures/#tag-lang-cpp
 * Running Time: 201ms
 */

class Solution
{
public:
	/**
     * @param temperatures: a list of daily temperatures
     * @return: a list of how many days you would have to wait until a warmer temperature
     */
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		vector<int>::size_type n = temperatures.size();
		stack<int> st;
		vector<int> waitingDays(n, 0);

		for (vector<int>::size_type i = 0; i != n; i++)
		{
			while (!st.empty() && temperatures[i] > temperatures[st.top()])
			{
				waitingDays[st.top()] = i - st.top();
				st.pop();
			}
			st.push(i);
		}
		return waitingDays;
	}
};