/** 
 * 165. Merge Two Sorted Lists
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Merge two sorted (ascending) linked lists and return it as a new sorted list. 
 * The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.
 * 
 * Example
 * Example 1
 * Input: list1 = null, list2 = 0->3->3->null
 * Output: 0->3->3->null
 * 
 * Example 2:
 * Input: list1 = 1->3->8->11->15->null, list2 = 2->null
 * Output: 1->2->3->8->11->15->null	
 * 
 * Related Problems
 * 839. Merge Two Sorted Interval Lists
 * 6. Merge Two Sorted Arrays
 */

/** 
 * Ref: https://www.jiuzhang.com/problem/merge-two-sorted-lists/
 * Running Time: 81ms
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
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return l1;

        ListNode *head = nullptr, **cur = &head;

        while (l1 && l2)
        {
            auto next = (l1->val) > (l2->val) ? &l2 : &l1;
            *cur = *next;
            cur = &(*cur)->next;
            *next = *cur;
        }
        *cur = l1 ? l1 : l2;

        return head;
    }
};