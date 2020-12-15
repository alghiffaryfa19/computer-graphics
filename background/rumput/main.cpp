#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS); /*garis hijau*/
		glColor3f(0, 0.392, 0);
		glVertex2f(1, 6);
		glVertex2f(1, 7);
		glVertex2f(4, 7);
		glVertex2f(4, 6);
	glEnd();

	glBegin(GL_QUADS); /*garis hijau*/
		glColor3f(0, 0.392, 0);
		glVertex2f(4, 6);
		glVertex2f(4, 5);
		glVertex2f(7, 5);
		glVertex2f(7, 6);
	glEnd();

    glFlush();
}

void myinit() {
    glClearColor(50.0f/255.0f, 168.0f/255.0f, 82.0f/255.0f, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 60.0, 0.0, 60.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("apartemen");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}
