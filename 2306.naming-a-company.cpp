/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 */

// @lc code=start
class SolutionTLE {
public:
	long long distinctNames(vector<string>& ideas) {
		int ans = 0;
		for (int i = 0; i < ideas.size(); i++) {
			for (int j = 0; j < ideas.size(); j++) {
				if (i == j) continue;

				string tmp1 = ideas[i];
				string tmp2 = ideas[j];

				swap(tmp1[0], tmp2[0]);
				if (find(ideas.begin(), ideas.end(), tmp1) == ideas.end() &&
						find(ideas.begin(), ideas.end(), tmp2) == ideas.end())
					ans++;
			}
		}

		return ans;
	}
};

class Solution {
	int countRepeatElems(const unordered_set<string>& A, const unordered_set<string>& B) {
		int count = 0;
		for (const auto& elem : A)
			if (B.count(elem)) count++;
		return count;
	}

public:
	long long distinctNames(vector<string>& ideas) {
		long long ans = 0;
		unordered_map<char, unordered_set<string>> memo;
		for (const auto& idea : ideas)
			memo[idea[0]].insert(idea.substr(1, idea.length() - 1));

		for (char prefixA = 'a'; prefixA <= 'z'; prefixA++) {
			for (char prefixB = 'a'; prefixB <= 'z'; prefixB++) {
				if (prefixA == prefixB) continue;

				int sizeOfSetA = memo[prefixA].size();
				int sizeOfSetB = memo[prefixB].size();
				int sizeOfRepeatSuffix = countRepeatElems(memo[prefixA], memo[prefixB]);

				ans += (sizeOfSetA - sizeOfRepeatSuffix) * (sizeOfSetB - sizeOfRepeatSuffix);
			}
		}

		return ans;
	}
};
// @lc code=end
