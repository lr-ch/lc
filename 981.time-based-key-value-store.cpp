/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
	map<string, map<int, string>> dict;
public:
	TimeMap() {
	}

	void set(string key, string value, int timestamp) {
		dict[key].insert(pair<int, string>(timestamp, value));
	}

	string get(string key, int timestamp) {
		for (int i = timestamp; i > 0; i--)
			if (dict[key].find(i) != dict[key].end())
				return dict[key][i];
		return "";
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
