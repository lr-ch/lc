/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
	array<int, 3> spaces;
public:
	ParkingSystem(int big, int medium, int small)
		: spaces({ big, medium, small }) {

	}

	bool addCar(int carType) {
		return spaces[carType - 1]-- > 0;
	}
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
