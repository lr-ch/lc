/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
	priority_queue<int, vector<int>, greater<int>> small;	// min priority queue
	priority_queue<int> large;
public:
	MedianFinder() {
	}

	void addNum(int num) {
		// small trick to ensure no number in min priority queue larger than the other, and vice versa
		small.push(num);
		large.push(small.top());
		small.pop();

		// balance two queues
		if (large.size() > small.size()) {
			small.push(large.top());
			large.pop();
		}
	}

	double findMedian() {
		if (large.size() > small.size())
			return large.top();
		else if (large.size() < small.size())
			return small.top();
		return (large.top() + small.top()) / 2.0;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

