#include <GL/glut.h>

GLsizei winWidth = 500, winHeight = 500;

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void displayWirePolyhedra() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(10.0, 0.0, 0.0);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 10.0, 0.0);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 10.0);

    glEnd();

    glPushMatrix();
        glScalef(1.2, 1.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef(30.0, 0.0, 1.0, 0.0);
    glutWireCube(1.0);

    glPushMatrix();
        glScalef(1.0, 0.5, 2.0);
        glTranslatef(0.0, 2.0, 0.0);
        glRotatef(0.0, 30.0, 0.0, 0.0);
    glutWireCube(2.0);

    glPopMatrix();

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Wire-Frame polyhedra");
    init();
    glutDisplayFunc(displayWirePolyhedra);
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
    glutMainLoop();
    return 0;
}