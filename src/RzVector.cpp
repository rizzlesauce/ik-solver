/*
 * RzVector.cpp
 *
 *  Created on: Jun 4, 2010
 *      Author: ross
 */

#include "RzVector.h"
using namespace std;

RzVector::RzVector(int size_) : size(size_) {
	// TODO Auto-generated constructor stub
	M = new float[size_];
}

RzVector::RzVector() : size(0), M(NULL) {
}

RzVector::RzVector(const RzVector& other) : size(other.size) {
	memcpy(M, other.M, (sizeof(float)*size));
}

void RzVector::resize(int size_) {
	size = size_;
	freeMIfNULL();
	M = new float[size_];
}

float *RzVector::itemPointer(int index) const {
	return M + index;
}

float RzVector::itemValue(int index) const {
	return *itemPointer(index);
}

void RzVector::setItemValue(int index, float value) {
	*itemPointer(index) = value;
}

RzVector::~RzVector() {
	// TODO Auto-generated destructor stub
	freeMIfNULL();
}

void RzVector::freeMIfNULL() {
	if (M != NULL) {
		delete [] M;
	}
}

string RzVector::toString() {
	stringstream ss;
	ss << "(";
	for (int i = 0; i < size; ++i) {
		if (i != 0) {
			ss << ", ";
		}
		ss << itemValue(i);
	}
	ss << ")";
	return ss.str();
}
