/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
	int compress(vector<char>& chars) {
		int left = 0, right = 0;
		while (right < chars.size()) {
			int counter = right + 1;
			while (counter < chars.size() && chars[right] == chars[counter])
				counter++;

			chars[left++] = chars[right];
			if (counter - right > 1)
				for(auto& ch : to_string(counter - right))
					chars[left++] = ch;

			right = counter;
		}

		return left;
	}
};
// @lc code=end
