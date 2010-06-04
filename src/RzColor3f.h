/*
 * RzColor3f.h
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#ifndef RZCOLOR3F_H_
#define RZCOLOR3F_H_

class RzColor3f {
public:
	RzColor3f();
	RzColor3f(const RzColor3f&);
	virtual ~RzColor3f();
	void deepCopy(const RzColor3f&);

	float getRed();
	float getGreen();
	float getBlue();

	unsigned int getScaledRed();
	unsigned int getScaledGreen();
	unsigned int getScaledBlue();

	void setRed(float r);
	void setGreen(float g);
	void setBlue(float b);

	float components[3];
};

#endif /* RZCOLOR3F_H_ */
