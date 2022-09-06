/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *  - 53/60 cases passed (N/A)
 */
class SolutionTLE {
public:
	int maxArea(vector<int>& height) {
		int max_capacity = INT_MIN;
		for (int slow = 0; slow < height.size() - 1; slow++)
			for (int fast = slow + 1; fast < height.size(); fast++) {
				int capacity = min(height[slow], height[fast]) * (fast - slow);
				max_capacity = max(capacity, max_capacity);
			}
		return max_capacity;
	}
};

class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_capacity = INT_MIN, left = 0, right = height.size() - 1;
		while (left < right) {
			int capacity = min(height[left], height[right]) * (right - left);
			max_capacity = max(capacity, max_capacity);
			if (height[left] > height[right])
				right--;
			else
				left++;
		}
		return max_capacity;
	}
};
// @lc code=end
