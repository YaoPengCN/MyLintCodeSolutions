/** 
 * 802. Sudoku Solver
 * Difficulty
 * Hard
 * 
 * Description
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the number 0.
 * You may assume that there will be only one unique solution.
 *
 * Example
 * Given a Sudoku puzzle:
 * [
 * [0,0,9,7,4,8,0,0,0],
 * [7,0,0,0,0,0,0,0,0],
 * [0,2,0,1,0,9,0,0,0],
 * [0,0,7,0,0,0,2,4,0],
 * [0,6,4,0,1,0,5,9,0],
 * [0,9,8,0,0,0,3,0,0],
 * [0,0,0,8,0,3,0,2,0],
 * [0,0,0,0,0,0,0,0,6],
 * [0,0,0,2,7,5,9,0,0]
 * ]
 * 
 * Return its solution:
 * [
 * [5,1,9,7,4,8,6,3,2],
 * [7,8,3,6,5,2,4,1,9],
 * [4,2,6,1,3,9,8,7,5],
 * [3,5,7,9,8,6,2,4,1],
 * [2,6,4,3,1,7,5,9,8],
 * [1,9,8,5,2,4,3,6,7],
 * [9,7,5,8,6,3,1,2,4],
 * [8,3,2,4,9,1,7,5,6],
 * [6,4,1,2,7,5,9,8,3]
 * ]
 * 
 * Related Problems 
 * 635. Boggle Game
 * 33. N-Queens
 */

/**
 * Ref[1]:https://www.cnblogs.com/yuzhangcmu/p/4067733.html
 * Ref[2]: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/sudoku
 * Ref[3]: https://www.jiuzhang.com/problem/sudoku-solver/#tag-lang-cpp
 * Running Time: 270ms
 */
class Solution
{
public:
    /**
     * @param board: the sudoku puzzle
     * @return: nothing
     */
    void solveSudoku(vector<vector<int>> &board)
    {
        int startRow = 0, startCol = 0;
        backtrack(board, board.size(), startRow, startCol);
    }

private:
    bool backtrack(vector<vector<int>> &board, int n, int row, int col)
    {
        // after traversing all the columns, return to the first column
        if (col == n)
            return backtrack(board, board.size(), row + 1, 0);
        // after traversing all the row and columns, return true
        if (row == n)
            return true;
        // if any number has already existed
        if (board[row][col] != 0)
            return backtrack(board, board.size(), row, col + 1);

        // traverse all the possibilities
        for (int num = 1; num <= 9; num++)
        {
            if (!isValid(board, row, col, num))
                continue;

            // choose num
            board[row][col] = num;
            if (backtrack(board, board.size(), row, col + 1))
                return true;

            // undo choosing num
            board[row][col] = 0;
        }

        return false;
    }

    bool isValid(vector<vector<int>> &board, int row, int col, int val)
    {
        for (int i = 0; i != 9; i++)
        {
            // if any duplication exists in the row
            if (board[row][i] == val)
            {
                return false;
            }

            // if any duplication exists in the column
            if (board[i][col] == val)
            {
                return false;
            }

            // if any duplication exists in the block
            if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }
};