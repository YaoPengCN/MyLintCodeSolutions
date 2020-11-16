/** 
 * 518. Super Ugly Number
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Write a program to find the nth super ugly number.
 * A super ugly number is a positive integer in which all prime factors are within a given set of prime numbers.
 * For example, given [2, 7, 13, 19], then [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the first 12 super ugly numbers.
 *
 * Clarification
 * 1 is a super ugly number for any given primes.
 * 0 < k ≤ 100, 0 < n ≤ 10^610​6, 0 < primes[i] < 1000
 * k is the length of the ugly set
 * 
 * Example
 * Example 1
 * Input:
 * n = 6, [2,7,13,19]
 * Output:
 * 13
 * 
 * Example 2
 * Input:
 * n = 11, [2,3,5]
 * Output:
 * 15
 * 
 * Related Problems
 * 517. Ugly Number
 * 4. Ugly Number II
 * */

/**
 * Min heap
 * Ref[1]: https://iq.opengenus.org/max-heap-min-heap/
 * Running Time: 101ms
 */

class Solution {
public:
    /**
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        heap.push(1LL);

        set<long long> seen;
        seen.insert(1LL);

        long long currUgly = 1LL, newUgly;

        for (int i = 0; i != n; i++)
        {
            // pop the current minimum ugly number
            currUgly = heap.top();
            heap.pop();
            // generate a new ugly number
            for (int &f : primes)
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