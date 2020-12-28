#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/glut.h>
#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
#else
    #include <GL/gl.h>
#endif
#include "colors.h"
#include "axis.h"
#include "cube.h"
#include "reader.h"

#define STEP    0.5
#define PI      3.14159
//.................................................... Variaveis
GLint wScreen = 600;
GLint hScreen = 500;

GLfloat lightPos[3] = {0,1,0};
GLfloat  rVisao = 8, aVisao = PI/2, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), 3.0, rVisao * sin(aVisao) };

char filenameV[] = "VertexShader.cpp"; 
char filenameF[] = "FragmentShader.cpp";

char* VertexShaderSource;
char* FragmentShaderSource;

GLuint  VertexShader, FragmentShader;
GLuint  ShaderProgram;

GLuint uLoc_position;


void drawScene(void){
    
    glColor4f(YELLOW);
    glPushMatrix();
    glTranslatef(lightPos[0],lightPos[1],lightPos[2]);
        drawCube(0.1);
    glPopMatrix();
    
    glColor4f(ORANGE);
    glPushMatrix();
        glutSolidTeapot(1);
    glPopMatrix();
}

void draw(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, wScreen, hScreen);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, 1, 0.1, 10.0);
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obsP[0], obsP[1], obsP[2], 0, 0, 0, 0, 1, 0);
    
    drawScene();
    //----------------------------------------------usa variaveis uniform
    glUniform3fv(uLoc_position, 1, lightPos);
  
    glutSwapBuffers();
}



void event(unsigned char key, int x, int y) {
    switch (key) {
        //ESC
        case 27:
            exit(0);
            break;
        //W
        case 'W':
        case 'w':
            lightPos[1]+=STEP;
            break;
        //A
        case 'A':
        case 'a':
            lightPos[0]-=STEP;
            break;
        //S
        case 'S':
        case 's':
            lightPos[1]-=STEP;
            break;
        //S
        case 'D':
        case 'd':
            lightPos[0]+=STEP;
            break;
        }
    glutPostRedisplay();
}

void eventArrows(int key, int x, int y) {
    if (key == GLUT_KEY_UP)    obsP[1] = obsP[1] + 0.5;
    if (key == GLUT_KEY_DOWN)  obsP[1] = obsP[1] - 0.5;
    if (key == GLUT_KEY_LEFT)  aVisao = aVisao + 0.1;
    if (key == GLUT_KEY_RIGHT) aVisao = aVisao - 0.1;
    obsP[0] = rVisao * cos(aVisao);
    obsP[2] = rVisao * sin(aVisao);
    glutPostRedisplay();
}

int main(int argc, char** argv){
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 40);
    glutCreateWindow("Dylan Perdigão | Projeto | Shaders");
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Init
    glClearColor(0, 0, 0, 1);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GLEW
    glewInit();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Criar, compilar, linkar, e usar
    GLEW_ARB_vertex_shader;
    GLEW_ARB_fragment_shader;
    //Criar
    VertexShader = glCreateShader(GL_VERTEX_SHADER);
    FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    VertexShaderSource = readShaderFile(filenameV);
    FragmentShaderSource = readShaderFile(filenameF);
    const char* VS = VertexShaderSource;
    const char* FS = FragmentShaderSource;
    glShaderSource(VertexShader, 1, &VS, NULL);
    glShaderSource(FragmentShader, 1, &FS, NULL);
    free(VertexShaderSource);
    free(FragmentShaderSource);
    //Compilar
    glCompileShaderARB(VertexShader);
    glCompileShaderARB(FragmentShader);
    //Criar e Linkar
    ShaderProgram = glCreateProgramObjectARB();
    glAttachShader(ShaderProgram, VertexShader);
    glAttachShader(ShaderProgram, FragmentShader);
    glLinkProgram(ShaderProgram);
    //Usar
    glUseProgramObjectARB(ShaderProgram);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~UNIFORM
    uLoc_position = glGetUniformLocation(ShaderProgram, "u_lightPos"); 
    glUniform1fv(uLoc_position,1,lightPos);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Libertar os Shaders
    glDetachShader(ShaderProgram, VertexShader);
    glDetachShader(ShaderProgram, FragmentShader);
    glDeleteShader(ShaderProgram);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glutSpecialFunc(eventArrows);
    glutDisplayFunc(draw);
    glutKeyboardFunc(event);
    glutIdleFunc(draw);    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glutMainLoop();
    return 1;
}
    
   
