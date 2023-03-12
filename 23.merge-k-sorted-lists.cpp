/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
	 * Shamelessly copied from
	 *  [21] Merge Two Sorted Lists
	 */
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode dummy, *current = &dummy;
		current->next = nullptr;

		while (list1 && list2) {
			if (list1->val < list2->val) {
				current->next = list1;
				list1 = list1->next;
			} else {
				current->next = list2;
				list2 = list2->next;
			}
			current = current->next;
		}

		if (list1)
			current->next = list1;

		if (list2)
			current->next = list2;

		return dummy.next;
	}

	ListNode* helper(vector<ListNode*>& lists, int begin, int end) {
		if (begin == end) return lists[begin];

		int mid = (begin + end) / 2;
		ListNode *left = helper(lists, begin, mid);
		ListNode *right = helper(lists, mid + 1, end);
		return mergeTwoLists(left, right);
	}

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		return helper(lists, 0, lists.size() - 1);
	}
};
// @lc code=end
