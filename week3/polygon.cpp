#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 0.0);
	for(int i = 0; i < 10; i++)
	{
        glVertex2i(10+5*i, 100);
	}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINES);
	    glVertex2i(10, 10);
		glVertex2i(100, 100);

	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);
	    glVertex2f(0.0, 0.0);
		glVertex2i(0.0, 3.0);
		glVertex2i(4.0, 3.0);
		glVertex2i(6.0, 3.0);
		glVertex2i(4.0, 3.0);
	glEnd();

	glFlush();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("points and lines");
	init2D(0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
