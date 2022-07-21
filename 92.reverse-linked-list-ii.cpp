/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
	ListNode* Successor = nullptr;
	ListNode* reverseN(ListNode *root, int n) {
		if (n == 1) {
			Successor = root->next;
			return root;
		}

		ListNode *last = reverseN(root->next, n - 1);
		root->next->next = root;
		root->next = Successor;
		return last;
	}

public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left == 1)
			return reverseN(head, right);

		head->next = reverseBetween(head->next, left - 1, right - 1);
		return head;
	}
};
// @lc code=end

