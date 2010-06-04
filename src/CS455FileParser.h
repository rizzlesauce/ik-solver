/*
 * CS455FileParser.h
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#ifndef CS455FILEPARSER_H_
#define CS455FILEPARSER_H_

#include <string>
#include "RzPolygonGroupCollection.h"

class CS455FileParser {
public:
	CS455FileParser();
	virtual ~CS455FileParser();

	RzPolygonGroupCollection *parseFile(const std::string fileName);
};

#endif /* CS455FILEPARSER_H_ */
