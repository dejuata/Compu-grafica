/*
 Parcial 1 Computacion Grafica

 Nombre: Juan David Pino
 Codigo: 1610460

 Sistema Solar

 Realizado en Visual Studio 2019

 Para ejecutarlo en Visual Studio, configurar freeglut

  */

#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <string.h>

using namespace std;


void drawPlanet(float data[7]) {
    glPushMatrix();
    glColor3f(data[0], data[1], data[2]);
    glTranslatef(data[3], data[4], data[5]);
    glutSolidSphere(data[6], 100, 100);
    glPopMatrix();
}


void drawOrbit(float orbit[8], float angle) {
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);

    for (int i = 0; i < sizeof(orbit); i++) {
        for (double j = 0.0; j < 10; j += angle) {

            float x = (float)orbit[i] * cos(j);
            float y = (float)orbit[i] * sin(j);
            glVertex2f(x, y);
        }
    }

    glEnd();
    glPopMatrix();
}

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sol
    float sol[7] = { 1, 0.937, 0.015, 0, 0, 0, 0.19 };
    drawPlanet(sol);

    // Orbitas
    float orbit[8] = { 0.25, 0.3, 0.4, 0.5, 0.7, 0.8, 0.9, 1.0 };
    drawOrbit(orbit, 0.001);

    // Asteroides
    float asteroids[1] = { 0.57 };
    drawOrbit(asteroids, 0.1);

    // Mercurio
    float mercurio[7] = { 0.882, 0.450, 0.007, 0.24, 0.05, 0.0, 0.02 };
    drawPlanet(mercurio);

    // Venus
    float venus[7] = { 0.996, 0.286, 0.023, 0.23, 0.2, 0.0, 0.03 };
    drawPlanet(venus);

    // Tierra
    float tierra[7] = { 0.047, 0.274, 0.427, -0.25, 0.3, 0.0, 0.05 };
    drawPlanet(tierra);

    // Marte
    float marte[7] = { 0.6, 0.054, 0.019, 0.43, -0.25, 0.0, 0.045 };
    drawPlanet(marte);

    // Jupiter
    float jupiter[7] = { 0.407, 0.266, 0.160, -0.62, -0.3, 0.0, 0.085 };
    drawPlanet(jupiter);

    // Saturno
    float saturno[7] = { 0.811, 0.627, 0.376, 0.63, 0.5, 0.0, 0.07 };
    drawPlanet(saturno);

    // Urano
    float urano[7] = { 0.223, 0.305, 0.376, -0.03, 0.9, 0.0, 0.055 };
    drawPlanet(urano);

    // Neptuno
    float neptuno[7] = { 0.141, 0.258, 0.627, -1.0, 0.05, 0.0, 0.055 };
    drawPlanet(neptuno);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        glRotatef(1.0, 1., 0., 0.);
        break;
    case '2':
        glRotatef(1.0, 0., 1., 0.);
        break;
    case 'q':
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void init() {
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sistema Solar");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);

    init();

    return 0;
}