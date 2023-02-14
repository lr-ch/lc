/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
	string addBinary(string a, string b) {
		int lenA = a.length() - 1, lenB = b.length() - 1, carry = 0;
		string ans;

		// DO NOT USE LIKE (lenA-- || lenB--) IN WHILE CONDITION
		// BECAUSE POSSIBLY ONLY lenA-- BEING EVALUATED, lenB-- IS SKIPPED
		while (lenA >= 0 || lenB >= 0) {
			int digitA = (lenA >= 0 ? a[lenA] - '0' : 0);
			int digitB = (lenB >= 0 ? b[lenB] - '0' : 0);
			int sum = digitA + digitB + carry;

			switch (sum) {
				case 0 :
					ans.push_back('0');
					carry = 0;
					break;
				case 1 :
					ans.push_back('1');
					carry = 0;
					break;
				case 2 :
					ans.push_back('0');
					carry = 1;
					break;
				case 3 :
					ans.push_back('1');
					carry = 1;
					break;
			}
			lenA--; lenB--;
		}

		// don forget the final carry digit!!
		if (carry) ans.push_back('1');

		return string(ans.rbegin(), ans.rend());
	}
};
// @lc code=end
