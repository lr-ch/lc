/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
class Solution {
	unordered_map<char, pair<int, int>> dirs = {
		{ 'N', {  0,  1 } },
		{ 'S', {  0, -1 } },
		{ 'E', {  1,  0 } },
		{ 'W', { -1,  0 } } };
public:
	bool isPathCrossing(string path) {
		set<pair<int, int>> history;
		pair<int, int> curr = { 0, 0 };		// current position
		history.insert(curr);

		for (auto& ch : path) {
			auto& [x, y] = dirs[ch];
			curr.first += x;
			curr.second += y;
			if (history.count(curr)) return true;
			history.insert(curr);
		}
		return false;
	}
};
// @lc code=end
