/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
class Solution {
public:
	string decodeAtIndex(string s, int k) {
		long decode_len = 0, i;
		for (i = 0; decode_len < k; i++)
			decode_len = isdigit(s[i]) ?
							decode_len * (s[i] - '0') /*repeat*/ :
							decode_len + 1 /*single char*/;
		while (i--) {
			char ch = s[i];
			k %= decode_len;

			if (0 == k && isalpha(ch))
				return string(1, ch);

			if (isdigit(ch))
				decode_len /= (ch -'0');
			else
				decode_len--;
		}

		return "";
	}
};
// @lc code=end
