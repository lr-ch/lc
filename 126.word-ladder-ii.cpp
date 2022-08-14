/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *  21/35 cases passed (N/A)
 */
class BruteForce {
	bool oneCharDiff(const string& a, const string& b) {
		int diff_count = 0;

		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i])
				diff_count++;
			if (diff_count > 1)
				return false;
		}
		return true;
	}

	void bt(string& target, map<string, bool>& opts, vector<string>& path) {
		// skip if path length is already longer than current length
		if (currentLength > 0 && path.size() > currentLength) return;

		if (path.back() == target) {
			if (currentLength > 0) {
				if (path.size() == currentLength) {
					ans.push_back(path);
				} else {
					// update current ladder length
					ans.clear();
					currentLength = path.size();
					ans.push_back(path);
				}
			} else {
				currentLength = path.size();
				ans.push_back(path);
			}
			return;
		}

		for (auto& p : opts) {
			if (p.second && oneCharDiff(p.first, path.back())) {
				p.second = false;
				path.push_back(p.first);
				bt(target, opts, path);
				path.pop_back();
				p.second = true;
			}
		}
	}

	vector<vector<string>> ans;
	int currentLength = 0;
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		map<string, bool> options;	// [word, selectable]
		for (auto& s : wordList)
			options.insert(pair<string, bool>(s, true));

		vector<string> path;
		path.push_back(beginWord);

		bt(endWord, options, path);

		return ans;
	}
};

class Solution {
	void retrieveAnswer(string& begin, string &end, map<string, vector<string>>& prt, vector<string>& cur) {
		if (begin == end) {
			res.push_back(vector<string>(cur.rbegin(), cur.rend()));
			return;
		}

		for (string& p : prt[end]) {
			cur.push_back(p);
			retrieveAnswer(begin, p, prt, cur);
			cur.pop_back();
		}
	}

	vector<vector<string>> res;

public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		set<string> dict(wordList.begin(), wordList.end());
		if (dict.count(endWord) == 0) return {};
		dict.erase(beginWord);
		dict.erase(endWord);

		map<string, int> steps{{beginWord, 1}};		// <string, steps needed>
		map<string, vector<string>> parents;		// <string A, strings which can generate string A>
		queue<string> node;
		node.push(beginWord);

		int step = 0, word_length = beginWord.length();
		bool found = false;

		while (!node.empty() && !found) {
			step++;
			for (int count = node.size(); count > 0; count--) {
				string node_word = node.front();
				node.pop();
				string word = node_word;	// make a copy
				for (int i = 0; i < word_length; i++) {
					// store i-th character
					char ch = word[i];
					for (int j = 'a'; j <= 'z'; j++) {
						word[i] = j;

						// found target
						if (word == endWord) {
							parents[word].push_back(node_word);
							found = true;
						} else {
							if (steps.count(word) && step < steps[word])
								parents[word].push_back(node_word);
						}

						// not in wordList
						if (dict.count(word) == 0) continue;

						// remove word from dict and expand to next level nodes
						dict.erase(word);
						node.push(word);
						steps[word] = steps[node_word] + 1;
						parents[word].push_back(node_word);
					}
					// restore i-th character
					word[i] = ch;
				}
			}
		}

		if (found) {
			vector<string> current{endWord};
			retrieveAnswer(beginWord, endWord, parents, current);
		}

		return res;
	}
};
// @lc code=end
