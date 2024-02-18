/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
class Solution {
public:
	int mostBooked(int n, vector<vector<int>>& meetings) {
		// free.top() -> lowest number of free room
		priority_queue<int, vector<int>, greater<>> free;
		// busy.top() -> the least (end time, number) of the room
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
		// freq[i] -> the frequency of room[i] being occupied
		vector<int> freq(n, 0);

		sort(meetings.begin(), meetings.end());

		// init free rooms
		for (int i = 0; i < n; i++) free.push(i);

		// the start time is current time, we always fast-forward the time to current meeting's start time
		for (const auto& m : meetings) {
			auto start = m[0], end = m[1];

			// re-count all busy meeting room, and move available rooms to free
			while (!busy.empty() && busy.top().first <= start) {
				free.push(busy.top().second);
				busy.pop();
			}

			// occupy a free room if available
			if (!free.empty()) {
				freq[free.top()]++;
				busy.push({ end, free.top() });
				free.pop();
			} else {
				// no free room available, fast-forward to a busy room with least end time
				freq[busy.top().second]++;
				busy.push({ busy.top().first + (end - start), busy.top().second });
				busy.pop();
			}
		}

		return distance(
					freq.begin(),
					max_element(freq.begin(), freq.end())
				);
	}
};
// @lc code=end
