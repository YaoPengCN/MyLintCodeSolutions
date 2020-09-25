/** 
* 28. Search a 2D Matrix
* Difficulty
* Easy
* 
* Description
* Write an efficient algorithm that searches for a value in an m x n matrix.
* This matrix has the following properties:
* · Integers in each row are sorted from left to right.
* · The first integer of each row is greater than the last integer of the previous row.
*
* Example
* Example 1
* Input: [[5]],2
* Output: false
* Explanation: 	false if not included.
*
* Example 2
* Input: [
*     [1, 3, 5, 7],
*     [10, 11, 16, 20],
*     [23, 30, 34, 50]
* ],3
* Output: true
* Explanation: 	return true if included.
*
* Challenge
* O(log(n) + log(m)) time
*
* Related Problems 
* 832. Count Negative Number
* 62. Search in Rotated Sorted Array
* 38. Search a 2D Matrix II
*/

/**
 * Challenge: O(log(n) + log(m)) time
 * Run Time: 50ms
 */
class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty())
            return false;

        vector<int>::size_type col = matrix[0].size();
        vector<int>::size_type left = 0;
        vector<int>::size_type right = matrix.size() * matrix[0].size() - 1;
        
        while(left < right){
            vector<int>::size_type mid = left + (right - left) / 2;
            if(matrix[mid/col][mid%col] == target){
                return true;
            }
            else if(matrix[mid/col][mid%col] > target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        if(matrix[right/col][right%col] == target){
            return true;
        }   
        return false;
    }
};