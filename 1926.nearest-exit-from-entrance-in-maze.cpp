/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int row = maze.size(), col = maze[0].size();	// boundary
		int steps = 0;

		maze[entrance[0]][entrance[1]] = '+';	// entrance is not exit

		queue<pair<int, int>> q;
		q.push({ entrance[0], entrance[1] });

		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto [y, x] = q.front();
				q.pop();

				// check boundary
				if ((y == 0 || y == row - 1 || x == 0 || x == col -1) &&
					steps != 0)		// impossible steps to be 0
					return steps;

				// go up
				if (y - 1 >= 0 && maze[y - 1][x] == '.') {
					maze[y - 1][x] = '+';		// prevent from revisiting here
					q.push({ y - 1, x });
				}
				// go down
				if (y + 1 < row && maze[y + 1][x] == '.') {
					maze[y + 1][x] = '+';
					q.push({ y + 1, x });
				}
				// go left
				if (x - 1 >= 0 && maze[y][x - 1] == '.') {
					maze[y][x - 1] = '+';
					q.push({ y, x - 1 });
				}
				// go right
				if (x + 1 < col && maze[y][x + 1] == '.') {
					maze[y][x + 1] = '+';
					q.push({ y, x + 1 });
				}
			}
			steps++;
		}
		return -1;
	}
};
// @lc code=end
