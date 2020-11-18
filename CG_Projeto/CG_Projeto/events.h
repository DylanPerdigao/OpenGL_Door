//
//  events.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 27/10/2020.
//
//Projections

#define PERSPECTIVE 0
#define ORTHOGONAL 1

#ifndef events_h
#define events_h
///timer
GLint msec = 10;
///observador
GLfloat maxY = 50.0;
GLfloat distance = 10;
GLfloat theta = acos(-1)/2;
GLfloat  obsP[] = { distance * cos(theta), 3.0, distance * sin(theta) };
GLfloat  obsT[] = { obsP[0] - distance * cos(theta), obsP[1], obsP[2] - distance * sin(theta) };
float angleZ = 95;
int projectionType = 0;
int zoom=1;
///porta
GLfloat maxDoorShift=16;
GLfloat maxWindowShift=1;
GLfloat maxDoorAngle=100;
GLfloat mainDoorPosX;
GLfloat secDoorAngle;
GLfloat windowPosY;

void Timer(int value){
    glutPostRedisplay();
    glutTimerFunc(msec, Timer, 1);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
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
            glutPostRedisplay();
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
            glutPostRedisplay();
            break;
        ///EXIT
        case 27:
            exit(0);
            break;
    }
}

void keysNotAscii(int key, int x, int y) {
    //------------------------------- olhar para a origem
    switch (key) {
        case GLUT_KEY_UP:
            obsP[1] += 0.5;
            break;
        case GLUT_KEY_DOWN:
            obsP[1] -= 0.5;
            break;
        case GLUT_KEY_LEFT:
            theta += 0.1;
            break;
        case GLUT_KEY_RIGHT:
            theta -= 0.1;
            break;
        default:
            break;
    }
    if (obsP[1] > maxY){
        obsP[1] = maxY;
    }
    if (obsP[1] < -maxY){
        obsP[1] = -maxY;
    }
    obsP[0] = distance * cos(theta);
    obsP[2] = distance * sin(theta);
    glutPostRedisplay();
}

#endif /* events_h */
