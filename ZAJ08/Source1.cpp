/*
* (c) Copyright 2016, Vasyl Martsenyuk
* Email: marceniuk@yahoo.com
*/


#include "../packages/nupengl.core.0.1.0.1/build/native/include/GL/glut.h"

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// w��czenie bufora szablonowego
	glEnable(GL_STENCIL_TEST);


	// rysujemy sze�cian i uzupe�niamy bufor szablonowy
	// jedynkami w tym miejscu gdzie narysujemy sze�cian

	glStencilFunc(GL_ALWAYS, 1, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	/*glutSolidCube(2.5);*/
	glutSolidCone(1,200, 10, 10);
	// uzupe�niamy bufor szablonowy dw�jkami w tych miejscach
	// gdzie kula pokrywa sze�cian
	glStencilFunc(GL_ALWAYS, 2, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glutSolidSphere(1.5, 100, 100);

	// // czyszczenie bufora koloru i bufora g��boko�ci
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// wy��czenie testu bufora szablonowego i rysejemy czerwon� kul�
	glDisable(GL_STENCIL_TEST);
	glColor3d(1, 0, 0);
	glutSolidSphere(0.5, 100, 100);
	//niebieski torus
	glColor3d(0, 0, 1);
	glutSolidTorus(0.15, 0.6, 80, 100);
	// zielony torus obracany na 90 stopni wed�ug niebieskiego
	glColor3d(0, 1, 0);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.15, 0.6, 80, 100);
	glPopMatrix();

	// jeszcze raz pozwalamy test buforu szablonowego
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_EQUAL, 1, 255);
	glColor3d(1, 1, 1);
	glutSolidCube(2.5);

	// wracamy scen�

	glRotated(0.3, 1, 0, 0);
	glRotated(0.5, 0, 1, 0);
	glRotated(0.7, 0, 0, 1);

	glFlush();

	glutSwapBuffers();
}


void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5, 5, -5, 5, 2, 12);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	display();
}

///////////////////////////////////////////////////////////
// Wywo�ywana przez bibliotek GLUT w czasie, gdy okno nie
// jest przesuwane ani nie jest zmieniana jego wielko��
void TimerFunction(int value) {

	display();
	// Ponowne rysowanie sceny z nowymi wsp�rz�dnymi  
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

int main(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);
	float pos[4] = { 3,3,3,1 };
	float dir[3] = { -1,-1,-1 };

	GLfloat mat_specular[] = { 1,1,1,1 };

	glutInitWindowPosition(50, 10);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Stencil buffer");
	glutInitDisplayMode(GL_DOUBLE | GL_RGB | GL_DEPTH);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);

	glEnable(GL_DEPTH_TEST);


	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);

	/*
	* Enter your code here
	*/
	glutTimerFunc(33, TimerFunction, 1);
	glutMainLoop();
	return 0;
}
