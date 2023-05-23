/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
	priority_queue<int, vector<int>, greater<>> pq;
	int Kth;
public:
	KthLargest(int k, vector<int>& nums) {
		Kth = k;
		for (const auto& n : nums) pq.push(n);
	}

	int add(int val) {
		pq.push(val);
		while (pq.size() > Kth) pq.pop();
		return pq.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
