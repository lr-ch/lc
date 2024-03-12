/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
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
	ListNode* removeZeroSumSublists(ListNode* head) {
		ListNode root(0, head), *left = &root;

		while (left) {
			ListNode *right = left->next;
			int preSum = 0;
			while (right) {
				preSum += right->val;
				if (!preSum)
					left->next = right->next;

				right = right->next;
			}
			left = left->next;
		}
		return root.next;
	}
};
// @lc code=end
