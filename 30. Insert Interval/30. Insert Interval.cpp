/** 
 * 30. Insert Interval
 * Difficulty
 * Medium
 * 
 * Description
 * Given a non-overlapping interval list which is sorted by start point.
 * Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).
 *
 * Example
 * Input: (2, 5) into [(1,2), (5,9)]
 * Output: [(1,9)]
 * 
 * Example 2:
 * Input:  (3, 4) into [(1,2), (5,9)]
 * Output: [(1,2), (3,4), (5,9)]
 * 
 * Related Problems 
 * 1207. Teemo Attacking
 * 1074. Range Module
 * 1045. Partition Labels
 * 920. Meeting Rooms
 * 919. Meeting Rooms II
 * 839. Merge Two Sorted Interval Lists
 * 391. Number of Airplanes in the Sky
 * 156. Merge Intervals
 */

/** 
 * Ref[1]: https://www.jiuzhang.com/problem/insert-interval/#tag-lang-cpp
 * Ref[2]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/qu-jian-wen-ti-he-ji
 * 
 * Running Time: 797ms
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
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        if (intervals.empty())
            return {};
        vector<Interval> newIntervals;
        for (vector<Interval>::size_type i = 0; i != intervals.size(); i++)
        {
            if (newInterval.end < intervals[i].start)
            {
                newIntervals.push_back(newInterval);
                for (vector<Interval>::size_type j = i; j != intervals.size(); j++)
                {
                    newIntervals.push_back(intervals[j]);
                }
                break;
            }
            else if (newInterval.start > intervals[i].end)
            {
                newIntervals.push_back(intervals[i]);
            }
            else
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            if (i == intervals.size() - 1)
            {
                newIntervals.push_back(newInterval);
            }
        }
        return newIntervals;
    }
};