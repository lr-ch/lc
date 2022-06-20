/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
	int capacity_;
	// key-value pair
	list<pair<int, int>> list_;
	// key-<key-value> pair
	unordered_map<int, list<pair<int, int>>::iterator> map_;

public:
	LRUCache(int capacity) {
		capacity_ = capacity;
	}

	int get(int key) {
		auto iter = map_.find(key);
		if (iter != map_.end())	{
			// key found, move the item to front of cache
			list_.splice(list_.begin(), list_, iter->second);
			// return the value;
			return iter->second->second;
		}
		return -1;
	}

	void put(int key, int value) {
		auto iter = map_.find(key);
		if (iter != map_.end()) {
			// key found, update the value
			iter->second->second = value;
			// move the item to front of cache
			list_.splice(list_.begin(), list_, iter->second);
		} else {
			// key not found, insert new item to map and list
			// first of all, check the cache size
			if (list_.size() >= capacity_) {
				// remove the list tail from map and list
				map_.erase(list_.back().first);
				list_.pop_back();
			}

			// insert the <key, value> to front of list
			list_.push_front(pair(key, value));
			// insert the <key, <key, value>::iterator> to map
			map_.insert(pair(key, list_.begin()));
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

