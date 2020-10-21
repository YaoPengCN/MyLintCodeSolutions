/** 
* 35. Reverse Linked List
* Difficulty
* Easy
* 
* Description
* Reverse a linked list.
* 
* Example
* Example 1
* Input: 1->2->3->null
* Output: 3->2->1->null
* 
* Example 2
* Input: 1->2->3->4->null
* Output: 4->3->2->1->null
*
* Challenge
* Reverse it in-place and in one-pass
*
* Related Problems 
* 767. Reverse Array
* 649. Binary Tree Upside Down
* 450. Reverse Nodes in K-group
* 223. Palindrome Linked List
* 221. Add Two Numers II
* 53. Reverse Words in a String
* 36. Reverse Linked List II
*/

/**
 * Challenge: Reverse it in one-place and in one-pass
 * Running Time:  50ms
 */
/**
 * Definition of singly-linked-list:
 *
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
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = head;
        ListNode *cur = NULL;
        ListNode *next = NULL;
        
        if (prev == NULL)
        {
            return NULL;
        }
        for(cur = prev->next; cur != NULL; cur = next)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
        }
        head->next = NULL;
        return prev;
    }
};