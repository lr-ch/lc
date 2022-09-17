/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *   78/136 cases passed (N/A)
 */
class SolutionTLE {
	bool isPalindrome(string& str) {
		for (int left = 0, right = str.length() - 1; left <= right; left++, right--)
			if (str[left] != str[right]) return false;
		return true;
	}
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> res;
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words.size(); j++) {
				if (i == j) continue;
				string tmp = words[i] + words[j];
				if (isPalindrome(tmp))
					res.push_back({i, j});
			}
		}
		return res;
	}
};

/*
 * Time Limit Exceeded
 *   134/136 cases passed (N/A)
 */
class SolutionByCase {
	bool isPalindrome(const string& str) {
		for (int left = 0, right = str.length() - 1; left <= right; left++, right--)
			if (str[left] != str[right]) return false;
		return true;
	}
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> res;
		unordered_map<string, int> word_idx;	// <word, index in words>
		for (int i = 0; i < words.size(); i++)
			word_idx[words[i]] = i;

		for (const auto& word : words) {
			// case.1 - if word is palindrome and there is "" in words
			if (!word.empty() && word_idx.count("") > 0 && isPalindrome(word)) {
				res.push_back({ word_idx[word], word_idx[""] });
				res.push_back({ word_idx[""], word_idx[word] });
			}

			// case.2 - if a reverse of word exists. e.g. "abc" -> "cba" exists
			string rword = string(word.rbegin(), word.rend());
			if (word_idx.count(rword) > 0 && word_idx[word] != word_idx[rword])
				res.push_back({ word_idx[word], word_idx[rword] });

			// case.3 - separate word into left/right parts, if any part is a palindrome
			//          and a reverse of the other part exists
			// e.g.1 "abcvv" -> "vv" is a palindrome and "cba" exists -> "abcvvcba"
			// e.g.2 "vvabc" -> "vv" is a palindrome and "cba" exists -> "cbavvabc"
			for (int j = 1; j < word.length(); j++) {
				string left = word.substr(0, j);
				string rleft = string(left.rbegin(), left.rend());
				string right = word.substr(j);
				string rright = string(right.rbegin(), right.rend());

				// "abcvv" + "cba"
				if (isPalindrome(right) && word_idx.count(rleft) > 0)
					res.push_back({ word_idx[word], word_idx[rleft] });

				// "cba" + "vvabc"
				if (isPalindrome(left) && word_idx.count(rright) > 0)
					res.push_back({ word_idx[rright], word_idx[word] });
			}
		}
		return res;
	}
};

/*
 * Ref: https://leetcode.com/problems/palindrome-pairs/discuss/2585494/C%2B%2B-or-Trie-or-Related-Problems
 */
class Solution {
	struct TrieNode {
		array<TrieNode*, 26> nodes;
		int index;
		vector<int> indices;

		TrieNode() : index(-1) {
			fill(nodes.begin(), nodes.end(), nullptr);
		}
	};

	void add(string &str, int i) {
		auto node = &root;
		for (int j = str.size() - 1; j >= 0; --j) {
			if (isPalindrome(str, 0, j)) node->indices.push_back(i);

			int c = str[j] - 'a';
			if (!node->nodes[c]) node->nodes[c] = new TrieNode();
			node = node->nodes[c];
		}
		node->index = i;
		node->indices.push_back(i);
	}

	bool isPalindrome(string& str, int left, int right) {
		for (int i = left, j = right; i < j; i++, j--)
			if (str[i] != str[j]) return false;
		return true;
	}

	TrieNode root;
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i) add(words[i], i);

		vector<vector<int>> ans;
		for (int i = 0; i < words.size(); ++i) {
			auto word = words[i];
			auto node = &root;
			for (int j = 0; j < word.size() && node; ++j) {
				if (node->index != -1 && node->index != i && isPalindrome(word, j, word.size() - 1))
					ans.push_back({ i, node->index });
				node = node->nodes[word[j] - 'a'];
			}

			if (!node) continue;

			for (int j : node->indices)
				if (i != j) ans.push_back({ i, j });
		}
		return ans;
	}
};
// @lc code=end
