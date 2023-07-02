/*
 * @lc app=leetcode id=1601 lang=cpp
 *
 * [1601] Maximum Number of Achievable Transfer Requests
 */

// @lc code=start
class Solution {
public:
	int maximumRequests(int n, vector<vector<int>>& requests) {
		vector<bitset<16>> cb(pow(2, requests.size()));
		iota(cb.begin(), cb.end(), 0);

		// for each combinations of requests
		int ans = 0;
		for (const auto & c : cb) {
			vector<int> buildings(n, 0);

			for (int i = 0; i < 16; i++) {
				// if the bit is 1, apply the request
				if (c[i] == 1) {
					int from = requests[i][0], to = requests[i][1];
					buildings[from]--;
					buildings[to]++;
				}
			}

			// check buildings are all zero
			auto non_zero = find_if(buildings.begin(), buildings.end(), [](int i) {return i != 0;});
			if (non_zero == buildings.end())
				ans = max(ans, (int)c.count());
		}

		return ans;
	}
};
// @lc code=end
