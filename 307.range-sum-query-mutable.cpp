/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
	/*
	 * Time Limit Exceeded
	 *   11/15 cases passed (N/A)
	 */
class PrefixSum {
	array<long long, 30001> prSum;

public:
	void NumArray(vector<int>& nums) {
		prSum[0] = 0;
		for (int i = 0; i < nums.size(); i++)
			prSum[i + 1] = prSum[i] + nums[i];
	}

	void update(int index, int val) {
		int diff = val - (prSum[index + 1] - prSum[index]);
		for (int i = index + 1; i < prSum.size(); i++)
			prSum[i] = prSum[i] + diff;
	}

	int sumRange(int left, int right) {
		return prSum[right + 1] - prSum[left];
	}
};
	/*
	 * Accepted
	 *   15/15 cases passed (964 ms)
	 *   Your runtime beats 8.02 % of cpp submissions
	 *   Your memory usage beats 98.82 % of cpp submissions (149.8 MB)
	 */
class SqrtBlockSum {
	vector<int> nums_, blocksum_;
	int length;
public:
	void NumArray(vector<int>& nums) {
		nums_ = nums;
		length = ceil(nums_.size() / sqrt(nums_.size()));
		blocksum_.assign(length, 0);
		for (int i = 0; i < nums_.size(); i++)
			blocksum_[i / length] += nums_[i];
	}

	void update(int index, int val) {
		int target = index / length;
		blocksum_[target] = blocksum_[target] - nums_[index] + val;
		nums_[index] = val;
	}

	int sumRange(int left, int right) {
		int sum = 0;
		int start = left / length, end = right / length;

		if (start == end) {
			for (int i = left; i <= right; i++)
				sum += nums_[i];
		} else {
			for (int i = left; i <= (start + 1) * length - 1; i++)
				sum += nums_[i];
			for (int i = start + 1; i <= end - 1; i++)
				sum += blocksum_[i];
			for (int i = end * length; i <= right; i++)
				sum += nums_[i];
		}
		return sum;
	}
};
	/*
	 * Accepted
	 *   15/15 cases passed (694 ms)
	 *   Your runtime beats 51.17 % of cpp submissions
	 *   Your memory usage beats 57.73 % of cpp submissions (152.1 MB)
	 */
class SegmentTree {
	int merge(int a, int b) {
		return a + b;
	}

	void buildSegTree(vector<int>& v, int index, int left, int right) {
		if (left == right) {
			tree[index] = v[left];
			return;
		}

		int mid = left + (right - left) / 2;
		buildSegTree(v, 2 * index + 1, left, mid);
		buildSegTree(v, 2 * index + 2, mid + 1, right);

		tree[index] = merge(tree[2 * index + 1], tree[2 * index + 2]);
	}

	int querySegTree(int index, int lo, int hi, int left, int right) {
		// outside the range
		if (lo > right || hi < left) return 0;

		// segment completely inside range
		if (left <= lo && right >= hi) return tree[index];

		int mid = lo + (hi - lo) / 2;
		if (left > mid)
			return querySegTree(2 * index + 2, mid + 1, hi, left, right);
		else if (right <= mid)
			return querySegTree(2 * index + 1, lo, mid, left, right);

		int leftQuery = querySegTree(2 * index + 1, lo, mid, left, mid);
		int rightQuery = querySegTree(2 * index + 2, mid + 1, hi, mid + 1, right);

		return merge(leftQuery, rightQuery);
	}

	void updateValSegTree(int index, int lo, int hi, int valIndex, int val) {
		if (lo == hi) {
			tree[index] = val;
			return;
		}

		int mid = lo + (hi - lo) / 2;
		if (valIndex > mid)
			updateValSegTree(2 * index + 2, mid + 1, hi, valIndex, val);
		else if (valIndex <= mid)
			updateValSegTree(2 * index + 1, lo, mid, valIndex, val);

		tree[index] = merge(tree[2 * index + 1], tree[2 * index + 2]);
	}

	vector<int> tree;
	int length;
public:
	void NumArray(vector<int>& nums) {
		tree.assign(4 * nums.size(), 0);
		length = nums.size();
		buildSegTree(nums, 0, 0, length - 1);
	}

	void update(int index, int val) {
		updateValSegTree(0, 0, length - 1, index, val);
	}

	int sumRange(int left, int right) {
		return querySegTree(0, 0, length - 1, left, right);
	}
};

class NumArray {
	// TLE
//	PrefixSum Solution;

	// two solutions, pick one to submit
//	SqrtBlockSum Solution;
	SegmentTree Solution;

public:
	NumArray(vector<int>& nums) {
		Solution.NumArray(nums);
	}

	void update(int index, int val) {
		Solution.update(index, val);
	}

	int sumRange(int left, int right) {
		return Solution.sumRange(left, right);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

