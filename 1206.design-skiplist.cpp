/*
 * @lc app=leetcode id=1206 lang=cpp
 *
 * [1206] Design Skiplist
 */

// @lc code=start
class Skiplist {
	struct Node {
		int val;
		shared_ptr<Node> next, down;
		Node(int v)
			: val(v), next(nullptr), down(nullptr) {}
		Node(int v, auto n, auto d)
			: val(v), next(n), down(d) {}
	};

	shared_ptr<Node> layer;
public:
	Skiplist() {
		layer = make_shared<Node>(INT_MIN);
	}

	bool search(int target) {
		auto iter = layer;
		while (iter) {
			while (iter->next && iter->next->val < target) iter = iter->next;

			if (iter->next && iter->next->val == target) return true;
			iter = iter->down;
		}
		return false;
	}

	void add(int num) {
		stack<shared_ptr<Node>> nodes;
		auto iter = layer;
		while (iter) {
			while (iter->next && iter->next->val < num) iter = iter->next;

			nodes.push(iter);
			iter = iter->down;
		}

		shared_ptr<Node> d;
		bool insert = true;
		while (!nodes.empty() && insert) {
			auto iter = nodes.top(); nodes.pop();
			iter->next = make_shared<Node>(num, iter->next, d);
			d = iter->next;

			insert = (rand() % 2);
		}

		if (insert)
			layer = make_shared<Node>(INT_MIN, nullptr, layer);
	}

	bool erase(int num) {
		bool flag = false;
		auto iter = layer;
		while (iter) {
			while (iter->next && iter->next->val < num) iter = iter->next;

			if (iter->next && iter->next->val == num) {
				flag = true;
				iter->next = iter->next->next;
			}
			iter = iter->down;
		}
		return flag;
	}
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end
