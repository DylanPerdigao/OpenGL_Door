//
//  cube.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//
#include "textures.h"
#ifndef cube_h
#define cube_h

void drawCube(GLfloat size, GLdouble r,GLdouble g,GLdouble b, GLdouble a){
    ///vertices
    GLfloat vertices[] = {
        //left
        0,   0,     size,           // 0
        0,   size,  size,           // 1
        0,   size,  0,              // 2
        0,   0,     0,              // 3
        //right
        size,    0,     size,       // 4
        size,    size,  size,       // 5
        size,    size,  0,          // 6
        size,    0,     0,          // 7
        //up
        0,      size,    size,      // 8
        0,      size,    0,         // 9
        size,   size,    0,         // 10
        size,   size,    size,      // 11
        //down
        0,      0,   size,          // 12
        0,      0,   0,             // 13
        size,   0,   0,             // 14
        size,   0,   size,          // 15
        //front
        0,      size,   0,          // 16
        0,      0,      0,          // 17
        size,   0,      0,          // 18
        size,   size,   0,          // 19
        //back
        0,      size,   size,       // 20
        0,      0,      size,       // 21
        size,   0,      size,       // 22
        size,   size,   size,       // 23
    };
    ///vetores normais
    GLfloat normals[] = {
        //left
        -1.0,  0.0,  0.0,
        -1.0,  0.0,  0.0,
        -1.0,  0.0,  0.0,
        -1.0,  0.0,  0.0,
        //right
        1.0,  0.0,  0.0,
        1.0,  0.0,  0.0,
        1.0,  0.0,  0.0,
        1.0,  0.0,  0.0,
        //up
        0.0,  1.0,  0.0,
        0.0,  1.0,  0.0,
        0.0,  1.0,  0.0,
        0.0,  1.0,  0.0,
        //down
        0.0,  -1.0,  0.0,
        0.0,  -1.0,  0.0,
        0.0,  -1.0,  0.0,
        0.0,  -1.0,  0.0,
        //front
        0.0,  0.0,  -1.0,
        0.0,  0.0,  -1.0,
        0.0,  0.0,  -1.0,
        0.0,  0.0,  -1.0,
        //back
        0.0,  0.0,  1.0,
        0.0,  0.0,  1.0,
        0.0,  0.0,  1.0,
        0.0,  0.0,  1.0,
    };
    ///faces visiveis
    GLuint     left[] = {0, 1, 2, 3};
    GLuint     right[] = {4, 7, 6, 5};
    GLuint     up[] = {8, 11, 10, 9};
    GLuint     down[] = {12, 13, 14, 15};
    GLuint     front[] = {16, 19, 18, 17};
    GLuint     back[] = {20, 21, 22, 23};
    ///init
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals);
    glEnableClientState(GL_NORMAL_ARRAY);
    ///desenho
    glEnable(GL_TEXTURE_2D);
   
    glPushMatrix();
        glColor4f(r,g,b,a);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, up);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, down);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, left);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, right);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, front);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, back);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

#endif /* cube_h */
