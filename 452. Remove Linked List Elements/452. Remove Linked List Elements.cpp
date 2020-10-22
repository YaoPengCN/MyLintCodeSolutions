/** 
 * 452. Remove Linked List Elements
 * Difficulty
 * Easy
 * 
 * Description
 * Remove all elements from a linked list of integers that have value val.
 *  
 * Clarification
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * Example
 * Example 1:
 * Input: head = 1->2->3->3->4->5->3->null, val = 3
 * Output: 1->2->4->5->null
 * 
 * Example 2:
 * Input: head = 1->1->null, val = 1
 * Output: null
 * 
 * Related Problems 
 * 113. Remove Duplicates from Sorted List II
 * 112. Remove Duplicates from Sorted List
 * */

/**
 * Two pointers
 * Ref[1]: https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ
 * Ref[2]: https://www.jiuzhang.com/problem/remove-linked-list-elements/#tag-lang-cpp
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
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummy;
        dummy.next = head;
        head = &dummy;

        while (head->next != NULL)
        {
            if (head->next->val == val)
            {
                head->next = head->next->next;
            }
            else
            {
                head = head->next;
            }
        }

        return dummy.next;
    }
};