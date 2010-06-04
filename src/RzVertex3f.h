/*
 * RZVertex3f.h
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#ifndef RZVERTEX3F_H_
#define RZVERTEX3F_H_

#include <string>

class RzVertex3f {
public:
	RzVertex3f();
	RzVertex3f(const RzVertex3f&);
	virtual ~RzVertex3f();

	float getX() const;
	float getY() const;
	float getZ() const;

	float getOrthoX() const;
	float getOrthoY() const;
	float getOrthoZ() const;

	void setX(float);
	void setY(float);
	void setZ(float);

	void setOrthoX(float);
	void setOrthoY(float);
	void setOrthoZ(float);


	void deepCopy(const RzVertex3f&);
	std::string toString() const;

	float coordinates[6];
	float screen_x, screen_y;
};

#endif /* RZVERTEX3F_H_ */
