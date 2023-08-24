/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res, cur_words;
		int cur_len = 0;

		for (const auto& w : words) {
			if (cur_len + w.length() + cur_words.size() > maxWidth) {
				int paddings = maxWidth - cur_len;
				int gaps = cur_words.size() - 1;
				if (gaps == 0) {
					res.push_back(cur_words[0] + string(paddings, ' '));
				} else {
					int average = paddings / gaps;
					int additional = paddings % gaps;
					string line;
					for (int i = 0; i < cur_words.size(); ++i) {
						line += cur_words[i];
						if (i < gaps) {
							line += string(average, ' ');
							if (i < additional) {
								line += ' ';
							}
						}
					}
					res.push_back(line);
				}
				cur_words.clear();
				cur_len = 0;
			}
			cur_words.push_back(w);
			cur_len += w.length();
		}

		string last_line;
		for (const string& w : cur_words) {
			if (!last_line.empty()) {
				last_line += ' ';
			}
			last_line += w;
		}
		last_line += string(maxWidth - last_line.length(), ' ');
		res.push_back(last_line);

		return res;
	}
};
// @lc code=end
