//
//  door.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//

#ifndef door_h
#define door_h
void drawDoor(GLfloat mainDoorPosX,GLfloat secDoorAngle,GLfloat windowPosY){
    glPushMatrix();
    glTranslatef(-8+mainDoorPosX, 0, 0);
        //porta
        glPushMatrix();
            glTranslatef(6, 0, 0);
            glRotatef(secDoorAngle, 0, 1, 0);
            glScalef(4, 7, 1);
            drawCube(1,GREEN);
        glPopMatrix();
        //janela
        glPushMatrix();
            glTranslatef(3, 8+windowPosY, 0.5);
            glScalef(10, 1, 0);
            drawCube(1,BLUE);
        glPopMatrix();
        //cima
        glPushMatrix();
            glTranslatef(3, 9, 0);
            glScalef(10, 1, 1);
            drawCube(1,WHITE);
        glPopMatrix();
        //entre janela e porta
        glPushMatrix();
            glTranslatef(6, 7, 0);
            glScalef(4, 1, 1);
            drawCube(1,WHITE);
        glPopMatrix();
        //esquerda
        glPushMatrix();
            glScalef(6, 8, 1);
            drawCube(1,WHITE);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 8, 0);
            glScalef(3, 2, 1);
            drawCube(1,WHITE);
        glPopMatrix();
        //direita
        glPushMatrix();
            glTranslatef(13, 8, 0);
            glScalef(3, 2, 1);
            drawCube(1,WHITE);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(10, 0, 0);
            glScalef(6, 8, 1);
            drawCube(1,WHITE);
        glPopMatrix();
    glPopMatrix();
}

#endif /* door_h */
