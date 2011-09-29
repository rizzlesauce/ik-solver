#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "CS455FileParser.h"
#include "RzPolygonGroupCollection.h"
#include "RzPolygonGroup.h"
#include "RzPolygon.h"
#include "RzTriangle.h"
#include "RzColor3f.h"
#include "RzVertex3f.h"
#include "Debugger.h"
#include "Utils.h"
#include "matrixmath.h"
#include "RobotArm.h"
#include "RobotArmTarget.h"
#include "sphere.h"
#include "cylinder.h"
#include "RzMatrix.h"
#include "RzVector.h"

using namespace std;

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

float interpolateComponent(float, float, float, float, float, float, float, float, float, float);
/* Prototype of our callback function */
void my_audio_callback(void *userdata, Uint8 *stream, int len);
Uint8 *bird_buffer = NULL;
Uint8 *bird_position = NULL;
Uint32 bird_length = 0;

RobotArm *firstArmSegment = NULL;
RobotArmTarget target;
float joint_size = 0.2f;

GLuint texture;

int mouse_x = 0;
int mouse_y = 0;

int quitButton = 0;
bool calculate_target = false;

// Keydown booleans
bool key[321];
CS455FileParser parser;

string modelFiles[] = { //"apple.dat",
        //"arm.dat",
        "armory.dat",
        "biplane.dat",
        "camaro.dat",
        //"monster.dat",
        //"skull.dat"
};
int numModels = 3;
int currentModelIndex = 1;

POINT4D light_pos = {-50.0f, 50.0f, 50.0f, 1.0f };
//POINT3D light_pos = {0.0f, 1.0f, 5.0f};
POINT4D relative_light_pos;
RzColor3f light_color;
RzColor3f ambient_light;
RzColor3f specular_highlight;
float phong_exponent = 10.0f;
float cube_rotation = 0;
float cube_rotation_amount = 10;
Uint32 cube_rotation_delay = 30;
Uint32 cube_rotation_duration = 600;
Uint32 cube_rotation_start_time = 0;
Uint32 cube_last_movement = 0;

//float eye_z, near_z, far_z, other_factor;
POINT3D camera_position = {0.0f, 0.0f, 20.0f};
POINT3D camera_target = {0.0f, 0.0f, 0.0f};
VECTOR3D camera_up = {0.0f, 1.0f, 0.0f};
float near_z = 0.1;
float far_z = 100;
float field_of_view = 45; // degrees

float move_amount = 0.1f;

//int numPointPlots = 0;
//int maxPointPlots = 0;
//int numScanLines = 0;
//int maxScanLines = 1000000000;
//int maxScanLines = 0;

RzPolygonGroupCollection *collection = NULL;
RzPolygonGroupCollection *perspectified;

// Process pending events
bool events() {
    stringstream ss;
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
        case SDL_KEYDOWN : key[event.key.keysym.sym] = true; break;
        case SDL_KEYUP   : key[event.key.keysym.sym] = false; break;
        case SDL_JOYAXISMOTION:  /* Handle Joystick Motion */
            if ((event.jaxis.value < -3200) || (event.jaxis.value > 3200)) {
                if (event.jaxis.axis == 0) {
                    // rotate the camera target

                } else if (event.jaxis.axis == 1) {
                    // move the camera toward the camera target
                    VECTOR3D target_vector = { camera_target.x - camera_position.x,
                            camera_target.y - camera_position.y,
                            camera_target.z - camera_position.z };
                    VECTOR3D_Normalize(&target_vector);
                    VECTOR3D_Scale(move_amount * -0.0001f * event.jaxis.value, &target_vector);
                    VECTOR3D_Add(&target_vector, &camera_position, &camera_position);
                }
                /*
                Debugger::getInstance().print("axis: " + Utils::getInstance().itos(event.jaxis.axis)
                        + ", value: " + Utils::getInstance().itos(event.jaxis.value));
                        */
            }
            break;
        case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
            if ( event.jbutton.button == 0 )
            {
                /* code goes here */
            }
            /*
            Debugger::getInstance().print("button down: " + Utils::getInstance().itos(event.jbutton.button));
            */
            // play the bird sound
            SDL_LockAudio();
            bird_position = bird_buffer;
            SDL_UnlockAudio();

            // start a little rotation animation on the cube
            cube_rotation_start_time = SDL_GetTicks();
            cube_last_movement = cube_rotation_start_time;
            break;
        case SDL_JOYBUTTONUP:  /* Handle Joystick Button Presses */
            if ( event.jbutton.button == quitButton )
            {
                /* code goes here */
                return false;
            }
            /*
            Debugger::getInstance().print("button up: " + Utils::getInstance().itos(event.jbutton.button));
            */
            break;
        case SDL_JOYHATMOTION:  /* Handle Hat Motion */
            /*
            if ( event.jhat.value & SDL_HAT_UP )
            {
                Debugger::getInstance().print("joystick hat up");
            }
            if ( event.jhat.value & SDL_HAT_LEFT )
            {
                Debugger::getInstance().print("joystick hat left");
            }
            if ( event.jhat.value & SDL_HAT_RIGHTDOWN )
            {
            }
            Debugger::getInstance().print("hat motion: " + Utils::getInstance().itos(event.jhat.value));
            */
            break;
        case SDL_MOUSEBUTTONUP:
            // convert mouse coordinates to camera space
            mouse_x = event.button.x;
            mouse_y = event.button.y;
            calculate_target = true;

            /*
            GLdouble model[16];
            GLdouble proj[16];
            GLint view[4];
            GLdouble objX, objY, objZ;
            glGetDoublev(GL_MODELVIEW_MATRIX, model);
            glGetDoublev(GL_PROJECTION_MATRIX, proj);
            glGetIntegerv(GL_VIEWPORT, view);

            gluUnProject(event.motion.x, event.motion.y, 0,
                    model, proj, view,
                    &objX, &objY, &objZ
                    );
            target.position.x = objX;
            target.position.y = objY;
            target.position.z = objZ;
            */

            break;
        case SDL_QUIT    : return false; break;
        }
    }
    return true;
}

void my_audio_callback(void *userdata, Uint8 *stream, int len) {
    if (bird_position != NULL) {
        // play the bird sound
        Uint32 length_to_go = bird_buffer + bird_length - bird_position;

        if (length_to_go == 0) {
            bird_position = NULL;
            return;
        }

        /* Mix as much data as possible */
        len = (len > length_to_go ? length_to_go : len);
        SDL_MixAudio(stream, bird_position, len, SDL_MIX_MAXVOLUME);
        bird_position += len;
    }
}

void swapPointers(void **v1, void **v2) {
    void *tmp_v = *v1;
    *v1 = *v2;
    *v2 = tmp_v;
}

int round1f(float f) {
    return floor(0.5 + f);
}

int intify(float f) {
    //return floor(f);
    return round1f(f);
    //return ceil(f);
}

float computeSlope2d(RzVertex3f *v1, RzVertex3f *v2) {
    float denominator = (float)(intify(v1->screen_x) - intify(v2->screen_x));
    float numerator = (float)(intify(v1->screen_y) - intify(v2->screen_y));

    float slope;

    slope = numerator / denominator;

    /*
    if (numerator == 0) {
        if (denominator == 0) {
            slope = 0;
        } else {
            if (denominator < 0) {
                slope = -slope;
            }
        }
    }
    */
    /*
    if (denominator == 0) {
        stringstream ss;
        ss << "denominator 0: slope: " << slope;
        Debugger::getInstance().print(ss.str());
    }
    */
    return slope;
}

float computeDelta2d(RzVertex3f *v1, RzVertex3f *v2) {
    float delta = 1.0f / computeSlope2d(v1, v2);
    return delta;
}

/*
bool compareVertexYs(RzVertex3f v1, RzVertex3f v2) {
    return v1.getY() < v2.getY();
}
*/

float interpolateComponent(float c1, float c2, float c3, float y1, float ys, float y2, float y3, float xa, float xs, float xb) {
    float ca, cb, cs;

    y1 = (float)intify(y1);
    ys = (float)intify(ys);
    y2 = (float)intify(y2);
    y3 = (float)intify(y3);
    xa = (float)intify(xa);
    xs = (float)intify(xs);
    xb = (float)intify(xb);

    ca = c1 - (c1 - c2) * (y1 - ys) / (y1 - y2);
    cb = c1 - (c1 - c3) * (y1 - ys) / (y1 - y3);
    cs = cb - (cb - ca) * (xb - xs) / (xb - xa);

    return cs;
}

string getModelPath(int modelIndex) {
    return "data/" + modelFiles[modelIndex];
}

void loadModel(int modelIndex) {
    if (collection == NULL) {

    } else {
        delete collection;
    }
    collection = parser.parseFile(getModelPath(modelIndex));
}


void main_loop_function()
{
    //vector<MATRIX4X4> matrices;
    unsigned int polygonGroupIndex;
    unsigned int polygonIndex;
    unsigned int triangleIndex;
    unsigned int vertexIndex;
    unsigned int x, y;
    RzPolygonGroup *polygonGroup;
    RzPolygon *polygon;
    RzTriangle *triangle;
    RzVertex3f *vertex3f;
    RzColor3f *color3f;
    //float boundingWidth;
    //float boundingHeight;
    //float scaleFactor;
    stringstream ss;
    RzVertex3f *midVertex, *topVertex, *bottomVertex;
    vector<RzTriangle> triangles;
    float slopeTopMid;
    float slopeTopBottom;
    float slopeMidBottom;

    // figure out which side is left and right
    // compare deltas
    float deltaTopMid;
    float deltaTopBottom;
    float deltaMidBottom;
    float scale_factor = 1.0f;
    float scale_amount = 0.05f;
    VECTOR4D vertex_vector, result_vector, normal_vector;
    MATRIX4X4 normal_transform_matrix,
        model_transform_matrix,
        result_4x4,
        transform_matrix,
        perspective_transform_matrix,
        light_transform_matrix;

    bool draw_triangles = false;

    //int lastNumScanLines = 0;

    float rotation = 0.0f;
    float rotation_amount = 0.05f;
    float cos_rot;
    float sin_rot;

    float angle_amount = 0.05f;

    float translate_x = 0.0f;
    float translate_y = 0.0f;
    float translate_z = 0.0f;
    float translate_amount = 0.5;

    //int mycount = RAND_RANGE(0, 30);

    VECTOR3D_INITXYZ(&target.position, 10, 10, 10);
    target.size = 0.1;

    // set up the arm
    firstArmSegment = new RobotArm(2.0f, 20.0f,
            new RobotArm(1.0f, 45.0f,
                    new RobotArm(0.7f, -20.0f)
            )
    );

    while(events())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //glTranslatef(0,0, -10);
        gluLookAt(camera_position.x, camera_position.y, camera_position.z,
                camera_target.x, camera_target.y, camera_target.z,
                camera_up.x, camera_up.y, camera_up.z);

//        // figure out the z-buffer value at the origin
//        POINT4D rasterPosition;
//        glRasterPos3f(0, 0, 0);
//        glGetFloatv(GL_CURRENT_RASTER_POSITION, rasterPosition.M);

        if (calculate_target) {
            GLdouble model[16];
            GLdouble proj[16];
            GLint view[4];
            GLdouble x1, y1, z1, x2, y2, z2;

            glGetDoublev(GL_MODELVIEW_MATRIX, model);
            glGetDoublev(GL_PROJECTION_MATRIX, proj);
            glGetIntegerv(GL_VIEWPORT, view);

            gluUnProject(mouse_x, WINDOW_HEIGHT - mouse_y, 0,
                    model, proj, view,
                    &x1, &y1, &z1
                    );
            gluUnProject(mouse_x, WINDOW_HEIGHT - mouse_y, 1.0,
                    model, proj, view,
                    &x2, &y2, &z2
                    );

            // figure out where the line intersects the x-y plane
            float xz_slope = (x2 - x1) / (z2 - z1);
            float x_intercept = x1 - xz_slope * z1;

            float yz_slope = (y2 - y1) / (z2 - z1);
            float y_intercept = y1 - yz_slope * z1;

            target.position.x = x_intercept;
            target.position.y = y_intercept;
            target.position.z = 0;

            calculate_target = false;
        }

            // draw target
        /*
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_QUADS);
        float sizeDiv2 = target.size / 2.0;
        glVertex3f(target.position.x - sizeDiv2, target.position.y + sizeDiv2, target.position.z);
        glVertex3f(target.position.x + sizeDiv2, target.position.y + sizeDiv2, target.position.z);
        glVertex3f(target.position.x + sizeDiv2, target.position.y - sizeDiv2, target.position.z);
        glVertex3f(target.position.x - sizeDiv2, target.position.y - sizeDiv2, target.position.z);
        glEnd();
        */
        glPushMatrix();
        glTranslatef(target.position.x, target.position.y, target.position.z);
        glScalef(joint_size, joint_size, joint_size);

        glColor3f(1.0, 0.0, 0.0);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glVertexPointer(3, GL_FLOAT, sizeof(VERTEX_DATA_3D), &sphereVertexData[0].vertex);
        glNormalPointer(GL_FLOAT, sizeof(VERTEX_DATA_3D), &sphereVertexData[0].normal);
        glDrawArrays(GL_TRIANGLES, 0, sphereNumberOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);

        glPopMatrix();

        /*
        ss.clear();
        ss << "target.position.z: " << target.position.z << endl;
        Debugger::getInstance().print(ss.str());
        */

        Uint32 ticks = SDL_GetTicks();
        if (ticks < cube_rotation_start_time + cube_rotation_duration) {
            // rotate cube if timing is right
            if (ticks - cube_last_movement >= cube_rotation_delay) {
                cube_last_movement = ticks;
                cube_rotation += cube_rotation_amount;
            }
        }

        // draw the arm segments
        RobotArm *arm_pointer = firstArmSegment;
        POINT3D lastPoint = { 0, 0, 0 };
        float lastAngle = 0.0;
        int numSegments = 0;

        while (arm_pointer != NULL) {
            ++numSegments;

            // draw a joint
            glPushMatrix();
            glTranslatef(lastPoint.x, lastPoint.y, lastPoint.z);
            glScalef(joint_size, joint_size, joint_size);

            glColor3f(0.0, 1.0, 0.0);
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_NORMAL_ARRAY);
            glVertexPointer(3, GL_FLOAT, sizeof(VERTEX_DATA_3D), &sphereVertexData[0].vertex);
            glNormalPointer(GL_FLOAT, sizeof(VERTEX_DATA_3D), &sphereVertexData[0].normal);
            glDrawArrays(GL_TRIANGLES, 0, sphereNumberOfVertices);
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_NORMAL_ARRAY);

            glPopMatrix();

            // draw the arm segment
            glPushMatrix();
            glTranslatef(lastPoint.x, lastPoint.y, lastPoint.z);
            glRotatef(lastAngle + arm_pointer->rotation, 0.0, 0.0, 1.0);

            glRotatef(90, 0.0, 1.0, 0.0);
            glScalef(0.1, 0.1, arm_pointer->length / 2.0);
            glTranslatef(0.0, 0.0, 1.0);

            glColor3f(0.8, 0.8, 0.8);
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_NORMAL_ARRAY);
            glVertexPointer(3, GL_FLOAT, sizeof(VERTEX_DATA_3D), &cylinderVertexData[0].vertex);
            glNormalPointer(GL_FLOAT, sizeof(VERTEX_DATA_3D), &cylinderVertexData[0].normal);
            glDrawArrays(GL_TRIANGLES, 0, cylinderNumberOfVertices);
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_NORMAL_ARRAY);

            glPopMatrix();

            // figure out position
            arm_pointer->calculateEndPoint(&lastPoint, lastAngle);
            VECTOR3D_COPY(&lastPoint, &arm_pointer->endPoint);
            lastAngle = lastAngle + arm_pointer->rotation;

            arm_pointer = arm_pointer->getNextArm();
        }
        // draw the grabber
        glPushMatrix();
        glTranslatef(lastPoint.x, lastPoint.y, lastPoint.z);
        glScalef(joint_size, joint_size, joint_size);

        glColor3f(0.0, 0.0, 1.0);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glVertexPointer(3, GL_FLOAT, sizeof(VERTEX_DATA_3D), &sphereVertexData[0].vertex);
        glNormalPointer(GL_FLOAT, sizeof(VERTEX_DATA_3D), &sphereVertexData[0].normal);
        glDrawArrays(GL_TRIANGLES, 0, sphereNumberOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);

        glPopMatrix();

        // move the arm in order to get to the target
        VECTOR3D targetVector = VECTOR3D_Sub(&target.position, &lastPoint);
        float distance = VECTOR3D_Length(&targetVector);
        VECTOR3D_Normalize(&targetVector);
        VECTOR3D_Scale(max(distance, 0.3f) / numSegments, &targetVector);

        /*
        POINT3D normalEndPoint = VECTOR3D_Add(&lastPoint, &targetVector);
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z);
        glVertex3f(normalEndPoint.x, normalEndPoint.y, normalEndPoint.z);
        glEnd();
        */

        VECTOR3D lastBegin = {0, 0, 0};
        arm_pointer = firstArmSegment;
        RzMatrix jacobian(numSegments, 2);
        int i = 0;

        while (arm_pointer != NULL) {
            VECTOR3D effectorVector = VECTOR3D_Sub(&lastPoint, &lastBegin);

            //VECTOR3D axisOfRotation = {lastBegin.x, lastBegin.y, 1.0f};
            VECTOR3D axisOfRotation = {0, 0, 1};
            VECTOR3D entry = VECTOR3D_Cross(&axisOfRotation, &effectorVector);

            jacobian.setCellValue(i, 0, entry.x);
            jacobian.setCellValue(i, 1, entry.y);

            /*
            VECTOR3D endPoint = VECTOR3D_Add(&lastBegin, &entry);

            glBegin(GL_LINES);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f(lastBegin.x, lastBegin.y, lastBegin.z);
            glVertex3f(endPoint.x, endPoint.y, endPoint.z);
            glEnd();
            */

            VECTOR3D_COPY(&lastBegin, &arm_pointer->endPoint);
            arm_pointer = arm_pointer->getNextArm();
            ++i;
        }

        RzVector rzVector(2);
        rzVector.setItemValue(0, targetVector.x);
        rzVector.setItemValue(1, targetVector.y);

        RzVector changes = jacobian.multiplyVectorToStack(rzVector);
        //Debugger::getInstance().print(changes.toString() + "\n");

        if (distance > 0.1) {
            i = 0;
            arm_pointer = firstArmSegment;
            while (arm_pointer != NULL) {
                //arm_pointer->rotation += distance * 0.01 / changes.itemValue(i);
                arm_pointer->rotation += changes.itemValue(i);
                arm_pointer = arm_pointer->getNextArm();
                ++i;
            }
        }

        //glRotatef(rotation, 0, 1, 0);
        //glBegin(GL_POINTS);
        //glBegin(GL_TRIANGLES);

//
//        glBegin(GL_TRIANGLES);
//        glColor3f(1.0, 0, 0);
//        glVertex2f(200, 200);
//        glColor3f(0, 1.0, 0);
//        glVertex2f(500, 300);
//        glColor3f(0, 0, 1.0);
//        glVertex2f(300, 600);
//        glEnd();
//
//        SDL_GL_SwapBuffers();
//
//        continue;

            //numPointPlots = 0;
        //numScanLines = 0;

        // create the perspectified version of the model
        perspectified = new RzPolygonGroupCollection(*collection);
        for (polygonGroupIndex = 0; polygonGroupIndex < perspectified->polygonGroups.size(); ++polygonGroupIndex) {
            polygonGroup = &perspectified->polygonGroups[polygonGroupIndex];
            color3f = &polygonGroup->color;

            // set the color
            glColor3f(color3f->getRed(),
                    color3f->getGreen(),
                    color3f->getBlue());

            // draw the polygons
            for (polygonIndex = 0; polygonIndex < polygonGroup->polygons.size(); ++polygonIndex) {
                polygon = &polygonGroup->polygons[polygonIndex];

                triangles = polygon->getTriangles();

                // get the triangles
                for (triangleIndex = 0; triangleIndex < triangles.size(); ++triangleIndex) {

                        // draw the triangle vertices
                    triangle = &triangles[triangleIndex];
                    // scan line convert

                    /*
                    glBegin(GL_TRIANGLES);
                    //glColor3f(1.0, 0, 0);
                    glVertex3f(triangle->vertices[0].getX(),
                            triangle->vertices[0].getY(),
                            triangle->vertices[0].getZ());
                    //glColor3f(0, 1.0, 0);
                    glVertex3f(triangle->vertices[1].getX(),
                            triangle->vertices[1].getY(),
                            triangle->vertices[1].getZ());
                    //glColor3f(0, 0, 1.0);
                    glVertex3f(triangle->vertices[2].getX(),
                            triangle->vertices[2].getY(),
                            triangle->vertices[2].getZ());
                    glEnd();
                    */
//
//                    break;
                }
            }
        }

        /*
        // draw the color buffer
        glBegin(GL_POINTS);
        for (x = 0; x < WINDOW_WIDTH; ++x) {
            for (y = 0; y < WINDOW_HEIGHT; ++y) {
                // set the color
                glColor3f(colorBuffer[x][y].getRed(),
                        colorBuffer[x][y].getGreen(),
                        colorBuffer[x][y].getBlue());

                //glVertex3f((float)x, (float)y, 0.5);
                glVertex2f((float)x, (float)y);

            }
        }
        glEnd();
        */

        SDL_GL_SwapBuffers();
        // Check keypresses
        if(key[SDLK_RIGHT]) {
            //++maxPointPlots;
            //++maxScanLines;
            //angle-=0.5;

            // move camera around origin
            //angle += angle_amount;

            cos_rot = cos(angle_amount);
            sin_rot = sin(angle_amount);

            MATRIX3X3 rotate_matrix = {
                    cos_rot, 0, sin_rot,
                    0, 1, 0,
                    -sin_rot, 0, cos_rot};

            VECTOR3D result_3d;

            Mat_Mul_3X3_VECTOR3D(&rotate_matrix, &camera_position, &result_3d);
            VECTOR3D_COPY(&camera_position, &result_3d);
        }
        if(key[SDLK_LEFT]) {
            //--maxPointPlots;
            //--maxScanLines;
            //angle+=0.5;
            //rotation += 0.05;

            // move camera around origin
            //angle -= angle_amount;

            cos_rot = cos(-angle_amount);
            sin_rot = sin(-angle_amount);

            MATRIX3X3 rotate_matrix = {
                    cos_rot, 0, sin_rot,
                    0, 1, 0,
                    -sin_rot, 0, cos_rot};

            VECTOR3D result_3d;

            Mat_Mul_3X3_VECTOR3D(&rotate_matrix, &camera_position, &result_3d);
            VECTOR3D_COPY(&camera_position, &result_3d);
        }
        if (key[SDLK_UP]) {
            //zAdd += 10.0;
            //Debugger::getInstance().print("up key");

            // move the camera toward the camera target
            VECTOR3D target_vector = { camera_target.x - camera_position.x,
                    camera_target.y - camera_position.y,
                    camera_target.z - camera_position.z };
            VECTOR3D_Normalize(&target_vector);
            VECTOR3D_Scale(move_amount, &target_vector);
            VECTOR3D_Add(&target_vector, &camera_position, &camera_position);
        }
        if (key[SDLK_DOWN]) {
            //zAdd -= 10.0;
            //Debugger::getInstance().print("down key");
            VECTOR3D target_vector = { camera_target.x - camera_position.x,
                    camera_target.y - camera_position.y,
                    camera_target.z - camera_position.z };
            VECTOR3D_Normalize(&target_vector);
            VECTOR3D_Scale(-move_amount, &target_vector);
            VECTOR3D_Add(&target_vector, &camera_position, &camera_position);
        }
        if (key[SDLK_a]) {
            rotation += rotation_amount;
        }
        if (key[SDLK_s]) {
            rotation -= rotation_amount;
        }
        if (key[SDLK_z]) {
            scale_factor -= scale_amount;
        }
        if (key[SDLK_x]) {
            scale_factor += scale_amount;
        }
        if (key[SDLK_u]) {
            /*
            ss.clear();
            ss << "translate toward negative x: " << translate_x << endl;
            Debugger::getInstance().print(ss.str());
            */
            translate_x -= translate_amount;
        }
        if (key[SDLK_j]) {
            /*
            ss.clear();
            ss << "translate toward positive x: " << translate_x << endl;
            Debugger::getInstance().print(ss.str());
            */
            translate_x += translate_amount;
        }
        if (key[SDLK_k]) {
            translate_y -= translate_amount;
        }
        if (key[SDLK_i]) {
            translate_y += translate_amount;
        }
        if (key[SDLK_o]) {
            translate_z -= translate_amount;
        }
        if (key[SDLK_l]) {
            translate_z += translate_amount;
        }
        if (key[SDLK_t]) {
            draw_triangles = !draw_triangles;
        }
        if (key[SDLK_m]) {
            RobotArm *arm = firstArmSegment;
            while (arm->hasNextArm()) {
                arm = arm->getNextArm();
            }

            arm->setNextArm(new RobotArm(RAND_RANGE_FLOAT(0.5, 2.0, 1000), 0.0));
        }
        if (key[SDLK_n]) {
            RobotArm *arm = firstArmSegment;
            while (arm->hasNextArm() && arm->getNextArm()->hasNextArm()) {
                arm = arm->getNextArm();
            }

            arm->removeNextSegment();
        }
        delete perspectified;
    }
}

// Initialze OpenGL perspective matrix
void GL_Setup(int width, int height)
{
    /*
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    */

    //Load Bitmap

    /* Standard OpenGL texture creation code */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    // select modulate to mix texture with color for shading
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //change the texture matrix to flip and mirror
    glMatrixMode(GL_TEXTURE);
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
    glScalef(-1.0f, 1.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);

    light_color.setRed(1.0f);
    light_color.setGreen(1.0f);
    light_color.setBlue(1.0f);

    ambient_light.setRed(0.0f);
    ambient_light.setGreen(0.0f);
    ambient_light.setBlue(0.0f);

    specular_highlight.setRed(1.0f);
    specular_highlight.setGreen(1.0f);
    specular_highlight.setBlue(1.0f);

    GLfloat main_light_color[] = {light_color.getRed(), light_color.getGreen(), light_color.getBlue(), 1.0f};
    GLfloat main_ambient_light[] = {ambient_light.getRed(), ambient_light.getGreen(), ambient_light.getBlue(), 1.0f};
    GLfloat main_specular_highlight[] = {specular_highlight.getRed(), specular_highlight.getGreen(), specular_highlight.getBlue(), 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos.M);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, main_light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, main_ambient_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, main_specular_highlight);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //glColorMaterial(GL_FRONT, GL_DIFFUSE);

    //GLfloat material_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    //glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);

    GLfloat material_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //GLfloat material_specular[] = { 0.2f, 0.2f, 0.2f, 0.2f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);

    GLfloat material_shininess[] = { 45.0f };
    //GLfloat material_shininess[] = { 60.0f };
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

    glClearColor(0.3, 0.3, 1.0, 0.0);
    glShadeModel(GL_SMOOTH);

    //glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0, width, height, 0, 0, 1);
    gluPerspective(field_of_view, (float)width/height, near_z, far_z);

    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //glTranslatef(0.375, 0.375, 0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

int main(int argc, char *argv[]) {
    // Initialize SDL with best video mode
    stringstream ss;

    SDL_AudioSpec wav_spec;
    Uint32 wav_length;
    Uint8 *wav_buffer = NULL;

    SDL_AudioCVT  wav_cvt;
    int ret;

    /* Open the audio device */
    SDL_AudioSpec *desired, *obtained;
    SDL_AudioSpec *hardware_spec = NULL;

    SDL_Joystick *joystick = NULL;

    try {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK);

        /* Allocate a desired SDL_AudioSpec */
        desired = (SDL_AudioSpec*)malloc(sizeof(SDL_AudioSpec));

        /* Allocate space for the obtained SDL_AudioSpec */
        obtained = (SDL_AudioSpec*)malloc(sizeof(SDL_AudioSpec));

        //desired->freq=22050;
        desired->freq=44100;

        /* 16-bit signed audio */
        desired->format=AUDIO_S16SYS;

        /* Mono */
        desired->channels=2;

        /* Large audio buffer reduces risk of dropouts but increases response time */
        //desired->samples=8192;
        desired->samples=2048;

        /* Our callback function */
        desired->callback=my_audio_callback;

        desired->userdata=NULL;

        /* Open the audio device */
        if (SDL_OpenAudio(desired, obtained) < 0) {
            ss.clear();
            ss << "Couldn't open audio: " << SDL_GetError() << endl;
            throw ss.str();
        }
        /* desired spec is no longer needed */
        free(desired);

        hardware_spec=obtained;
        Debugger::getInstance().print("Audio hardware:\nfreq: " + Utils::getInstance().itos(hardware_spec->freq) +
                "\n" +
                "channels: " + Utils::getInstance().itos(hardware_spec->channels) +
                "\n" +
                "samples: " + Utils::getInstance().itos(hardware_spec->samples) +
                "\n"
                );

        /* Load the WAV */
        if (SDL_LoadWAV("data/bird.wav", &wav_spec, &wav_buffer, &wav_length) == NULL) {
            ss.clear();
            ss << "Could not open test.wav: " << SDL_GetError() << endl;
            throw ss.str();
        }

        /* Build AudioCVT */
        ret = SDL_BuildAudioCVT(&wav_cvt,
                                wav_spec.format, wav_spec.channels, wav_spec.freq,
                                hardware_spec->format, hardware_spec->channels, hardware_spec->freq);

        /* Check that the convert was built */
        if (ret == -1) {
            ss.clear();
            ss << "Couldn't build converter!" << endl;
            throw ss.str();
        }

        /* Setup for conversion, copy original data to new buffer*/
        wav_cvt.buf = (Uint8*)malloc(wav_length * wav_cvt.len_mult);
        wav_cvt.len = wav_length;
        memcpy(wav_cvt.buf, wav_buffer, wav_length);

        /* We can delete to original WAV data now */
        SDL_FreeWAV(wav_buffer);

        /* And now we're ready to convert */
        SDL_ConvertAudio(&wav_cvt);
        bird_buffer = wav_cvt.buf;
        bird_length = wav_cvt.len;

        /* Start playing */
        SDL_PauseAudio(0);

        ss.clear();
        ss << SDL_NumJoysticks() << " joysticks were found" << endl;
        Debugger::getInstance().print(ss.str());
        Debugger::getInstance().print("The names of the joysticks are:\n");

        for(int i=0; i < SDL_NumJoysticks(); i++ )
        {
            ss.clear();
            ss << SDL_JoystickName(i) << endl;
            Debugger::getInstance().print(ss.str());
        }

        SDL_JoystickEventState(SDL_ENABLE);
        if (SDL_NumJoysticks() > 0) {
            joystick = SDL_JoystickOpen(0);
        }

        const SDL_VideoInfo* info = SDL_GetVideoInfo();
        int vidFlags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER;
        if (info->hw_available) {
            vidFlags |= SDL_HWSURFACE;
            Debugger::getInstance().print("using hardware surface");
        } else {
            vidFlags |= SDL_SWSURFACE;
            Debugger::getInstance().print("using software surface");
        }
        int bpp = info->vfmt->BitsPerPixel;
        SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, bpp, vidFlags);
        GL_Setup(WINDOW_WIDTH, WINDOW_HEIGHT);

        loadModel(currentModelIndex);

        main_loop_function();
    } catch (std::string exc) {
        Debugger::getInstance().print(exc);
    }

    if (collection != NULL) {
        delete collection;
    }
    if (joystick != NULL) {
        SDL_JoystickClose(joystick);
    }
    SDL_CloseAudio();
    if (bird_buffer != NULL) {
        SDL_FreeWAV(bird_buffer);
    }
    if (hardware_spec != NULL) {
        free(hardware_spec);
    }
    if (firstArmSegment != NULL) {
        delete firstArmSegment;
    }

    glDeleteTextures(1, &texture);

    return 0;
}
