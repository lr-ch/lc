/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueueLinkedList {
	struct Node {
		Node* next;
		int val;
	};

	Node* front = nullptr;
	Node* rear = nullptr;
	int qsize = 0, cursize = 0;
public:
	void init(int k) {
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

class MyCircularQueueArray {
	vector<int> q;
	int qsize = 0, front = 0;
public:
	void init(int k) {
		q.resize(k);
	}

	bool enQueue(int value) {
		if (!isFull()) {
			q[(front + qsize) % q.size()] = value;
			qsize++;
			return true;
		}
		return false;
	}

	bool deQueue() {
		if (!isEmpty()) {
			front = (front + 1) % q.size();
			qsize--;
			return true;
		}
		return false;
	}

	int Front() {
		return isEmpty() ? -1 : q[front];
	}

	int Rear() {
		return isEmpty() ? -1 : q[(front + qsize - 1) % q.size()];
	}

	bool isEmpty() {
		return qsize == 0;
	}

	bool isFull() {
		return qsize == q.size();
	}
};

class MyCircularQueue {
/*
 * Accepted
 *  - 58/58 cases passed (33 ms)
 *  - Your runtime beats 71.04 % of cpp submissions
 *  - Your memory usage beats 48.83 % of cpp submissions (16.8 MB)
 */
	MyCircularQueueArray		solution;

/*
 * Accepted
 *  - 58/58 cases passed (71 ms)
 *  - Your runtime beats 5.11 % of cpp submissions
 *  - Your memory usage beats 11.06 % of cpp submissions (17 MB)
 */
//	MyCircularQueueLinkedList	solution;

public:
	MyCircularQueue(int k) {
		solution.init(k);
	}

	bool enQueue(int value) {
		return solution.enQueue(value);
	}

	bool deQueue() {
		return solution.deQueue();
	}

	int Front() {
		return solution.Front();
	}

	int Rear() {
		return solution.Rear();
	}

	bool isEmpty() {
		return solution.isEmpty();
	}

	bool isFull() {
		return solution.isFull();
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
