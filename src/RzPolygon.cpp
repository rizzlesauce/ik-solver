/*
 * RzPolygon.cpp
 *
 *  Created on: Apr 29, 2010
 *      Author: ross
 */

#include "RzPolygon.h"

RzPolygon::RzPolygon() {
    // TODO Auto-generated constructor stub

}

RzPolygon::RzPolygon(const RzPolygon& other) {
    deepCopy(other);
}

RzPolygon::~RzPolygon() {
    // TODO Auto-generated destructor stub
}

void RzPolygon::deepCopy(const RzPolygon& other) {
    vertices.resize(other.vertices.size());
    for (unsigned int i = 0; i < other.vertices.size(); ++i) {
        vertices[i].deepCopy(other.vertices[i]);
    }
}

/**
 * Get the triangles that make up this polygon.
 */
vector<RzTriangle> RzPolygon::getTriangles() {
    vector<RzTriangle> triangles;
    unsigned int vertexIndex;

    for (vertexIndex = 1; vertexIndex < vertices.size() - 1; ++vertexIndex) {
        RzTriangle triangle;
        // the first vertex is the first polygon vertex
        triangle.vertices[0].deepCopy(vertices[0]);
        // second triangle vertex
        triangle.vertices[1].deepCopy(vertices[vertexIndex]);
        // third triangle vertex
        triangle.vertices[2].deepCopy(vertices[vertexIndex + 1]);

        triangles.push_back(triangle);
    }

    return triangles;
}
