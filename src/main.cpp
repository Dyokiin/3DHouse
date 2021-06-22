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

float profondeur = 0.2;
float latitude = 1.8322;
float longitude = -2.0937;
float offx = -97;
float offy = 31;
float offz = -12;
float cx;
float cy;
float cz;

SceneNode* house;


/*********************************************************/
/* fonction de dessin de la scène à l'écran              */
static void drawFunc(void) { 
	/* reinitialisation des buffers : couleur et ZBuffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* modification de la matrice de la scène */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Debut du dessin de la scène */
	glPushMatrix();
	
	/* placement de la caméra */
	cx = profondeur*sin(longitude)*sin(latitude);
	cy = profondeur*cos(latitude);
	cz = profondeur*cos(longitude)*sin(latitude);
	gluLookAt(cx + offx,
			  cy + offy,
			  cz + offz,
              0.0+offx,0.0+offy,0.0+offz,
              0.0,1.0,0.0
	);

	/* Debut du dessin */
	glBegin(GL_TRIANGLES);
	house->update();
	//cameraSpline();
	glEnd();
	/* Fin du dessin */
	glPopMatrix();

	/* fin de la définition de la scène */
	glFinish();

	/* changement de buffer d'affichage */
	glutSwapBuffers();
}

/*********************************************************/
/* fonction de changement de dimension de la fenetre     */
/* paramètres :                                          */
/* - width : largeur (x) de la zone de visualisation     */
/* - height : hauteur (y) de la zone de visualisation    */
static void reshapeFunc(int width,int height) {
	GLfloat  h = (GLfloat) width / (GLfloat) height ;
	
	/* dimension de l'écran GL */
	glViewport(0, 0, (GLint)width, (GLint)height);
	/* construction de la matrice de projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* définition de la camera */
	gluPerspective( 70.0, h, 0.01, 500.0 );			// Angle de vue, rapport largeur/hauteur, near, far

	/* Retour a la pile de matrice Modelview
			et effacement de celle-ci */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void kbdFunc(unsigned char c, int x, int y) {
	switch(c) {
		case 27 :
			std::cout << "profondeur : " << profondeur << std::endl;
			std::cout << "longitude : " << longitude << std::endl;
			std::cout << "latitude : " << latitude << std::endl;
			std::cout << "(" << offx << "," << offy << "," << offz << ")" << std::endl;
			exit(0);
			break;
		case 'F' : case 'f' : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		case 'P' : case 'p' : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		case 'Z' : case 'z' : 
			offx+=5*(-profondeur*sin(longitude)*sin(latitude));
			offz+=5*(-profondeur*cos(longitude)*sin(latitude));
			break;
		case 'S' : case 's' : 
			offx-=5*(-profondeur*sin(longitude)*sin(latitude));
			offz-=5*(-profondeur*cos(longitude)*sin(latitude));
			break;
		case 32 :
			offy+=0.5;
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
		case GLUT_KEY_PAGE_UP :
			profondeur += STEP_PROF;
			break;
		case GLUT_KEY_PAGE_DOWN :
			if (profondeur>0.1+STEP_PROF) profondeur -= STEP_PROF;
			break;
	}
	glutPostRedisplay();
}

void init() {


	/* INITIALISATION DES PARAMETRES GL */
	/* couleur du fond (gris sombre) */
	glClearColor(0.2,0.2,0.4,0.0);
	/* activation du ZBuffer */
	glEnable( GL_DEPTH_TEST);
	glEnable( GL_NORMALIZE);

	/* INITIALISATION DE LA SCENE */
	house = initScene();
	cameraSpline();

}

int main(int argc, char** argv) {
	/* traitement des paramètres du programme propres à GL */
	glutInit(&argc, argv);
	/* initialisation du mode d'affichage :                */
	/* RVB + ZBuffer + Double buffer.                      */
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	/* placement et dimentions originales de la fenêtre */
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1220, 780);
	/* ouverture de la fenêtre */
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

	/* boucle principale de gestion des événements */
	glutMainLoop();
	/* Cette partie du code n'est jamais atteinte */
	return 0;
}
