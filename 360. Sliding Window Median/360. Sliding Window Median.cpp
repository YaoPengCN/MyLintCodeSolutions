/** 
 * 360. Sliding Window Median
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Given an array of n integer, and a moving window(size k), 
 * move the window at each iteration from the start of the array, 
 * find the median of the element inside the window at each moving. 
 * (If there are even numbers in the array, return the N/2-th number after sorting the element in the window. )
 * 
 * Example
 * Example 1
 * Input:
 * [1,2,7,8,5]
 * 3
 * Output:
 * [2,7,7]
 * Explanation:
 * At first the window is at the start of the array like this `[ | 1,2,7 | ,8,5]` , return the median `2`;
 * then the window move one step forward.`[1, | 2,7,8 | ,5]`, return the median `7`;
 * then the window move one step forward again.`[1,2, | 7,8,5 | ]`, return the median `7`;
 * 
 * Example 2
 * Input:
 * [1,2,3,4,5,6,7]
 * 4
 * Output:
 * [2,3,4,5]
 * Explanation:
 * At first the window is at the start of the array like this `[ | 1,2,3,4, | 5,6,7]` , return the median `2`;
 * then the window move one step forward.`[1,| 2,3,4,5 | 6,7]`, return the median `3`;
 * then the window move one step forward again.`[1,2, | 3,4,5,6 | 7 ]`, return the median `4`;
 * then the window move one step forward again.`[1,2,3,| 4,5,6,7 ]`, return the median `5`;
 * 
 * Challenge
 * O(nlog(n)) time
 *
 * Related Problems
 * 685. First Unique Number in Data Stream
 * 642. Moving Average from Data Stream
 * 81. Find Median from Data Stream
 * 80. Median
 * 65. Median of two Sorted Arrays
 * 5. Kth Largest Element
 * */

/** 
 * Challenge
 * Total run time in O(nlogn).
 * 
 * multiset
 * Ref: https://www.jiuzhang.com/problem/sliding-window-median/#tag-lang-cpp
 * Running Time:  251ms
 */

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.size() < k || k < 1)
        {
            return vector<int>();
        }

        // two multiset, two BST
        vector<int> median(nums.size() - k + 1, 0);

        // lo size = hi size / hi size + 1
        for (int i = 0; i < nums.size(); i++)
        {
            push(nums[i]);
            if (i >= k)
            {
                pop(nums[i - k]);
            }

            if (i >= k - 1)
            {
                median[i - k + 1] = *lo.begin();
            }
        }

        return median;
    }

private:
    multiset<int, greater<int>> lo; // from large to small
    multiset<int> hi;               // from small to large

    void push(int x)
    {
        if (lo.empty() || x <= *lo.begin())
        {
            lo.insert(x);
        }
        else
        {
            hi.insert(x);
        }
        rebalance();
    }

    void pop(int x)
    {
        if (lo.count(x))
        {
            lo.erase(lo.find(x));
        }
        else
        {
            hi.erase(hi.find(x));
        }
        rebalance();
    }

    void rebalance()
    {
        if (lo.size() > hi.size() + 1)
        {
            hi.insert(*lo.begin());
            lo.erase(lo.begin());
        }
        if (lo.size() < hi.size())
        {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }
};