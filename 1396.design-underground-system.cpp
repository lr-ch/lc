/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
	map<pair<string, string>, vector<int>> timeNeed;
	unordered_map<int, pair<string, int>> travelRecord;
public:
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		travelRecord[id] = { stationName, t };
	}

	void checkOut(int id, string stationName, int t) {
		const auto& [startStation, inTime] = travelRecord[id];
		timeNeed[{ startStation, stationName }].push_back(t - inTime);
		travelRecord.erase(id);
	}

	double getAverageTime(string startStation, string endStation) {
		const auto& timeArray = timeNeed[{ startStation, endStation }];
		double totalTime = accumulate(timeArray.begin(), timeArray.end(), 0);
		return totalTime / timeArray.size();
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
