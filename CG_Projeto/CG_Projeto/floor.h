//
//  floor.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 06/11/2020.
//
#include "textures.h"

#ifndef floor_h
#define floor_h
void drawFloor(GLfloat x,GLfloat z, GLfloat width,GLfloat depth, GLint texture, int mat){
    float      med_dim = (float)dim / 2;
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glPushMatrix();
    glTranslatef(x, 0, z);
    glScalef(width, 1, depth);
    glNormal3f(0, 1, 0);
    
    glBegin(GL_QUADS);
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++) {
            glTexCoord2f((float)j*width / dim,         (float)i*depth / dim);
            glVertex3d((  float)j / med_dim,     0,(float)i / med_dim);
           
            glTexCoord2f((float)j*width / dim,         (float)(i + 1)*depth / dim);
            glVertex3d((  float)j / med_dim,     0,(float)(i + 1) / med_dim);
            
            glTexCoord2f((float)(j + 1)*width /dim,    (float)(i + 1)*depth / dim);
            glVertex3d((  float)(j + 1) /med_dim,0,(float)(i + 1) / med_dim);

            glTexCoord2f((float)(j + 1)*width /dim,    (float)i*depth / dim);
            glVertex3d((  float)(j + 1) /med_dim,0,(float)i / med_dim);
        }
    }
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


#endif /* floor_h */
