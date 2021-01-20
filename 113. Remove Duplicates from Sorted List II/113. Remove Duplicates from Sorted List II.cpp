/** 
 * 113. Remove Duplicates from Sorted List II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * Example
 * Example 1
 * Input : 1->2->3->3->4->4->5->null
 * Output : 1->2->5->null
 * 
 * Example 2:
 * Input : 1->1->1->2->3->null
 * Output : 2->3->null
 *  
 * Related Problems
 * 452. Remove Linked List Elements
 * 217. Remove Duplicates from Unsorted List
 * 112. Remove Duplicates from Sorted List
 */

/**
 * Running Time: 320ms
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
     * @return: head of the linked list
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy;

        while (prev->next != NULL)
        {
            ListNode *cur = prev->next;
            ListNode *succ = cur->next;

            if (succ != NULL && succ->val == cur->val)
            {
                do
                {
                    succ = succ->next;
                } while (succ != NULL && succ->val == cur->val);
                prev->next = succ;
            }
            else
            {
                if (prev->next != NULL)
                {
                    prev = prev->next;
                }
            }
        }

        return dummy->next;
    }
};