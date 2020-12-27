/** 
 * 1685. The maze IV
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Give you a map where 'S' indicates the starting point and 'T' indicates the ending point. 
 * '#' means that the wall is unable to pass, and '.' means that the road can take a minute to pass. 
 * Please find the minimum time it takes to get from the start point to the end point. 
 * If the end point cannot be reached, please output -1.
 * 
 * Example
 * Input:
 * map=[['S','.'],['#','T']]
 * Output:
 * t=2
 *  
 * Related Problems
 * 789. The maze III
 * 788. The Maze II
 * 787. The Maze
 */

/**
 * BFS
 * Ref: https://www.jiuzhang.com/problem/the-mazeiv/#tag-lang-cpp
 * Running Time: 201ms
 */

class Solution
{
public:
    /**
     * @param maps: 
     * @return: nothing
     */
    int theMazeIV(vector<vector<char>> &maps)
    {
        n = maps.size(), m = maps[0].size();
        for (int i = 0; i < maps.size(); i++)
            for (int j = 0; j < maps[i].size(); j++)
                if (maps[i][j] == 'S')
                    S.x = i, S.y = j, S.t = 0;
                else if (maps[i][j] == 'T')
                    T.x = i, T.y = j, T.t = 0;
        bfs(maps);
        return ans;
    }

private:
    int n, m, ans = -1;
    struct node
    {
        int x, y, t;
    } S, T;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    void bfs(vector<vector<char>> &maps)
    {
        queue<node> q;
        bool vis[1100][1100];
        memset(vis, 0, sizeof(vis));
        q.push(S);
        while (!q.empty())
        {
            node now = q.front();
            q.pop();
            if (now.x == T.x && now.y == T.y)
            {
                ans = now.t;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                node next;
                next.x = now.x + dx[i];
                next.y = now.y + dy[i];
                next.t = now.t + 1;
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)
                    continue;
                if (vis[next.x][next.y] == 1)
                    continue;
                if (maps[next.x][next.y] == '#')
                    continue;
                vis[next.x][next.y] = 1;
                q.push(next);
            }
        }
    }
};