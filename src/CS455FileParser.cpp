/*
 * CS455FileParser.cpp
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#include "CS455FileParser.h"
#include "Utils.h"
#include "Debugger.h"
#include "Tokenizer.h"
#include <fstream>
#include <sstream>
using namespace std;

CS455FileParser::CS455FileParser() {
	// TODO Auto-generated constructor stub

}

CS455FileParser::~CS455FileParser() {
	// TODO Auto-generated destructor stub
}

RzPolygonGroupCollection *CS455FileParser::parseFile(const string fileName) {
	RzPolygonGroupCollection *collection = new RzPolygonGroupCollection;
	string fileType;
	string numPolygonGroupsString;
	int numPolygonGroups;
	string numPolygonsString;
	int numPolygons;
	stringstream stringStream;
	int polygonGroupIndex;
	int polygonIndex;
	int vertexIndex;
	int vertexComponentIndex;
	Tokenizer tokenizer;
	string vertexString;
	string polygonGroupColorString;
	string numVerticesString;
	int numVertices;
	int colorComponentIndex;

	// open the file
	ifstream fileStream(fileName.c_str());
	if (!fileStream.is_open()) {
		Debugger::getInstance().throwMessage("file couldn't be opened: " + fileName);
	}

	// get the file type
	fileStream >> fileType;

	if (fileType != "c") {
			// wrong file type
		Debugger::getInstance().throwMessage("wrong file type: " + fileType);
	}

	// get number of polygon groups
	fileStream >> numPolygonGroupsString;
	numPolygonGroups = Utils::getInstance().stoi(numPolygonGroupsString);
	//Debugger::getInstance().print("numPolygonGroups: " + Utils::getInstance().itos(numPolygonGroups));

	// get the polygon groups
	for (polygonGroupIndex = 0; polygonGroupIndex < numPolygonGroups; ++polygonGroupIndex) {
		RzPolygonGroup polygonGroup;

		// get the number of polygons
		fileStream >> numPolygonsString;
		numPolygons = Utils::getInstance().stoi(numPolygonsString);
		//Debugger::getInstance().print("numPolygons: " + Utils::getInstance().itos(numPolygons));

		// get each polygon
		for (polygonIndex = 0; polygonIndex < numPolygons; ++polygonIndex) {
			RzPolygon polygon;

			// get the number of vertices
			fileStream >> numVerticesString;
			numVertices = Utils::getInstance().stoi(numVerticesString);
			//Debugger::getInstance().print("numVertices: " + Utils::getInstance().itos(numVertices));

			// get the vertices
			//Debugger::getInstance().print("vertices: ");
			for (vertexIndex = 0; vertexIndex < numVertices; ++vertexIndex) {
				RzVertex3f vertex;

				/*
				vertexString = fileStream.getLinegetLine);
				//Debugger::getInstance().print("parsing string: " + vertexString);
				vector<string> vertexComponents = tokenizer.parse(vertexString);
				*/
				//Debugger::getInstance().print("vertex " + Utils::getInstance().itos(vertexIndex) + ": ");


				for (vertexComponentIndex = 0; vertexComponentIndex < 6; ++vertexComponentIndex) {
					//vertex.coordinates[vertexComponentIndex] = Utils::getInstance().stof(vertexComponents[vertexComponentIndex]);
					fileStream >> vertex.coordinates[vertexComponentIndex];

					//Debugger::getInstance().print(Utils::getInstance().ftos(vertex.coordinates[vertexComponentIndex]));
				}

				polygon.vertices.push_back(vertex);
			}

			polygonGroup.polygons.push_back(polygon);
		}

		/*
		// get the polygon group color
		fileStream >> polygonGroupColorString;
		vector<string> colorComponents = tokenizer.parse(polygonGroupColorString);
		*/
		//Debugger::getInstance().print("polygon group color: ");


		// get the color components
		for (colorComponentIndex = 0; colorComponentIndex < 3; ++colorComponentIndex) {
			/*
			polygonGroup.color.components[colorComponentIndex]
			        = Utils::getInstance().stof(colorComponents[colorComponentIndex]);
			        */
			fileStream >> polygonGroup.color.components[colorComponentIndex];
			//Debugger::getInstance().print(Utils::getInstance().ftos(polygonGroup.color.components[colorComponentIndex]));

		}

		// add the polygon group to the collection
		collection->polygonGroups.push_back(polygonGroup);
	}
	fileStream.close();

	return collection;
}
