#include <GLUT/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "RgbImage.h"

#include "colors.h"
#include "cube.h"
#include "door.h"
#include "wall.h"
#include "events.h"
#include "axis.h"
#include "text.h"
#include "observator.h"
#include "floor.h"
#include "textures.h"

///janela
GLint wScreen = 600;
GLint hScreen = 600;


void drawScene() {
    glPushMatrix();
    glScalef((GLfloat)1/zoom,(GLfloat)1/zoom,(GLfloat)1/zoom);
    drawFloor(-100,0,-100,92,0,200);
    drawFloor(-8,0,-100,16,0,200);
    drawFloor(8,0,-100,92,0,200);


    drawWall();
    drawDoor(mainDoorPosX,secDoorAngle,windowPosY);
    glPopMatrix();
}

void display(void) {
    //================================================================= Apaga
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //================================================================= Viewport 1 MAPA
    ///projecao ortogonal
    glViewport(0, 0, 0.25 * wScreen, 0.25 * hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 30, 0, 0, 0, 0, 0, 0, -1);
    ///Objetos
    drawAxis();
    drawObservador_Local();
    drawObservador_Target();
    drawScene();
    drawInformation();
    //================================================================= Viewport 2 COMANDOS
    ///projecao ortogonal
    glViewport(0, 0.75*hScreen,0.25*wScreen, 1.2*hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 30, 0, 0, 0, 0, 0, 0, -1);
    drawCommands(-15,-20,1);
    //================================================================= Viewport 3
    glViewport(0.5 * wScreen, 0.25 * hScreen, 0.75 * wScreen*2, 0.75 * hScreen*2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    switch (projectionType) {
        case ORTHOGONAL:
            glOrtho(-20, 20, -20, 20, -100, 100);
            break;
        case PERSPECTIVE:
            gluPerspective(angleZ, (float)wScreen / hScreen, 0.1, 9999);
            break;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obsP[0], obsP[1], obsP[2], obsT[0], obsT[1], obsT[2], 0, 1, 0);
    ///Objectos
    drawScene();
    ///Atualizacao
    glutSwapBuffers();
}




int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(wScreen, hScreen);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Door Project\t-\tDylan Perdigão\t-\tdgp@student.dei.uc.pt");
    glClearColor(BLACK);                        //  Apagar
    glEnable(GL_DEPTH_TEST);                    //  Profundidade
    glShadeModel(GL_SMOOTH);                    //  Interpolacao de cores
    glEnable(GL_CULL_FACE);                     //  Faces visiveis
    glCullFace(GL_BACK);                        //  Mostrar so as da frente
    initTextures();
    glutSpecialFunc(keysNotAscii);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(msec, Timer, 1);
    glutMainLoop();
    return 0;
}




