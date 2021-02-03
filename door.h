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
            glTranslatef(6, 0, 0.75);
            glRotatef(secDoorAngle, 0, 1, 0);
            glScalef(4, 7, 0.25);
            drawCube(1,texture[5],4,7,0.25,CHROME);
        glPopMatrix();
        //janela
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPushMatrix();
            glTranslatef(3, 8+windowPosY, 0.5);
            glScalef(10, 1, 0.1);
            drawCube(1,texture[6],10,1,0.1,GLASS);
        glPopMatrix();
        glDisable(GL_BLEND);
        //cima
        glPushMatrix();
            glTranslatef(3, 9, 0);
            glScalef(10, 1, 1);
            drawCube(1,texture[3],10,1,1,CHROME);
        glPopMatrix();
        //entre janela e porta
        glPushMatrix();
            glTranslatef(6, 7, 0);
            glScalef(4, 1, 1);
            drawCube(1,texture[3],4,1,1,CHROME);
        glPopMatrix();
        //esquerda
        glPushMatrix();
            glScalef(6, 8, 1);
            drawCube(1,texture[3],6,8,1,CHROME);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 8, 0);
            glScalef(3, 2, 1);
            drawCube(1,texture[3],3,2,1,CHROME);
        glPopMatrix();
        //direita
        glPushMatrix();
            glTranslatef(13, 8, 0);
            glScalef(3, 2, 1);
            drawCube(1,texture[3],3,2,1,CHROME);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(10, 0, 0);
            glScalef(6, 8, 1);
            drawCube(1,texture[3],6,8,1,CHROME);
        glPopMatrix();
    glPopMatrix();
}

#endif /* door_h */
