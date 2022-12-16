/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
	stack<int> s1, s2;
public:
	MyQueue() {

	}

	void push(int x) {
		s1.push(x);
	}

	int pop() {
		int ret = peek();
		s2.pop();
		return ret;
	}

	int peek() {
		if (s2.empty())
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}

		return s2.top();
	}

	bool empty() {
		return s1.empty() && s2.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

