/*
 * RzMatrix.cpp
 *
 *  Created on: Jun 4, 2010
 *      Author: ross
 */

#include "RzMatrix.h"

RzMatrix::RzMatrix(int rows_, int columns_) : rows(rows_), columns(columns_) {
    // TODO Auto-generated constructor stub
    M = new float[rows_ * columns_];
}

RzMatrix::RzMatrix() : rows(0), columns(0), M(NULL) {
}

RzMatrix::RzMatrix(const RzMatrix& other) : rows(other.rows), columns(other.columns) {
    memcpy(M, other.M, (sizeof(float)*rows*columns));
}

void RzMatrix::resize(int rows_, int columns_) {
    rows = rows_;
    columns = columns_;
    freeMIfNULL();
    M = new float[rows_ * columns_];
}

int RzMatrix::cellIndex(int row, int col) const {
    return row * columns + col;
}

float *RzMatrix::cellPointer(int row, int col) const {
    return M + cellIndex(row, col);
}

float RzMatrix::cellValue(int row, int col) const {
    return *cellPointer(row, col);
}

void RzMatrix::setCellValue(int row, int col, float value) {
    *cellPointer(row, col) = value;
}

RzMatrix RzMatrix::transposeToStack() const {
    RzMatrix transposed(columns, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposed.setCellValue(j, i, cellValue(i, j));
        }
    }

    return transposed;
}

RzMatrix::~RzMatrix() {
    // TODO Auto-generated destructor stub
    freeMIfNULL();
}

RzVector RzMatrix::multiplyVectorToStack(RzVector &vector) const {
    // assert columns == vector.size
    RzVector result(rows);

    for (int row = 0; row < rows; ++row) {
        float sum = 0;
        for (int col = 0; col < columns; ++col) {
            sum += cellValue(row, col) * vector.itemValue(col);
        }
        result.setItemValue(row, sum);
    }

    return result;
}

void RzMatrix::freeMIfNULL() {
    if (M != NULL) {
        delete [] M;
    }
}
