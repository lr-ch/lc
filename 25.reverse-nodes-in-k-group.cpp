/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
	ListNode* reverseSegment(ListNode* start, ListNode* end) {
		if (!start || start->next == end) return start;

		ListNode* node = reverseSegment(start->next, end);
		start->next->next = start;
		start->next = nullptr;
		return node;
	}
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head) return nullptr;

		ListNode *fast = head, *slow = head;
		for (int i = 0; i < k; i ++) {
			if (!fast) return head;
			fast = fast->next;
		}

		ListNode *newhead = reverseSegment(slow, fast);
		slow->next = reverseKGroup(fast, k);

		return newhead;
	}
};
// @lc code=end

