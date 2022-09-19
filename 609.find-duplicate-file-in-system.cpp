/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
	void split(string& str, vector<string>& output) {
		string ln;
		stringstream ss(str);
		while (getline(ss, ln, ' ')) output.push_back(ln);
	}

public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>> mp;	// <content, full path filename>
		vector<string> path;
		for (auto& p : paths) {
			split(p, path);

			// path[0] is directory name
			for (int i = 1; i < path.size(); i++) {
				size_t left = path[i].find('('), right = path[i].find(')');
			//	string filename = path[i].substr(0, left);
			//	string content = path[i].substr(left + 1, right - left - 1);
			//	mp[content].push_back(path[0] + '/' + filename);
				mp[path[i].substr(left + 1, right - left - 1)].push_back(path[0] + '/' + path[i].substr(0, left));
			}
			path.clear();
		}

		vector<vector<string>> ans;
		for (auto& p : mp)
			if (p.second.size() > 1) ans.push_back(p.second);
		return ans;
	}
};
// @lc code=end
