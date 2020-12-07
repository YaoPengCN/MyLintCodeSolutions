/** 
 * 81. Find Median from Data Stream
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Numbers keep coming, return the median of numbers at every time a new number added.
 * 
 * Clarification
 * What's the definition of Median?
 * The median is not equal to median in math.
 * Median is the number that in the middle of a sorted array. 
 * If there are n numbers in a sorted array A, the median is A[(n - 1) / 2].
 * For example, if A=[1,2,3], median is 2. If A=[1,19], median is 1.
 * 
 * Example
 * Example 1
 * Input: 
 * [1,2,3,4,5]
 * Output: 
 * [1,1,2,2,3]
 * Explanation:
 * The medium of [1] and [1,2] is 1.
 * The medium of [1,2,3] and [1,2,3,4] is 2.
 * The medium of [1,2,3,4,5] is 3.
 * 
 * Example 2
 * Input: 
 * [4,5,1,3,2,6,0]
 * Output: 
 * [4,4,4,3,3,3,3]
 * Explanation:
 * The medium of [4], [4,5], [4,5,1] is 4.
 * The medium of [4,5,1,3], [4,5,1,3,2], [4,5,1,3,2,6] and [4,5,1,3,2,6,0] is 3.
 * 
 * Challenge
 * Total run time in O(nlogn).
 *
 * Related Problems
 * 685. First Unique Number in Data Stream
 * 642. Moving Average from Data Stream
 * 360. Sliding Window Median
 * 80. Median
 * 65. Median of two Sorted Arrays
 * 5. Kth Largest Element
 * */

/** 
 * Challenge
 * Total run time in O(nlogn).
 * 
 * multiset
 * Ref: https://www.jiuzhang.com/problem/find-median-from-data-stream/#tag-lang-cpp
 * Running Time:  62ms
 */

template <class T>
class MedianStream
{
public:
    inline void add(const T &x)
    {
        // Count elements BEFORE insertion
        const int n = cache.size();
        cache.insert(x);
        if (n == 0)
        {
            pos = cache.begin();
            return;
        }
        if (x >= *pos && n % 2 == 0)
        {
            ++pos;
            return;
        }
        if (x < *pos && n % 2 == 1)
            --pos;
    }

    inline T median() const
    {
        return *pos;
    }

private:
    multiset<T> cache;
    typename multiset<T>::iterator pos;
};

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums)
    {
        MedianStream<int> stream;
        vector<int> medians;
        for (const int &x : nums)
        {
            stream.add(x);
            medians.push_back(stream.median());
        }
        return medians;
    }
};

// /**
//  * Maxheap, minheap
//  * Ref: https://www.jiuzhang.com/problem/find-median-from-data-stream/#tag-lang-cpp
//  * Running Time:  101ms
//  */
// class Solution
// {
// public:
//     /**
//      * @param nums: A list of integers
//      * @return: the median of numbers
//      */
//     vector<int> medianII(vector<int> &nums)
//     {
//         vector<int> ans;
//         for (int num : nums)
//         {
//             push(num);
//             ans.push_back(maxQ.top());
//         }
//         return ans;
//     }

// private:
//     priority_queue<int, vector<int>, greater<int>> minQ;
//     priority_queue<int> maxQ;
//     void push(int num)
//     {
//         if (maxQ.empty() || num <= maxQ.top())
//             maxQ.push(num);
//         else
//             minQ.push(num);
//         rebalance();
//     }
//     void rebalance()
//     {
//         if (maxQ.size() - 1 > minQ.size())
//         {
//             minQ.push(maxQ.top());
//             maxQ.pop();
//         }
//         if (minQ.size() > maxQ.size())
//         {
//             maxQ.push(minQ.top());
//             minQ.pop();
//         }
//     }
// };