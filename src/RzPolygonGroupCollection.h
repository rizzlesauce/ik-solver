/*
 * RzPolygonGroupCollection.h
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#ifndef RZPOLYGONGROUPCOLLECTION_H_
#define RZPOLYGONGROUPCOLLECTION_H_

#include <vector>
#include "RzPolygonGroup.h"

class RzPolygonGroupCollection {
public:
    RzPolygonGroupCollection();
    RzPolygonGroupCollection(const RzPolygonGroupCollection&);
    virtual ~RzPolygonGroupCollection();
    void deepCopy(const RzPolygonGroupCollection& other);

    vector<RzPolygonGroup> polygonGroups;
};

#endif /* RZPOLYGONGROUPCOLLECTION_H_ */
