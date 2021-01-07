/** 
 * 36. Reverse Linked List II
 *  
 * Difficulty
 * Medium
 * 
 * Description
 * Reverse a linked list from position m to n.
 * 
 * Clarification
 * Given m, n satisfy the following condition: 1 <= m <= n <= length of list.
 * 
 * Example
 * Example 1 
 * Input: 1->2->3->4->5->NULL, m = 2 and n = 4.
 * Output: 1->4->3->2->5->NULL.
 * 
 * Example 2
 * Input: 1->2->3->4->NULL, m = 2 and n = 3.
 * Output: 1->3->2->4->NULL.
 *
 * Challenge
 * Reverse it in-place and in one-pass
 *
 * Related Problems 
 * 450. Reverse Nodes in k-Group
 * 53. Reverse Words in a String
 * 35. Reverse Linked List
 * */

/**
 * Challenge
 * Reverse it in-place and in one-pass.
 * 
 * Ref: https://www.jiuzhang.com/problem/reverse-linked-list-ii/
 * 
 * Running Time:  353ms
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
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre, *front, *last;
        ListNode *cur = dummy;
        for (int i = 0; i < m - 1; i++)
        {
            cur = cur->next;
        }
        pre = cur;
        last = cur->next;
        for (int i = m; i <= n; i++)
        {
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return dummy->next;
    }
};