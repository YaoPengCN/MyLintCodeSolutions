/** 
* 22. Flatten List
* Difficulty
* Easy
* 
* Description
* Given a list, each element in the list can be a list or integer. 
* Flatten it into a simply list with integers.
* 
* Example
* Example 1
* Input:  [[1,1],2,[1,1]]
* Output: [1,1,2,1,1]
* Explanation: flatten it into a simply list with integers.
* 
* Example 2
* Input: [1,2,1,2]
* Output: 2
* Explanation: flatten it into a simply list with integers.
* 
* Example 3
* Input: [4,[3,[2,[1]]]]
* Output: Output:[4,3,2,1]
* Explanation: flatten it into a simply list with integers.
*
* Challenge
* Do it in non-recursive.

* Related Problems 
* 604. Flattern 2D vector.
*/

/**
 * Challenge: Do it in non-recursive.
 * Run Time: 727 ms
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList)
    {
        vector<int> result;

        if (nestedList.empty())
            return result;

        stack<vector<NestedInteger>::const_reverse_iterator> st;

        for (auto it = nestedList.rbegin(); it != nestedList.rend(); it++)
        {
            st.push(it);
        }

        while (!st.empty())
        {
            auto item = st.top();
            st.pop();
            if (item->isInteger())
            {
                result.push_back(item->getInteger());
            }
            else
            {
                const auto &lst = item->getList();
                for (auto it = lst.rbegin(); it != lst.rend(); it++)
                {
                    st.push(it);
                }
            }
        }

        return result;
    }
};

// /**
//  * Run Time: 785 ms
//  */
// /**
//  * // This is the interface that allows for creating nested lists.
//  * // You should not implement it, or speculate about its implementation
//  * class NestedInteger {
//  *   public:
//  *     // Return true if this NestedInteger holds a single integer,
//  *     // rather than a nested list.
//  *     bool isInteger() const;
//  *
//  *     // Return the single integer that this NestedInteger holds,
//  *     // if it holds a single integer
//  *     // The result is undefined if this NestedInteger holds a nested list
//  *     int getInteger() const;
//  *
//  *     // Return the nested list that this NestedInteger holds,
//  *     // if it holds a nested list
//  *     // The result is undefined if this NestedInteger holds a single integer
//  *     const vector<NestedInteger> &getList() const;
//  * };
//  */
// class Solution
// {
// public:
//     // @param nestedList a list of NestedInteger
//     // @return a list of integer
//     vector<int> flatten(vector<NestedInteger> &nestedList)
//     {
//         vector<int> result;

//         if (nestedList.empty())
//             return result;

//         vector<NestedInteger>::size_type i, end;

//         for (i = 0, end = nestedList.size() - 1; i <= end; i++)
//         {
//             if (nestedList[i].isInteger())
//                 result.push_back(nestedList[i].getInteger());
//             else
//             {
//                 vector<NestedInteger> subList = nestedList[i].getList();
//                 vector<int> temp = flatten(subList);
//                 result.insert(result.end(), temp.begin(), temp.end());
//             }
//         }

//         return result;
//     }
// };