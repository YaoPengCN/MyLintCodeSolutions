/** 
 * 492. Implement Queue by Linked List
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Implement a Queue by linked list. Support the following basic methods:
 * enqueue(item). Put a new item in the queue.
 * dequeue(). Move the first item out of the queue, return it.
 * 
 * 
 * Example
 * Example 1
 * Input:
 * enqueue(1)
 * enqueue(2)
 * enqueue(3)
 * dequeue() // return 1
 * enqueue(4)
 * dequeue() // return 2
 * 
 * Example 2
 * Input:
 * enqueue(10)
 * dequeue()// return 10
 *
 * Related Problems
 * 955. Implement Queue by Circular Array
 * 642. Moving Average from Data Stream
 * 546. Implement Queue by Interface
 * 493. Implement Queue by Linked List II
 * 40. Implement Queue by Two Stacks
 * */

/** 
 * Ref: https://www.jiuzhang.com/problem/implement-queue-by-linked-list/#tag-lang-ALL
 * Running Time: 365ms
 */

class Node
{
public:
    int val;
    Node *next;
    Node(int _val)
    {
        val = _val;
        next = NULL;
    }
};

class MyQueue
{
public:
    /*
     * @param item: An integer
     * @return: nothing
     */

    Node *first, *last;

    MyQueue()
    {
        first = last = NULL;
        // do initialization if necessary
    }

    void enqueue(int item)
    {
        if (!first)
        {
            last = new Node(item);
            first = last;
        }
        else
        {
            last->next = new Node(item);
            last = last->next;
        }
    }

    /*
     * @return: An integer
     */
    int dequeue()
    {
        int item = -1;
        if (first != NULL)
        {
            Node *toBeDeletedNode = first;
            item = toBeDeletedNode->val;
            if (last == first)
            {
                last = NULL;
            }
            first = first->next;
            delete toBeDeletedNode;
        }
        return item;
    }
};

