/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
	map<int, int> table;
public:
	MyCalendarThree() {
	}

	int book(int start, int end) {
		table[start]++;
		table[end]--;

		int count = 0, ans = 0;
		for (auto& [event, number] : table) {
			count += number;
			ans = max(count, ans);
		}
		return ans;
	}
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

