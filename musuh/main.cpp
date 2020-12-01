#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS); /*kepala*/
		glColor3f(1, 0.647, 0);
		glVertex2f(7, 16);
		glVertex2f(7, 15);
		glVertex2f(10, 15);
		glVertex2f(10, 16);
	glEnd();

	glBegin(GL_QUADS); /*kepala 2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(5, 15);
		glVertex2f(12, 15);
		glVertex2f(12, 13);
		glVertex2f(5, 13);
	glEnd();

	glBegin(GL_QUADS); /*kepala 3*/
		glColor3f(1, 0.647, 0);
		glVertex2f(4, 14);
		glVertex2f(4, 13);
		glVertex2f(5, 13);
		glVertex2f(5, 14);
	glEnd();

	glBegin(GL_QUADS); /*kepala 4*/
		glColor3f(1, 0.647, 0);
		glVertex2f(12, 14);
		glVertex2f(13, 14);
		glVertex2f(13, 13);
		glVertex2f(12, 13);
	glEnd();

	glBegin(GL_QUADS); /*kepala 5*/
		glColor3f(1, 0.647, 0);
		glVertex2f(3, 13);
		glVertex2f(6, 13);
		glVertex2f(6, 12);
		glVertex2f(3, 12);
	glEnd();

	glBegin(GL_QUADS); /*kepala 6*/
		glColor3f(1, 0.647, 0);
		glVertex2f(8, 13);
		glVertex2f(8, 12);
		glVertex2f(11, 12);
		glVertex2f(11, 13);
	glEnd();

	glBegin(GL_QUADS); /*badan*/
		glColor3f(1, 0.647, 0);
		glVertex2f(3, 12);
		glVertex2f(5, 12);
		glVertex2f(5, 3);
		glVertex2f(3, 3);
	glEnd();

	glBegin(GL_QUADS); /*kaki kiri*/
		glColor3f(1, 0.647, 0);
		glVertex2f(2, 10);
		glVertex2f(3, 10);
		glVertex2f(3, 1);
		glVertex2f(2, 1);
	glEnd();

	glBegin(GL_QUADS); /*kaki kiri2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(3, 2);
		glVertex2f(4, 2);
		glVertex2f(4, 3);
		glVertex2f(3, 3);
	glEnd();

	glBegin(GL_QUADS); /*badan*/
		glColor3f(1, 0.647, 0);
		glVertex2f(5, 8);
		glVertex2f(5, 3);
		glVertex2f(15, 3);
		glVertex2f(15, 8);
	glEnd();

	glBegin(GL_QUADS); /*badan2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(8, 9);
		glVertex2f(8, 8);
		glVertex2f(11, 8);
		glVertex2f(11, 9);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata*/
		glColor3f(1, 0.647, 0);
		glVertex2f(9, 12);
		glVertex2f(10, 12);
		glVertex2f(10, 9);
		glVertex2f(9, 9);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(5, 9);
		glVertex2f(6, 9);
		glVertex2f(6, 8);
		glVertex2f(5, 8);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata3*/
		glColor3f(1, 0.647, 0);
		glVertex2f(13, 9);
		glVertex2f(13, 8);
		glVertex2f(15, 8);
		glVertex2f(15, 9);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata4*/
		glColor3f(1, 0.647, 0);
		glVertex2f(14, 9);
		glVertex2f(14, 10);
		glVertex2f(15, 10);
		glVertex2f(15, 9);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah*/
		glColor3f(1, 0.647, 0);
		glVertex2f(5, 3);
		glVertex2f(5, 2);
		glVertex2f(7, 2);
		glVertex2f(7, 3);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(6, 2);
		glVertex2f(6, 1);
		glVertex2f(7, 1);
		glVertex2f(7, 2);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah3*/
		glColor3f(1, 0.647, 0);
		glVertex2f(9, 3);
		glVertex2f(9, 1);
		glVertex2f(11, 1);
		glVertex2f(11, 3);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah*/
		glColor3f(1, 0.647, 0);
		glVertex2f(11, 2);
		glVertex2f(12, 2);
		glVertex2f(12, 3);
		glVertex2f(11, 3);
	glEnd();

	glBegin(GL_QUADS); /*kaki kanan*/
		glColor3f(1, 0.647, 0);
		glVertex2f(13, 3);
		glVertex2f(13, 2);
		glVertex2f(15, 2);
		glVertex2f(15, 3);
	glEnd();

	glBegin(GL_QUADS); /*kaki kanan 2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(14, 2);
		glVertex2f(14, 1);
		glVertex2f(15, 1);
		glVertex2f(15, 2);
	glEnd();

	glBegin(GL_QUADS); /*mata kiri*/
		glColor3f(0, 0.545, 0.545);
		glVertex2f(7, 12);
		glVertex2f(9, 12);
		glVertex2f(9, 10);
		glVertex2f(7, 10);
	glEnd();

	glBegin(GL_QUADS); /*mata kanan*/
		glColor3f(0, 0.545, 0.545);
		glVertex2f(12, 12);
		glVertex2f(14, 12);
		glVertex2f(14, 10);
		glVertex2f(12, 10);
	glEnd();

	glBegin(GL_QUADS); /*mata putih*/
		glColor3f(1, 1, 1);
		glVertex2f(6, 12);
		glVertex2f(8, 12);
		glVertex2f(8, 13);
		glVertex2f(6, 13);
	glEnd();

	glBegin(GL_QUADS); /*mata putih2*/
		glColor3f(1, 1, 1);
		glVertex2f(6, 12);
		glVertex2f(8, 12);
		glVertex2f(8, 13);
		glVertex2f(6, 13);
	glEnd();

    glBegin(GL_QUADS); /*mata putih3*/
		glColor3f(1, 1, 1);
		glVertex2f(5, 12);
		glVertex2f(7, 12);
		glVertex2f(7, 9);
		glVertex2f(5, 9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih4*/
		glColor3f(1, 1, 1);
		glVertex2f(7, 10);
		glVertex2f(9, 10);
		glVertex2f(9, 9);
		glVertex2f(7, 9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih5*/
		glColor3f(1, 1, 1);
		glVertex2f(6, 9);
		glVertex2f(8, 9);
		glVertex2f(8, 8);
		glVertex2f(6, 8);
	glEnd();

    glBegin(GL_QUADS); /*mata putih6*/
		glColor3f(1, 1, 1);
		glVertex2f(10, 12);
		glVertex2f(10, 9);
		glVertex2f(12, 9);
		glVertex2f(12, 12);
	glEnd();

	glBegin(GL_QUADS); /*mata putih7*/
		glColor3f(1, 1, 1);
		glVertex2f(12, 10);
		glVertex2f(14, 10);
		glVertex2f(14, 9);
		glVertex2f(12, 9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih8*/
		glColor3f(1, 1, 1);
		glVertex2f(11, 9);
		glVertex2f(11, 8);
		glVertex2f(13, 8);
		glVertex2f(13, 9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih*/
		glColor3f(1, 1, 1);
		glVertex2f(11, 13);
		glVertex2f(11, 12);
		glVertex2f(13, 12);
		glVertex2f(13, 13);
	glEnd();

	glBegin(GL_QUADS); /*mata ujung*/
		glColor3f(1, 0.647, 0);
		glVertex2f(13, 13);
		glVertex2f(13, 12);
		glVertex2f(14, 12);
		glVertex2f(14, 13);
	glEnd();

    glFlush();
}

void myinit() {
    glClearColor(50.0f/255.0f, 168.0f/255.0f, 82.0f/255.0f, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 30.0, 0.0, 30.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Musuh");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}
