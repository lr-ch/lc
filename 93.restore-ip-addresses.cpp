/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
	int valid(string s) {
		// check leading zero
		if (s[0] == '0' && s.length() > 1) return -1;

		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] < '0' || s[i] > '9')
				return -1;
			res = res * 10 + s[i] - '0';
		}
		if (res > 255) return -1;
		return res;
	}

	void bt(string& s, vector<int>& ip, int index) {
		if (ip.size() == 4 && index == s.length()) {
			ans.push_back(
				to_string(ip[0]) + "." +
				to_string(ip[1]) + "." +
				to_string(ip[2]) + "." +
				to_string(ip[3]));
		}

		if (index == s.length()) return;

		for (int i = 0; i < 3 && index + i < s.length(); i++) {
			int digit = valid(s.substr(index, i + 1));
			if (digit != -1) {
				ip.push_back(digit);
				bt(s, ip, index + i + 1);
				ip.pop_back();
			}
		}
	}

	vector<string> ans;
public:
	vector<string> restoreIpAddresses(string s) {
		vector<int> ip_digit;
		bt(s, ip_digit, 0);
		return ans;
	}
};
// @lc code=end
