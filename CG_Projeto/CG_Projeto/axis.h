//
//  axis.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//

#ifndef axis_h
#define axis_h
void drawAxis(){
    glColor4f(ORANGE);
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
}
#endif /* axis_h */
