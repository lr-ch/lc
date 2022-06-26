/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
	// works, but TLE (37 / 40 test cases passed)
	/*
	int maxScore(vector<int>& cardPoints, int k) {
		int maxPoints = 0;
		// sliding window
		// [1, 2, 3, 4, 5, 6, 1], k = 3
		// [1, 2, 3, ...       ], points = 6
		// [1, 2, ...         1], points = 4
		// [1, ...         6, 1], points = 8
		// [...         5, 6, 1], points = 12
		int anchor = k;
		while (anchor >= 0) {
			int p = 0;
			for (int i = 0; i < anchor; i++) {
				p += cardPoints[i];
			}
			for (int j = cardPoints.size() - (k - anchor); j < cardPoints.size(); j++) {
				p += cardPoints[j];
			}
			maxPoints = max(maxPoints, p);
			anchor--;
		}
		return maxPoints;
	}
	*/

	int maxScore(vector<int>& cardPoints, int k) {
		// still sliding window, find the minimun sum of subarray
		// [1, 2, 3, 4, 5, 6, 1], k = 3, window size = n - k = 4
		// [1, 2, 3, 4]           sum = 10 ([5, 6, 1]) *
		// [   2, 3, 4, 5]        sum = 14 ([1, 6, 1])
		// [      3, 4, 5, 6]     sum = 18 ([1, 2, 1])
		// [         4, 5, 6, 1]  sum = 16 ([1, 2, 3])
		// total sum - minimun subarray sum = 22 - 10 = 12
		int n = cardPoints.size(), totalSum = 0, minSubarray = 0;

		for (int i = 0, currSum = 0; i < n; i++) {
			totalSum += cardPoints[i];
			currSum += cardPoints[i];
			if (i < n - k)
				minSubarray += cardPoints[i];
			else {
				// take back the points from previously added
				currSum -= cardPoints[i - (n - k)];
				minSubarray = min(minSubarray, currSum);
			}
		}

		return totalSum - minSubarray;
	}
};
// @lc code=end

