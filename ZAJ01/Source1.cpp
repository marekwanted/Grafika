//#include <ostream>
//#include <iostream>
//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include "GL/glut.h"
//#endif
//
//GLfloat xy[7][2] =
//{
//	{200,100},
//	{161,119},
//	{151,161},
//	{178,195},
//	{222,195},
//	{249,161},
//	{239,119}
//};
//GLsizei rsize = 1;
//
//// Rozmiar kroku (liczba pikseli) w osi x i y
//GLfloat xstep = 1;
//GLfloat ystep = 1;
//// Dane zmieniajcych siê rozmiarów okna
//GLfloat windowWidth;
//GLfloat windowHeight;
//
/////////////////////////////////////////////////////////////
//// Wywo³ywana w celu przerysowania sceny
//void RenderScene(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor3f(1.0f, 1.0f, 0.0f);
//
//	glBegin(GL_POLYGON);
//
//
//	for (auto coordinates : xy)
//	{
//		glVertex2f(coordinates[0], coordinates[1]);
//	}
//
//
//	glEnd();
//
//
//	glFlush();
//}
//
//void SetupRC(void)
//{
//	// Ustalenie niebieskiego koloru czyszczcego     
//	glClearColor(0.6f, 0.4f, 0.12f, 1.0f);
//}
//
/////////////////////////////////////////////////////////////
//// Wywo³ywana przez bibliotek GLUT w przypadku zmiany rozmiaru okna
//void ChangeSize(GLsizei w, GLsizei h)
//{
//	// Zabezpieczenie przed dzieleniem przez zero
//	if (h == 0)
//		h = 1;
//
//	// Ustalenie wielkoœci widoku zgodnego z rozmiarami okna
//	glViewport(0, 0, w, h);
//
//	// Ustalenie uk³adu wspó³rzêdnych
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	// Keep the square square, this time, save calculated
//	// width and height for later use
//	if (w <= h)
//	{
//		windowHeight = 250.0f * h / w;
//		windowWidth = 250.0f;
//	}
//	else
//	{
//		windowWidth = 250.0f * w / h;
//		windowHeight = 250.0f;
//	}
//
//	// Ustanowienie przestrzeni ograniczaj¹cej (lewo, prawo, dó³, góra, blisko, daleko)
//	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void ChangeSizee(int w, int h)
//{
//	GLfloat aspectRatio;
//	// Zabezpieczenie przed dzieleniem przez zero  
//	if (h == 0) h = 1;
//	// Ustawienie wielkoœci widoku na równ¹ wielkoœci okna     
//	glViewport(0, 0, w, h);
//	// Ustalenie uk³adu wspó³rzêdnych  
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	// Wyznaczenie przestrzeni ograniczaj¹cej (lewy, prawy, dolny, górny, bliski, odleg³y)  
//	aspectRatio = (GLfloat)w / (GLfloat)h;
//	if (w <= h) glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
//	else glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
/////////////////////////////////////////////////////////////
//// G³ówny punkt wejcia programu
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("GL 7 Wierzcholkow");
//	glutDisplayFunc(RenderScene);
//	glutReshapeFunc(ChangeSize);
//
//	SetupRC();
//
//	glutMainLoop();
//	std::cout << windowWidth << std::endl << windowHeight;
//	return 0;
//}
