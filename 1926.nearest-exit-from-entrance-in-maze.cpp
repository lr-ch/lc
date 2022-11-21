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

		queue<vector<int>> q;
		q.push(entrance);

		while (!q.empty()) {
			int qsize = q.size();
			for (int i = 0; i < qsize; i++) {
				vector<int> pos= q.front();
				q.pop();

				// check boundary
				if ((pos[0] == 0 || pos[0] == row - 1 ||
					pos[1] == 0 || pos[1] == col -1) &&
					steps != 0)		// impossible steps to be 0
					return steps;

				// go up
				if (pos[0] - 1 >= 0 && maze[pos[0] - 1][pos[1]] != '+') {
					maze[pos[0] - 1][pos[1]] = '+';		// prevent from revisiting here
					q.push({ pos[0] - 1, pos[1] });
				}
				// go down
				if (pos[0] + 1 < row && maze[pos[0] + 1][pos[1]] != '+') {
					maze[pos[0] + 1][pos[1]] = '+';
					q.push({ pos[0] + 1, pos[1] });
				}
				// go left
				if (pos[1] - 1 >= 0 && maze[pos[0]][pos[1] - 1] != '+') {
					maze[pos[0]][pos[1] - 1] = '+';
					q.push({ pos[0], pos[1] - 1 });
				}
				// go right
				if (pos[1] + 1 < col && maze[pos[0]][pos[1] + 1] != '+') {
					maze[pos[0]][pos[1] + 1] = '+';
					q.push({ pos[0], pos[1] + 1 });
				}
			}
			steps++;
		}
		return -1;
	}
};
// @lc code=end
