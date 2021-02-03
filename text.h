//
//  text.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//
#include <string.h>

#ifndef text_h
#define text_h

char* meshText(char* str){
    char aux[30];
    sprintf(aux,"%d",dim);
    strcat(str,aux);
    return str;
}

char* intensityText(char* str){
    char aux[30];
    float percentage = abs(100*(torchIntensity)/INTENSITY_MAX);
    sprintf(aux,"%.0f%s",percentage,"%");
    strcat(str,aux);
    return str;
}

char* colorsText(char* str){
    if(isRed){
        strcat(str,"1");
    }else{
        strcat(str,"0");
    }
    if(isGreen){
        strcat(str,"1");
    }else{
        strcat(str,"0");
    }
    if(isBlue){
        strcat(str,"1");
    }else{
        strcat(str,"0");
    }
    return str;
}

char* dayText(char* str){
    if(isDay){
        strcat(str,"DAY");
    }else{
        strcat(str,"NIGHT");
    }
    return str;
}

char* torchText(char* str){
    if(isTorchON){
        strcat(str,"ON");
    }else{
        strcat(str,"OFF");
    }
    return str;
}

char* specularityText(char* str){
    if(originalCoef){
        strcat(str,"TRUE");
    }else{
        strcat(str,"FALSE");
    }
    return str;
}

char* projectionText(char* text){
    switch (projectionType) {
        case ORTHOGONAL:
            strcat(text, "Orthogonal");
            break;
        case PERSPECTIVE:
            strcat(text, "Perspective");
            break;
    }
    return text;
}
char* zoomText(char* text){
    switch (zoom) {
        case 1:
            strcat(text, "1x");
            break;
        case 2:
            strcat(text, "2x");
            break;
        case 4:
            strcat(text, "4x");
            break;
    }
    return text;
}

void drawText(char* string, GLfloat x, GLfloat y){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(x, 0, y);
    glRasterPos2f(0, 0);
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

void drawCommands(int x,int y,int ySpace){
    int line=0;
    char text[100];
    glColor4f(RED);
    snprintf(text, 100, "COMMANDS");
    drawText(text, x, y);line++;
    //MOVES
    glColor4f(GREEN);
    snprintf(text, 100, "- AD..............Shift door left/right");
    drawText(text, x,y+line*ySpace);line++;
    snprintf(text, 100, "- WS..............Shift window up/down");
    drawText(text, x,y+line*ySpace);line++;
    snprintf(text, 100, "- QE..............Open/Close sec. door");
    drawText(text, x,y+line*ySpace);line++;
    snprintf(text, 100, "- ARROWS....Move observator");
    drawText(text, x,y+line*ySpace);line++;
    //PROJECTION
    snprintf(text, 100, "- P.................Projection Mode");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........");
    drawText(projectionText(text), x,y+line*ySpace);line++;
    //ZOOM
    glColor4f(GREEN);
    snprintf(text, 100, "- O................Zoom");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........Zoom-");
    drawText(zoomText(text), x,y+line*ySpace);line++;
    //COLOR
    glColor4f(GREEN);
    snprintf(text, 100, "- RGB............Torch color");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........RGB-");
    drawText(colorsText(text), x,y+line*ySpace);line++;
    //DAY/NIGHT
    glColor4f(GREEN);
    snprintf(text, 100, "- 1.................Switch day/night");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........");
    drawText(dayText(text), x,y+line*ySpace);line++;
    //ON/OFF TORCH
    glColor4f(GREEN);
    snprintf(text, 100, "- 2.................On/Off torch");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........");
    drawText(torchText(text), x,y+line*ySpace);line++;
    //Intensity
    glColor4f(GREEN);
    snprintf(text, 100, "- 34................Torch Intensity");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........Intensity: ");
    drawText(intensityText(text), x,y+line*ySpace);line++;
    //Intensity
    glColor4f(GREEN);
    snprintf(text, 100, "- M.................Mesh");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........Mesh dim: ");
    drawText(meshText(text), x,y+line*ySpace);line++;
    //Intensity
    glColor4f(GREEN);
    snprintf(text, 100, "- C...............Original Specularity Coef.");
    drawText(text, x,y+line*ySpace);line++;
    glColor4f(CYAN);
    snprintf(text, 100, "..........State: ");
    drawText(specularityText(text), x,y+line*ySpace);line++;
}

#endif /* text_h */
