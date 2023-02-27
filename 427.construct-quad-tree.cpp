/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
	Node* dfs(vector<vector<int>>&g, int row0, int col0, int row1, int col1) {
		if (row0 > row1 || col0 > col1) return nullptr;

		int val = g[row0][col0], isLeaf = 1;
		for (int i = row0; i <= row1; i++)
			for (int j = col0; j <= col1; j++)
				if (g[i][j] != val) {
					isLeaf = 0;
					break;
				}

		if (1 == isLeaf) {
			return new Node(val == 1, true);
		} else {
			int midRow = (row0 + row1) / 2, midCol = (col0 + col1) / 2;

			return new Node(
				val == 1,
				false,
				dfs(g, row0, col0, midRow, midCol),				// topLeft
				dfs(g, row0, midCol + 1, midRow, col1),			// topRight
				dfs(g, midRow + 1, col0, row1, midCol),			// bottomLeft
				dfs(g, midRow + 1, midCol + 1, row1, col1));	// bottomRight
		}
	}

public:
	Node* construct(vector<vector<int>>& grid) {
		int row = grid.size(), col = grid[0].size();
		return dfs(grid, 0, 0, row - 1, col - 1);
	}
};
// @lc code=end

