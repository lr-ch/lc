/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
	struct PairCompare {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b){
			return a.first > b.first;
		}
	};

public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		int N = profits.size();

		priority_queue<
			pair<int, int>,
			vector<pair<int, int>>,
			PairCompare> candidate;
		for (int i = 0; i < N; i++) candidate.push({ capital[i], profits[i] });

		priority_queue<int> gain;

		while (k--) {
			while (!candidate.empty() && w >= candidate.top().first) {
				gain.push(candidate.top().second);
				candidate.pop();
			}

			if (!gain.empty()) {
				w += gain.top();
				gain.pop();
			}
		}

		return w;
	}
};
// @lc code=end
