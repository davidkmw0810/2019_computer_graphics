#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLsizei winWidth = 500, winHeight = 500;


GLfloat vertices[][3]={
        {-1.0, -1.0, 1.0},
        {-1.0, 1.0, 1.0},
        {1.0, 1.0, 1.0},
        {1.0, -1.0, 1.0},
        {-1.0, -1.0, -1.0},
        {-1.0, 1.0, -1.0},
        {1.0, 1.0, -1.0},
        {1.0, -1.0, -1.0}
};

GLfloat colors[][3]={
        {1.0, 0.0, 0.0},
        {1.0, 1.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 1.0, 1.0},
        {1.0, 0.0, 1.0}
};

void polygon(int a, int b, int c){
    glColor3fv(colors[a]);
    glBegin(GL_POLYGON);
        glVertex3fv(vertices[a]);
        glVertex3fv(vertices[b]);
        glVertex3fv(vertices[c]);
        //glVertex3fv(vertices[d]);
    glEnd();
}

void createCube(){
    /*
    polygon(0, 3, 2, 1);
    polygon(2, 3, 7, 6);
    polygon(3, 0, 4, 7);
    polygon(4, 5, 6, 7);
    polygon(1, 2, 6, 5);
    polygon(5, 4, 0, 1);
     */
    polygon(0, 4, 7);
    polygon(0, 4, 5);
    polygon(4, 5, 7);
    polygon(0, 6, 7);
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}

void display(){
    float x, y, theta;

    theta = 1.0;
    x = 2.0*cos(theta);
    y = 2.0*sin(theta);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, 2.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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

    createCube();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("cube");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}