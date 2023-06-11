/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
	int id;
	vector<vector<pair<int, int>>> history;
public:
	SnapshotArray(int length) {
		id = 0;
		history.resize(length);
		for (int i = 0; i < length; i++)
			history[i].push_back({ 0, 0 });
	}

	void set(int index, int val) {
		history[index].push_back({ id, val });
	}

	int snap() {
		return id++;
	}

	int get(int index, int snap_id) {
		auto it = upper_bound(history[index].begin(), history[index].end(), pair<int, int>(snap_id, INT_MAX));
		it = prev(it);
		return it->second;
	}
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end
