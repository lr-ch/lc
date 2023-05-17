/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode* last = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return last;
	}

public:
	int pairSum(ListNode* head) {
		ListNode *fast = head, *slow = head;
		while (fast && fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode *reversedHead = reverseList(slow);

		int ans = 0;
		while (head && reversedHead) {
			ans = max(ans, head->val + reversedHead->val);
			head = head->next;
			reversedHead = reversedHead->next;
		}

		return ans;
	}
};
// @lc code=end
