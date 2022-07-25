/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode empty, *root, *last = &empty;
		empty.next = head;

		int count = 0;
		while (last->next != nullptr) {
			count++;
			last = last->next;
		}

		if (empty.next) {
			k = k % count;
			count = count - k;

			for (root = &empty; count > 0; count--)
				root = root->next;

			last->next = empty.next;		// link up
			empty.next = root->next;		// new head
			root->next = nullptr;			// cut off
		}

		return empty.next;
	}
};
// @lc code=end

