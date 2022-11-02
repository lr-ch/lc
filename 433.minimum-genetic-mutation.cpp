/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
	const array<char, 4> geneBit = { 'A', 'C', 'G', 'T' };
public:
	int minMutation(string start, string end, vector<string>& bank) {
		set<string> dict(bank.begin(), bank.end());
		if (dict.count(end) == 0) return -1;

		queue<string> node;
		node.push(start);

		int steps = 0;
		while (!node.empty()) {
			steps++;

			int qsize = node.size();
			while (qsize--) {
				string geneStr = node.front();
				node.pop();

				for (int i = 0; i < geneStr.length(); i++) {
					// preserve the original geneBit
					char old = geneStr[i];

					for (auto& ch : geneBit) {
						// sam as original gene, so skip this bit
						if (geneStr[i] == ch) continue;

						// replace i-th geneBit
						geneStr[i] = ch;

						// mutate successfully, return
						if (geneStr == end) return steps;

						// remove the gene from bank and expand to next level
						if (dict.count(geneStr)) {
							dict.erase(geneStr);
							node.push(geneStr);
						}
					}

					// restore original geneBit, try next bit
					geneStr[i] = old;
				}
			}
		}
		return -1;
	}
};
// @lc code=end

