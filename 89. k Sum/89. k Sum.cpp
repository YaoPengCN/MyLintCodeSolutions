/** 
 * 89. k Sum
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Given n distinct positive integers, integer k (k <= n) and a number target.
 * Find k numbers where sum is target. Calculate how many solutions there are?
 * 
 * Example
 * Example 1
 * Input:
 * List = [1,2,3,4]
 * k = 2
 * target = 5
 * Output:
 * 2
 * Explanation: 
 * 1 + 4 = 2 + 3 = 5
 * 
 * Example 2
 * Input: 
 * List = [1,2,3,4,5]
 * k = 3
 * target = 6
 * Output:	
 * 1
 * Explanation: 
 * There is only one method. 1 + 2 + 3 = 6
 *
 * Related Problems
 * 1689. k Sum III
 * 90. k Sum II
 * 58. 4Sum
 * 57. 3Sum
 * 56. Two Sum
 * */

/**
 * Dynamic programming
 * Ref[1]: https://www.jiuzhang.com/problem/k-sum/#tag-lang-cpp
 * Running Time:  151ms
 */

class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int K, int T) {
        int n = A.size();
        if (K > n || T <= 0) {
            return 0;
        }
        
        // if K is large, take the complement
        if (K > n / 2) {
            int sum = 0;
            for (int &a : A) {
                sum += a;
            }
            K = n - K;
            T = sum - T;
        }
        
        sort(A.begin(), A.end());
        
        // f[i][k][t] = using A[0...i-1], k numbers, sum = t
        // f[i][k][t] = f[i-1][k][t] + f[i-1][k-1][t-A[i-1]], t>=A[i-1]
        // f[0][0][0] = 1, f[0][k][t] = 0, k>0 or t>0
        // i>0,f[i][0][0]=1, f[i][0][t] = 0, t >0, f[i][k][0] = 0, k>0
        
        vector<vector<int>> f(K + 1, vector<int>(T + 1, 0));
        f[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int k = min(K, i); k >= 1; k--) {
                int v = A[i - 1];
                for (int t = T; t >= v; t--) {
                    f[k][t] += f[k - 1][t - v];
                }
            }
        }
        return f[K][T];
    }
};

// /**
//  * This solution works but fails to reach the time limitation.
//  * Ref[1]: https://mp.weixin.qq.com/s/fSyJVvggxHq28a0SdmZm6Q
//  * Running Time:  ms
//  */
// class Solution
// {
// public:
//     /**
//      * @param A: An integer array
//      * @param k: A positive integer (k <= length(A))
//      * @param target: An integer
//      * @return: An integera
//      */
//     int kSum(vector<int> &A, int k, int target)
//     {
//         sort(A.begin(), A.end());

//         if (k == 1)
//         {
//             int count = 0;
//             for (int i = 0; i != A.size(); i++)
//             {
//                 if (A[i] == target)
//                     count++;
//             }
//             return count;
//         }
//         return nSumTarget(A, k, 0, target).size();
//     }

// private:
//     vector<vector<int>> nSumTarget(vector<int> &nums, int n, int start, int target)
//     {
//         int sz = nums.size();
//         vector<vector<int>> res;

//         if (n < 2 || sz < n)
//             return res;

//         // 2Sum
//         if (n == 2)
//         {
//             // double pointers
//             int lo = start, hi = sz - 1;
//             while (lo < hi)
//             {
//                 int sum = nums[lo] + nums[hi];
//                 int left = nums[lo], right = nums[hi];
//                 if (sum < target)
//                 {
//                     while (lo < hi && nums[lo] == left)
//                         lo++;
//                 }
//                 else if (sum > target)
//                 {
//                     while (lo < hi && nums[hi] == right)
//                         hi--;
//                 }
//                 else
//                 {
//                     res.push_back({left, right});
//                     while (lo < hi && nums[lo] == left)
//                         lo++;
//                     while (lo < hi && nums[hi] == right)
//                         hi--;
//                 }
//             }
//         }
//         else
//         {
//             // n > 2, nSum
//             for (int i = start; i < sz; i++)
//             {
//                 vector<vector<int>> sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
//                 for (vector<int> &arr : sub)
//                 {
//                     // the result of nSum is the result of (n-1)Sum with nums[i]
//                     arr.push_back(nums[i]);
//                     sort(arr.begin(), arr.end());
//                     res.push_back(arr);
//                 }
//                 while (i < sz - 1 && nums[i] == nums[i + 1])
//                     i++;
//             }
//         }
//         return res;
//     }
// };
