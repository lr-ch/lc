/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> st;

		/*
		 * the final state will be like [-, -, -, +, +, +],
		 * always keep ones fly to right, and handle cases fly to left
		 */
		for (int i = 0; i < asteroids.size(); i++) {
			if (asteroids[i] > 0) {
				// this one flies to right
				st.push_back(asteroids[i]);
			} else {
				// this one flies to left
				// first, check whether stack is empty
				if (st.empty()) {
					st.push_back(asteroids[i]);
					continue;
				}

				// if stack is not empty, check if the top one flies to left
				if (st.back() < 0) {
					st.push_back(asteroids[i]);
					continue;
				}

				// if the top one flies to right, check conditions below
				if (abs(st.back()) > abs(asteroids[i]))
					// this one is smaller, it explodes
					continue;
				else if (abs(st.back()) < abs(asteroids[i])) {
					// this one is larger than top one on stack, keep it to next turn
					i--;
					// and the top one on stack explodes
					st.pop_back();
					continue;
				} else if (abs(st.back()) == abs(asteroids[i])) {
					// both explode
					st.pop_back();
				}
			}
		}

		return st;
	}
};
// @lc code=end
