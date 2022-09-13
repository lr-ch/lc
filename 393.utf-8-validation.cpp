/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
	inline int filter(int m1, int m2) { return m1 & m2; }
	inline bool followByteValid(int b) {
		int filtered = filter(b, 0xc0);
		return filtered < 0xc0 && filtered >= 0x80;
	}
public:
	bool validUtf8(vector<int>& data) {
		int i = 0;
		while (i < data.size()) {
			// 1-byte
			// 0xxx xxxx
			if (filter(data[i], 1 << 7) < 0x80) {
				i += 1;
				continue;
			}

			// 2-bytes
			// 110xxxxx 10xxxxxx
			if (filter(data[i], 0xe0) < 0xe0 &&
				filter(data[i], 0xe0) >= 0xc0 &&
				i + 1 < data.size() &&
				followByteValid(data[i + 1])) {
				i += 2;
				continue;
			}

			// 3-bytes
			// 1110xxxx 10xxxxxx 10xxxxxx
			if (filter(data[i], 0xf0) < 0xf0 &&
				filter(data[i], 0xf0) >= 0xe0 &&
				i + 2 < data.size() &&
				followByteValid(data[i + 1]) &&
				followByteValid(data[i + 2])) {
				i += 3;
				continue;
			}

			// 4-bytes
			// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			if (filter(data[i], 0xf8) < 0xf8 &&
				filter(data[i], 0xf8) >= 0xf0 &&
				i + 3 < data.size() &&
				followByteValid(data[i + 1]) &&
				followByteValid(data[i + 2]) &&
				followByteValid(data[i + 3])) {
				i += 4;
				continue;
			}

			return false;
		}

		return true;
	}
};
// @lc code=end
