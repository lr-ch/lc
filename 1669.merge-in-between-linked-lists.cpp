/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode root(0, list1), *curr = root.next, *cut = nullptr;
		for (int i = 0; i < b; i++) {
			if (i == a - 1)
				cut = curr;
			curr = curr->next;
		}

		for (cut->next = list2; cut->next; cut = cut->next);
		cut->next = curr->next;

		return root.next;
	}
};
// @lc code=end
