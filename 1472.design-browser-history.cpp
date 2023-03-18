/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
	stack<string> visited_back, visited_forward;
public:
	BrowserHistory(string homepage) {
		visited_back.push(homepage);
	}

	void visit(string url) {
		visited_back.push(url);
		while (!visited_forward.empty()) visited_forward.pop();
	}

	string back(int steps) {
		while (steps && visited_back.size() > 1) {
			visited_forward.push(visited_back.top());
			visited_back.pop();
			steps--;
		}
		return visited_back.top();
	}

	string forward(int steps) {
		while (steps && !visited_forward.empty()) {
			visited_back.push(visited_forward.top());
			visited_forward.pop();
			steps--;
		}
		return visited_back.top();
	}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
