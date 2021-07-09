#include <cstdlib>
#include <cmath>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/camera.hpp"
#include "../include/createScene.hpp"

float phi ;
float teta;
float offx;
float offy;
float offz;
float cx;
float cy;
float cz;

SceneNode* house;
point zero = makePoint(0.,0.,0.);
KeyPoints* cam = new KeyPoints();

static void drawFunc() { 

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	
	cx = 0.1*sin(teta)*sin(phi);
	cy = 0.1*cos(phi);
	cz = 0.1*cos(teta)*sin(phi);
	gluLookAt(cx + offx,
			  cy + offy,
			  cz + offz,
              0.0+offx,
			  0.0+offy,
			  0.0+offz,
              0.0,1.0,0.0
	);

	/* Debut du dessin */
	glBegin(GL_TRIANGLES);
	house->update(zero);
	glEnd();
	/* Fin du dessin */

	glPopMatrix();

	glFinish();
	glutSwapBuffers();
}

static void reshapeFunc(int width,int height) {
	GLfloat  h = (GLfloat) width / (GLfloat) height ;
	glViewport(0, 0, (GLint)width, (GLint)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective( 70.0, h, 0.01, 500.0 );		

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle(void) {
	cam->step(cx+offx, cy+offy, cz+offz);
	glutPostRedisplay();
}

static void kbdFunc(unsigned char c, int x, int y) {
	switch(c) {
		case 27 :
			exit(0);
			break;
		case 32 :
			glutIdleFunc(idle);
			break;
	}
	glutPostRedisplay();
}

void init() {
	glClearColor(0.2,0.2,0.4,0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	phi = 1.832;
	teta = -2.0;
	offx = -97;
	offy = 31;
	offz = -16;
	house = initScene();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1220, 780);
	if (glutCreateWindow("3DHouse") == GL_FALSE) {
		return 1;
	}

	init();

	glutReshapeFunc(reshapeFunc);
	glutDisplayFunc(drawFunc);
	glutKeyboardFunc(kbdFunc);

	glutMainLoop();
	return 0;
}
