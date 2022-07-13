/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		string k_str = to_string(k);
		vector<int> k_v(k_str.begin(), k_str.end());
		for (int i = 0; i < k_v.size(); i++)
			k_v[i] -= '0';

		int carry = 0, index_n = num.size() - 1, index_k = k_v.size() - 1;
		list<int> ans_l;

		while (index_n >= 0 && index_k >= 0) {
			ans_l.push_front(num[index_n] + k_v[index_k] + carry);
			carry = *(ans_l.begin()) / 10;
			*(ans_l.begin()) %= 10;
			index_n--; index_k--;
		}

		while (index_n >= 0) {
			ans_l.push_front(num[index_n] + carry);
			carry = *(ans_l.begin()) / 10;
			*(ans_l.begin()) %= 10;
			index_n--;
		}

		while (index_k >= 0) {
			ans_l.push_front(k_v[index_k] + carry);
			carry = *(ans_l.begin()) / 10;
			*(ans_l.begin()) %= 10;
			index_k--;
		}

		if (carry != 0) ans_l.push_front(carry);

		vector<int> ans_v;
		for (auto i : ans_l)
			ans_v.push_back(i);

		return ans_v;
	}
};
// @lc code=end

