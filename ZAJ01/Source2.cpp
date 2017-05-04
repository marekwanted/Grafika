#include <ostream>
#include <iostream>
#include <ctime>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat xy[7][2] =
{
	{200,100},
	{161,119},
	{151,161},
	{178,195},
	{222,195},
	{249,161},
	{239,119}
};
GLsizei rsize = 1;

// Rozmiar kroku (liczba pikseli) w osi x i y
GLfloat xstep = 1;
GLfloat ystep = 1;
// Dane zmieniajcych si� rozmiar�w okna
GLfloat windowWidth;
GLfloat windowHeight;

///////////////////////////////////////////////////////////
// Wywo�ywana w celu przerysowania sceny
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);


	for (auto coordinates : xy)
	{
		glVertex2f(coordinates[0], coordinates[1]);
	}


	glEnd();


	glFlush();
}

void TimerFunction(int value)
{
	bool IsXDirChanged = false;
	for (auto checker : xy)
	{
		if (checker[0] > windowWidth - rsize || checker[0] < 0 + rsize) IsXDirChanged = true;
	}
	if (IsXDirChanged)
	{
		xstep = -xstep;
	}
	bool IsYDirChanged = false;
	for (auto checker : xy)
	{
		if (checker[1] > windowHeight - rsize || checker[1] < 0 + rsize) IsYDirChanged = true;
	}
	if (IsYDirChanged)
	{
		ystep = -ystep;
	}


	/*for (auto element : xy)
	{*/
	if (xy[0][0] > windowWidth - rsize)
		xy[0][0] = windowWidth - rsize - 1;
	if (xy[1][0] > windowHeight - rsize)
		xy[1][0] = windowHeight - rsize - 1;
	//}

	for (auto element : xy)
	{
		element[0] += xstep;
		element[1] += ystep;
	}

	glutPostRedisplay();
	glutTimerFunc(5, TimerFunction, 1);
}

///////////////////////////////////////////////////////////
// Konfiguracja stanu renderowania  
void SetupRC(void)
{
	// Ustalenie niebieskiego koloru czyszczcego     
	glClearColor(0.0f, 0.5f, 0.4f, 1.0f);
}

///////////////////////////////////////////////////////////
// Wywo�ywana przez bibliotek GLUT w przypadku zmiany rozmiaru okna
void ChangeSize(GLsizei w, GLsizei h)
{
	// Zabezpieczenie przed dzieleniem przez zero
	if (h == 0)
		h = 1;

	// Ustalenie wielko�ci widoku zgodnego z rozmiarami okna
	glViewport(0, 0, w, h);

	// Ustalenie uk�adu wsp�rz�dnych
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Keep the square square, this time, save calculated
	// width and height for later use
	if (w <= h)
	{
		windowHeight = 250.0f * h / w;
		windowWidth = 250.0f;
	}
	else
	{
		windowWidth = 250.0f * w / h;
		windowHeight = 250.0f;
	}

	// Ustanowienie przestrzeni ograniczaj�cej (lewo, prawo, d�, g�ra, blisko, daleko)
	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void ChangeSizee(int w, int h)
{
	GLfloat aspectRatio;
	// Zabezpieczenie przed dzieleniem przez zero  
	if (h == 0) h = 1;
	// Ustawienie wielko�ci widoku na r�wn� wielko�ci okna     
	glViewport(0, 0, w, h);
	// Ustalenie uk�adu wsp�rz�dnych  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Wyznaczenie przestrzeni ograniczaj�cej (lewy, prawy, dolny, g�rny, bliski, odleg�y)  
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h) glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

///////////////////////////////////////////////////////////
// G��wny punkt wejcia programu
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("GL 7 Wierzcholkow");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	glutTimerFunc(33, TimerFunction, 1);
	SetupRC();

	glutMainLoop();
	std::cout << windowWidth << std::endl << windowHeight;
	return 0;
}
