
#include <stdlib.h>
#include <GL/glut.h>

// light position
GLfloat xl=-1.5,yl=1.5,zl=1.5;

// initial camera position
GLfloat eyex=4,eyey=4,eyez=4;

// material properties
	GLfloat mat_ambient[]   = { 1.0 , 1.0 , 1.0 , 1.0 };
	GLfloat mat_diffuse[]   = { 0.01 , 0.01 , 0.01 , 1.0 };
	GLfloat mat_specular[]  = { 0.01 , 0.01 , 0.01 , 1.0 };
	GLfloat mat_emission[]  = { 1.0 , 1.0 , 0.0 , 0.0 };
	GLfloat mat_shininess[] = { 32 };

void myInit()
{
	// clear color, it will be the "background"
	glClearColor(0.3 , 0.3 , 0.8 , 1.0);

	// enable depth test
	glEnable();

	// enable lighting and the first light source
	glEnable(  );
	glEnable(  );

	// let OpenGL normalize the normal vectors
	glEnable(  );

	// interpolate the colors on the surface of the polygon "smoothly"
	glShadeModel(  );

	// define properties of the light source, at a point
	GLfloat light_position[] = {xl,yl,zl,1};
	GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
	GLfloat light_ambient[] = {0.2,0.2,0.2,1.0};
	GLfloat light_specular[] = {1.0,1.0,1.0,1.0};

	// assign the above properties to light source 0
	glLightfv(GL_LIGHT0 , GL_POSITION , light_position);
	glLightfv(GL_LIGHT0 , GL_DIFFUSE , light_diffuse);
	glLightfv(GL_LIGHT0 , GL_AMBIENT , light_ambient);
	glLightfv(GL_LIGHT0 , GL_SPECULAR , light_specular);
}

void triangle () {
	glBegin(GL_POLYGON);
		glVertex3f(  );
		glVertex3f(  );
		glVertex3f(  );
	glEnd();
}

void display(void)
{
	// define the projection matrix below
	GLint i;
	GLfloat m[16];
	// clear it to 0 initially
	for (i=0; i<=15; i++) { m[i]=0.0; }
	// now, assign the required elements to do the projection
	// m[0]= ;   m[5]= ;   m[10]= ;   m[7]= ;


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// placing camera
	gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);

	/*
	// set the properties for a small, yellow sphere which will be rendered in the
	// same position as the source of the light
	mat_ambient[0]=  ; mat_ambient[1]=  ; mat_ambient[2]=  ;
	mat_diffuse[0]=  ; mat_diffuse[1]=  ; mat_diffuse[2]=  ;
	mat_specular[0]=  ; mat_specular[1]=  ; mat_specular[2]=  ;
	mat_emission[0]=  ; mat_emission[1]=  ; mat_emission[2]=  ;
	mat_shininess[0]=20.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	// render the small, yellow sphere which will look like it is
	// "lighting up" the scene
	glPushMatrix();
	glTranslatef(   );
	glutSolidSphere(0.15,10,8);
	glPopMatrix();
	// turn off emission for the rest of the objects
	mat_emission[0]=0.0; mat_emission[1]=0.0; mat_emission[2]=0.0;
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	*/

	// set the material properties of the bronze triangle
	mat_ambient[0]=  ; mat_ambient[1]=   ; mat_ambient[2]=  ;
	mat_diffuse[0]=  ; mat_diffuse[1]=   ; mat_diffuse[2]=  ;
	mat_specular[0]=  ; mat_specular[1]=  ; mat_specular[2]=  ;
	mat_shininess[0]=25.6;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	// render the bronze triangle
	triangle();


	// set the material properties for the bottom wall
	mat_ambient[0]=0.0; mat_ambient[1]=1.0; mat_ambient[2]=0.0;
	mat_diffuse[0]=0.2;mat_diffuse[1]=0.2; mat_diffuse[2]=0.2;
	mat_specular[0]=0.2;mat_specular[1]=0.5;mat_specular[2]=0.2;
	mat_shininess[0]=5;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	// render the bottom wall
	glBegin(GL_POLYGON);
		glVertex3f(-5,-0.01,-5);
		glVertex3f(-5,-0.01,5);
		glVertex3f(5,-0.01,5);
		glVertex3f(5,-0.01,-5);
	glEnd();

	/*
	// set the material properties of the shadow
	mat_ambient[0]=0.0; mat_ambient[1]=0.0; mat_ambient[2]=0.0;
	mat_diffuse[0]=0.0;mat_diffuse[1]=0.0; mat_diffuse[2]=0.0;
	mat_specular[0]=0.0;mat_specular[1]=0.0;mat_specular[2]=0.0;
	mat_shininess[0]=5;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	// project the shadow onto the flat plate
	glPushMatrix();
	glTranslatef(xl,yl,zl);
	glMultMatrixf(m);
	glTranslatef(-xl,-yl,-zl);
	triangle();
	glPopMatrix();
	*/

	glutSwapBuffers();
}


void keyboard (unsigned char key, int x , int y)
{

/* keyboard callback, selects an axis about which to rotate */

	if (key=='1') {eyex+=0.2;glutPostRedisplay();}
	if (key=='2') {eyex-=0.2;glutPostRedisplay();}
	if (key=='5') {eyey+=0.2;glutPostRedisplay();}
	if (key=='6') {eyey-=0.2;glutPostRedisplay();}
	if (key=='9') {eyez+=0.2;glutPostRedisplay();}
	if (key=='0') {eyez-=0.2;glutPostRedisplay();}

	if (key=='q' || key=='Q') exit(0);

}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(60, (double) w/h , 1,20);
    glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("colorcube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

	myInit();

	glutMainLoop();
}
