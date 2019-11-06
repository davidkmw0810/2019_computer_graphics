#include <GL/glut.h>
#include <stdlib.h>

void init(void)
{

    glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 500);
	glutCreateWindow("An Example OpenGL Program");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int rounding(const float a) {return (int)(a+0.5);}

void setPixel(GLint xCoord, GLint yCoord)
{
    glBegin(GL_POINTS);
	glVertex2i(xCoord, yCoord);
	glEnd();
}

void lineDDA(int x0, int y0, int xEnd, int yEnd)
{

    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
	float xIncrement, yIncrement, x=x0, y=y0;
	
	if(abs(dx) > abs(dy))
	    steps = abs(dx);
	else
	    steps = abs(dy);
    xIncrement= (float)dx/(float)steps;
    yIncrement= (float)dy/(float)steps;

	setPixel(rounding(x), rounding(y));
	for(k=0; k < steps; k++)
	{
        x += xIncrement;
		y += yIncrement;
		setPixel(rounding(x), rounding(y));
	}
}

void DrawlineDDA(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	lineDDA(10, 400, 600, 15);

	glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	init();
	glutDisplayFunc(DrawlineDDA);
	glutMainLoop();

	return 0;
}
