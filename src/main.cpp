#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/voxels.hpp"
#include "../include/createObjects.hpp"
#include "../include/assets.hpp"

#define STEP_PROF 0.5
#define STEP_ANGLE 3.14/6


/* variables globales pour la gestion de la caméra */
float profondeur;
float latitude;
float longitude;

float global_time = 0.0f;
float global_light = 0.0f;
bool use_shader = true;
bool animate_world = false;
bool animate_light = false;
GLUquadric *quadric = NULL;
Vox* tex;
Vox* mex;
Vox* rex;
Vox* sex;
Object* wallo;

void glDrawRepere(float length) {
	// dessin du repère
	glBegin(GL_LINES);
		glColor3f(1.,0.,0.);
		glVertex3f(0.,0.,0.);
		glVertex3f(length,0.,0.);
		glColor3f(0.,1.,0.);
		glVertex3i(0.,0.,0.);
		glVertex3i(0.,length,0.);
		glColor3f(0.,0.,1.);
		glVertex3i(0.,0.,0.);
		glVertex3i(0.,0.,length);
	glEnd();
}

void glDrawLight(float length) {
	glColor3f(1.,1.,0.);
	gluSphere(quadric,length,16,16);
}


void showMatrix(float* mat) {
	std::cerr<<"Matrix "<<std::endl;
	for(int i =0; i<4; i++ ) {
		for(int j=0; j<4; j++) {
			std::cerr<<mat[j*4+i]<<":";
		}
		std::cerr<<std::endl;
	}
}

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
	gluLookAt(profondeur*sin(longitude)*sin(latitude),
			  profondeur*cos(latitude),
			  profondeur*cos(longitude)*sin(latitude),
              0.0,0.0,0.0,
              0.0,1.0,0.0
	);

	glColor3f(1.0,0.0,0.0);
	glDrawRepere(2.0);

	/* Debut du dessin */
	glBegin(GL_TRIANGLES);
	tex->Display(0.,0.,0.);
	mex->Display(0.,0.,0.);
	rex->Display(0.,0.,0.);
	sex->Display(0.,0.,0.);
	wallo->Display(0.,0.,0.);
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
	gluPerspective( 60.0, h, 0.01, 100.0 );			// Angle de vue, rapport largeur/hauteur, near, far

	/* Retour a la pile de matrice Modelview
			et effacement de celle-ci */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************************/
/* fonction associée aux interruptions clavier           */
/* paramètres :                                          */
/* - c : caractère saisi                                 */
/* - x,y : coordonnée du curseur dans la fenêtre         */
static void kbdFunc(unsigned char c, int x, int y) {
	/* sortie du programme si utilisation des touches ESC, */
	/* 'q' ou 'Q'*/
	switch(c) {
		case 27 :
			exit(0);
			break;
		case 'F' : case 'f' : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		case 'P' : case 'p' : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
		case 'A' : case 'a' : 
			animate_world = !animate_world;
			break;
		case 'L' : case 'l' : 
			animate_light = !animate_light;
			break;
		case 'S' : case 's' : 
			use_shader = !use_shader;
			break;
		default:
			printf("Appui sur la touche %c\n",c);
			break;
	}
	glutPostRedisplay();
}

/*********************************************************/
/* fonction associée aux interruptions clavier pour les  */
/*          touches spéciales                            */
/* paramètres :                                          */
/* - c : code de la touche saisie                        */
/* - x,y : coordonnée du curseur dans la fenêtre         */
static void kbdSpFunc(int c, int x, int y) {
	/* sortie du programme si utilisation des touches ESC, */
	switch(c) {
		case GLUT_KEY_UP :
			if (latitude>STEP_ANGLE) latitude -= STEP_ANGLE;
			break;
		case GLUT_KEY_DOWN :
			if(latitude<M_PI-STEP_ANGLE) latitude += STEP_ANGLE;
			break;
		case GLUT_KEY_LEFT :
			longitude -= STEP_ANGLE;
			break;
		case GLUT_KEY_RIGHT :
			longitude += STEP_ANGLE;
			break;
		case GLUT_KEY_PAGE_UP :
			profondeur += STEP_PROF;
			break;
		case GLUT_KEY_PAGE_DOWN :
			if (profondeur>0.1+STEP_PROF) profondeur -= STEP_PROF;
			break;
		default:
			printf("Appui sur une touche spéciale\n");
	}
	glutPostRedisplay();
}


/*********************************************************/
/* fonction d'initialisation des paramètres de rendu et  */
/* des objets de la scènes.                              */
void init() {
	profondeur = 10.0;
	latitude = M_PI/3.0;
	longitude = -M_PI/4.0;

	global_time = 0.0;
	global_light = 0.0;

	quadric = gluNewQuadric();

	/* INITIALISATION DES PARAMETRES GL */
	/* couleur du fond (gris sombre) */
	glClearColor(0.05,0.05,0.05,0.0);
	/* activation du ZBuffer */
	glEnable( GL_DEPTH_TEST);
	glEnable( GL_NORMALIZE);

	/* lissage des couleurs sur les facettes */
	glShadeModel(GL_SMOOTH);

	/* INITIALISATION DE LA SCENE */
	tex = new Vox(1.,1.,1.,1.,0.,0.,0.);
	mex = new Vox(1.,0.,0.,1.,1.,0.,0.);
	rex = new Vox(0.,1.,0.,1.,0.,1.,0.);
	sex = new Vox(0.,0.,1.,1.,0.,0.,1.);
	wallo = new Object(wall);

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