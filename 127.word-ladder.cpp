/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *  25/50 cases passed (N/A)
 */
class BruteForce {
	bool oneCharDiff(const string& a, const string& b) {
		int count = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])
				count++;
			if (count > 1)
				return false;
		}
		return count == 1;
	}

	void bt(const string& target, map<string, bool>& opts, vector<string>& path) {
		// skip if length of path is longer than current path in res
		if (currentLength > 0 && path.size() > currentLength) return;

		if (path.back() == target) {
			currentLength = min((unsigned long)currentLength, path.size());
		}

		for (auto& opt : opts) {
			if (opt.second && oneCharDiff(opt.first, path.back())) {
				opt.second = false;
				path.push_back(opt.first);
				bt(target, opts, path);
				path.pop_back();
				opt.second = true;
			}
		}
	}

	int currentLength = INT_MAX;
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		map<string, bool> options;
		for (auto& i : wordList)
			options.insert(pair<string, bool>(i, true));

		vector<string> path;
		path.push_back(beginWord);

		bt(endWord, options, path);

		return currentLength == INT_MAX ? 0 : currentLength;
	}
};
/*
 * Accepted
 *   50/50 cases passed (761 ms)
 *   Your runtime beats 39.09 % of cpp submissions
 *   Your memory usage beats 65.07 % of cpp submissions (14.2 MB)
 */
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		set<string> dict(wordList.begin(), wordList.end());
		if (dict.count(endWord) == 0) return 0;

		queue<string> node;
		node.push(beginWord);
		int step = 0, word_length = beginWord.length();

		while (!node.empty()) {
			step++;
			for (int count = node.size(); count > 0; count--) {
				string node_word = node.front();
				node.pop();
				for (int i = 0; i < word_length; i++) {
					// store the i-th character
					char ch = node_word[i];

					for (int j = 'a'; j <= 'z'; j++) {
						node_word[i] = j;

						// found target
						if (node_word == endWord) return step + 1;

						// not in wordList
						if (dict.count(node_word) == 0) continue;

						// remove word from dict and expand to next level nodes
						dict.erase(node_word);
						node.push(node_word);
					}

					// restore the i-th character
					node_word[i] = ch;
				}
			}
		}

		return 0;
	}
};
// @lc code=end

