/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	unordered_set<ListNode *> seen;
public:
	ListNode *detectCycle(ListNode *head) {
		while (head) {
			if (seen.find(head) != seen.end())
				return head;

			seen.insert(head);
			head = head->next;
		}
		return nullptr;
	}
};
// @lc code=end
