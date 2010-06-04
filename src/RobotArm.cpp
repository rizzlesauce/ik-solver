/*
 * RobotArm.cpp
 *
 *  Created on: Jun 3, 2010
 *      Author: ross
 */

#include "RobotArm.h"

RobotArm::RobotArm(float p_length, float p_rotation, RobotArm *p_nextSegment) : length(p_length), rotation(p_rotation),
		nextArm(p_nextSegment) {
	// TODO Auto-generated constructor stub
	VECTOR3D_INITXYZ(&endPoint, 0, 0, 0);
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

void RobotArm::calculateEndPoint(VECTOR3D *beginPoint) {
	endPoint.x = length * cos(DEG_TO_RAD(rotation));
	endPoint.y = length * sin(DEG_TO_RAD(rotation));

	VECTOR3D_Add(beginPoint, &endPoint, &endPoint);
}

RobotArm::~RobotArm() {
	// TODO Auto-generated destructor stub
	if (nextArm != NULL) {
		delete nextArm;
	}
}
