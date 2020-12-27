//
//  axis.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//

#ifndef axis_h
#define axis_h
void drawAxis(float x, float y, float z){
    glColor4f(ORANGE);
    glPushMatrix();
    glTranslatef(x, y, z);
        glBegin(GL_LINES);
            glVertex3i(0, 0, 0);
            glVertex3i(10, 0, 0);
        glEnd();
        glColor4f(GREEN);
        glBegin(GL_LINES);
            glVertex3i(0, 0, 0);
            glVertex3i(0, 10, 0);
        glEnd();
        glColor4f(CYAN);
        glBegin(GL_LINES);
            glVertex3i(0, 0, 0);
            glVertex3i(0, 0, 10);
        glEnd();
    glPopMatrix();
}
#endif /* axis_h */
