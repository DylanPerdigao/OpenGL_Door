//
//  events.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//
//Projections

#include "illumination.h"

#define PERSPECTIVE 0
#define ORTHOGONAL 1

#ifndef events_h
#define events_h
///timer
GLint msec = 10;
///observador
GLfloat theta = acos(-1)/2;
GLfloat  obsP[] = { 0, 2.5, 10};
GLfloat  obsT[] = { obsP[0] - cos(theta), obsP[1], obsP[0] - sin(theta) };
float angleZ = 95;
int projectionType = 0;
int zoom=2;
///porta
GLfloat maxDoorShift=16;
GLfloat maxWindowShift=1;
GLfloat maxDoorAngle=100;
GLfloat mainDoorPosX;
GLfloat secDoorAngle;
GLfloat windowPosY;
///malha
GLint      dim = 32;   //numero divisoes da grelha
void Timer(int value){
    glutPostRedisplay();
    glutTimerFunc(msec, Timer, 1);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            isDay = !isDay;
            if (isDay) {
                for(int i=0;i<3;i++){
                    sunAmb[i] = SUN_LIGHT;
                }
            }else{
                for(int i=0;i<3;i++){
                    sunAmb[i] = MOON_LIGHT;
                }
            }
            break;
        case '2':
            isTorchON = !isTorchON;
            break;
        case '3':
            if (torchIntensity > INTENSITY_MIN){
                torchIntensity -= INTENSITY_STEP;
            }
            break;
        case '4':
            if (torchIntensity < INTENSITY_MAX){
                torchIntensity += INTENSITY_STEP;
            }
            break;
        case 'r':
        case 'R':
            isRed=!isRed;
            break;
        case 'g':
        case 'G':
            isGreen=!isGreen;
            break;
        case 'b':
        case 'B':
            isBlue=!isBlue;
            break;
        ///Specualr
        case 'c':
        case 'C':
            originalCoef=!originalCoef;
            break;
        ///deslocamento porta direita esquerda
        case 'd':
        case 'D':
            if(mainDoorPosX<0){
                mainDoorPosX++;
            }
            break;
        case 'a':
        case 'A':
            if(mainDoorPosX>-maxDoorShift){
                mainDoorPosX--;
            }
            break;
        ///deslocamento janela cima baixo
        case 'w':
        case 'W':
            if(windowPosY<maxWindowShift){
                windowPosY+=0.1;
            }
            break;
        case 's':
        case 'S':
            if(windowPosY>0){
                windowPosY-=0.1;
            }
            break;
        ///deslocamento porta secundaria abrir fechar
        case 'q':
        case 'Q':
            if (secDoorAngle>-maxDoorAngle){
                secDoorAngle-=3;
            }
            break;
        case 'e':
        case 'E':
            if (secDoorAngle<0){
                secDoorAngle+=3;
            }
            break;
        ///projeção
        case 'p':
        case 'P':
            switch (projectionType) {
                case ORTHOGONAL:
                    projectionType=PERSPECTIVE;
                    break;
                case PERSPECTIVE:
                    projectionType=ORTHOGONAL;
                    break;
            }
            break;
        ///Zoom
        case 'o':
        case 'O':
            switch (zoom) {
                case 2:
                    zoom=4;
                    break;
                case 4:
                    zoom=1;
                    break;
                default:
                    zoom=2;
                    break;
            }
            break;
        ///Malha
        case 'm':
        case 'M':
            if(dim<512){
                dim*=2;
            }else{
                dim=1;
            }
            break;
        ///EXIT
        case 27:
            exit(0);
            break;
    }
    updateLights();
    glutPostRedisplay();
}

void keysNotAscii(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            obsP[0] -= 0.5 * cos(theta);
            obsP[2] -= 0.5 * sin(theta);
            break;
        case GLUT_KEY_DOWN:
            obsP[0] += 0.5 * cos(theta);
            obsP[2] += 0.5 * sin(theta);
            break;
        case GLUT_KEY_LEFT:
            theta -= 0.1;
            break;
        case GLUT_KEY_RIGHT:
            theta += 0.1;
            break;
        default:
            break;
    }
    obsT[0] = obsP[0] - cos(theta);
    obsT[2] = obsP[2] - sin(theta);
    updateLights();
    glutPostRedisplay();
}

#endif /* events_h */
