/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution {
/*
 * Works, but TLE
 *
 * Time Limit Exceeded
 *   45/52 cases passed (N/A)
 */
/*
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		vector<int> res;
		for (auto p : persons) {
			int blooms = 0;
			for (auto f : flowers)
				if (p >= f[0] && p <=f[1])
					blooms++;
			res.push_back(blooms);
		}
		return res;
	}
*/
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		/*
		 * Separately sort start_i and end_i in flowers, the result is equlivant
		 * e.g. [[4,20],[7,16]] == [[4,16],[7,20]]
		 *
		 * +-----------------------
		 * |   +---------------+  [4, 20]
		 * |      +--------+      [7, 16]
		 *
		 * +-----------------------
		 * |   +-----------+      [4, 16]
		 * |      +------------+  [7, 20]
		 */
		vector<int> start_, end_;
		for (auto f : flowers) {
			start_.push_back(f[0]);
			end_.push_back(f[1]);
		}
		sort(start_.begin(), start_.end());
		sort(end_.begin(), end_.end());

		/*
		 * Now find the upper/lower bound index of start_ and end_, the index represents
		 * the total number of flowers bloom start/end.
		 * e.g. person = [5,10,21], start_ = [4,7], end_= [16,20]
		 *      upper/lower bound of  5 = [1,0], bloom flowers = 1
		 *      upper/lower bound of 10 = [2,0], bloom flowers = 2
		 *      upper/lower bound of 21 = [2,2], bloom flowers = 0
		 */
		vector<int> res;
		for (auto p : persons) {
			int totalStart = upper_bound(start_.begin(), start_.end(), p) - start_.begin();
			int totalEnd = lower_bound(end_.begin(), end_.end(), p) - end_.begin();
			res.push_back(totalStart - totalEnd);
		}
		return res;
	}
};
// @lc code=end

