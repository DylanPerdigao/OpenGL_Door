//
//  textures.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 07/11/2020.
//
#include<stdio.h>
#include<string.h>

#ifndef textures_h
#define textures_h
GLUquadricObj* bola = gluNewQuadric();
GLuint   texture[8];
RgbImage imag;
void initTextures(){
    char* textureNameList[8];
    textureNameList[0]=strdup("sky.bmp");
    textureNameList[1]=strdup("grass.bmp");
    textureNameList[2]=strdup("stone.bmp");
    textureNameList[3]=strdup("door.bmp");
    textureNameList[4]=strdup("bricks.bmp");
    textureNameList[5]=strdup("terracotta.bmp");
    textureNameList[6]=strdup("glass.bmp");
    textureNameList[7]=strdup("slider.bmp");
    for(int i=0;i<8;i++){
        glGenTextures(1, &texture[i]);
        glBindTexture(GL_TEXTURE_2D, texture[i]);
        imag.LoadBmpFile(textureNameList[i]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, 3,imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());
        
    }
}
void drawBola()
{
    //------------------------- Bola
    glCullFace(GL_FRONT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glPushMatrix();
        glTranslatef(2, 4, 2);
        gluQuadricDrawStyle(bola, GLU_FILL);
        gluQuadricNormals(bola, GLU_SMOOTH);
        gluQuadricTexture(bola, GL_TRUE);
        gluSphere(bola, 100.0, 100, 100);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glCullFace(GL_BACK);                    
}
#endif /* textures_h */
