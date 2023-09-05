/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
		unordered_map<Node *, Node *> m;	// (original, copy)
		for (Node *s = head; s; s = s->next)
			m[s] = new Node(s->val);

		for (Node *s = head; s; s = s->next) {
			m[s]->next = m[s->next];
			m[s]->random = m[s->random];
		}

		return m[head];
	}
};
// @lc code=end
