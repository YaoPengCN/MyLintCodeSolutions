/** 
 * 63. Search in Rotated Sorted Array II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Follow up for Search in Problem 62. Rotated Sorted Array:
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 * 
 * Example
 * Example 1
 * Input:
 * []
 * 1
 * Output:
 * false
 * 
 * Example 2
 * [3,4,4,5,7,0,1,2]
 * 4
 * Output:
 * true
 * 
 * Related Problems
 * 160. Find Minimum in Rotated Sorted Array II
 * 159. Find Minimum in Rotated Sorted Array
 * 62. Search in Rotated Sorted Array
 * 28. Search a 2D Matrix
 * */

/**
 * Ref: https://www.jiuzhang.com/problem/search-in-rotated-sorted-array-ii/
 * 
 * Running Time: 101ms
 */

class Solution {
public:
    /**
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> &A, int target) {
        if (A.empty())
            return false;
        
        // step1: find pivot
        int left = 0, right = A.size() - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (A[mid] > A[right]){
                left = mid + 1;
            }
            else if(A[mid] < A[right]){
                right = mid;
            }
            else{
                if (right > 0 && A[right - 1] > A[right]){
                    left = right;
                }
                else{
                    right--;
                }
            }
        }
        int pivot = left;

        // step2: split
        if (pivot == 0){
            left = 0;
            right = A.size() - 1;
        }
        else if (target >= A[0]){
            left = 0;
            right = pivot - 1;
        }
        else{
            left = pivot;
            right = A.size() - 1;
        }
        
        // step3: find target
        while (left + 1 < right) { 
            int mid = left + (right - left) / 2; 
            if (A[mid] < target) { 
                left = mid; 
            } else { 
                right = mid; 
            } 
        }          
            
        if (A[left] == target) { 
            return true; 
        } 
        if (A[right] == target) { 
            return true;
        }         
        return false; 
    }
};