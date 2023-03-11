/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return nullptr;
		if (!head->next) return new TreeNode(head->val);

		ListNode *slow = head, *fast = head, *prev = slow;

		// find the middle
		while (fast->next && fast->next->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		// cut in the middle
		fast = slow->next;
		prev->next = nullptr;

		// create root node for subtrees
		TreeNode *mid = new TreeNode(slow->val);

		if (head != slow)
			mid->left = sortedListToBST(head);
		mid->right = sortedListToBST(fast);

		return mid;
	}
};
// @lc code=end
