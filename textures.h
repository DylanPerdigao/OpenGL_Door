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
GLuint   texture[11];
RgbImage imag;
void initTextures(){
    size_t n = sizeof(texture)/sizeof(texture[0]);
    char* textureNameList[n];
    textureNameList[0]=strdup("sky.bmp");
    textureNameList[1]=strdup("grass.bmp");
    textureNameList[2]=strdup("stone.bmp");
    textureNameList[3]=strdup("door.bmp");
    textureNameList[4]=strdup("bricks.bmp");
    textureNameList[5]=strdup("terracotta.bmp");
    textureNameList[6]=strdup("glass.bmp");
    textureNameList[7]=strdup("slider.bmp");
    textureNameList[8]=strdup("torch.bmp");
    textureNameList[9]=strdup("torch_off.bmp");
    textureNameList[10]=strdup("night.bmp");
    for(int i=0;i<n;i++){
        glGenTextures(1, &texture[i]);
        glBindTexture(GL_TEXTURE_2D, texture[i]);
        imag.LoadBmpFile(textureNameList[i]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, 3,imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());
        
    }
}
#endif /* textures_h */
