/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
	unordered_map<string, pair<int, int>> timeNeed;
	unordered_map<int, pair<string, int>> travelRecord;
public:
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		travelRecord[id] = { stationName, t };
	}

	void checkOut(int id, string stationName, int t) {
		auto& [startStation, inTime] = travelRecord[id];
		auto& [count, totalTime] = timeNeed[startStation + "To" + stationName];
		count++;
		totalTime += (t - inTime);
		travelRecord.erase(id);
	}

	double getAverageTime(string startStation, string endStation) {
		const auto& [count, totalTime] = timeNeed[startStation + "To" + endStation];
		return (double)totalTime / count;
	}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end
