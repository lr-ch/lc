/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
	string predictPartyVictory(string senate) {
		queue<int> dq, rq;

		for (int i = 0; i < senate.size(); i++)
			if (senate[i] == 'R') rq.push(i);
			else dq.push(i);

		while (!rq.empty() && !dq.empty()) {
			int ri = rq.front(); rq.pop();
			int di = dq.front(); dq.pop();

			// lower indexed one can ban larger indexed, winner this round
			//  will be re-indexed and enqueued for next round
			if (ri < di) rq.push(ri + senate.size());
			else dq.push(di + senate.size());
		}

		return dq.empty() ? "Radiant" : "Dire";
	}
};
// @lc code=end
