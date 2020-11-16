/** 
 * 4. Ugly Number II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Ugly number is a number that only have prime factors 2, 3 and 5.
 * Design an algorithm to find the nth ugly number. 
 * The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
 *
 * Clarification
 * Note that 1 is typically treated as an ugly number.
 * 
 * Example
 * Example 1
 * Input:
 * 9
 * Output:
 * 10
 * 
 * Example 2
 * Input:
 * 1
 * Output:
 * 1
 * 
 * Challenge
 * O(n log n) or O(n) time.
 * 
 * Related Problems
 * 791. Merge Number
 * 518. Super Ugly Number
 * 513. Perfect Squares
 * 488. Happy Number
 * 147. Narcissistic Number
 * 104. Merge K Sorted Lists
 * */

/**
 * Challenge
 * O(n log n) or O(n) time.
 * 
 * Min heap
 * Ref[1]: https://iq.opengenus.org/max-heap-min-heap/
 * Ref[2]: https://www.jiuzhang.com/problem/ugly-number-ii/#tag-lang-cpp
 * Time complexation O(nlog(n)), space complexation O(n)
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        heap.push(1LL);

        set<long long> seen;
        seen.insert(1LL);

        vector<int> factors({2, 3, 5});

        long long currUgly = 1LL, newUgly;

        for (int i = 0; i < n; i++)
        {
            // pop the current minimum ugly number
            currUgly = heap.top();
            heap.pop();
            // generate a new ugly number
            for (int &f : factors)
            {
                newUgly = currUgly * f;
                if (seen.count(newUgly) == 0)
                {
                    seen.insert(newUgly);
                    heap.push(newUgly);
                }
            }
        }
        return (int)currUgly;
    }
};