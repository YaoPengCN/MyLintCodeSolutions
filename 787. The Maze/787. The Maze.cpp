/** 
 * 787. The Maze
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * There is a ball in a maze with empty spaces and walls. 
 * The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
 * When the ball stops, it could choose the next direction.
 * Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
 * The maze is represented by a binary 2D array. 
 * 1 means the wall and 0 means the empty space. 
 * You may assume that the borders of the maze are all walls. 
 * The start and destination coordinates are represented by row and column indexes.
 * 
 * Clarification
 * 1.There is only one ball and one destination in the maze.
 * 2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
 * 3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
 * 5.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
 * 
 * Example
 * Example 1
 * Input:
 * map = 
 * [
 *  [0,0,1,0,0],
 *  [0,0,0,0,0],
 *  [0,0,0,1,0],
 *  [1,1,0,1,1],
 *  [0,0,0,0,0]
 * ]
 * start = [0,4]
 * end = [3,2]
 * Output:
 * false
 * 
 * Example 2:
 * Input:
 * map =
 * [
 *  [0,0,1,0,0],
 *  [0,0,0,0,0],
 *  [0,0,0,1,0],
 *  [1,1,0,1,1],
 *  [0,0,0,0,0]
 * ]
 * start = [0,4]
 * end = [4,4]
 * Output:
 * true
 *  
 * Related Problems
 * 1685. The mazeIV
 * 789. The Maze III
 * 788. The Maze II
 */

/**
 * BFS
 * Ref: https://www.jiuzhang.com/problem/the-maze/#tag-lang-cpp
 * Running Time: 151ms
 */

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        set<vector<int>> visited;
        return helper(maze, start, destination, visited);
    }
private:
    bool helper(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination, set<vector<int>> &visited)
    {
        if (start == destination)
        {
            return true;
        }
        if (visited.find(start) != visited.end())
        {
            return false;
        }
        visited.insert(start);
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i != dirs.size(); i++)
        {
            vector<int> res = toEnd(maze, start, dirs[i]);
            if (res == destination || helper(maze, res, destination, visited))
            {
                return true;
            }
        }
        return false;
    }
    vector<int> toEnd(vector<vector<int>> &maze, vector<int> &start, vector<int> &dir)
    {
        int i = start[0] + dir[0];
        int j = start[1] + dir[1];
        int m = maze.size();
        int n = maze[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 1)
        {
            return start;
        }
        vector<int> newStart = {i, j};
        return toEnd(maze, newStart, dir);
    }
};