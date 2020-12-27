//
//  illumination.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 23/11/2020.
//

#ifndef illumination_h
#define illumination_h

#define SUN_LIGHT 2
#define MOON_LIGHT 0.3
#define INTENSITY_STEP 0.1
#define INTENSITY_MAX 1.1
#define INTENSITY_MIN 0.1

int isDay = true;
int isTorchON = true;
int isRed = true;
int isGreen = true;
int isBlue = true;

GLfloat luzGlobalCorAmb[4] = { 0.1, 0.1, 0.1, 1};

GLfloat torchIntensity = 1;
GLfloat torchPos[4] = { 10, 6, 0, 1};
GLfloat torchColor[4] = { (GLfloat)isRed, (GLfloat)isGreen, (GLfloat)isBlue, 1.0 };
GLfloat torchDir[]  = { -1, -1, 0.5, 0 };
GLfloat torchCutoff = 20;
GLfloat torchCA     = 1;
GLfloat torchLA     = 0.05f;
GLfloat torchQA     = 0;
GLfloat torchExp    = 2;

GLfloat sunIntensity = SUN_LIGHT;
GLfloat sunDir[4]    = { 0,-1,1, 0};
GLfloat sunAmb[4] = { SUN_LIGHT, SUN_LIGHT, SUN_LIGHT, 1 };
GLfloat sunDif[4] = { 1, 1, 1, 1.0 };
GLfloat sunEsp[4] = { 1, 1, 1, 1.0 };

void initLights(void) {
    glEnable(GL_LIGHTING);
    if (isTorchON){
        glEnable(GL_LIGHT0);
    }else{
        glDisable(GL_LIGHT0);
    }
    glEnable(GL_LIGHT1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);
    
    glLightfv(GL_LIGHT0, GL_POSITION, torchPos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, torchDir);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, torchColor);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, torchCutoff);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, torchCA);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, torchLA);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, torchQA);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, torchExp);
    
    glLightfv(GL_LIGHT1, GL_POSITION, sunDir);
    glLightfv(GL_LIGHT1, GL_AMBIENT, sunAmb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, sunDif);
    glLightfv(GL_LIGHT1, GL_SPECULAR, sunEsp);
}

void updateLights() {
    if (isTorchON){
        glEnable(GL_LIGHT0);
    }else{
        glDisable(GL_LIGHT0);
    }
    torchColor[0] = isRed * torchIntensity;
    torchColor[1] = isGreen * torchIntensity;
    torchColor[2] = isBlue * torchIntensity;
    glLightfv(GL_LIGHT0, GL_DIFFUSE, torchColor);
}

#endif /* illumination_h */
