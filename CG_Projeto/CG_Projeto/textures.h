//
//  textures.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 07/11/2020.
//
#ifndef textures_h
#define textures_h
GLuint   texture[5];
RgbImage imag;
void initTextures(){
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    imag.LoadBmpFile("grass.bmp");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
        imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
        imag.ImageData());
}

#endif /* textures_h */
