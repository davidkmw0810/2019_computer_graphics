#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define sign(x) ((x > 0)?1:((x < 0) ?-1:0))

void init(void)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("An Example OpenGL Program");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void setPixel(GLint xCoord, GLint yCoord)
{
    glBegin(GL_POINTS);
	glVertex2i(xCoord, yCoord);
	glEnd();
}

void bres_general(int x1, int y1, int x2, int y2)
{
    int dx, dy, x, y, d, s1, s2, isdYBigger=0, temp;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	s1 = sign(x2 - x1);
	s2 = sign(y2 - y1);

    if (dy > dx) {temp = dx; dx = dy; dy = temp; isdYBigger = 1;}

	d = 2*dy - dx;
	x = x1;
	y = y1;
	
	int i;
	for(i=0; i <= dx; i++)
    {
        setPixel(x, y);
		while(d >= 0)
		{
		    if(isdYBigger) 
			    x += s1;
			else
			{
			    y += s2;
				d -= 2*dx;
			}
		}
	
	    if(isdYBigger)
	        y += s2;
    	else
	        x += s1;
    	d += 2*dy;
	}
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	bres_general(20, 40, 620, 40);
	bres_general(620, 40, 620, 440);
	bres_general(620, 440, 20, 440);
	bres_general(20, 440, 20, 40);

	bres_general(320, 440, 20, 240);
	bres_general(20, 240, 320, 40);
	bres_general(320, 40, 620, 240);
	bres_general(620, 240, 320, 440);

	bres_general(250, 150, 250, 250);

	bres_general(300, 250, 400, 250);
	bres_general(400, 250, 400, 150);
	bres_general(400, 150, 300, 150);
	bres_general(300, 150, 300, 250	);

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	init();
	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}
