/*
 * RzVector.h
 *
 *  Created on: Jun 4, 2010
 *      Author: ross
 */

#ifndef RZVECTOR_H_
#define RZVECTOR_H_

#include <cstring>
#include <string>
#include <sstream>
using namespace std;

class RzVector {
public:
	RzVector();
	RzVector(int);
	RzVector(const RzVector&);
	virtual ~RzVector();

	void resize(int size_);
	float *itemPointer(int index) const;
	float itemValue(int index) const;
	void setItemValue(int index, float value);
	void freeMIfNULL();
	string toString();

	int size;
	float *M;
};

#endif /* RZVECTOR_H_ */
