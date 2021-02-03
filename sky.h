//
//  sky.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 25/11/2020.
//

#ifndef sky_h
#define sky_h
GLUquadricObj* sphere = gluNewQuadric();

void drawSky(int isDay){
    //------------------------- Bola
    glCullFace(GL_FRONT);
    glEnable(GL_TEXTURE_2D);
    if (isDay){
        glBindTexture(GL_TEXTURE_2D, texture[0]);
    }else{
        glBindTexture(GL_TEXTURE_2D, texture[10]);
    }
    glPushMatrix();
        glTranslatef(2, -1, 2);
        glRotatef(180, 0, 0, 1);
        gluQuadricDrawStyle(sphere, GLU_FILL);
        gluQuadricNormals(sphere, GLU_SMOOTH);
        gluQuadricTexture(sphere, GL_TRUE);
        gluSphere(sphere, 100.0, 100, 100);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glCullFace(GL_BACK);
}

#endif /* sky_h */
