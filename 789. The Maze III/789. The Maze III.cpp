/** 
 * 789. The Maze III
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * There is a ball in a maze with empty spaces and walls. 
 * The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. 
 * When the ball stops, it could choose the next direction. 
 * There is also a hole in this maze. 
 * The ball will drop into the hole if it rolls on to the hole.
 * Given the ball position, the hole position, and the maze, find out how the ball could drop into the hole by moving the shortest distance. 
 * The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). 
 * Output the moving directions by using 'u', 'd', 'l' and 'r'. 
 * Since there could be several different shortest ways, you should output the lexicographically smallest way. 
 * If the ball cannot reach the hole, output "impossible".
 * The maze is represented by a binary 2D array. 
 * 1 means the wall and 0 means the empty space. 
 * You may assume that the borders of the maze are all walls. 
 * The ball and the hole coordinates are represented by row and column indexes.
 * 
 * Clarification
 * 1.There is only one ball and one hole in the maze.
 * 2.Both the ball and hole exist on an empty space, and they will not be at the same position initially.
 * 3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
 * 4.The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.
 * 
 * Example
 * Example 1
 * Input:
 * [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]]
 * [4,3]
 * [0,1]
 * Output:
 * "lul"
 * 
 * Example 2:
 * Input:
 * [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]]
 * [0,0]
 * [1,1]
 * [2,2]
 * [3,3]
 * Output:
 * "impossible"
 *  
 * Related Problems
 * 1685. The maze IV
 * 788. The Maze II
 * 787. The Maze
 */

/**
 * BFS + priority queue
 * Ref: https://www.jiuzhang.com/problem/the-maze-iii/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param ball: the ball position
     * @param hole: the hole position
     * @return: the lexicographically smallest way
     */
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole)
    {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<char> way{'l', 'u', 'r', 'd'};
        queue<pair<int, int>> q;
        unordered_map<int, string> u;

        dists[ball[0]][ball[1]] = 0;
        q.push({ball[0], ball[1]});

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int x = t.first, y = t.second, dist = dists[x][y];

                string path = u[x * n + y];

                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && (x != hole[0] || y != hole[1]))
                {
                    x += dirs[i][0];
                    y += dirs[i][1];
                    ++dist;
                }

                if (x != hole[0] || y != hole[1])
                {
                    x -= dirs[i][0];
                    y -= dirs[i][1];
                    --dist;
                }

                path.push_back(way[i]);
                if (dists[x][y] > dist)
                {
                    dists[x][y] = dist;
                    u[x * n + y] = path;
                    if (x != hole[0] || y != hole[1])
                        q.push({x, y});
                }
                else if (dists[x][y] == dist && u[x * n + y].compare(path) > 0)
                {
                    u[x * n + y] = path;
                    if (x != hole[0] || y != hole[1])
                        q.push({x, y});
                }
            }
        }

        string res = u[hole[0] * n + hole[1]];

        return res.empty() ? "impossible" : res;
    }
};