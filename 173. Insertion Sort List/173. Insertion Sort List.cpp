/** 
 * 173. Insertion Sort List
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Sort a linked list using insertion sort.
 * 
 * Example
 * Example 1
 * Input: 0->null
 * Output: 0->null
 * 
 * Example 2:
 * Input:  1->3->2->0->null
 * Output :0->1->2->3->null
 * 
 * Related Problems
 * 599. Insert into a Cyclic Sorted List
 * 98. Sort List
 */

/**
 * Ref: https://www.jiuzhang.com/problem/insertion-sort-list/
 * Running Time: 163ms
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);

        while (head != nullptr)
        {
            ListNode *temp = dummy;
            ListNode *succ = head->next;

            while (temp->next != nullptr && (temp->next->val) < (head->val))
            {
                temp = temp->next;
            }

            head->next = temp->next;
            temp->next = head;
            head = succ;
        }

        return dummy->next;
    }
};