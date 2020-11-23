/** 
 * 839. Merge Two Sorted Interval Lists
 * Difficulty
 * Easy
 * 
 * Description
 * Merge two sorted (ascending) lists of interval and return it as a new sorted list. 
 * The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.
 *
 * Clarification
 * The intervals in the given list do not overlap.
 * The intervals in different lists may overlap.
 * 
 * Example 
 * Example 1
 * Input: list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)]
 * Output: [(1,4),(5,6)]
 * Explanation:
 * (1,2),(2,3),(3,4) --> (1,4)
 * (5,6) --> (5,6)
 * 
 * Example 2:
 * Input: list1 = [(1,2),(3,4)] and list2 = [(4,5),(6,7)]
 * Output: [(1,2),(3,5),(6,7)]
 * Explanation:
 * (1,2) --> (1,2)
 * (3,4),(4,5) --> (3,5)
 * (6,7) --> (6,7)
 * 
 * Related Problems 
 * 1207. Teemo Attacking
 * 1074. Range Module
 * 1045. Partition Labels
 * 920. Meeting Rooms
 * 919. Meeting Rooms II
 * 577. Merge K Sorted Interval Lists
 * 486. Merge K Sorted Arrays
 * 391. Number of Airplanes in the Sky
 * 156. Merge Intervals
 * 30. Insert Interval
 */

/** 
 * Ref[1]: https://www.jiuzhang.com/problem/merge-two-sorted-interval-lists/#tag-lang-cpp
 * Ref[2]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/qu-jian-wen-ti-he-ji
 * 
 * Running Time: 354ms
 */

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2)
    {
        if (list1.empty() && list2.empty())
            return {};
        if (list1.empty())
            return list2;
        if (list2.empty())
            return list1;

        vector<Interval>::size_type index1 = 0, index2 = 0;

        Interval now;

        vector<Interval> ans;

        while (index1 != list1.size() && index2 != list2.size())
        {

            Interval a = list1[index1], b = list2[index2];

            if (a.start <= b.start)
            {

                now = a;
                index1++;
            }
            else
            {

                now = b;
                index2++;
            }

            if (ans.empty())
            {
                ans.push_back(now);
            }
            else
            {
                merge(ans, ans[ans.size() - 1], now);
            }
        }

        while (index2 != list2.size())
        {
            merge(ans, ans[ans.size() - 1], list2[index2++]);
        }

        while (index1 != list1.size())
        {
            merge(ans, ans[ans.size() - 1], list1[index1++]);
        }

        return ans;
    }

private:
    void merge(vector<Interval> &ans, Interval &last, Interval &now)
    {

        if (last.end < now.start)
        {
            ans.push_back(now);
        }
        else
        {
            last.end = max(last.end, now.end);
        }
    }
};