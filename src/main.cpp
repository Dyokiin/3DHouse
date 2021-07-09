#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/camera.hpp"
#include "../include/createScene.hpp"


#define STEP_PROF 0.5
#define STEP_ANGLE 3.14/12

float latitude = 1.8322;
float longitude = -2.0937;
float offx = -97;
float offy = 31;
float offz = -16;
float cx;
float cy;
float cz;

SceneNode* house;
point zero = makePoint(0.,0.,0.);
KeyPoints* cam = new KeyPoints();

static void drawFunc(void) { 

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	
	cx = 0.1*sin(longitude)*sin(latitude);
	cy = 0.1*cos(latitude);
	cz = 0.1*cos(longitude)*sin(latitude);
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
			std::cout << "0.1 : " << 0.1 << std::endl;
			std::cout << "longitude : " << longitude << std::endl;
			std::cout << "latitude : " << latitude << std::endl;
			std::cout << "(" << offx << "," << offy << "," << offz << ")" << std::endl;
			exit(0);
			break;
		case 'F' : case 'f' : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		case 'P' : case 'p' : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		case 'Z' : case 'z' : 
			offx+=5*(-0.1*sin(longitude)*sin(latitude));
			offz+=5*(-0.1*cos(longitude)*sin(latitude));
			break;
		case 'S' : case 's' : 
			offx-=5*(-0.1*sin(longitude)*sin(latitude));
			offz-=5*(-0.1*cos(longitude)*sin(latitude));
			break;
		case 32 :
			offy+=0.5;
			glutIdleFunc(idle);
			break;
	}
	glutPostRedisplay();
}

static void kbdSpFunc(int c, int x, int y) {
	switch(c) {
		case GLUT_KEY_UP :
			if (latitude>STEP_ANGLE) latitude += STEP_ANGLE;
			break;
		case GLUT_KEY_DOWN :
			if(latitude<M_PI-STEP_ANGLE) latitude -= STEP_ANGLE;
			break;
		case GLUT_KEY_LEFT :
			longitude += STEP_ANGLE;
			break;
		case GLUT_KEY_RIGHT :
			longitude -= STEP_ANGLE;
			break;
	}
	glutPostRedisplay();
}

void init() {
	glClearColor(0.2,0.2,0.4,0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

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

	/* association de la fonction callback de redimensionnement */
	glutReshapeFunc(reshapeFunc);
	/* association de la fonction callback d'affichage */
	glutDisplayFunc(drawFunc);
	/* association de la fonction callback d'événement du clavier */
	glutKeyboardFunc(kbdFunc);
	/* association de la fonction callback d'événement du clavier (touches spéciales) */
	glutSpecialFunc(kbdSpFunc);

	glutMainLoop();
	return 0;
}
