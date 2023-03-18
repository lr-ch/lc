/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
	vector<string> record;
	int curr;
public:
	BrowserHistory(string homepage) {
		record.push_back(homepage);
		curr = 0;
	}

	void visit(string url) {
		if (curr < record.size() - 1)
			record.erase(record.begin() + curr + 1, record.end());
		record.push_back(url);
		curr = record.size() - 1;
	}

	string back(int steps) {
		curr = (curr - steps < 0) ? 0 : curr - steps;
		return record[curr];
	}

	string forward(int steps) {
		curr = (curr + steps > record.size() - 1) ? record.size() - 1 : curr + steps;
		return record[curr];
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
