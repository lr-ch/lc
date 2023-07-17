/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
	 * ref. [206] Reverse Linked List
	 */
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode *last = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return last;
	}

public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		l1 = reverseList(l1);
		l2 = reverseList(l2);

		ListNode *ans = nullptr;
		int carry = 0;
		while (l1 || l2 || carry) {
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			ListNode *add = new ListNode((val1 + val2 + carry) % 10, ans);
			carry = (val1 + val2 + carry) / 10;
			ans = add;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		return ans;
	}
};
// @lc code=end
