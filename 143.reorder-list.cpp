/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
	void reorderList(ListNode* head) {
		if (!head->next) return;

		stack<ListNode *> st;
		auto curr = head;
		while (curr) {
			st.push(curr);
			curr = curr->next;
		}

		int pop_count = st.size() / 2;
		bool odd = st.size() % 2;

		curr = head;
		auto next = curr->next;				// original next
		while (pop_count--) {
			curr->next = st.top();			// switch to stack next
			st.pop();

			curr->next->next = next;		// switch to orignal next
			curr = next;					// proceed curr and next
			next = curr->next;
		}

		if (odd) {
			curr->next = next;
			curr = curr->next;
		}

		curr->next->next = nullptr;
	}
};
// @lc code=end
