/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
class Solution1 {
public:
	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
		vector<pair<int, int>> bags;
		for (int i = 0; i < capacity.size(); i++)
			bags.push_back(pair<int, int>(capacity[i], rocks[i]));
		sort(bags.begin(), bags.end(), [](const auto& a, const auto& b) {
			// prefer less remain capacity for "maximun" bags
			return a.first - a.second < b.first - b.second;
		});

		int totalBags = 0;
		for (auto b : bags) {
			// select number of rocks should be remain rocks or remain capacity
			int rocksToPutIn = min(additionalRocks, b.first - b.second);

			// put rocks into the bag
			if (rocksToPutIn > 0) {
				additionalRocks -= rocksToPutIn;
				b.second += rocksToPutIn;
			}

			// check whether the bag is full
			if (0 == b.first - b.second)
				totalBags++;
		}
		return totalBags;
	}
};

class Solution2 {
public:
	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
		vector<int> remains;

		for (int i = 0; i < capacity.size(); i++)
			remains.push_back(capacity[i] - rocks[i]);
		sort(remains.begin(), remains.end());

		int fullBag = 0;
		for (int remain : remains) {
			if (additionalRocks >= remain) {
				additionalRocks -= remain;
				fullBag++;
			} else
				break;
		}
		return fullBag;
	}
};

class Solution {
	/*
	 * Accepted
	 *  79/79 cases passed (249 ms)
	 *  Your runtime beats 72.09 % of cpp submissions
	 *  Your memory usage beats 9.45 % of cpp submissions (94 MB)
	 */
	Solution1 sol1;

	/*
	 * Accepted
	 *  79/79 cases passed (202 ms)
	 *  Your runtime beats 89.01 % of cpp submissions
	 *  Your memory usage beats 12.75 % of cpp submissions (89.6 MB)
	 */
	Solution2 sol2;
public:
	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
	//	return sol1.maximumBags(capacity, rocks, additionalRocks);
		return sol2.maximumBags(capacity, rocks, additionalRocks);
	}
};
// @lc code=end
