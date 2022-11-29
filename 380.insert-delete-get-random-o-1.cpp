/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
	vector<int> record;
	map<int, int> indexOfRecord;	// <val, record index of val>
public:
	RandomizedSet() {
	}

	bool insert(int val) {
		if (indexOfRecord.count(val) == 0) {
			indexOfRecord[val] = record.size();
			record.push_back(val);
			return true;
		}
		return false;
	}

	bool remove(int val) {
		if (indexOfRecord.count(val)) {
			int index = indexOfRecord[val];

			// swap record[index] and record[record.size() - 1]
			indexOfRecord[record.back()] = index;
			swap(record[index], record.back());

			// remove original record[index]
			record.pop_back();
			indexOfRecord.erase(val);

			return true;
		}
		return false;
	}

	int getRandom() {
		return record[rand() % record.size()];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
