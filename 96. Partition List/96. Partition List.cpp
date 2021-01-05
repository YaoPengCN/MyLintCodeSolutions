/** 
 * 96. Partition List
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Example
 * Input:  
 * list = null, x = 0
 * Output: 
 * null
 * Explanation: 
 * The empty list Satisfy the conditions by itself.
 * 
 * Example 2:
 * Input:  
 * list = 1->4->3->2->5->2->null, x = 3
 * Output: 
 * 1->2->2->4->3->5->null
 * Explanation:  
 * keep the original relative order of the nodes in each of the two partitions.
 * 
 * Related Problems
 * 1292. Odd Even Linked List
 * 31. Partition Array
 */

/** 
 * Ref: https://www.jiuzhang.com/problem/partition-list/#tag-lang-cpp
 * Running Time: 50ms
 */

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);
        ListNode *leftTail = leftDummy;
        ListNode *rightTail = rightDummy;

        while (head != NULL)
        {
            if (head->val < x)
            {
                leftTail->next = head;
                leftTail = head;
            }
            else
            {
                rightTail->next = head;
                rightTail = head;
            }
            head = head->next;
        }

        leftTail->next = rightDummy->next;
        rightTail->next = NULL;

        return leftDummy->next;
    }
};