//
//  observator.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//

#ifndef observator_h
#define observator_h
void drawObservador_Local(){
    glDisable(GL_LIGHTING);
    glColor4f(GREEN);
    glPushMatrix();
        glTranslatef(obsP[0], obsP[1], obsP[2]);
        glutSolidCube(1);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}
void drawObservador_Target(){
    glDisable(GL_LIGHTING);
    glColor4f(YELLOW);
    glPushMatrix();
        glTranslatef(obsT[0], obsT[1], obsT[2]);
        glutSolidCube(0.8);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

#endif /* observator_h */
