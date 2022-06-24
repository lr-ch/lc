/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */

// @lc code=start
class Solution {
public:
	bool isPossible(vector<int>& target) {
		priority_queue<int> array;
		long long sum = 0;

		for (auto i : target) {
			array.push(i);
			sum += i;
		}
		// reverse validation
		// example #1: [9, 5, 3], sum = 17
		// top = 9, newtop = 9 % 8 = 1, [1(newtop), 5, 3], sum = 9
		// top = 5, newtop = 5 % 4 = 1, [1(newtop), 1, 3], sum = 5
		// top = 3, newtop = 3 % 2 = 1, [1(newtop), 1, 1], sum = 3
		// return true
		//
		// example #2: [1, 1, 1, 2], sum = 5
		// top = 2, newtop = 2 % 3 = 2, [2(newtop), 1, 1, 1], sum = 5
		// return false (top == newtop, infinite loop)
		//
		// example #3: [8, 5], sum = 13
		// top = 8, newtop = 8 % 5 = 3, [3(newtop), 5], sum = 8
		// top = 5, newtop = 5 % 3 = 2, [2(newtop), 3], sum = 5
		// top = 3, newtop = 3 % 2 = 1, [1(newtop), 2], sum = 3
		// top = 2, newtop = 2 % 1 = 0, [0(newtop), 1], sum = 1
		// return true ([0,1] can be expanded to [1,1], others cannot)
		while (array.top() != 1) {
			int top = array.top();
			int diff = sum - top;

			// impossible case, e.g. [2]
			if (diff == 0) return false;
			int newtop = top % diff;
			// [0,1] can be expanded to [1,1], others cannot
			if (top == newtop || (newtop == 0 && diff != 1)) return false;

			// replace top with newtop, also renew sum value
			array.pop();
			array.push(newtop);
			sum = diff + newtop;
		}
		return true;
	}
};
// @lc code=end

