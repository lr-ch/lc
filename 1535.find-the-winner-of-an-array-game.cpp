/*
 * @lc app=leetcode id=1535 lang=cpp
 *
 * [1535] Find the Winner of an Array Game
 */

// @lc code=start
class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		queue<int> q;
		int maxi = INT_MIN;
		for (int& i : arr) {
			q.push(i);
			maxi = max(maxi, i);
		}

		int curr = q.front(); q.pop();
		int wins = 0;
		while (1) {
			if (wins == k || curr == maxi) return curr;

			int challenger = q.front(); q.pop();
			if (curr > challenger) {
				q.push(challenger);
				wins++;
			} else {
				q.push(curr);
				curr = challenger;
				wins = 1;
			}
		}

		// should not come here
		return -1;
	}
};
// @lc code=end
