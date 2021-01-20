/** 
 * 112. Remove Duplicates from Sorted List
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * Example
 * Example 1
 * Input:  null
 * Output: null
 * 
 * Example 2:
 * Input:  1->1->2->null
 * Output: 1->2->null
 * 
 * Example 3:
 * Input:  1->1->2->3->3->null
 * Output: 1->2->3->null
 *  
 * Related Problems
 * 452. Remove Linked List Elements
 * 217. Remove Duplicates from Unsorted List
 * 113. Remove Duplicates from Sorted List II
 */

/**
 * Running Time: 101ms
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
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *cur = head;
        while (cur->next != NULL)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};