/** 
* 8. Rotate String
* Difficulty
* Easy
* 
* Description
* Given a string (Given in the way of char array) and an offset, rotate the string by offset in place. (rotate from left to right).
* （offset >= 0
* the length of str >= 0
* Make changes on the original input data）
*
* Clarification
* in place means you should change string s in the function. You don't return anything.

* Example
* Example 1
* Input: str="abcdefg", offset = 3
* Output: str = "efgabcd"	
* Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "efgabcd".
* 
* Example 2:
* Input: str="abcdefg", offset = 0
* Output: str = "abcdefg"	
* Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "abcdefg".
* 
* Example 3:
* Input: str="abcdefg", offset = 1
* Output: str = "gabcdef"	
* Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "gabcdef".
* 
* Example 4:
* Input: str="abcdefg", offset =2
* Output: str = "fgabcde"	
* Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "fgabcde".
* 
* Example 5:
* Input: str="abcdefg", offset = 10
* Output: str = "efgabcd"	
* Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "efgabcd".

* Challenge
* Rotate in-place with O(1) extra memory.

* Related Problems 
* 1790. Rotate String II
* 1589. Groups of Special-Equivalent Strings
* 671. Rotate Words
* 216. Substring Rotation
* 170. Rotate List
* 161. Rotate Image
* 39. Recover Rotated Sorted Array
*/

/**
 * Challenge: Rotate in-place with O(1) extra memory.
 * Run Time: 134 ms
 */

class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        if (str.size() == 0 || str.size() == 1) {
            return;
        }
        offset %= str.size();
        str = str.substr(str.size() - offset, offset) + str.substr(0, str.size() - offset);
        return;
    }
};