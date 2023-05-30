/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
	bitset<1000001> table;
public:
	MyHashSet() {
		table = 0;
	}

	void add(int key) {
		table[key] = 1;
	}

	void remove(int key) {
		table[key] = 0;
	}

	bool contains(int key) {
		return table[key] == 1;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
