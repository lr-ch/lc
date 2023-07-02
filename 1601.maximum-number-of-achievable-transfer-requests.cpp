/*
 * @lc app=leetcode id=1601 lang=cpp
 *
 * [1601] Maximum Number of Achievable Transfer Requests
 */

// @lc code=start
class SolutionTab {
public:
	int maximumRequests(int n, vector<vector<int>>& requests) {
		vector<bitset<16>> cb(pow(2, requests.size()));
		iota(cb.begin(), cb.end(), 0);

		// for each combinations of requests
		int ans = 0;
		vector<int> buildings(n, 0);
		for (const auto & c : cb) {
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

			fill(buildings.begin(), buildings.end(), 0);
		}

		return ans;
	}
};

class SolutionRecur {
	void bt(vector<vector<int>>& r, vector<int>& b, int applied, int i) {
		if (i == r.size()) {
			auto non_zero = find_if(b.begin(), b.end(), [](const int i) {return i != 0;});
			if (non_zero == b.end())
				ans = max(ans, applied);
			return;
		}

		// do not apply this request
		bt(r, b, applied, i + 1);

		// apply this request
		b[r[i][0]]--; b[r[i][1]]++;
		bt(r, b, applied + 1, i + 1);
		b[r[i][0]]++; b[r[i][1]]--;
	}

	int ans = 0;
public:
	int maximumRequests(int n, vector<vector<int>>& requests) {
		vector<int> buildings(n, 0);
		bt(requests, buildings, 0, 0);
		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 117/117 cases passed (378 ms)
	 *  - Your runtime beats 39.22 % of cpp submissions
	 *  - Your memory usage beats 40.2 % of cpp submissions (24.8 MB)
	 */
	SolutionTab tab;

	/*
	 * Accepted
	 *  - 117/117 cases passed (106 ms)
	 *  - Your runtime beats 69.61 % of cpp submissions
	 *  - Your memory usage beats 92.16 % of cpp submissions (8.7 MB)
	 */
	SolutionRecur recur;
public:
	int maximumRequests(int n, vector<vector<int>>& requests) {
	//	return tab.maximumRequests(n, requests);
		return recur.maximumRequests(n, requests);
	}
};
// @lc code=end
