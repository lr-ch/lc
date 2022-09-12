/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		vector<pair<int, int>> engrs;	// <speed, efficiency>
		for (int i = 0; i < n; i++)
			engrs.push_back({ speed[i], efficiency[i] });

		// sort efficiency first, because the performance is sum(speed) * min(efficiency)
		// we don't need to worry which member's efficiency is the minimun later
		sort(engrs.begin(), engrs.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
		});

		// store each member's speed in descending order, i.e. the smallest speed on top(),
		// and keep the queue's size == k
		priority_queue<int, vector<int>, greater<>> members;

		// currSpeed = sum(speed)
		long currSpeed = 0, perf = 0;
		// interview with each engineer
		for (auto& [spd, eff] : engrs) {
			// if the team is full, kick out least speed
			if (members.size() == k) {
				currSpeed -= members.top();
				members.pop();
			}
			members.push(spd);
			currSpeed += spd;
			perf = max(perf, currSpeed * eff);
		}
		return perf % MOD;
	}
};
// @lc code=end
