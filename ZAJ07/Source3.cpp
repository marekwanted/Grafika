///*
//(c) Janusz Ganczarski
//http://www.januszg.hg.pl
//JanuszG@enter.net.pl
//*/
//
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <math.h>
//#include "../Library/master.h"
//
//// sta�e do obs�ugi menu podr�cznego
//
//enum
//{
//	FILL, // obiekt wype�niony
//	WIRE, // kraw�dzie obiektu
//	HALO, // efekt halo
//	EXIT // wyj�cie
//};
//
//// rozmiary bry�y obcinania
//
//const GLint left = -5;
//const GLint right = 5;
//const GLint bottom = -5;
//const GLint top = 5;
//const GLint near_ = -5;
//const GLint far_ = 5;
//
//// k�ty obrotu sceny
//
//GLfloat rotatex = 0.0;
//GLfloat rotatey = 0.0;
//
//// wska�nik naci�ni�cia lewego przycisku myszki
//
//int button_state = GLUT_UP;
//
//// po�o�enie kursora myszki
//
//int button_x, button_y;
//
//// tryb rysowania
//
//int render_mode = WIRE;
//
//// funkcja generuj�ca scen� 3D
//
//void DisplayScene()
//{
//	// kolor t�a - zawarto�� bufora koloru
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//
//	// czyszczenie bufora koloru i bufora g��boko�ci
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	// wyb�r macierzy modelowania
//	glMatrixMode(GL_MODELVIEW);
//
//	// macierz modelowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// obroty ca�ej sceny
//	glRotatef(rotatex, 1.0, 0.0, 0.0);
//	glRotatef(rotatey, 0.0, 1.0, 0.0);
//
//	// w��czenie bufora g��boko�ci
//	glEnable(GL_DEPTH_TEST);
//
//	// kolor obiektu
//	glColor4fv(Green);
//
//	// narysowanie wybranych element�w sceny
//	switch (render_mode)
//	{
//		// obiekt wype�niony
//	case FILL:
//		glutSolidSphere(3.0, 15, 15);
//		break;
//
//		// rysowanie tylko kraw�dzi obiektu
//	case WIRE:
//
//		// wy��czenie bufora g��boko�ci
//		glDisable(GL_DEPTH_TEST);
//
//		// tryb rysowania wielok�t�w
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//		// szeroko�� linii - linia normalna
//		glLineWidth(3.0);
//
//		// narysowanie obiektu
//		glutSolidSphere(3.0, 15, 15);
//
//		// tryb rysowania wielok�t�w
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//
//		// w��czenie testu bufora g��boko�ci
//		glEnable(GL_DEPTH_TEST);
//		break;
//
//		// efekt halo
//	case HALO:
//		// tryb rysowania wielok�t�w
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//		// wy��czenie zapisu do bufora kolor�w
//		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
//
//		// szeroko�� linii - linia pogrubiona
//		glLineWidth(9.0);
//
//		// narysoanie obiektu
//		glutSolidSphere(3.0, 15, 15);
//
//		// w��czenie zapisu do bufora g��boko�ci
//		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
//
//		// szeroko�� linii - linia normalna
//		glLineWidth(3.0);
//
//		// rodzaj testu bufora g��boko�ci
//		glDepthFunc(GL_LEQUAL);
//
//		// narysowanie obiektu
//		glutSolidSphere(3.0, 15, 15);
//
//		// rodzaj testu bufora g��boko�ci
//		glDepthFunc(GL_LESS);
//
//		// tryb rysowania wielok�t�w
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		break;
//	}
//
//	// skierowanie polece� do wykonania
//	glFlush();
//
//	// zamiana bufor�w koloru
//	glutSwapBuffers();
//}
//
//// zmiana wielko�ci okna
//
//void Reshape(int width, int height)
//{
//	// obszar renderingu - ca�e okno
//	glViewport(0, 0, width, height);
//
//	// wyb�r macierzy rzutowania
//	glMatrixMode(GL_PROJECTION);
//
//	// macierz rzutowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// parametry bry�y obcinania
//	glOrtho(left, right, bottom, top, near_, far_);
//
//	// generowanie sceny 3D
//	DisplayScene();
//}
//
//// obs�uga przycisk�w myszki
//
//void MouseButton(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON)
//	{
//		// zapami�tanie stanu lewego przycisku myszki
//		button_state = state;
//
//		// zapami�tanie po�o�enia kursora myszki
//		if (state == GLUT_DOWN)
//		{
//			button_x = x;
//			button_y = y;
//		}
//	}
//}
//
//// obs�uga ruchu kursora myszki
//
//void MouseMotion(int x, int y)
//{
//	if (button_state == GLUT_DOWN)
//	{
//		rotatey += 50 * (right - left) / (float)glutGet(GLUT_WINDOW_WIDTH) *(x - button_x);
//		button_x = x;
//		rotatex -= 50 * (top - bottom) / (float)glutGet(GLUT_WINDOW_HEIGHT) *(button_y - y);
//		button_y = y;
//		glutPostRedisplay();
//	}
//}
//
//// obs�uga menu podr�cznego
//
//void Menu(int value)
//{
//	switch (value)
//	{
//		// wybrany tryb rysowania
//	case FILL:
//	case WIRE:
//	case HALO:
//		render_mode = value;
//		DisplayScene();
//		break;
//
//		// wyj�cie
//	case EXIT:
//		exit(0);
//	}
//}
//
//int main(int argc, char * argv[])
//{
//	// inicjalizacja biblioteki GLUT
//	glutInit(&argc, argv);
//
//	// inicjalizacja bufora ramki
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//	// rozmiary g��wnego okna programu
//	glutInitWindowSize(500, 500);
//
//	// utworzenie g��wnego okna programu
//	glutCreateWindow("Linie z halo");
//
//	// do��czenie funkcji generuj�cej scen� 3D
//	glutDisplayFunc(DisplayScene);
//
//	// do��czenie funkcji wywo�ywanej przy zmianie rozmiaru okna
//	glutReshapeFunc(Reshape);
//
//	// obs�uga przycisk�w myszki
//	glutMouseFunc(MouseButton);
//
//	// obs�uga ruchu kursora myszki
//	glutMotionFunc(MouseMotion);
//
//	// utworzenie podmenu - Tryb rysowania
//	int MenuRenderMode = glutCreateMenu(Menu);
//#ifdef WIN32
//
//	glutAddMenuEntry("Obiekt wype�niony", FILL);
//	glutAddMenuEntry("Kraw�dzie obiektu", WIRE);
//	glutAddMenuEntry("Efekt halo", HALO);
//#else
//
//	glutAddMenuEntry("Obiekt wypelniony", FILL);
//	glutAddMenuEntry("Krawedzie obiektu", WIRE);
//	glutAddMenuEntry("Efekt halo", HALO);
//#endif
//
//	// menu g��wne
//	glutCreateMenu(Menu);
//	glutAddSubMenu("Tryb rysowania", MenuRenderMode);
//
//#ifdef WIN32
//
//	glutAddMenuEntry("Wyj�cie", EXIT);
//#else
//
//	glutAddMenuEntry("Wyjscie", EXIT);
//#endif
//
//	// okre�lenie przycisku myszki obs�uguj�cego menu podr�czne
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	// wprowadzenie programu do obs�ugi p�tli komunikat�w
//	glutMainLoop();
//	return 0;
//}
//
