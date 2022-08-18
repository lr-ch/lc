/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
/*
 * Accepted
 *  * 33/33 cases passed (349 ms)
 *  * Your runtime beats 49.73 % of cpp submissions
 *  * Your memory usage beats 10.98 % of cpp submissions (83 MB)
 */
class PriorityQueue {
	struct PairCompare {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b){
			return a.second < b.second;
		}
	};

public:
	int minSetSize(vector<int>& arr) {
		// <number, occurrences of the number>
		map<int, int> occurTable;
		for (const int& i : arr)
			occurTable[i]++;

		// sort map by occurrences of the number
		// note: vector<pair<int, int>> and sort() will be faster?
		priority_queue <
			pair<int, int>,
			vector<pair<int, int>>,
			PairCompare> table;
		for (const auto& j : occurTable)
			table.emplace(j);

		const int arrSize = arr.size();
		int newArrSize = arrSize, res = 0;
		while (!table.empty()) {
			auto top = table.top();
			newArrSize -= top.second;
			res++;
			table.pop();
			if (newArrSize <= arrSize / 2)
				break;
		}
		return res;
	}
};

class Solution {
public:
	int minSetSize(vector<int>& arr) {
		// <number, occurrences of the number>
		map<int, int> occurTable;
		for (const int& i : arr)
			occurTable[i]++;

		vector<pair<int, int>> table;
		for (const auto& j : occurTable)
			table.push_back(j);
		sort(table.begin(), table.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
		});

		const int arrSize = arr.size();
		int newArrSize = arrSize, res = 0;
		for (int i = 0; i < table.size(); i++) {
			newArrSize -= table[i].second;
			res++;
			if (newArrSize <= arrSize / 2)
				break;
		}
		return res;
	}
};
// @lc code=end
