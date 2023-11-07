/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		int n = dist.size();
		vector<float> time_to_city(n);
		for (int i = 0; i < n; i++)
			time_to_city[i] = (float)dist[i] / speed[i];
		sort(time_to_city.begin(), time_to_city.end());

		int count = 0;
		for (int i = 0; i < n; i++)
			if (time_to_city[i] > i)
				count++;
			else
				break;

		return count;
	}
};
// @lc code=end
