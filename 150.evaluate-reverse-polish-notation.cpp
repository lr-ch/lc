/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
	void implOp(string& op) {
		long op1 = s.top();
		s.pop();

		long op2 = s.top();
		s.pop();

		switch (op[0]) {
			case '+' :
				s.push(op2 + op1);
				break;
			case '-' :
				s.push(op2 - op1);
				break;
			case '*' :
				s.push(op2 * op1);
				break;
			case '/' :
				s.push(op2 / op1);
				break;
		}
	}

	stack<long> s;
public:
	int evalRPN(vector<string>& tokens) {
		for (auto& str : tokens) {
			if (str == "+" || str == "-" || str == "*" || str == "/")
				implOp(str);
			else
				s.push(stoi(str));
		}
		return (int)s.top();
	}
};
// @lc code=end
