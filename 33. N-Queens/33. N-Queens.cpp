/** 
* 33. N-Queens
* Difficulty
* Medium
* 
* Description
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
* (Any two queens can't be in the same row, column, diagonal line).
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' each indicate a queen and an empty space respectively.
*
* Example
* Example 1
* Input: 1
* Output:
* [["Q"]]
* 
* Example 2
* Input: 4
* Output:
* [
*   // Solution 1
*   [".Q..",
*    "...Q",
*    "Q...",
*    "..Q."
*   ],
*   // Solution 2
*   ["..Q.",
*    "Q...",
*    "...Q",
*    ".Q.."
*   ]
* ]
*
* 
* Challenge
* Do it without recursion.
* 
* Related Problems 
* 802. Sudoku Solver
* 778. Pacific Atlantic Water Flow
* 152. Combinations
* 34. N-Queens II
*/

/**
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban
 * Ref[2]: https://www.jiuzhang.com/problem/n-queens/
 * Ref[3]: https://blog.csdn.net/wusecaiyun/article/details/47111529
 * Run Time:  355ms
 */

class Solution
{
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;

        vector<int> state(n, -1); //注意vector的这种初始化方法
        for (int row = 0, col;;)
        {
            for (col = state[row] + 1; col < n; col++) //从上一次放置的位置后面开始放置
            {
                if (isValid(state, row, col))
                {
                    state[row] = col;
                    if (row == n - 1) //找到了一个解,继续试探下一列
                    {
                        vector<string> tmpres(n, string(n, '.')); // 注意vector的这种初始化方法，可以嵌套着进行。
                        for (int i = 0; i < n; i++)
                            tmpres[i][state[i]] = 'Q';
                        res.push_back(tmpres);
                    }
                    else
                    {
                        row++;
                        break;
                    } //当前状态合法，去放置下一行的皇后
                }
            }
            if (col == n) //当前行的所有位置都尝试过，回溯到上一行
            {
                if (row == 0)
                    break;       //所有状态尝试完毕，退出
                state[row] = -1; //回溯前清除当前行的状态
                row--;
            }
        }
        return res;
    }

    //判断在row行col列位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(vector<int> &state, int row, int col)
    {
        for (int i = 0; i < row; i++)                                   //只需要判断row前面的行，因为后面的行还没有放置
            if (state[i] == col || abs(row - i) == abs(col - state[i])) //注意abs函数可以直接使用
                return false;
        return true;
    }
};

// /**
//  * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban
//  * Ref[2]: https://www.jiuzhang.com/problem/n-queens/
//  * Run Time:  288ms
//  */

// class Solution
// {
// public:
//     /*
//      * @param n: The number of queens
//      * @return: All distinct solutions
//      */
//     vector<vector<string>> solveNQueens(int n)
//     {
//         //result用于存储答案
//         //col用于存储每个皇后所在的列
//         vector<vector<string>> result;
//         vector<int> col;
//         search(n, col, result);
//         return result;
//     }

// private:
//     //search函数为搜索函数，n表示已经放置了n个皇后，col表示每个皇后所在的列
//     void search(int n, vector<int> &col, vector<vector<string>> &result)
//     {
//         //若已经放置了n个皇后表示出现了一种解法，绘制后加入答案result
//         if (col.size() == n)
//         {
//             result.push_back(Draw(col, n));
//             return;
//         }
//         //枚举当前皇后放置的列，若不合法则跳过
//         for (int now_col = 0; now_col < n; now_col++)
//         {
//             if (!isValid(col, now_col))
//             {
//                 continue;
//             }
//             //若合法则递归枚举下一行的皇后
//             col.push_back(now_col);
//             search(n, col, result);
//             col.pop_back();
//         }
//     }

//     //isValid函数为合法性判断函数
//     bool isValid(vector<int> &col, int now_col)
//     {
//         int row = col.size();
//         for (int i = 0; i < row; i++)
//         {
//             //若有其他皇后在同一列或同一斜线上则不合法
//             if (col[i] == now_col)
//             {
//                 return false;
//             }
//             if (abs(i - row) == abs(col[i] - now_col))
//             {
//                 return false;
//             }
//         }
//         return true;
//     }

//     //Draw函数为将col数组转换为答案的绘制函数
//     vector<string> Draw(vector<int> &col, int n)
//     {
//         vector<string> result;
//         for (int i = 0; i < n; i++)
//         {
//             string temp(n, '.');
//             temp[col[i]] = 'Q';
//             result.push_back(temp);
//         }
//         return result;
//     }
// };