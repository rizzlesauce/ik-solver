/*
 * RobotArm.cpp
 *
 *  Created on: Jun 3, 2010
 *      Author: ross
 */

#include "RobotArm.h"

RobotArm::RobotArm() {
	// TODO Auto-generated constructor stub

	nextArm = NULL;
}

RobotArm *RobotArm::getNextArm() {
	return nextArm;
}

void RobotArm::setNextArm(RobotArm *arm) {
	nextArm = arm;
}

bool RobotArm::hasNextArm() {
	return nextArm != NULL;
}

RobotArm::~RobotArm() {
	// TODO Auto-generated destructor stub
	if (nextArm != NULL) {
		delete nextArm;
	}
}
