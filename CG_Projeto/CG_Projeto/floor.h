//
//  floor.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 06/11/2020.
//
#include "textures.h"

#ifndef floor_h
#define floor_h
void drawFloor(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height,GLfloat depth){

    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(width, height,depth);
    drawCube(1,DARK_GREEN);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

#endif /* floor_h */
