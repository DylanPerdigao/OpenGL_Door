//
//  text.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//
#ifndef text_h
#define text_h


void drawText(char* string, GLfloat x, GLfloat y){
    glPushMatrix();
    glTranslatef(x, 0, y);
    glRasterPos2f(0, 0);
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++);
    glPopMatrix();
}
void drawInformation(GLfloat x, GLfloat y){
    char text[30];
    switch (projectionType) {
        case ORTHOGONAL:
            snprintf(text, 30, "Orthogonal Projection");
            break;
        case PERSPECTIVE:
            snprintf(text, 30, "Perspective Projection");
            break;
    }
    drawText(text, x,y);
}
void drawCommands(int x,int y,int ySpace){
    char text[30];
    glColor4f(RED);
    snprintf(text, 30, "COMMANDS");
    drawText(text, x, y);
    glColor4f(GREEN);
    snprintf(text, 30, "- A/D   Shift door left/right");
    drawText(text, x,y+ySpace);
    snprintf(text, 30, "- W/S   Shift window up/down");
    drawText(text, x,y+2*ySpace);
    snprintf(text, 30, "- Q/E   Open/Close sec. door");
    drawText(text, x,y+3*ySpace);
    snprintf(text, 30, "- ARROWS Move observator");
    drawText(text, x,y+4*ySpace);
    snprintf(text, 30, "- P      Projection Mode");
    drawText(text, x,y+5*ySpace);
    snprintf(text, 30, "- O      Zoom");
    drawText(text, x,y+6*ySpace);
}

#endif /* text_h */
