#include <GL/glut.h>
#include <stdlib.h>

void init(void){
    // (R, G, B, Alpha)
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void line_segment(void){
    // Clear buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// set Color
	glColor3f(1.0, 0.0, 0.0);

	// Draw line
    glBegin(GL_LINES);
	    glVertex2i(180, 15);
	    glVertex2i(10, 145);

	    glVertex2i(10, 145);
	    glVertex2i(10, 15);

	    glVertex2i(10, 15);
	    glVertex2i(180, 15);
	glEnd();

	glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 500);
	glutCreateWindow("an Example");

	init();
	glutDisplayFunc(line_segment);
	glutMainLoop();

	return 0;
}
