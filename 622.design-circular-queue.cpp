/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
	struct Node {
		Node* next;
		int val;
		Node() {}
		~Node() {}
	};

	Node* front = nullptr;
	Node* rear = nullptr;
	int qsize = 0, cursize = 0;
public:
	MyCircularQueue(int k) {
		qsize = k;
		front = new Node[k];
		rear = front;

		for (int i = 0; i < k - 1; i++)
			front[i].next = &front[i + 1];

		// make it circular
		front[k - 1].next = &front[0];
	}

	bool enQueue(int value) {
		if (!isFull()) {
			rear = rear->next;
			rear->val = value;
			cursize++;

			if (cursize == 1) front = rear;
			return true;
		}
		return false;
	}

	bool deQueue() {
		if (!isEmpty()) {
			front = front->next;
			cursize--;

			if (cursize == 0) rear = front;
			return true;
		}
		return false;
	}

	int Front() {
		return isEmpty() ? -1 : front->val;
	}

	int Rear() {
		return isEmpty() ? -1 : rear->val;
	}

	bool isEmpty() {
		return cursize == 0;
	}

	bool isFull() {
		return cursize == qsize;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
