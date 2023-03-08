/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
	inline int hours(vector<int> &piles, int k) {
		int h = 0;
		for (const auto& p : piles)
			h += (p / k) + (p % k ? 1 : 0);
	//	cout << "need time : " << h << " hours\n";
		return h;
	}

public:
	int minEatingSpeed(vector<int>& piles, int h) {        
		int left = 1, right = *max_element(piles.begin(), piles.end());
		while (left < right) {
			int mid = (left + right) / 2;
			int need = hours(piles, mid);
		//	cout << left << ":" << mid << ":" << right << endl;

			if (need > h)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};
// @lc code=end
