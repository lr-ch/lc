/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
	bitset<1001> memo;
	priority_queue<int, vector<int>, greater<int>> pq;
public:
	SmallestInfiniteSet() {
		for (int i = 1; i <= 1000; i++) {
			memo.set(i);
			pq.push(i);
		}
	}

	int popSmallest() {
		int res = pq.top();
		memo.reset(res);
		pq.pop();
		return res;
	}

	void addBack(int num) {
		if (!memo[num]) {
			memo.set(num);
			pq.push(num);
		}
	}
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
