/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class SolutionArray {
public:
	int trap(vector<int>& height) {
		vector<int> left(height.size(), 0), right(height.size(), 0);

		int right_idx = height.size() - 1;

		left[0] = height[0];
		right[right_idx] = height[right_idx];

		for (int i = 1; i < height.size() - 1; i++) {
			left[i] = max(left[i - 1], height[i]);
			right[right_idx - i] = max(right[right_idx - i + 1], height[right_idx - i]);
		}

		int ans = 0;
		for (int j = 0; j < height.size(); j++) {
			int height_diff = min(left[j], right[j]);
			if (0 != height_diff)
				ans += height_diff - height[j];
		}

		return ans;
	}
};

class Solution2Ptr {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int l_max = 0, r_max = 0, ans = 0;
		while (left < right) {
			if (height[left] > height[right]) {
				height[right] >= r_max ?
					r_max = height[right] : ans += r_max - height[right];
				right--;
			} else {
				height[left] >= l_max ?
					l_max = height[left] : ans += l_max - height[left];
				left++;
			}
		}
		return ans;
	}
};

class Solution {
	SolutionArray solArray;
	Solution2Ptr sol2Ptr;

public:
	int trap(vector<int>& height) {
		return sol2Ptr.trap(height);
	}
};

// @lc code=end
