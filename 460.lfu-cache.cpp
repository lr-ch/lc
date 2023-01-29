/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
	struct data {
		int key;
		int value;
		int freq;
		data(int k, int v, int f)
			: key(k), value(v), freq(f) {}
	};

	int size, used, minFreq;
	unordered_map<int, list<data>> freq_data;				// <freq, list of data>
	unordered_map<int, list<data>::iterator> key_data;		// <key, iterator of list of data>
public:
	LFUCache(int capacity) {
		size = capacity;
		used = 0;
		minFreq = 1;
	}

	int get(int key) {
		if (key_data.count(key) == 0) return -1;

		auto old_iter = key_data[key];
		int old_freq = old_iter->freq;
		int res = old_iter->value;

		freq_data[old_freq].erase(old_iter);
		freq_data[old_freq + 1].push_front(data(key, res, old_freq + 1));
		key_data[key] = freq_data[old_freq + 1].begin();

		if (old_freq + 1 < minFreq) minFreq = old_freq + 1;
		return res;
	}

	void put(int key, int value) {
		if (size == 0) return;

		auto old_iter = key_data.find(key);
		if (old_iter != key_data.end()) {
			int old_freq = old_iter->second->freq;
			freq_data[old_freq].erase(old_iter->second);
			freq_data[old_freq + 1].push_front(data(key, value, old_freq + 1));
			key_data[key] = freq_data[old_freq + 1].begin();

			if (old_freq + 1 < minFreq) minFreq = old_freq + 1;
		} else {
			if (used >= size) {
				/*
				 * note. freq_data[minFreq] could be empty! Because get() updates
				 *       freq_data[minFreq] as well. if freq_data[minFreq] is empty,
				 *       minFreq is going to be updated to 1 anyway, so it is fine
				 *       to use it freely as counter
				 */
				while (freq_data[minFreq].empty()) minFreq++;
				int del_key = freq_data[minFreq].back().key;
				freq_data[minFreq].pop_back();
				key_data.erase(del_key);
				used--;
			}
			freq_data[1].push_front(data(key, value, 1));
			key_data.insert(pair(key, freq_data[1].begin()));
			minFreq = 1;
			used++;
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
