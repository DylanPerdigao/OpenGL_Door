//
//  wall.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//

#ifndef wall_h
#define wall_h
void drawWall(){
    //muro
    glPushMatrix();
        glTranslatef(-8, 0, 0);
        glScalef(-16, 15, -1);
        drawCube(1,texture[4],-16,15,-1,YELLOW);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(8, 0, -1);
        glScalef(10, 15, 1);
        drawCube(1,texture[4],10,15,1,YELLOW);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-8, 10, -1);
        glScalef(16, 5, 1);
        drawCube(1,texture[4],16,5,1,YELLOW);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-24, 10, 0);
        glScalef(32, 0.25, 0.25);
        drawCube(1,texture[7],32,0.25,0.25,ORANGE);
    glPopMatrix();
    
}

#endif /* wall_h */
