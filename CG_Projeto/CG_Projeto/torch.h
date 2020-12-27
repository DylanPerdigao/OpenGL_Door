//
//  torch.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 25/11/2020.
//
#include "illumination.h"

#ifndef torch_h
#define torch_h

void drawTorch(){
    //torcha
    glPushMatrix();
        glTranslatef(torchPos[0], torchPos[1], torchPos[2]);
        glScalef(0.6, 2, 0.6);
        if (isTorchON){
            drawCube(1,texture[8],0.2,1,0.2,POLISHED_SILVER);
        }else{
            drawCube(1,texture[9],0.2,1,0.2,POLISHED_SILVER);
        }
    glPopMatrix();
}

#endif /* torch_h */
