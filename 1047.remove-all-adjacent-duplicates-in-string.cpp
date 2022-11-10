/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
	string solutionStack(string& s) {
		vector<char> stack;
		for (auto& ch : s)
			if (!stack.empty() && stack.back() == ch)
				stack.pop_back();
			else
				stack.push_back(ch);

		return string(stack.begin(), stack.end());
	}

	string solutionTwoPtr(string& s) {
		int slow = 0;
		for (int fast = 0; fast < s.length(); fast++)
			if (slow > 0 && s[fast] == s[slow - 1])
				slow--;
			else
				s[slow++] = s[fast];
		return s.substr(0, slow);
	}

public:
	string removeDuplicates(string s) {
	//	return solutionStack(s);
		return solutionTwoPtr(s);
	}
};
// @lc code=end
