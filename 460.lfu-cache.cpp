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

		int old_freq = key_data[key]->freq;
		int res = key_data[key]->value;

		freq_data[old_freq].erase(key_data[key]);
		freq_data[old_freq + 1].push_front(data(key, res, old_freq + 1));
		key_data[key] = freq_data[old_freq + 1].begin();

		minFreq = freq_data[minFreq].empty() ? minFreq + 1 : minFreq;
		return res;
	}

	void put(int key, int value) {
		if (size == 0) return;

		if (key_data.find(key) != key_data.end()) {
			int old_freq = key_data.find(key)->second->freq;
			freq_data[old_freq].erase(key_data.find(key)->second);
			freq_data[old_freq + 1].push_front(data(key, value, old_freq + 1));
			key_data[key] = freq_data[old_freq + 1].begin();

			minFreq = freq_data[minFreq].empty() ? minFreq + 1 : minFreq;
		} else {
			if (used >= size) {
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
