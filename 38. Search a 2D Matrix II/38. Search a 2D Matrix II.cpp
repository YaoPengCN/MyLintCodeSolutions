/** 
 * 38. Search a 2D Matrix II
 *  
 * Difficulty
 * Medium
 * 
 * Description
 * Write an efficient algorithm that searches for a value in an m x n matrix, and returns the occurrence of it.
 * This matrix has the following properties:
 * · Integers in each row are sorted from left to right.
 * · Integers in each column are sorted from up to bottom.
 * · No duplicate integers in each row or column.
 * 
 * Example
 * Example 1 
 * Input:
 *     [[3,4]]
 *     target = 3
 * Output:
 *     1
 * 
 * Example 2
 * Input:
 *     [
 *       [1, 3, 5, 7],
 *       [2, 4, 7, 8],
 *       [3, 5, 9, 10]
 *     ]
 *     target = 3
 * Output:
 *     2
 *
 * Challenge
 * O(m+n) time and O(1) extra space
 *
 * Related Problems
 * 832. Count Negative Number 
 * 465. K-th Smallest Sum in Two Sorted Arrays
 * 28. Search a 2D Matrix
 * */

/**
 * Challenge
 * O(m+n) time and O(1) extra space
 * 
 * Start from the bottom left corner of the matrix to the upper right corner.
 * 
 * Ref: https://www.jiuzhang.com/problem/search-a-2d-matrix-ii/
 * 
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int res = 0;
        int m = matrix.size(), n = matrix[0].size();

        // start from the bottom left corner of the matrix
        int x = m - 1, y = 0;
        while (x >= 0 && y < n)
        {
            if (matrix[x][y] == target)
            {
                res++;
                x--;
                y++;
            }
            else if (matrix[x][y] > target)
            {
                x--;
            }
            else
            {
                y++;
            }
        }
        return res;
    }
};