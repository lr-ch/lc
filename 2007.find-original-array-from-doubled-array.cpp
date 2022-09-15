/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *   133/178 cases passed (N/A)
 */
class SolutionTLE {
public:
	vector<int> findOriginalArray(vector<int>& changed) {
		if (changed.size() % 2) return {};

		vector<int> res;
		sort(changed.begin(), changed.end());

		for (int i = 0; i < changed.size(); i++) {
			auto it = find(changed.begin() + i + 1, changed.end(), changed[i] * 2);
			if (it != changed.end()) {
				res.push_back(changed[i]);
				*it = -1;
			}
			if (res.size() == changed.size() / 2)
				return res;
		}

		return {};
	}
};

class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) {
		if (changed.size() % 2) return {};
		sort(changed.begin(), changed.end());

		unordered_map<int, int> mp; // <value, freq(value)>
		for (auto i : changed) mp[i]++;

		vector<int> res;
		for (auto i : changed) {
			// zero here means it is some value's double
			if (!mp[i]) continue;

			if (mp[i * 2] > 0) {
				res.push_back(i);
				mp[i]--;
				mp[i * 2]--;
			} else
				return {};
		}

		return res;
	}
};
// @lc code=end
