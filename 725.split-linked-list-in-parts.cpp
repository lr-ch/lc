/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
	vector<ListNode*> splitListToParts(ListNode* head, int k) {
		int count = 0;
		ListNode *h = head;
		while (h) {
			count++;
			h = h->next;
		}

		vector<ListNode *> ret;
		int avg = count / k, remain = count % k;
		h = head;
		for (int i = 0; i < k; i++) {
			ret.push_back(h);
			for (int j = 0; j < avg + (i < remain ? 1 : 0) - 1; j++)
				if (h) h = h->next;

			if (h) {
				ListNode *tmp = h;
				h = h->next;
				tmp->next = nullptr;
			}
		}
		return ret;
	}
};
// @lc code=end
