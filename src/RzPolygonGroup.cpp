/*
 * RzPolygonGroup.cpp
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#include "RzPolygonGroup.h"

RzPolygonGroup::RzPolygonGroup() {
    // TODO Auto-generated constructor stub

}

RzPolygonGroup::RzPolygonGroup(const RzPolygonGroup& other) {
    deepCopy(other);
}

RzPolygonGroup::~RzPolygonGroup() {
    // TODO Auto-generated destructor stub
}

void RzPolygonGroup::deepCopy(const RzPolygonGroup& other) {
    color.deepCopy(other.color);
    polygons.resize(other.polygons.size());

    for (unsigned int i = 0; i < other.polygons.size(); ++i) {
        polygons[i].deepCopy(other.polygons[i]);
    }
}
