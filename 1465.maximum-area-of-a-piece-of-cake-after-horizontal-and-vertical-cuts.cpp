/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
class Solution {
/*
 * Works, but TLE
 *
 * Time Limit Exceeded
 *   55/56 cases passed (N/A)
 */
/*
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		// h = 5, w = 4, hc = [1,2,4], vc = [1,3]
		// h = [1-0, 2-1, 4-2, 5-4], w = [1-0, 3-1, 4-3]
		// areas = w x h = [1,2,1, (h0 x w0, h0 x w1, h0 x w2)
		//                  1,2,1, (h1 x w0, h1 x w1, h1 x w2)
		//                  2,4,1, (h2 x w0, h2 x w1, h2 x w2)
		//                  1,2,1] (h3 x w0, h3 x w1, h3 x w2)
		horizontalCuts.push_back(0);
		verticalCuts.push_back(0);
		horizontalCuts.push_back(h);
		verticalCuts.push_back(w);

		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());

		long long maxArea = 0;
		for (int i = 1; i < horizontalCuts.size(); i++) {
			for (int j = 1; j < verticalCuts.size(); j++) {
				long long h = horizontalCuts[i] - horizontalCuts[i - 1];
				long long w = verticalCuts[j] - verticalCuts[j - 1];
				maxArea = max(maxArea, h * w);
			}
		}
		return maxArea % 1000000007;
	}
*/
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		horizontalCuts.push_back(0);
		verticalCuts.push_back(0);
		horizontalCuts.push_back(h);
		verticalCuts.push_back(w);

		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());

		int maxh = 0;
		for (int i = 1; i < horizontalCuts.size(); i++)
			maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i - 1]);

		int maxw = 0;
		for (int i = 1; i < verticalCuts.size(); i++)
			maxw = max(maxw, verticalCuts[i] - verticalCuts[i - 1]);

		return ((long long)maxh * (long long)maxw) % 1000000007;
	}
};
// @lc code=end

