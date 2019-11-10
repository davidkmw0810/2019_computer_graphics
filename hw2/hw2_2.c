#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

GLsizei winWidth = 600, winHeight = 300;

typedef GLfloat Matrix3x3[3][3];
Matrix3x3 matComposite;
const GLdouble pi = 3.14159;
GLint v0, s, alpha;
GLfloat theta;

class wcPt2D{
        public:
        GLfloat x, y;
};

void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, winWidth, 0, winHeight);
}

void matrix3x3SetIdentity(Matrix3x3 matIdent3x3){
    GLint row, col;
    for(row=0; row < 3; row++){
        for(col=0; col < 3; col++)
            matIdent3x3[row][col] = (row == col);
    }
}

void matrix3x3PreMultiply(Matrix3x3 m1, Matrix3x3 m2){
    GLint row, col;
    Matrix3x3 matTemp;

    for(row=0; row < 3; row++){
        for(col=0; col < 3; col++){
            matTemp[row][col] = m1[row][0]*m2[0][col] + m1[row][1]*m2[1][col] + m1[row][2]*m2[2][col];
        }
    }

    for(row=0; row < 3; row++){
        for(col=0; col < 3; col++){
            m2[row][col] = matTemp[row][col];
        }
    }

}

void translate2D(GLfloat tx, GLfloat ty){
    Matrix3x3 matTransl;
    matrix3x3SetIdentity(matTransl);

    matTransl[0][2] = tx;
    matTransl[1][2] = ty;

    matrix3x3PreMultiply(matTransl, matComposite);
}

void rotate2D(wcPt2D pivotPt, GLfloat theta){
    Matrix3x3 matRot;
    matrix3x3SetIdentity(matRot);

    matRot[0][0] = cos(theta);
    matRot[0][1] = (-sin(theta));
    matRot[0][2] = pivotPt.x*(1-cos(theta)) + pivotPt.y*sin(theta);
    matRot[1][0] = sin(theta);
    matRot[1][1] = cos(theta);
    matRot[1][2] = pivotPt.y*(1-cos(theta)) - pivotPt.x*sin(theta);

    matrix3x3PreMultiply(matRot, matComposite);
}

void scale2D(GLfloat sx, GLfloat sy, wcPt2D fixedPt){
    Matrix3x3 matScale;
    matrix3x3SetIdentity(matScale);

    matScale[0][0] = sx;
    matScale[0][2] = (1 - sx)*fixedPt.x;
    matScale[1][1] = sy;
    matScale[1][2] = (1 - sy)*fixedPt.y;

    matrix3x3PreMultiply(matScale, matComposite);
}

void transformVerts2D(GLint nVerts, wcPt2D* verts){
    GLint k;
    GLfloat temp;

    for(k=0; k< nVerts; k++){
        temp = matComposite[0][0]*verts[k].x + matComposite[0][1]*verts[k].y + matComposite[0][2];
        verts[k].y = matComposite[1][0]*verts[k].x + matComposite[1][1]*verts[k].y + matComposite[1][2];
        verts[k].x = temp;
    }
}

void triangle(wcPt2D* verts){
    GLint k;
    glBegin(GL_TRIANGLES);
    for(k=0; k < 3; k++)
        glVertex2f(verts[k].x, verts[k].y);
    glEnd();
}

void Cannon(){

    GLint nVerts = 3;
    GLint t = 0;
    GLint xt = 0;
    GLint yt = 0;
    wcPt2D verts[3] = {{0.0, -10.0}, {-5.0, 5.0}, {5.0, 5.0}};

    wcPt2D centorPt, pivPt, fixedPt;
    centorPt.x = 0;
    centorPt.y = 0;

    for(int i = 0; i < nVerts; i++){
        centorPt.x += verts[i].x;
        centorPt.y += verts[i].y;
    }

    centorPt.x = GLfloat(centorPt.x)/GLfloat(nVerts);
    centorPt.y = GLfloat(centorPt.y)/GLfloat(nVerts);
    pivPt = centorPt;
    fixedPt = centorPt;

    while(centorPt.x >= 0 && centorPt.y >= 0){

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        triangle(verts);

        t++;
        matrix3x3SetIdentity(matComposite);

        xt = v0*cos(theta)*t;
        yt = v0*sin(theta)*t - 5*t*t;

        scale2D(s, s, fixedPt);
        rotate2D(pivPt, theta);
        translate2D(xt, yt);

        transformVerts2D(nVerts, verts);

        //centorPt.x = 0; centorPt.y = 0;
        for(int i = 0; i < nVerts; i++){
            centorPt.x += verts[i].x;
            centorPt.y += verts[i].y;
        }

        centorPt.x = GLfloat(centorPt.x)/GLfloat(nVerts);
        centorPt.y = GLfloat(centorPt.y)/GLfloat(nVerts);
        pivPt = centorPt;
        fixedPt = centorPt;

    }

    glFlush();
}

int main(int argc, char** argv)
{

    srand(time(NULL));
    printf("v0, theta, s, alpha\n");
    scanf("%d %f %d %d", &v0, &theta, &s, &alpha);
    theta = theta*pi/180;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("hw2_1");
    init();

    glutDisplayFunc(Cannon);

    glutMainLoop();
    return 0;
}
