/*
 * RobotArm.h
 *
 *  Created on: Jun 3, 2010
 *      Author: ross
 */

#ifndef ROBOTARM_H_
#define ROBOTARM_H_

#include <cstring>
#include "matrixmath.h"

class RobotArm {
public:
	RobotArm();
	virtual ~RobotArm();

	RobotArm *getNextArm();
	void setNextArm(RobotArm *arm);
	bool hasNextArm();

protected:
	RobotArm *nextArm;

};

#endif /* ROBOTARM_H_ */
