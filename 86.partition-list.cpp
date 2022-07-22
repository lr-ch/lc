/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
	ListNode* partition(ListNode* head, int x) {
		ListNode before, after, *pb = &before, *pa = &after;

		while (head) {
			if (head->val >= x) {
				pa->next = head;
				pa = pa->next;
			} else {
				pb->next = head;
				pb = pb->next;
			}
			head = head->next;
		}

		pa->next = nullptr;
		pb->next = after.next;
		return before.next;
	}
};
// @lc code=end

