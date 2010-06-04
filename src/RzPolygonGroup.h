/*
 * RzPolygonGroup.h
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#ifndef RZPOLYGONGROUP_H_
#define RZPOLYGONGROUP_H_

#include <vector>
#include "RzPolygon.h"
#include "RzColor3f.h"

class RzPolygonGroup {
public:
	RzPolygonGroup();
	RzPolygonGroup(const RzPolygonGroup&);
	virtual ~RzPolygonGroup();
	void deepCopy(const RzPolygonGroup&);

	vector<RzPolygon> polygons;
	RzColor3f color;

};

#endif /* RZPOLYGONGROUP_H_ */
