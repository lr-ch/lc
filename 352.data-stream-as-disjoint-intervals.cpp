/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges {
	set<int> nums;

public:
	SummaryRanges() {
	}

	void addNum(int value) {
		nums.insert(value);
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> res;
		for (const int i : nums) {
			if (res.empty()) {
				res.push_back({ i, i });
			} else {
				if (i == res.back()[1] + 1)
					res.back()[1] = i;
				else
					res.push_back({ i, i });
			}
		}
		return res;
	}
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
