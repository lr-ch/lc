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
	void merge(vector<int>& v, ListNode* lists) {
		for (ListNode *it = lists; it; it = it->next)
			v.push_back(it->val);
	}

	ListNode* trans(vector<int>& v) {
		ListNode *dummy = new ListNode(INT_MIN);
		ListNode *p = dummy;

		if (v.size() == 0) {
			return nullptr;
		}

		for (int i : v) {
			ListNode *t = new ListNode(i);
			p->next = t;
			p = p->next;
		}
		return dummy->next;
	}

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int> merged;

		// merge all val into one vector
		for (int i = 0; i < lists.size(); i++)
			merge(merged, lists[i]);

		// sort
		sort(merged.begin(), merged.end());

		// transform vector to linked list
		return trans(merged);
	}
};
// @lc code=end

