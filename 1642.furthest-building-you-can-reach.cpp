/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// @lc code=start
class Solution {
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		// the most used bricks number is always on the top
		priority_queue<int> usedBrick;
		int i;
		for (i = 0; i < heights.size() - 1; i++) {
			// go ahead if the next one is equal or lower the current
			if (heights[i + 1] <= heights[i]) continue;

			int bricksToUse = heights[i + 1] - heights[i];
			if (bricks - bricksToUse >= 0) {
				// use brick to go next building
				bricks -= bricksToUse;
				usedBrick.push(bricksToUse);
				continue;
			}

			// bricks is not enough
			if (ladders > 0) {
				// check if we have usedBrick before, and make sure
				// the usedBrick is worth of replacing with ladder
				if (usedBrick.size() > 0 && usedBrick.top() > bricksToUse) {
					// restore the bricks from queue
					bricks += usedBrick.top();
					usedBrick.pop();
					// consume a ladder
					ladders--;
					// now use restored bricks to next building
					if (bricks > bricksToUse) {
						bricks -= bricksToUse;
						usedBrick.push(bricksToUse);
						continue;
					}
				}
				// if the usedBrick is not worthy for a ladder
				// or the restored bricks still not enough to proceed
				ladders--;
				continue;
			}

			// no ladders, no bricks
			break;
		}
		return i;
	}
};
// @lc code=end

