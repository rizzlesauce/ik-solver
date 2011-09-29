/*
 * RzTriangle.cpp
 *
 *  Created on: May 1, 2010
 *      Author: ross
 */

#include "RzTriangle.h"

RzTriangle::RzTriangle() {
    // TODO Auto-generated constructor stub

}

RzTriangle::RzTriangle(const RzTriangle& other) {
    deepCopy(other);
}

RzTriangle::~RzTriangle() {
    // TODO Auto-generated destructor stub
}

void RzTriangle::deepCopy(const RzTriangle& other) {
    for (int i = 0; i < 3; ++i) {
        vertices[i].deepCopy(other.vertices[i]);
    }
}
