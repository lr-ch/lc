/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
	void printV(vector<int>& v) {
		for (auto i : v) cout << i << " ";
		cout << endl;
	}
public:
	int candy(vector<int>& ratings) {
		vector<int> toRight(ratings.size(), 1);
		vector<int> toLeft(ratings.size(), 1);
		int sum = 0;

		for (int i = 1; i < ratings.size(); i++)
			if (ratings[i] > ratings[i - 1])
				toRight[i] = toRight[i - 1] + 1;
	//	printV(toRight);

		for (int j = ratings.size() - 1; j > 0; j--)
			if (ratings[j - 1] > ratings[j])
				toLeft[j - 1] = toLeft[j] + 1;
	//	printV(toLeft);

		for (int k = 0; k < ratings.size(); k++)
			sum += max(toRight[k], toLeft[k]);

		return sum;
	}
};
// @lc code=end

