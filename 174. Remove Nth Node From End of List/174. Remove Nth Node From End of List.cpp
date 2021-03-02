/** 
 * 174. Remove Nth Node From End of List
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * Clarification
 * The minimum number of nodes in list is n.
 * 
 * Example
 * Example 1
 * Input: list = 1->2->3->4->5->null, n = 2
 * Output: 1->2->3->5->null
 * 
 * Example 2:
 * Input:  list = 5->4->3->2->1->null, n = 2
 * Output: 5->4->3->1->null
 * 
 * Challenge
 * Can you do it without getting the length of the linked list?
 * 
 * Related Problems
 * 372. Delete Node in a Linked List
 * 228. Middle of Linked List
 */

/**
 * Challenge
 * Can you do it without getting the length of the linked list?
 * 
 * Double pointers
 * 
 * Running Time: 61ms
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
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *tmp = dummy;

        for (int i = 0; i != n; i++)
        {
            head = head->next;
        }

        while (head != NULL)
        {
            head = head->next;
            tmp = tmp->next;
        }

        tmp->next = tmp->next->next;
        return dummy->next;
    }
};