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

#define STEP 0.5
//.................................................... Variaveis
GLint wScreen = 600;
GLint hScreen = 500;

GLfloat lightX=0;
GLfloat lightY=0;

char filenameV[] = "Vshader.cpp";
char filenameF[] = "Fshader.cpp";

char* VertexShaderSource;
char* FragmentShaderSource;

GLuint  VertexShader, FragmentShader;
GLuint  ShaderProgram;


void drawScene(void){
    drawAxis(0,0,0); 
    glColor4f(YELLOW);
    glPushMatrix();
        glTranslatef(lightX, lightY, 0);
        drawCube(1);
    glPopMatrix();
    
    glColor3f(1, 0.5, 0);
    glPushMatrix();
        glTranslatef(-1, -1, 0);
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
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
    
    drawScene();
    
    glutSwapBuffers();                        //.. actualiza ecran
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
            lightY+=STEP;
            break;
        //A
        case 'A':
        case 'a':
            lightX-=STEP;
            break;
        //S
        case 'S':
        case 's':
            lightY-=STEP;
            break;
        //S
        case 'D':
        case 'd':
            lightX+=STEP;
            break;
        }
}



int main(int argc, char** argv){
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 40);
    glutCreateWindow("Dylan Perdigão | Projeto | Shaders");
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glClearColor(0, 0, 0, 1);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glewInit();
    glDetachShader(ShaderProgram, VertexShader);
    glDetachShader(ShaderProgram, FragmentShader);
    glDeleteShader(ShaderProgram);
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
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glutDisplayFunc(draw);
    glutKeyboardFunc(event);
    glutIdleFunc(draw);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    glutMainLoop();
    return 1;
}
