/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
	int count(ListNode* h) {
		int num = 1;
		while (h) {
			h = h->next;
			num++;
		}
		return num;
	}

public:
	ListNode* swapNodes(ListNode* head, int k) {
		int k2 = count(head) - k;
		ListNode *swap1, *swap2, *h = head;

		while (h) {
			if (--k == 0) swap1 = h;
			if (--k2 == 0) swap2 = h;

			h = h->next;
		}
		swap(swap1->val, swap2->val);

		return head;
	}
};
// @lc code=end
