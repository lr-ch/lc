/*
 * @lc app=leetcode id=1845 lang=cpp
 *
 * [1845] Seat Reservation Manager
 */

// @lc code=start
class SeatManager {
	priority_queue<int, vector<int>, greater<>> avail;
public:
	SeatManager(int n) {
		for (int i = 1; i <= n; i++)
			avail.push(i);
	}

	int reserve() {
		int ret = avail.top(); avail.pop();
		return ret;
	}

	void unreserve(int seatNumber) {
		avail.push(seatNumber);
	}
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end
