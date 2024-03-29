/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode *odd = head, *even = head->next;
		ListNode *oe = even;	// for connection at last

		while (even && even->next) {
			// split odd elements
			odd->next = even->next;
			odd = odd->next;
			// split even elements
			even->next = odd->next;
			even = even->next;
		}
		odd->next = oe;

		return head;
	}
};
// @lc code=end
