/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
	void verifyTable(int n) {
		for (int i = 0; i < n * n; i++) {
			cout << "(" << label_to_coord[i].first << ", " << label_to_coord[i].second << ") ";
			if ((i + 1) % n == 0) cout << endl;
		}
	}

	void genCoordTable(int N) {
		for (int row = N - 1, i = 0, reverse = 0; i < N; i++, row--) {
			for (int j = 0, col = 0; j < N; j++, col++)
				label_to_coord[i * N + j] = reverse ? pair<int, int>(row, N - 1 - col) : pair<int, int>(row, col);
			reverse = !reverse;
		}
	//	verifyTable(N);
	}

	int N, goal;
	array<pair<int, int>, 20 * 20> label_to_coord;
public:
	int snakesAndLadders(vector<vector<int>>& board) {
		N = board.size();
		goal = N * N - 1;

		genCoordTable(N);
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

				// check coord and decide next step
				for (int next = curr + 1; next <= min(curr + 6, goal); next++) {
					auto coord = label_to_coord[next];

					// NOTE!! Our board is 0-indiced, the board's label is 1-indiced
					int snake_ladder_next = board[coord.first][coord.second];

					if (snake_ladder_next == -1 && !visited[next]) {							// no snake or ladder
						square.push(next);
						visited[next] = true;
					} else if (snake_ladder_next != -1 && !visited[snake_ladder_next - 1]) {	// with snake or ladder
						square.push(snake_ladder_next - 1);
						visited[snake_ladder_next - 1] = true;
					}

					if (square.back() == goal) return move;
				}
			}
		}

		return -1;
	}
};
// @lc code=end
