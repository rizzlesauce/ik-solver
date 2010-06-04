/*
 * gltypes.h
 *
 *  Created on: May 28, 2010
 *      Author: ross
 */

#ifndef GLTYPES_H_
#define GLTYPES_H_

#include <SDL/SDL_opengl.h>

typedef struct TEXTURED_VERTEX_DATA_3D_TYPE {
	GLfloat vertex[3];
	GLfloat normal[3];
	GLfloat texCoord[2];
} TEXTURED_VERTEX_DATA_3D, *TEXTURED_VERTEX_DATA_3D_PTR;

#endif /* GLTYPES_H_ */
