/** 
* 13. Implement strStr()
* Difficulty
* Easy
* 
* Description
* For a given source string and a target string, you should output the first index(from 0) of target string in source string.
* If target does not exist in source, just return -1.
*
* Clarification
* Do I need to implement KMP Algorithm in a real interview?
* · Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure you confirm with the interviewer first.
* 
* Example
* Example 1
* Input: source = "source" ，target = "target"
* Output: -1	
* Explanation: If the source does not contain the target content, return - 1.
* 
* Example 2
* Input:source = "abcdabcdefg" ，target = "bcd"
* Output: 1	
* Explanation: If the source contains the target content, return the location where the target first appeared in the source.
* 
* Challenge
* O(n^2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

* Related Problems 
* 594. strStr II
*/

/**
 * Challenge: O(n^2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)
 * Running Time: 260ms
 */
class Solution
{
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target)
    {
        // Knuth-Morris-Pratt (KMP) algorithm
        // Reference [1]: "Algorithm (4th Edition)"
        // Reference [2] (Chinese): https://zhuanlan.zhihu.com/p/83334559
        int i, j, source_size = source.size(), target_size = target.size();

        if (target.empty())
        {
            return 0;
        }
        else if (source.empty())
        {
            return -1;
        }

        if (source_size < target_size)
        {
            return -1;
        }

        if (source == target)
        {
            return 0;
        }

        //define dfa in the KMP algorithm
        int R = 256; // 8bits, 256 characters of the extended ASCII
        vector< vector<int> > dfa(R);
        for (int i = 0; i < R; i++)
        {
            dfa[i].resize(target_size);
            for (int j = 0; j < target_size; j++)
            {
                dfa[i][j] = 0;
            }
        }
        dfa[target[0]][0] = 1;
        for (int X = 0, j = 1; j < target_size; j++)
        {
            for (int c = 0; c < R; c++)
            {
                dfa[c][j] = dfa[c][X];
            }
            dfa[target[j]][j] = j + 1;
            X = dfa[target[j]][X];
        }

        //search the target in the source by the KMP algorithm
        for (i = 0, j = 0; (i < source_size) && (j < target_size); i++)
        {
            j = dfa[source[i]][j];
        }
        if (j == target_size)
        {
            return i - target_size;
        }
        else
        {
            return -1;
        }
    }
};

// /**
//  * Running Time: 500ms
//  */
// class Solution {
// public:
//     /**
//      * @param source:
//      * @param target:
//      * @return: return the index
//      */
//     int strStr(string &source, string &target) {
//         if (target.empty()) {
//             return 0;
//         }
//         else if (source.empty()) {
//             return -1;
//         }

//         int source_size = source.size();
//         int target_size = target.size();

//         if (source_size < target_size) {
//             return -1;
//         }

//         for (int i = 0; i < source_size - target_size + 1; i++) {
//             if (source.substr(i,target_size) == target) {
//                     return i;
//                 }
//         }
//         return -1;
//     }
// };