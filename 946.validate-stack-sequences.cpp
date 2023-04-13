/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;

		auto curr_popped = popped.begin();
		for (const auto& val : pushed) {
			st.push(val);

			while (!st.empty() && st.top() == *curr_popped) {
				st.pop();
				curr_popped++;
			}
		}
		return st.empty();
	}
};
// @lc code=end
