/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution {
	/*
	 * Time Limit Exceeded
	 *   45/56 cases passed (N/A)
	 */
/*
	bool isSubset(string& str, vector<string>& ptrn) {
		for (auto& p : ptrn) {
			string s = str;
			for (auto& c : p) {
				auto found = s.find(c);
				if (found == string::npos)
					return false;
				// replace with '0' to prevent repeated match
				s.replace(found, 1, 1, '0');
			}
		}
		return true;
	}
public:
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
		vector<string> ans;
		for (int i = 0; i < words1.size(); i++)
			if (isSubset(words1[i], words2))
				ans.push_back(words1[i]);
		return ans;
	}
*/
	map<char, int> calculateOccurrences(string& str) {
		map<char, int> tmp;

		for (auto& ch : str) {
			auto it = tmp.find(ch);
			if (it == tmp.end())
				tmp.insert(pair<char, int>(ch, 1));
			else
				tmp[ch]++;
		}
		return tmp;
	}

	bool isSubset(map<char, int>& s, map<char, int>& p) {
		for (auto& pair : p) {
			auto it = s.find(pair.first);
			// character not found
			if (it == s.end())
				return false;
			// occurrence times not sufficient
			if (it->second < pair.second)
				return false;
		}
		return true;
	}

public:
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
		vector<string> ans;
		vector<map<char, int>> occurWords;
		map<char, int> occurSubstr, tmp;

		// calculate occurrence times vector for words1
		for (auto& str : words1)
			occurWords.push_back(calculateOccurrences(str));

		// calculate occurrence times for words2
		for (auto& str : words2) {
			tmp = calculateOccurrences(str);

			// merge all results into only one map
			for (auto& t : tmp) {
				auto it = tmp.find(t.first);

				// add this new character occurrence times
				if (it == tmp.end())
					occurSubstr.insert(*it);

				// update the occurrence times for this character
				if (occurSubstr[t.first] < t.second)
					occurSubstr[t.first] = t.second;
			}
		}

		for (int i = 0; i < occurWords.size(); i++)
			if (isSubset(occurWords[i], occurSubstr))
				ans.push_back(words1[i]);

		return ans;
	}
};
// @lc code=end

