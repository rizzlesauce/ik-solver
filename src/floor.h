#ifndef floor_h
#define floor_h

#include "gltypes.h"


static const TEXTURED_VERTEX_DATA_3D floorVertexData[] = {
	{/*v:*/{1.000000, 1.000000, 0.000000}, /*n:*/{0.000000, 0.000000, 1.000000}, /*t:*/{-14.913949, -15.098986}},
	{/*v:*/{-1.000000, 1.000000, 0.000000}, /*n:*/{0.000000, 0.000000, 1.000000}, /*t:*/{16.654099, -15.098986}},
	{/*v:*/{-1.000000, -1.000000, 0.000000}, /*n:*/{0.000000, 0.000000, 1.000000}, /*t:*/{16.654099, 16.469061}},
	{/*v:*/{1.000000, 1.000000, 0.000000}, /*n:*/{0.000000, 0.000000, 1.000000}, /*t:*/{-14.913949, -15.098986}},
	{/*v:*/{-1.000000, -1.000000, 0.000000}, /*n:*/{0.000000, 0.000000, 1.000000}, /*t:*/{16.654099, 16.469061}},
	{/*v:*/{1.000000, -1.000000, 0.000000}, /*n:*/{0.000000, 0.000000, 1.000000}, /*t:*/{-14.913949, 16.469057}},
};

#define floorNumberOfVertices	6
// Drawing Code:
// glEnableClientState(GL_VERTEX_ARRAY);
// glEnableClientState(GL_TEXTURE_COORD_ARRAY);
// glEnableClientState(GL_NORMAL_ARRAY);
// glVertexPointer(3, GL_FLOAT, sizeof(TEXTURED_VERTEX_DATA_3D), &floorVertexData[0].vertex);
// glNormalPointer(GL_FLOAT, sizeof(TEXTURED_VERTEX_DATA_3D), &floorVertexData[0].normal);
// glTexCoordPointer(2, GL_FLOAT, sizeof(TEXTURED_VERTEX_DATA_3D), &floorVertexData[0].texCoord);
// glDrawArrays(GL_TRIANGLES, 0, floorNumberOfVertices);
// glDisableClientState(GL_VERTEX_ARRAY);
// glDisableClientState(GL_TEXTURE_COORD_ARRAY);
// glDisableClientState(GL_NORMAL_ARRAY);


#endif
