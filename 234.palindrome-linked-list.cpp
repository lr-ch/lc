/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
	void reverse(ListNode *root, ListNode *sentry) {
		if (!root || root == sentry) return;
		reverse(root->next, sentry);
		root->next->next = root;
		root->next = nullptr;
	}

	bool compare(ListNode *head1, ListNode *head2) {
		while (head1 && head2) {
			if (head1->val != head2->val) return false;
			head1 = head1->next;
			head2 = head2->next;
		}
		return true;
	}

public:
	bool isPalindrome(ListNode* head) {
		ListNode *slow = head, *fast = head, middle;

		// find the middle node
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// deal with odd/even number of nodes
		if (fast->next != nullptr) middle = *(slow->next);
		else middle = *slow;

		// reverse list[head, slow]
		reverse(head, slow);

		return compare(slow, &middle);
	}
};
// @lc code=end
