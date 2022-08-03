/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
	vector<pair<int, int>> book_;	// <start, end>
public:
	MyCalendar() {
		book_.clear();
	}

	bool book(int start, int end) {
		for (auto& e : book_)
			if (start < e.second && end > e.first)
				return false;
		book_.push_back(pair<int, int>(start, end));
		return true;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

