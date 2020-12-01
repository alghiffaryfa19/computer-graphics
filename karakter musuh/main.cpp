#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON); /*kepala*/
		glColor3f(1, 0.647, 0);
		glVertex2f(7, 16);
		glVertex2f(7, 15);
		glVertex2f(10, 15);
		glVertex2f(10, 16);

	glEnd();

	glBegin(GL_QUADS); /*garis 2*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(8, 9);
		glVertex2f(8, 8);
		glVertex2f(6, 8);
		glVertex2f(6, 9);
	glEnd();

    glFlush();
}

void myinit() {
    glClearColor(50.0f/255.0f, 168.0f/255.0f, 82.0f/255.0f, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 30.0, -5.0, 30.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Karakter");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}
