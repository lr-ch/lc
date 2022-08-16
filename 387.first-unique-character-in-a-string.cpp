/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
/*
 * Accepted
 *  * 105/105 cases passed (42 ms)
 *  * Your runtime beats 69.35 % of cpp submissions
 *  * Your memory usage beats 15.65 % of cpp submissions (23.5 MB)
 */
class HashTable {
public:
	int firstUniqChar(string s) {
		// <char, indexes of appearance of char>
		//   example:
		//     leetcode
		//       { 'l', {0} }
		//       { 'e', {1, 2, 7} }
		//       { 't', {3} }
		//       { 'c', {4} }
		//       { 'o', {5} }
		//       { 'd', {6} }
		unordered_map<char, vector<int>> table;

		for (int i = 0; i < s.length(); i++)
			table[s[i]].push_back(i);

		int index = s.size();
		for (auto& j : table)
			if (j.second.size() == 1 && j.second[0] < index)
				index = j.second[0];

		return index == s.size() ? -1 : index;
	}
};

class Solution {
public:
	int firstUniqChar(string s) {
		array<int, 26> table = {0};

		for (int i = 0; i < s.length(); i++)
			table[s[i] - 'a']++;

		for (int j = 0; j < s.length(); j++)
			if (table[s[j] - 'a'] == 1)
				return j;

		return -1;
	}
};
// @lc code=end
