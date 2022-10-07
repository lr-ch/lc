/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
class MyCalendarTwo {
	map<int, int> table;
public:
	MyCalendarTwo() {
	}

	bool book(int start, int end) {
		table[start]++;
		table[end]--;

		int count = 0;
		for (auto& [event, number] : table) {
			count += number;
			if (count >= 3) {
				table[start]--;
				table[end]++;
				return false;
			}
		}
		return true;
	}
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

