/** 
* 796. Open the Lock
* Difficulty
* Hard
* 
* Description
* You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
* The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
* The lock initially starts at '0000', a string representing the state of the 4 wheels.
* You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
* Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
*
* Clarification
* 1.The length of deadends will be in the range [1, 500].
* 2.target will not be in the list deadends.
* 3.Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.
*
* Example
* Example 1
* Given deadends = ["0201","0101","0102","1212","2002"], target = "0202"
* Return 6
* Explanation:
* A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
* Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid, because the wheels of the lock become stuck after the display becomes the dead end "0102".
* 
* Example 2:
* Given deadends = ["8888"], target = "0009"
* Return 1
* Explanation:
* We can turn the last wheel in reverse to move from "0000" -> "0009".
* 
* Related Problems 
* 794. Sliding Puzzle II
* 630. Knight Shortest Path II
* 115. Unique Paths II

*/

/**
 * Bidirectional BFS
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/bfs-kuang-jia
 * Ref[2]: https://www.jiuzhang.com/problem/open-the-lock/
 * Running Time: 403ms
 */
class Solution
{
public:
    /**
     * @param deadends: the list of deadends
     * @param target: the value of the wheels that will unlock the lock
     * @return: the minimum total number of turns 
     */
    int openLock(vector<string> &deadends, string &target)
    {
        string start = "0000";
        if (start == target)
        {
            return 0;
        }

        unordered_set<string> deadset;

        for (int i = 0; i < deadends.size(); i++)
        {
            deadset.insert(deadends[i]);

            if (deadset.find(start) != deadset.end())
            {
                return -1;
            }
        }

        queue<string> q;
        q.push(start);

        unordered_set<string> v;
        v.insert(start);

        int dist = 0;
        while (!q.empty())
        {
            dist++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    char curr_c = cur[k];
                    string next = cur.substr(0, k) + char((curr_c - '0' - 1 + 10) % 10 + '0') + cur.substr(k + 1);
                    if (target == next)
                    {
                        return dist;
                    }

                    if (v.find(next) == v.end() && deadset.find(next) == deadset.end())
                    {
                        v.insert(next);
                        q.push(next);
                    }

                    next = cur.substr(0, k) + char((curr_c - '0' + 1 + 10) % 10 + '0') + cur.substr(k + 1);
                    if (target == next)
                    {
                        return dist;
                    }

                    if (v.find(next) == v.end() && deadset.find(next) == deadset.end())
                    {
                        v.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};