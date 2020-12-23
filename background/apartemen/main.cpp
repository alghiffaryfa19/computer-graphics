#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(4, 0);
		glVertex2f(6, 0);
		glVertex2f(6, 2);
		glVertex2f(4, 2);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(4, 0);
		glVertex2f(5, 0);
		glVertex2f(5, 10);
		glVertex2f(4, 10);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(4, 9);
		glVertex2f(4, 10);
		glVertex2f(13, 10);
		glVertex2f(13, 9);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(7, 9);
		glVertex2f(7, 13);
		glVertex2f(8, 13);
		glVertex2f(8, 9);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(8, 12);
		glVertex2f(8, 13);
		glVertex2f(13, 13);
		glVertex2f(13, 12);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(12, 13);
		glVertex2f(13, 13);
		glVertex2f(13, 6);
		glVertex2f(12, 6);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(14, 6);
		glVertex2f(14, 5);
		glVertex2f(9, 5);
		glVertex2f(9, 6);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(9, 5);
		glVertex2f(10, 5);
		glVertex2f(10, 0);
		glVertex2f(9, 0);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(10, 0);
		glVertex2f(8, 0);
		glVertex2f(8, 2);
		glVertex2f(10, 2);
    glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(14, 0);
		glVertex2f(15, 0);
		glVertex2f(15, 14);
		glVertex2f(14, 14);
	glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(14, 14);
		glVertex2f(14, 15);
		glVertex2f(18, 15);
		glVertex2f(18, 14);
	glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(15, 15);
		glVertex2f(16, 15);
		glVertex2f(16, 17);
		glVertex2f(15, 17);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(16, 17);
		glVertex2f(16, 16);
		glVertex2f(23, 16);
		glVertex2f(23, 17);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(18, 16);
		glVertex2f(18, 14);
		glVertex2f(19, 14);
		glVertex2f(19, 16);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(23, 16);
		glVertex2f(22, 16);
		glVertex2f(22, 0);
		glVertex2f(23, 0);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(13, 0);
		glVertex2f(14, 0);
		glVertex2f(14, 5);
		glVertex2f(13, 5);
	glEnd();

    glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(23, 13);
		glVertex2f(23, 14);
		glVertex2f(26, 14);
		glVertex2f(26, 13);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(25, 13);
		glVertex2f(25, 12);
		glVertex2f(26, 12);
		glVertex2f(26, 13);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(23, 12);
		glVertex2f(23, 11);
		glVertex2f(30, 11);
		glVertex2f(30, 12);
	glEnd();

	glBegin(GL_QUADS); /*garis biru*/
		glColor3f(0.529, 0.808, 0.922);
		glVertex2f(29, 0);
		glVertex2f(30, 0);
		glVertex2f(30, 11);
		glVertex2f(29, 11);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(9, 10);
		glVertex2f(10, 10);
		glVertex2f(10, 11);
		glVertex2f(9, 11);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(5, 8);
		glVertex2f(5, 6);
		glVertex2f(6, 6);
		glVertex2f(6, 8);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(7, 6);
		glVertex2f(8, 6);
		glVertex2f(8, 8);
		glVertex2f(7, 8);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(9, 8);
		glVertex2f(9, 6);
		glVertex2f(10, 6);
		glVertex2f(10, 8);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(5, 5);
		glVertex2f(5, 3);
		glVertex2f(6, 3);
		glVertex2f(6, 5);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(7, 5);
		glVertex2f(7, 3);
		glVertex2f(8, 3);
		glVertex2f(8, 5);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(11, 1);
		glVertex2f(11, 4);
		glVertex2f(12, 4);
		glVertex2f(12, 1);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(20, 15);
		glVertex2f(20, 14);
		glVertex2f(21, 14);
		glVertex2f(21, 15);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(16, 13);
		glVertex2f(16, 11);
		glVertex2f(17, 11);
		glVertex2f(17, 13);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(18, 13);
		glVertex2f(18, 11);
		glVertex2f(19, 11);
		glVertex2f(19, 13);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(20, 13);
		glVertex2f(20, 11);
		glVertex2f(21, 11);
		glVertex2f(21, 13);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(16, 10);
		glVertex2f(16, 8);
		glVertex2f(17, 8);
		glVertex2f(17, 10);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(18, 10);
		glVertex2f(18, 8);
		glVertex2f(19, 8);
		glVertex2f(19, 10);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(20, 10);
		glVertex2f(20, 8);
		glVertex2f(21, 8);
		glVertex2f(21, 10);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(16, 7);
		glVertex2f(16, 5);
		glVertex2f(17, 5);
		glVertex2f(17, 7);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(18, 7);
		glVertex2f(18, 5);
		glVertex2f(19, 5);
		glVertex2f(19, 7);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(20, 7);
		glVertex2f(20, 5);
		glVertex2f(21, 5);
		glVertex2f(21, 7);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(16, 4);
		glVertex2f(16, 2);
		glVertex2f(17, 2);
		glVertex2f(17, 4);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(18, 4);
		glVertex2f(18, 2);
		glVertex2f(19, 2);
		glVertex2f(19, 4);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(20, 4);
		glVertex2f(20, 2);
		glVertex2f(21, 2);
		glVertex2f(21, 4);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(25, 10);
		glVertex2f(25, 8);
		glVertex2f(26, 8);
		glVertex2f(26, 10);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(27, 10);
		glVertex2f(27, 8);
		glVertex2f(28, 8);
		glVertex2f(28, 10);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(25, 7);
		glVertex2f(25, 4);
		glVertex2f(26, 4);
		glVertex2f(26, 7);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(27, 7);
		glVertex2f(27, 4);
		glVertex2f(28, 4);
		glVertex2f(28, 7);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(25, 3);
		glVertex2f(25, 1);
		glVertex2f(26, 1);
		glVertex2f(26, 3);
	glEnd();

	glBegin(GL_QUADS); /*jendela*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(27, 3);
		glVertex2f(27, 1);
		glVertex2f(28, 1);
		glVertex2f(28, 3);
	glEnd();

	glBegin(GL_QUADS); /*bayangan*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(23, 13);
		glVertex2f(23, 12);
		glVertex2f(24, 12);
		glVertex2f(24, 13);
	glEnd();

	glBegin(GL_QUADS); /*bayangan*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(23, 0);
		glVertex2f(24, 0);
		glVertex2f(24, 11);
		glVertex2f(23, 11);
	glEnd();

	glBegin(GL_QUADS); /*bayangan*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(11, 6);
		glVertex2f(12, 6);
		glVertex2f(12, 9);
		glVertex2f(11, 9);
	glEnd();

	glBegin(GL_QUADS); /*bayangan*/
		glColor3f(0.565, 0.933, 0.565);
		glVertex2f(11, 10);
		glVertex2f(12, 10);
		glVertex2f(12, 12);
		glVertex2f(11, 12);
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
