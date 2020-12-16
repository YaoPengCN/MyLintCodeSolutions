/** 
 * 12. Min Stack
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Implement a stack with following functions:
 * push(val) push val into the stack;
 * pop() pop the top element and return it;
 * min() return the smallest number in the stack.
 * All above should be in O(1) cost.
 * 
 * Clarification
 * min() will never be called when there is no number in the stack.
 * 
 * Example
 * Example 1
 * Input:
 *   push(1)
 *   pop()
 *   push(2)
 *   push(3)
 *   min()
 *   push(1)
 *   min()
 * Output:
 *   1
 *   2
 *   1
 * 
 * Example 2
 * Input:
 *   push(1)
 *   min()
 *   push(2)
 *   min()
 *   push(3)
 *   min()
 * Output:
 *   1
 *   1
 *   1
 *
 * Related Problems
 * 859. Max Stack
 * 636. 132 Pattern
 * 126. Max Tree
 * 40. Implement Queue by Two Stacks
 * */

/**  
 * Ref: https://www.jiuzhang.com/problem/min-stack/#tag-lang-cpp
 * Running Time: 415ms
 */

class MinStack
{
public:
    stack<int> st;
    stack<int> minSt;

    MinStack()
    {
        // do initialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number)
    {
        st.push(number);
        if (minSt.empty() || minSt.top() > st.top())
        {
            minSt.push(number);
        }
        else
        {
            minSt.push(minSt.top());
        }
    }

    /*
     * @return: An integer
     */
    int pop()
    {
        int resultPop = st.top();
        minSt.pop();
        st.pop();
        return resultPop;
    }

    /*
     * @return: An integer
     */
    int min()
    {
        return minSt.top();
    }
};