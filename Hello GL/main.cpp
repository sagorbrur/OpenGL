#include<GL/gl.h>
#include<GL/glut.h>


void display(void)
{

    //clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);
    //draw white polygon with corner
    //at (.25,.25,.0) and (.75,.75,.0)
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_QUADS);
        glVertex3f(0.25,0.25,0.0);
        glVertex3f(0.75,0.25,0.0);
        glVertex3f(0.75,0.75,0.0);
        glVertex3f(0.25,0.75,0.0);//this for polygon
        glEnd();
        /*
        GL_POINTS       individual points
        GL_LINES        pairs of vertices interpreted as individual line segments
        GL_LINE_STRIP   series of connected line segments
        GL_LINE_LOOP    same as above, with a segment added between last and
                        first vertices
        GL_TRIANGLES    triples of vertices interpreted as triangles
        GL_TRIANGLE_STRIP linked strip of triangles
        GL_TRIANGLE_FAN linked fan of triangles
        GL_QUADS        quadruples of vertices interpreted as foursided
                        polygons
        GL_QUAD_STRIP   linked strip of quadrilaterals
        GL_POLYGON      boundary of a simple, convex polygon



        */

        //start processing buffered openGl
        //routines
        glFlush();

}
void init(void)
{

    //select clearing background
    glClearColor(0.0,0.0,0.0,0.0);
    //initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
/*declaring initial window size
position,and display mode
open window with "Hello"
in its title bar call initialization routins
Register callback function to display graphics
Enter main loop and process events


*/

int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(250,250);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;//requires C to return init
}
