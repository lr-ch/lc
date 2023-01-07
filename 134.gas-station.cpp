/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution1 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0, lowest = 0, ans = 0;

		for (int i = 0; i < gas.size(); i++) {
			// sum up remain fuel
			total += gas[i] - cost[i];

			if (total < lowest) {
				lowest = total;
				ans = i + 1;
			}
		}

		// not enough fuel
		if (total < 0) return -1;

		return ans == gas.size() ? 0 : ans;
	}
};

class Solution2 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0;

		for (int i = 0; i < gas.size(); i++)
			total += gas[i] - cost[i];

		// not enough fuel
		if (total < 0) return -1;

		int current_fuel = 0, ans = 0;
		for (int j = 0; j < gas.size(); j++) {
			// track current remain fuel
			current_fuel += gas[j] - cost[j];

			// if remain fuel is not enough, reset start point and remain fuel
			if (current_fuel < 0) {
				ans = j + 1;
				current_fuel = 0;
			}
		}

		return ans == gas.size() ? 0 : ans;
	}
};

class Solution {
	Solution1 sol1;
	Solution2 sol2;
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	//	return sol1.canCompleteCircuit(gas, cost);
		return sol2.canCompleteCircuit(gas, cost);
	}
};
// @lc code=end
