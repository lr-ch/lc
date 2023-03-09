/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionSpaceOn {
	unordered_set<ListNode *> seen;
public:
	ListNode *detectCycle(ListNode *head) {
		while (head) {
			if (seen.find(head) != seen.end())
				return head;

			seen.insert(head);
			head = head->next;
		}
		return nullptr;
	}
};

class SolutionSpaceO1 {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			// it only means there is a cycle, not sure this is the cross point
			if (fast == slow) break;
		}

		// there is no cycle
		if (!fast || !fast->next) return nullptr;

		// reset slow, sync steps until meets fast
		slow = head;
		while (slow != fast) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;	// or fast
	}
};

class Solution {
	/*
	 * Accepted
	 *  17/17 cases passed (16 ms)
	 *  Your runtime beats 23.25 % of cpp submissions
	 *  Your memory usage beats 19.71 % of cpp submissions (9.5 MB)
	 */
	SolutionSpaceOn on;

	/*
	 * Accepted
	 *  17/17 cases passed (8 ms)
	 *  Your runtime beats 76.5 % of cpp submissions
	 *  Your memory usage beats 84.91 % of cpp submissions (7.5 MB)
	 */
	SolutionSpaceO1 o1;
public:
	ListNode *detectCycle(ListNode *head) {
		return on.detectCycle(head);
	//	return o1.detectCycle(head);
	}
};
// @lc code=end
