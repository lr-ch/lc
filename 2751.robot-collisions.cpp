/*
 * @lc app=leetcode id=2751 lang=cpp
 *
 * [2751] Robot Collisions
 */

// @lc code=start
class Solution {
	/*
	 * ref. [735] Asteroid Collision
	 */
	typedef tuple<int, int, bool, int> state;	// (position, health, direction, index)
public:
	vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
		vector<state> robots;
		for (int i = 0; i < positions.size(); i++)
			robots.push_back({positions[i], healths[i], directions[i] == 'R' ? true : false, i});
		sort(robots.begin(), robots.end());

		vector<state> st;
		for (int i = 0; i < robots.size(); i++) {
			auto& [_, hp, dir, idx] = robots[i];

			if (dir) {
				// to right
				st.push_back(robots[i]);
			} else {
				// to left
				if (st.empty()) {
					st.push_back(robots[i]);
					continue;
				}

				auto& [__, _hp, _dir, _idx] = st.back();
				if (_dir == false) {
					// all to left
					st.push_back(robots[i]);
					continue;
				}

				if (_hp > hp) {
					_hp--;
				} else if (_hp < hp) {
					i--;
					hp--;
					st.pop_back();
				} else if (_hp == hp) {
					st.pop_back();
				}
			}
		}

		// restore order by original index
		sort(st.begin(), st.end(), [](const auto& a, const auto& b) {
			return get<3>(a) < get<3>(b);
		});

		vector<int> ans;
		for (int i = 0; i < st.size(); i++)
			ans.push_back(get<1>(st[i]));
		return ans;
	}
};
// @lc code=end
