/** 
 * 166. Nth to Last Node in List
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Find the nth to last element of a singly linked list.
 * The minimum number of nodes in list is n.
 * 
 * Example
 * Example 1
 * Input: list = 3->2->1->5->null, n = 2	
 * Output: 1
 * 
 * Example 2:
 * Input: list  = 1->2->3->null, n = 3
 * Output: 1
 * 
 * Related Problems
 * 380. Intersection of Two Linked Lists
 * 6. Merge Two Sorted Arrays
 */

/**
 * Double pointers
 * Running Time: 569ms
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution
{
public:
    /*
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (n)
        {
            fast = fast->next;
            n--;
        }

        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};