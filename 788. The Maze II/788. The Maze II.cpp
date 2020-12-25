/** 
 * 788. The Maze II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * There is a ball in a maze with empty spaces and walls. 
 * The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
 * When the ball stops, it could choose the next direction.
 * Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. 
 * The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). 
 * If the ball cannot stop at the destination, return -1.
 * The maze is represented by a binary 2D array. 
 * 1 means the wall and 0 means the empty space. 
 * You may assume that the borders of the maze are all walls. 
 * The start and destination coordinates are represented by row and column indexes.
 * 
 * Clarification
 * 1.There is only one ball and one destination in the maze.
 * 2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
 * 3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
 * 4.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
 * 
 * Example
 * Example 1
 * Input:
 *  (rowStart, colStart) = (0,4)
 *  (rowDest, colDest)= (4,4)
 *  0 0 1 0 0
 *  0 0 0 0 0
 *  0 0 0 1 0
 *  1 1 0 1 1
 *  0 0 0 0 0
 * Output:  
 *  12
 * Explanation:
 *  (0,4)->(0,3)->(1,3)->(1,2)->(1,1)->(1,0)->(2,0)->(2,1)->(2,2)->(3,2)->(4,2)->(4,3)->(4,4)
 * 
 * Example 2:
 * Input:
 * 	(rowStart, colStart) = (0,4)
 * 	(rowDest, colDest)= (0,0)
 * 	0 0 1 0 0
 * 	0 0 0 0 0
 * 	0 0 0 1 0
 * 	1 1 0 1 1
 * 	0 0 0 0 0
 * Output: 
 *  6
 * Explanation:
 *  (0,4)->(0,3)->(1,3)->(1,2)->(1,1)->(1,0)->(0,0)
 *  
 * Related Problems
 * 1685. The maze IV
 * 789. The Maze III
 * 787. The Maze
 */

/**
 * BFS + priority queue
 * Ref: https://www.jiuzhang.com/problem/the-maze-ii/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        m = maze.size();

        if (m == 0)
            return 0;

        n = maze[0].size();

        visited.assign(m, vector<int>(n, INT_MAX));

        return bfs(maze, start, destination);
    }

private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visited;
    int m;
    int n;

    int bfs(vector<vector<int>> &maze, vector<int> &start, vector<int> &dest)
    {
        queue<pair<int, int>> Q;
        Q.emplace(start[0], start[1]);

        int L = 0;

        visited[start[0]][start[1]] = 0;

        while (!Q.empty())
        {
            auto pair = Q.front();
            Q.pop();
            int x = pair.first;
            int y = pair.second;
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                int L = 0;
                while (true)
                {
                    if (dx < 0 || dx == m || dy < 0 || dy == n || maze[dx][dy] == 1)
                    {
                        dx -= dir[i][0];
                        dy -= dir[i][1];
                        break;
                    }

                    dx += dir[i][0];
                    dy += dir[i][1];

                    L++;
                }

                if (visited[x][y] + L < visited[dx][dy])
                {
                    visited[dx][dy] = visited[x][y] + L;
                    Q.emplace(dx, dy);
                }
            }
            L++;
        }

        return visited[dest[0]][dest[1]] == INT_MAX ? -1 : visited[dest[0]][dest[1]];
    }
};