/** 
 * 157. Unique Characters
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Implement an algorithm to determine if a string has all unique characters.
 * 
 * Example
 * Example 1
 * Input: "abc_____"
 * Output: false
 * 
 * Example 2:
 * Input:  "abc"
 * Output: true		
 * 
 * Challenge
 * What if you can not use additional data structures?
 * 
 * Related Problems
 * 209. First Unique Character in a String
 */

/**
 * Challenge
 * What if you can not use additional data structures?
 * 
 * Running Time: 324ms
 */

class Solution
{
public:
    /*
     * @param str: A string
     * @return: a boolean
     */
    bool isUnique(string &str)
    {
        vector<int> ch(128,0);
        for (int i = 0; i != str.length(); i++)
            if (ch[str[i]] != 0)
                return false;
            else
                ch[str[i]] = 1;
        return true;
    }
};

// /**
//  * Challenge
//  * What if you can not use additional data structures?
//  *
//  * Running Time: 407ms
//  */

// class Solution
// {
// public:
//     /*
//      * @param str: A string
//      * @return: a boolean
//      */
//     bool isUnique(string &str)
//     {
//         sort(str.begin(), str.end());

//         for (int i = 1; i != str.size(); i++)
//         {
//             if (str[i] == str[i - 1])
//                 return false;
//         }

//         return true;
//     }
// };