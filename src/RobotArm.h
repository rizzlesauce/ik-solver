/*
 * RobotArm.h
 *
 *  Created on: Jun 3, 2010
 *      Author: ross
 */

#ifndef ROBOTARM_H_
#define ROBOTARM_H_

#include <cstring>
#include <cmath>
#include "matrixmath.h"

class RobotArm {
public:
    RobotArm(float, float, RobotArm *p_nextSegment = NULL);
    virtual ~RobotArm();

    RobotArm *getNextArm();
    void setNextArm(RobotArm *arm);
    void insertNextArm(RobotArm *arm);
    bool hasNextArm();
    void calculateEndPoint(VECTOR3D *beginPoint, float last_rotation);
    void removeNextSegment();

    float rotation;
    float length;

    POINT3D endPoint;

protected:
    RobotArm *nextArm;

};

#endif /* ROBOTARM_H_ */
