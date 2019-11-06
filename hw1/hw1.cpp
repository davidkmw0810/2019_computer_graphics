#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100, 100.0, -100.0, 100.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
    //glVertex2i(320, 240); // x_k = 320, y_k = 240
	float y = 0; // y_k = 240
	for(int x = 0; x <= 100; x++) // x_k
	{
	    float l = x/50;
        float m = -(x + 1)*(x + 1) + 100*(y + 1/2);
		if(m < 0)
		{
            // choose NE
			y += 1 + (int)l;
		}

	    glVertex2i(x, y);
	    glVertex2i(-x, y);
	}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);

	glFlush();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("HW1");
	init2D(0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
