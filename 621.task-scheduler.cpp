/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> freq(26, 0);
		for (const auto& t : tasks) freq[t - 'A']++;

		sort(freq.begin(), freq.end(), greater<int>());
		int intervals = freq[0] - 1, idles = intervals * n;

		// Note. fill up intervals from secondly frequent task (freq[1])
		for (int i = 1; i < 26; i++)
			idles -= min(intervals, freq[i]);

		return idles < 0 ? tasks.size() : tasks.size() + idles;
	}
};
// @lc code=end
