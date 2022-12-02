/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
	/*
	 * re-arrange the freq array by appearance order 'a' - 'z'
	 * e.g.
	 *      +---+---+---+---+-------+
	 * ch   | a | b | c | d | ..... |
	 *      +---+---+---+---+-------+
	 * freq | 2 | 6 | 0 | 3 | ..... |
	 *      +---+---+---+---+-------+
	 *
	 * will be transformed to
	 *
	 *      +---+---+---+---+-------+
	 * ch   | a | b | c | d | ..... |
	 *      +---+---+---+---+-------+
	 * freq | 6 | 3 | 0 | 2 | ..... |
	 *      +---+---+---+---+-------+
	 */
	void customized(array<int, 26>& arr) {
		array<int, 26> custom = arr;

		// NOTE. custom is sorted by ascending order, so custom[25]
		//       has the largest freqencies
		sort(custom.begin(), custom.end());
		for (int i = 0, j = 25; i < 26; i++)
			if (arr[i]) arr[i] = custom[j--];
	}

public:
	bool closeStrings(string word1, string word2) {
		array<int, 26> freq1, freq2;
		freq1.fill(0);
		freq2.fill(0);

		for (char ch : word1) freq1[ch - 'a']++;
		for (char ch : word2) freq2[ch - 'a']++;

		customized(freq1);
		customized(freq2);

		return freq1 == freq2;
	}
};
// @lc code=end
