/*
 * RzMatrix.h
 *
 *  Created on: Jun 4, 2010
 *      Author: ross
 */

#ifndef RZMATRIX_H_
#define RZMATRIX_H_

#include <cstring>
#include "RzVector.h"

class RzMatrix {
public:
	RzMatrix();
	RzMatrix(int, int);
	RzMatrix(const RzMatrix&);
	virtual ~RzMatrix();

	void resize(int rows_, int columns_);
	int cellIndex(int row, int column) const;
	float *cellPointer(int row, int column) const;
	float cellValue(int row, int column) const;
	void setCellValue(int row, int column, float value);
	void freeMIfNULL();

	RzMatrix transposeToStack() const;
	RzVector multiplyVectorToStack(RzVector &vector) const;

	int rows, columns;
	float *M;
};

#endif /* RZMATRIX_H_ */
