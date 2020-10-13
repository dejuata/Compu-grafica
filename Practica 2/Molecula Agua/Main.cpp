/*
 Parcial 1 Computación Gráfica

 Nombre: Juan David Pino
 Código: 1610460

 Molecula Agua

 Realizado en Visual Studio

 Para ejecutarlo configurar freeglut en el proyecto:
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <string.h>

using namespace std;


void drawSphere(float data[7]) {
    glPushMatrix();
    glColor3f(data[0], data[1], data[2]);
    glTranslatef(data[3], data[4], data[5]);
    glutSolidSphere(data[6], 100, 100);
    glPopMatrix();
}


void drawOrbit(float orbit[8], float angle) {
    glPushMatrix();
    glColor3f(0.631, 0.635, 0.650);
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
    glClearColor(0.960, 0.960, 0.960, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Orbita oxigeno
    float orbitOxigeno[1] = { 0.4 };
    drawOrbit(orbitOxigeno, 0.001);

    // oxigeno
    float oxigeno[7] = { 0.623, 0.117, 0.031, 0, 0, 0, 0.12 };
    drawSphere(oxigeno);
 
    // Electrones
    // right-left
    float electron0[7] = { 0.313, 0.552, 0.815, 0.37, 0.14, 0, 0.05 };
    drawSphere(electron0);

    float electron1[7] = { 0.313, 0.552, 0.815, -0.37, 0.14, 0, 0.05 };
    drawSphere(electron1);

    float electron2[7] = { 0.313, 0.552, 0.815, 0.37, -0.14, 0, 0.05 };
    drawSphere(electron2);

    float electron3[7] = { 0.313, 0.552, 0.815, -0.37, -0.14, 0, 0.05 };
    drawSphere(electron3);

    // up-down
    float electron4[7] = { 0.313, 0.552, 0.815, 0.17, 0.36, 0, 0.05 };
    drawSphere(electron4);

    float electron5[7] = { 0.313, 0.552, 0.815, -0.17, 0.36, 0, 0.05 };
    drawSphere(electron5);

    float electron6[7] = { 0.313, 0.552, 0.815, 0.17, -0.36, 0, 0.05 };
    drawSphere(electron6);

    float electron7[7] = { 0.313, 0.552, 0.815, -0.17, -0.36, 0, 0.05 };
    drawSphere(electron7);

    // Hidrogenos
    // Hidrogeno 0
    float hidrogeno0[7] = { 0.623, 0.117, 0.031, 0.4, 0.4, 0, 0.12 };
    drawSphere(hidrogeno0);

    // Orbita hidrogeno 0
    glPushMatrix();
    glTranslatef(0.4, 0.4, 0);
    float orbitHidrogeno0[1] = { 0.25 };
    drawOrbit(orbitHidrogeno0, 0.001);
    glPopMatrix();

    // Hidrogeno 1
    float hidrogeno1[7] = { 0.623, 0.117, 0.031, -0.4, 0.4, 0, 0.12 };
    drawSphere(hidrogeno1);

    // Orbita hidrogeno 1
    glPushMatrix();
    glTranslatef(-0.4, 0.4, 0);
    float orbitHidrogeno1[1] = { 0.25 };
    drawOrbit(orbitHidrogeno1, 0.001);
    glPopMatrix();

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
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Molecula Agua");
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