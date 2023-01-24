/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
	pair<int, int> label_to_coord(int n) {
		int row = N - n / N - 1;
		int col;

		if (N % 2)
			col = row % 2 ? N - (n % N) - 1 : n % N;
		else
			col = row % 2 ? n % N : N - (n % N) - 1;

		return { row, col };
	}

	int N, goal;
public:
	int snakesAndLadders(vector<vector<int>>& board) {
		N = board.size();
		goal = N * N - 1;

		vector<bool> visited(N * N, false);
		queue<int> square;
		square.push(0);		// start from board[N - 1][0]

		int move = 0;
		while (!square.empty()) {
			int qsize = square.size();
			move++;
			while (qsize--) {
				int curr = square.front();
				square.pop();
				visited[curr] = true;

				// check coord and decide next step
				for (int next = curr + 1; next <= min(curr + 6, goal); next++) {
					auto coord = label_to_coord(next);

					// NOTE!! Our board is 0-indiced, the board's label is 1-indiced
					int snake_ladder_next = board[coord.first][coord.second];

					if (snake_ladder_next == -1 && !visited[next])                          // no snake or ladder
						square.push(next);
					else if (snake_ladder_next != -1 && !visited[snake_ladder_next - 1])    // with snake or ladder
						square.push(snake_ladder_next - 1);

					if (square.back() == goal) return move;
				}
			}
		}

		return -1;
	}
};
// @lc code=end
