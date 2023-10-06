/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
	struct Node {
		int val;
		shared_ptr<Node> next, prev;
		Node (int v)
			: val(v), next(nullptr), prev(nullptr) {}
		Node (int v, auto n, auto p)
			: val(v), next(n), prev(p) {}
	};

	shared_ptr<Node> head, tail;
	int n;
public:
	MyLinkedList() : n(0) {
		head = make_shared<Node>(INT_MIN);
		tail = make_shared<Node>(INT_MIN);
		head->next = tail;
		tail->prev = head;
	}

	int get(int index) {
		if (index < 0 || index >= n) return -1;

		auto iter = head->next;
		for (int i = 0; i < index; i++, iter = iter->next);
		return iter->val;
	}

	void addAtHead(int val) {
		auto added = make_shared<Node>(val, head->next, head);
		head->next->prev = added;
		head->next = added;
		n++;
	}

	void addAtTail(int val) {
		auto added = make_shared<Node>(val, tail, tail->prev);
		tail->prev->next = added;
		tail->prev = added;
		n++;
	}

	void addAtIndex(int index, int val) {
		if (index < 0 || index > n) return;

		auto iter = head;
		for (int i = 0; i < index; i++, iter = iter->next);

		auto added = make_shared<Node>(val, iter->next, iter);
		iter->next->prev = added;
		iter->next = added;
		n++;
	}

	void deleteAtIndex(int index) {
		if (index < 0 || index >= n) return;

		auto iter = head->next;
		for (int i = 0; i < index; i++, iter = iter->next);

		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
		n--;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
