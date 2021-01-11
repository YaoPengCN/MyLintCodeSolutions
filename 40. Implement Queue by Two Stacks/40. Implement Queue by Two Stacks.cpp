/** 
 * 40. Implement Queue by Two Stacks
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * As the title described, you should only use two stacks to implement a queue's actions.
 * The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.
 * Both pop and top methods should return the value of first element.
 * 
 * Clarification
 * Suppose the queue is not empty when the pop() function is called.
 * 
 * Example
 * Example 1
 * Input:
 *     push(1)
 *     pop()
 *     push(2)
 *     push(3)
 *     top()
 *     pop()
 * Output:
 *     1
 *     2
 *     2
 * 
 * Example 2
 * Input:
 *     push(1)
 *     push(2)
 *     push(2)
 *     push(3)
 *     push(4)
 *     push(5)
 *     push(6)
 *     push(7)
 *     push(1)
 * Output:
 *     []
 *
 * Challenge
 * Implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.
 *
 * Related Problems 
 * 955. Implement Queue by Circular Array
 * 546. Implement Queue by Interface
 * 493. Implement Queue by Linked List II
 * 492. Implement Queue by Linked List
 * 12. Min Stack
 * */

/**
 * Challenge
 * Implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.
 * 
 * Ref: https://www.jiuzhang.com/problem/implement-queue-by-two-stacks/
 * 
 * Running Time:  386ms
 */

class MyQueue
{
public:
    MyQueue()
    {
        // do initialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element)
    {
        stack1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop()
    {
        if (stack2.empty())
        {
            move();
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

    /*
     * @return: An integer
     */
    int top()
    {
        if (stack2.empty())
        {
            move();
        }
        return stack2.top();
    }

    void move()
    {
        while (not stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};