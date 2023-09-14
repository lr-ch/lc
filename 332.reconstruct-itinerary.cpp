/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
	void traverse(const string &depart) {
		auto& dests = trips[depart];
		while (!dests.empty()) {
			const auto next = dests.top(); dests.pop();
			traverse(next);
		}
		order.push_back(depart);
	}

	unordered_map<
		string,
		priority_queue<
			string,
			vector<string>,
			greater<>
		>
	> trips;	// (departure, destinations)
	vector<string> order;
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		for (const auto& t : tickets) trips[t[0]].push(t[1]);

		// post order recursive
		traverse("JFK");

		// reverse to output
		return vector<string>(order.crbegin(), order.crend());
	}
};
// @lc code=end
