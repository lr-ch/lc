/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return 0;

		ListNode *i = head, *j = i->next;
		while (j) {
			if (i->val != j->val) {
				i = i->next;
				i->val = j->val;
			}
			j = j->next;
		}
		i->next = nullptr;
		return head;
	}
};
// @lc code=end

