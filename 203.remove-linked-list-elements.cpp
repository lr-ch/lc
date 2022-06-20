/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(INT_MAX, head);
		ListNode *current = &dummy, *next = current->next;

		while (next) {
			if (next->val == val)
				current->next = next->next;
			else
				current = next;

			next = next->next;
		}
		return dummy.next;
    }
};
// @lc code=end

