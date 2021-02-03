#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#else
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "RgbImage.h"

#include "colors.h"
#include "cube.h"
#include "door.h"
#include "wall.h"
#include "torch.h"
#include "events.h"
#include "axis.h"
#include "text.h"
#include "observator.h"
#include "floor.h"
#include "sky.h"
#include "textures.h"
#include "materials.h"
#include "illumination.h"

///janela
GLint wScreen = 800;
GLint hScreen = 800;


void drawScene() {
    glPushMatrix();
    glScalef((GLfloat)1/zoom,(GLfloat)1/zoom,(GLfloat)1/zoom);
    drawFloor(-100,-100,46,100,texture[1],GREEN_RUBBER);
    drawFloor(-8,-100,8,100,texture[2],WHITE_RUBBER);
    drawFloor(8,-100,46,100,texture[1],GREEN_RUBBER);
    drawWall();
    drawTorch();
    drawSky(isDay);
    drawDoor(mainDoorPosX,secDoorAngle,windowPosY);
    glPopMatrix();
}

void display(void) {
    //================================================================= Apaga
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //================================================================= Viewport 1 MAPA
    ///projecao ortogonal
    glViewport(0, 0, 0.2*wScreen, 0.2*hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 30, 0, 0, 0, 0, 0, 0, -1);
    initLights();
    ///Objetos
    drawAxis(0,10,0);
    drawObservador_Local();
    drawObservador_Target();
    drawScene();
    //================================================================= Viewport 2 COMANDOS
  
    ///projecao ortogonal
    glViewport(0*wScreen, 0.4*hScreen,0.2*wScreen, 0.4*hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 30, 0, 0, 0, 0, 0, 0, -1);
    glDisable(GL_LIGHTING);
    drawCommands(-15,-20,2);
    //================================================================= Viewport 3
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glViewport(0.25 * wScreen, 0.25 * hScreen, 0.75 * wScreen, 0.75*hScreen);
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
    initLights();
    ///Objectos
    drawScene();
    ///Atualizacao
    glutSwapBuffers();
}




int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(wScreen, hScreen);
    glutInitWindowPosition(300, 0);
    glutCreateWindow("Door Project\t-\tDylan Perdigão\t-\tdgp@student.dei.uc.pt");
    glClearColor(BLACK);                        //  Apagar
    glEnable(GL_DEPTH_TEST);                    //  Profundidade
    glShadeModel(GL_FLAT);                    //  Interpolacao de cores
    glEnable(GL_CULL_FACE);                     //  Faces visiveis
    glCullFace(GL_BACK);                        //  Mostrar so as da frente
    glEnable(GL_NORMALIZE);
    initTextures();
    glutSpecialFunc(keysNotAscii);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(msec, Timer, 1);
    glutMainLoop();
    return 0;
}




