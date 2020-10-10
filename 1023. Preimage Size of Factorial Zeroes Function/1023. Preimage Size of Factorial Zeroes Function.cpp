/** 
* 1023. Preimage Size of Factorial Zeroes Function
* Difficulty
* Hard
* 
* Description
* Let f(x) be the number of zeroes at the end of x!.
* (Recall that x! = 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)
* For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has 2 zeroes at the end.
* Given K, find how many non-negative integers x have the property that f(x) = K.
* 
* 
* Clarification
* K will be an integer in the range [0, 10^9].
*
* Example
* Example1
* Input: K = 0
* Output: 5
* Explanation:
* 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.
* 
* Example2
* Input: K = 5
* Output: 0
* Explanation:
* There is no x such that x! ends in K = 5 zeroes.
* 
* Related Problems 
* 1347. Factorial Trailing Zeroes
* 2. Trailing Zeros
*/

/**
 * Ref[1]: https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/jie-cheng-ti-mu
 * Run Time: 51ms
 */

class Solution
{
public:
	/**
     * @param K: an integer
     * @return: how many non-negative integers x have the property that f(x) = K
     */
	int preimageSizeFZF(int K)
	{
		// 左边界和右边界之差 + 1 就是答案
		return right_bound(K) - left_bound(K) + 1;
	}

private:
	/* 搜索 trailingZeroes(n) == K 的左侧边界 */
	long left_bound(int target)
	{
		long lo = 0, hi = LONG_MAX;
		while (lo < hi)
		{
			long mid = lo + (hi - lo) / 2;
			if (trailingZeroes(mid) < target)
			{
				lo = mid + 1;
			}
			else if (trailingZeroes(mid) > target)
			{
				hi = mid;
			}
			else
			{
				hi = mid;
			}
		}

		return lo;
	}

	/* 搜索 trailingZeroes(n) == K 的右侧边界 */
	long right_bound(int target)
	{
		long lo = 0, hi = LONG_MAX;
		while (lo < hi)
		{
			long mid = lo + (hi - lo) / 2;
			if (trailingZeroes(mid) < target)
			{
				lo = mid + 1;
			}
			else if (trailingZeroes(mid) > target)
			{
				hi = mid;
			}
			else
			{
				lo = mid + 1;
			}
		}

		return lo - 1;
	}

	long trailingZeroes(long n)
	{
		long res = 0;
		for (long d = n; d / 5 > 0; d = d / 5)
		{
			res += d / 5;
		}
		return res;
	}
};