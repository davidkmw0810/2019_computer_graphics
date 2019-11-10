#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

GLsizei winWidth = 600, winHeight = 600;

typedef GLfloat Matrix3x3[3][3];
Matrix3x3 matComposite;
const GLdouble pi = 3.14159;
GLint n;

void init(){
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, winWidth, 0, winHeight);
}

void drawCircle(GLint x, GLint y, GLint r, GLint thick, Color col){

    GLint fill = rand()%2;
    glColor3f(col.r, col.g, col.b);

    if(fill == 1)
        glBegin(GL_POLYGON); // fill
    else
        glBegin(GL_LINE_LOOP); // empty

    for(GLint i = 0; i < 360; i++){
        GLfloat theta = i*pi / 180;
        GLfloat cx = r*cos(theta);
        GLfloat cy = r*sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawLine(GLint x1, GLint y1, GLint x2, GLint y2, GLint thick, Color col){
    glColor3f(col.r, col.g, col.b);
    glBegin(GL_LINE_STRIP);
    glLineWidth(thick);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void drawTriangle(GLint x, GLint y, GLint l, GLint thick, Color col){

    GLint fill = rand()%2;
    glColor3f(col.r, col.g, col.b);

    if(fill == 1)
        glBegin(GL_POLYGON); // fill
    else
        glBegin(GL_LINE_LOOP); // empty

    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + l); // 0
    glVertex2f(x - l*1.73205, y - l/2); // 120
    glVertex2f(x + l*1.73205, y - l/2); // 240

    glEnd();
}

void drawSquare(GLint x, GLint y, GLint l, GLint thick, Color col){

    GLint fill = rand()%2;

    glColor3f(col.r, col.g, col.b);

    if(fill == 1)
        glBegin(GL_POLYGON); // fill
    else
        glBegin(GL_LINE_LOOP); // empty

    glBegin(GL_QUADS);
    glVertex2f(x - l/2, y + l/2);
    glVertex2f(x + l/2, y + l/2);
    glVertex2f(x + l/2, y - l/2);
    glVertex2f(x - l/2, y - l/2);

    glEnd();
}

void randomDisp(){

    GLint x, x1, x2, y, y1, y2, r, l, thick, shape;
    Color col;

    for(int i = 0; i < n; i++) {
        shape = rand() % 4;
        col.r = ((int)rand()%11 + 1)/10;
        col.g = ((int)rand()%11 + 1)/10;
        col.b = ((int)rand()%11 + 1)/10;
        thick = rand()%50 +1;
        switch (shape) {
            case 0: // circle
                printf("%d is circle\n", i+1);
                r = rand()%300 + 1;
                x = rand()%300 +50;
                y = rand()%300 +50;
                drawCircle(x, y, r, thick, col);
                break;

            case 1: // line
                printf("%d is line\n", i+1);
                x1 = rand()%300;
                x2 = rand()%300;
                y1 = rand()%300;
                y2 = rand()%300;
                drawLine(x1, y1, x2, y2, thick, col);
                break;

            case 2: // triangle
                printf("%d is triangle\n", i+1);
                x = rand()%300;
                y = rand()%300;
                l = rand()%300;
                drawTriangle(x, y, l, thick, col);
                break;

            case 3: // square
                printf("%d is square\n", i+1);
                x = rand()%300;
                y = rand()%300;
                l = rand()%300;
                drawSquare(x, y, l, thick, col);
                break;

            default:
                exit(1);
                break;
        }
    }
    glFlush();
    exit(1);
}

int main(int argc, char** argv)
{

    srand(time(NULL));
    scanf("%d", &n);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("hw2_1");
    init();

    glutDisplayFunc(randomDisp);

    glutMainLoop();
    return 0;
}
