/** 
 * 156. Merge Intervals
 * Difficulty
 * Easy
 * 
 * Description
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example
 * Input: [(1,3)]
 * Output: [(1,3)]
 * 
 * Example 2:
 * Input:  [(1,3),(2,6),(8,10),(15,18)]
 * Output: [(1,6),(8,10),(15,18)]
 * 
 * Challenge
 * O(n log n) time and O(1) extra space.
 * 
 * Related Problems 
 * 1207. Teemo Attacking
 * 1074. Range Module
 * 1045. Partition Labels
 * 920. Meeting Rooms
 * 919. Meeting Rooms II
 * 839. Merge Two Sorted Interval Lists
 * 391. Number of Airplanes in the Sky
 * 30. Insert Interval
 */

/**
 * Challenge
 * O(n log n) time and O(1) extra space.
 * 
 * Ref[1]: https://www.jiuzhang.com/problem/merge-intervals/#tag-lang-cpp
 * Ref[2]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/qu-jian-wen-ti-he-ji
 * 
 * Running Time: 50ms
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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end(), intervalOrder);

        vector<Interval> result;
        Interval lastInterval = intervals[0];

        for (vector<Interval>::size_type i = 1; i != intervals.size(); i++)
        {
            if (haveIntercation(lastInterval, intervals[i]))
            {
                lastInterval = mergeTwoIntervals(lastInterval, intervals[i]);
            }
            else
            {
                result.push_back(lastInterval);
                lastInterval = intervals[i];
            }
        }
        result.push_back(lastInterval);

        return result;
    }

private:
    static bool intervalOrder(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }

    Interval mergeTwoIntervals(Interval &a, Interval &b)
    {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }

    bool haveIntercation(Interval &a, Interval &b)
    {
        return max(a.start, b.start) <= min(a.end, b.end);
    }
};