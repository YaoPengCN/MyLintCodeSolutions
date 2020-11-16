/** 
 * 104. Merge K Sorted Lists
 * Difficulty
 * Medium
 * 
 * Description
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 *
 * Example
 * Example 1
 * Input: [2->4->null,null,-1->null]
 * Output: -1->2->4->null
 * 
 * Example 2
 * Input: [2->6->null,5->null,7->null]
 * Output: 2->5->6->7->null
 * 
 * Related Problems 
 * 839. Merge Two Sorted Interval Lists
 * 791. Merge Number
 * 486. Merge K Sorted Arrays
 * 6. Merge Two Sorted Arrays
 * 4. Ugly Number II
 */

/**
 * Priority_queue
 * Ref[1]: https://www.jiuzhang.com/problem/merge-k-sorted-lists/#tag-lang-cpp
 * Ref[2]: https://blog.51cto.com/9250070/2506737
 * Running Time: 352ms
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
	/**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
        auto comp=[](ListNode* l,ListNode* r){return l->val>r->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)> Q(comp);
        ListNode *head=nullptr,**cur=&head;
        for(auto l:lists)
            if(l)
                Q.push(l);
        while(!Q.empty()){
            auto q=Q.top();
            Q.pop();
            *cur=q;
            cur=&q->next;
            if(*cur)
                Q.push(*cur);
        }
        return head;
	}
};

// /**
//  * Two pointers
//  * Ref: https://www.jiuzhang.com/problem/merge-k-sorted-lists/#tag-lang-cpp
//  * Running Time: 686ms
//  */
// /**
//  * Definition of ListNode
//  * class ListNode {
//  * public:
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int val) {
//  *         this->val = val;
//  *         this->next = NULL;
//  *     }
//  * }
//  */
// class Solution
// {
// public:
// 	/**
//      * @param lists: a list of ListNode
//      * @return: The head of one sorted list.
//      */
// 	ListNode *mergeKLists(vector<ListNode *> &lists)
// 	{
// 		// write your code here
// 		ListNode *tmp_node = NULL;
// 		ListNode *tar_node = NULL;
// 		ListNode *new_node = NULL;
// 		ListNode *result = NULL;
// 		for (int i = 0; i < lists.size(); ++i)
// 		{
// 			tmp_node = lists[i];
// 			if (NULL == tmp_node)
// 			{
// 				continue;
// 			}
// 			if (NULL == result)
// 			{
// 				result = new ListNode(tmp_node->val);
// 				tmp_node = tmp_node->next;
// 			}
// 			else
// 			{
// 				if (result->val > tmp_node->val)
// 				{
// 					new_node = new ListNode(tmp_node->val);
// 					new_node->next = result;
// 					result = new_node;
// 					tmp_node = tmp_node->next;
// 				}
// 			}
// 			tar_node = result;
// 			while (tmp_node != NULL)
// 			{
// 				while (NULL != tar_node->next && tar_node->next->val < tmp_node->val)
// 				{
// 					tar_node = tar_node->next;
// 				}
// 				if (NULL == tar_node->next)
// 				{
// 					new_node = new ListNode(tmp_node->val);
// 					tar_node->next = new_node;
// 				}
// 				else
// 				{
// 					new_node = new ListNode(tmp_node->val);
// 					new_node->next = tar_node->next;
// 					tar_node->next = new_node;
// 				}
// 				tmp_node = tmp_node->next;
// 			}
// 		}
// 		return result;
// 	}
// };