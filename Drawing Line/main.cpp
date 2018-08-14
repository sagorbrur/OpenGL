#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINT);
        glColor3f(0.0, 1.0, 0.0); /* green */
        glColor3f(1.0, 0.0, 0.0); /* red */
        glVertex3f(0.25,0.25,0.0);
        glColor3f(1.0, 1.0, 0.0); /* yellow */
        glColor3f(0.0, 0.0, 1.0); /* blue */
        glVertex3f(0.75,0.75,0.0);
        glVertex3f(0.25,0.75,0.0);


    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);//Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(250,250);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;//requires C to return init
}


