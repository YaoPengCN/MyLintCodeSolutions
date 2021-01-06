/** 
 * 34. N-Queens II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * (Any two queens can't be in the same row, column, diagonal line).
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' each indicate a queen and an empty space respectively.
 * Follow up for 33. N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 * Example
 * Example 1
 * Input: n=1
 * Output: 1
 * Explanation:
 * 1:
 * 1
 * 
 * Example 2
 * Input: n=4 
 * Output: 2
 * Explanation:
 * 1:
 * 0 0 1 0
 * 1 0 0 0
 * 0 0 0 1
 * 0 1 0 0
 * 2:
 * 0 1 0 0 
 * 0 0 0 1
 * 1 0 0 0
 * 0 0 1 0
 * 
 * Related Problems 
 * 802. Sudoku Solver
 * 778. Pacific Atlantic Water Flow
 * 152. Combinations
 * 33. N-Queens
 * */

/**
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban
 * Ref[2]: https://www.jiuzhang.com/problem/n-queens-ii/
 * Ref[3]: https://blog.csdn.net/wusecaiyun/article/details/47111529
 * Running Time:  50ms
 */

class Solution
{
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n)
    {
        vector<int> cols(n);

        sum = 0;
        dfs(n, 0, cols);
        return sum;
    }

private:
    int sum;

    bool canPut(int row, int col, vector<int> &cols)
    {
        for (int i = 0; i < row; i++)
        {
            if (cols[i] - i == col - row)
            {
                return false;
            }
            if (cols[i] + i == col + row)
            {
                return false;
            }
            if (cols[i] == col)
            {
                return false;
            }
        }
        return true;
    }

    void dfs(int n, int k, vector<int> &cols)
    {
        if (k == n)
        {
            sum++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!canPut(k, i, cols))
            {
                continue;
            }
            cols[k] = i;
            dfs(n, k + 1, cols);
        }
    }
};