/*
 * RzPolygonGroupCollection.cpp
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#include "RzPolygonGroupCollection.h"

RzPolygonGroupCollection::RzPolygonGroupCollection() {
	// TODO Auto-generated constructor stub

}

RzPolygonGroupCollection::RzPolygonGroupCollection(const RzPolygonGroupCollection& other) {
	deepCopy(other);
}

RzPolygonGroupCollection::~RzPolygonGroupCollection() {
	// TODO Auto-generated destructor stub
}

void RzPolygonGroupCollection::deepCopy(const RzPolygonGroupCollection& other) {
	polygonGroups.resize(other.polygonGroups.size());
	for (unsigned int i = 0; i < other.polygonGroups.size(); ++i) {
		polygonGroups[i].deepCopy(other.polygonGroups[i]);
	}
}
