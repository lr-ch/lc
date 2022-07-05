/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
	/*
	 * Time Limit Exceeded
	 *   34/38 cases passed (N/A)
	 */
/*
	void rotate(vector<int>& nums, int k) {
		while (k > 0) {
			int tmp_ = nums[nums.size() - 1];
			for (int i = nums.size() - 1; i > 0; i--)
				nums[i] = nums[i - 1];
			nums[0] = tmp_;
			k--;
		}
	}
*/
	/*
	 * Accepted
	 *   38/38 cases passed (64 ms)
	 *   Your runtime beats 13.83 % of cpp submissions
	 *   Your memory usage beats 9.22 % of cpp submissions (25.9 MB)
	 */
/*
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		vector<int> res(nums.end() - k, nums.end());
		res.insert(res.end(), nums.begin(), nums.end() - k);
		nums = res;
	}
*/
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		vector<int> rotated(size, 0);
		for (int i = 0; i < size; i++) {
		   /*
			* Example: [1,2,3,4,5,6,7]
			* rotated: [0,0,0,1,0,0,0]
			*          [0,0,0,1,2,0,0]
			*          [0,0,0,1,2,3,0]
			*          [0,0,0,1,2,3,4]
			*          [5,0,0,1,2,3,4]
			*          [5,6,0,1,2,3,4]
			*          [5,6,7,1,2,3,4]
			*/
			rotated[(i + k) % size] = nums[i];
		}
		nums = rotated;
	}
};
// @lc code=end

