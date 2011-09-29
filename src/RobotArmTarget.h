/*
 * RobotArmTarget.h
 *
 *  Created on: Jun 3, 2010
 *      Author: ross
 */

#ifndef ROBOTARMTARGET_H_
#define ROBOTARMTARGET_H_

#include "matrixmath.h"

class RobotArmTarget {
public:
    RobotArmTarget();
    virtual ~RobotArmTarget();

    POINT3D position;
    float size;
};

#endif /* ROBOTARMTARGET_H_ */
