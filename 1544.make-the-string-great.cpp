/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class SolutionStack {
public:
	string makeGood(string s) {
		const int diff = abs('A' - 'a');

		vector<char> stack;
		for (auto& ch : s)
			if (!stack.empty() && abs(stack.back() - ch) == diff)
				stack.pop_back();
			else
				stack.push_back(ch);

		return string(stack.begin(), stack.end());
	}
};

class SolutionTwoPtr {
public:
	string makeGood(string s) {
		const int diff = abs('A' - 'a');

		int slow = 0;
		for (int fast = 0; fast < s.length(); fast++)
			if (slow > 0 && abs(s[fast] - s[slow - 1]) == diff)
				slow--;
			else
				s[slow++] = s[fast];

		return s.substr(0, slow);
	}
};

class Solution {
	SolutionStack stack;
	SolutionTwoPtr twoPtr;
public:
	string makeGood(string s) {
	//	return stack.makeGood(s);
		return twoPtr.makeGood(s);
	}
};
// @lc code=end
