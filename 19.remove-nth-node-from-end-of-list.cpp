/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	/*
	 * Accepted
	 *  * 208/208 cases passed (9 ms)
	 *	* Your runtime beats 35.74 % of cpp submissions
	 *	* Your memory usage beats 74.43 % of cpp submissions (10.6 MB)
	 */
/*
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy, *tmp = head;
		dummy.next = head;

		// look for the total length
		int length = 0;
		while (tmp != nullptr) {
			tmp = tmp->next;
			length++;
		}

		tmp = &dummy;
		for (int i = 0; i < length - n; i++)
			tmp = tmp->next;
		tmp->next = tmp->next->next;

		return dummy.next;
	}
*/
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy, *fast = &dummy, *slow = &dummy;
		dummy.next = head;

		for (int i = 0; i < n; i++)
			fast = fast->next;

		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;

		return dummy.next;
	}
};
// @lc code=end

