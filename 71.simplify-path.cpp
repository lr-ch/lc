/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
	string simplifyPath(string path) {
		stringstream path_str(path);
		vector<string> tokens;

		string token;
		while (getline(path_str, token, '/')) {
			if (token == "..") {
				if (!tokens.empty()) tokens.pop_back();
			} else if (token == "." || token == "")
				continue;
			else
				tokens.push_back(token);
		}

		string ans = "/";
		for (const auto& t : tokens)
			ans += t + "/";

		if (ans != "/")
			ans.pop_back();

		return ans;
	}
};
// @lc code=end
