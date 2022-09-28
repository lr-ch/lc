/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class SolutionTwoPtr {
public:
	string pushDominoes(string dominoes) {
		int n = dominoes.length(), left = 0, right = 0;
		string ans(dominoes);

		for (right = 0; right < n; right++) {
            // do nothing to '.'
            if (ans[right] == '.')
                continue;

            if (ans[left] == ans[right] || (ans[left] == '.' && ans[right] == 'L')) {
				// case.1
				// if the direction is the same between (left, right), replace '.' with the direction
				// e.g. R...R -> RRRRR or L...L -> LLLLL
				// or if the left is '.' and right is L, replace '.' with L
				// e.g. ....L -> LLLLL
				for (int i = left; i < right; i++) ans[i] = ans[right];
			} else if (ans[left] == 'L' && ans[right] == 'R') {
				// case.2
				// do nothing
				// e.g. L...R -> L...R
			} else if (ans[left] == 'R' && ans[right] == 'L') {
				// case.3
				// calculate '.' between (left, right), replace the number of '.' to the closest direction
				//  a. odd, e.g. R...L, replace 3 / 2 = 1 with the 'R'/'L', -> RR.LL
				//  b. even, e.g. R..L, replace 2 / 2 = 1 with the 'R'/'L', -> RRLL
				int dot_num = right - left - 1;
				for (int i = 0; i < dot_num / 2; i++) {
					ans[left + 1 + i] = ans[left];
					ans[right - 1 - i] = ans[right];
				}
			}

            // advance left to right
			left = right;
		}
		// case.4
		// fill out 'R' to the end of string
		// e.g. ...R. -> ...RR
		if (ans[left] == 'R')
			for (int i = left; i < n; i++) ans[i] = 'R';

		return ans;
	}
};

class SolutionByForce {
public:
	string pushDominoes(string dominoes) {
		int n = dominoes.length(), force = 0;
		vector<int> rforce(n), lforce(n);

		// e.g. R.R...L, n = 7
		// rforce -> 7, 6, 7, 6, 5, 4, 0
		// lforce -> 0, 0, 0,-4,-5,-6,-7

		for (int i = 0; i < n; i++) {
			switch (dominoes[i]) {
				case 'R' :
					force = n;
					break;
				case 'L' :
					force = 0;
					break;
				default :
					force = max(force - 1, 0);
					break;
			}
			rforce[i] = force;
		}

		force = 0;
		for (int j = n - 1; j >= 0; j--) {
			switch (dominoes[j]) {
				case 'R' :
					force = 0;
					break;
				case 'L' :
					force = 0 - n;
					break;
				default :
					force = min(force + 1, 0);
					break;
			}
			lforce[j] = force;
		}

		string ans(n, '.');
		for (int k = 0; k < n; k++)
			if (rforce[k] + lforce[k] == 0) ans[k] = '.';
			else if (rforce[k] + lforce[k] < 0) ans[k] = 'L';
			else if (rforce[k] + lforce[k] > 0) ans[k] = 'R';
		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 43/43 cases passed (77 ms)
	 *  - Your runtime beats 48.18 % of cpp submissions
	 *  - Your memory usage beats 81.8 % of cpp submissions (14.6 MB)
	 */
	SolutionTwoPtr sol2ptr;

	/*
	 * Accepted
	 *  - 43/43 cases passed (67 ms)
	 *  - Your runtime beats 56.50 % of cpp submissions
	 *  - Your memory usage beats 28.60% % of cpp submissions (21.5 MB)
	 */
	SolutionByForce solForce;
public:
	string pushDominoes(string dominoes) {
		return sol2ptr.pushDominoes(dominoes);
	//	return solForce.pushDominoes(dominoes);
	}
};
// @lc code=end
