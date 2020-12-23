#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON); /*garis 1*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(8, 10);
		glVertex2f(8, 9);
		glVertex2f(14, 9);
		glVertex2f(14, 10);

	glEnd();

	glBegin(GL_QUADS); /*garis 2*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(8, 9);
		glVertex2f(8, 8);
		glVertex2f(6, 8);
		glVertex2f(6, 9);
	glEnd();

	glBegin(GL_QUADS); /*garis 3*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(6, 8);
		glVertex2f(6, 7);
		glVertex2f(5, 7);
		glVertex2f(5, 8);
	glEnd();

	glBegin(GL_QUADS); /*garis 4*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(7, 7);
		glVertex2f(7, 6);
		glVertex2f(3, 6);
		glVertex2f(3, 7);
	glEnd();

	glBegin(GL_QUADS); /*garis 5*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(3, 6);
		glVertex2f(3, 3);
		glVertex2f(2, 3);
		glVertex2f(2, 6);
	glEnd();

    glBegin(GL_QUADS); /*garis 6*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(4, 3);
		glVertex2f(4, 2);
		glVertex2f(3, 2);
		glVertex2f(3, 3);
	glEnd();

	glBegin(GL_POLYGON); /*garis 7*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(4, 2);
		glVertex2f(7, 2);
		glVertex2f(7, 1);
		glVertex2f(5, 1);
		glVertex2f(5, 0);
		glVertex2f(4, 0);
	glEnd();

    glBegin(GL_QUADS); /*garis 8*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(7, 0);
		glVertex2f(7, -1);
		glVertex2f(5, -1);
		glVertex2f(5, 0);
	glEnd();

	glBegin(GL_QUADS); /*garis 9*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(7, -1);
		glVertex2f(7, -2);
		glVertex2f(12, -2);
		glVertex2f(12, -1);
	glEnd();

	glBegin(GL_QUADS); /*garis 10*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(12, 0);
		glVertex2f(12, -1);
		glVertex2f(17, -1);
		glVertex2f(17, 0);
	glEnd();

	glBegin(GL_QUADS); /*garis 11*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(18, 0);
		glVertex2f(17, 0);
		glVertex2f(17, 1);
		glVertex2f(18, 1);
	glEnd();

	glBegin(GL_QUADS); /*garis 12*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(12, 1);
		glVertex2f(18, 1);
		glVertex2f(18, 2);
		glVertex2f(12, 2);
	glEnd();

	glBegin(GL_QUADS); /*garis 13*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(18, 2);
		glVertex2f(19, 2);
		glVertex2f(19, 3);
		glVertex2f(18, 3);
	glEnd();

	glBegin(GL_QUADS); /*garis 14*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(12, 2);
		glVertex2f(12, 3);
		glVertex2f(11, 3);
		glVertex2f(11, 2);
	glEnd();

	glBegin(GL_QUADS); /*garis 15*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(11, 2);
		glVertex2f(10, 2);
		glVertex2f(10, 1);
		glVertex2f(11, 1);
	glEnd();

	glBegin(GL_QUADS); /*garis 16*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(11, 1);
		glVertex2f(12, 1);
		glVertex2f(12, 0);
		glVertex2f(11, 0);
	glEnd();

	glBegin(GL_QUADS); /*garis 17*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(12, 3);
		glVertex2f(18, 3);
		glVertex2f(18, 4);
		glVertex2f(12, 4);
	glEnd();

	glBegin(GL_QUADS); /*garis 18*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(16, 4);
		glVertex2f(17, 4);
		glVertex2f(17, 7);
		glVertex2f(16, 7);
	glEnd();

	glBegin(GL_QUADS); /*garis 19*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(16, 7);
		glVertex2f(15, 7);
		glVertex2f(15, 8);
		glVertex2f(16, 8);
	glEnd();

	glBegin(GL_QUADS); /*garis 20*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(15, 8);
		glVertex2f(14, 8);
		glVertex2f(14, 9);
		glVertex2f(15, 9);
	glEnd();

	glBegin(GL_QUADS); /*garis 21*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(11, 9);
		glVertex2f(12, 9);
		glVertex2f(12, 8);
		glVertex2f(11, 8);
	glEnd();

	glBegin(GL_QUADS); /*garis 22*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(10, 8);
		glVertex2f(11, 8);
		glVertex2f(11, 5);
		glVertex2f(10, 5);
	glEnd();

	glBegin(GL_QUADS); /*garis 23*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(11, 5);
		glVertex2f(12, 5);
		glVertex2f(12, 4);
		glVertex2f(11, 4);
	glEnd();

	glBegin(GL_QUADS); /*garis 24*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(7, 6);
		glVertex2f(8, 6);
		glVertex2f(8, 5);
		glVertex2f(7, 5);
	glEnd();

	glBegin(GL_QUADS); /*garis 25*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(8, 3);
		glVertex2f(9, 3);
		glVertex2f(9, 5);
		glVertex2f(8, 5);
	glEnd();

	glBegin(GL_QUADS); /*garis 26*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(7, 3);
		glVertex2f(8, 3);
		glVertex2f(8, 2);
		glVertex2f(7, 2);
	glEnd();

	glBegin(GL_QUADS); /*mata*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(14, 7);
		glVertex2f(15, 7);
		glVertex2f(15, 5);
		glVertex2f(14, 5);
	glEnd();

	glBegin(GL_QUADS); /*mulut atas*/
		glColor3f(1, 0.549, 0); /*oren*/
		glVertex2f(12, 3);
		glVertex2f(12, 2);
		glVertex2f(18, 2);
		glVertex2f(18, 3);
	glEnd();

	glBegin(GL_QUADS); /*mulut bawah*/
		glColor3f(1, 0.549, 0); /*oren*/
		glVertex2f(12, 1);
		glVertex2f(12, 0);
		glVertex2f(17, 0);
		glVertex2f(17, 1);
	glEnd();

	glBegin(GL_QUADS); /*mulut tengah*/
		glColor3f(1, 0.549, 0); /*oren*/
		glVertex2f(11, 2);
		glVertex2f(12, 2);
		glVertex2f(12, 1);
		glVertex2f(11, 1);
	glEnd();

	glBegin(GL_QUADS); /*badan 1*/
		glColor3f(0.855, 0.647, 0.125); /*goldenrod*/
		glVertex2f(7, 0);
		glVertex2f(7, -1);
		glVertex2f(12, -1);
		glVertex2f(12, 0);
	glEnd();

    glBegin(GL_QUADS); /*badan 2*/
		glColor3f(0.855, 0.647, 0.125); /*goldenrod*/
		glVertex2f(7, 2);
		glVertex2f(7, 1);
		glVertex2f(10, 1);
		glVertex2f(10, 2);
	glEnd();

	glBegin(GL_QUADS); /*badan 3*/
		glColor3f(0.855, 0.647, 0.125); /*goldenrod*/
		glVertex2f(5, 1);
		glVertex2f(5, 0);
		glVertex2f(11, 0);
		glVertex2f(11, 1);
	glEnd();

	glBegin(GL_QUADS); /*sayap1*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(4, 3);
		glVertex2f(4, 2);
		glVertex2f(7, 2);
		glVertex2f(7, 3);
	glEnd();

	glBegin(GL_QUADS); /*sayap2*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(7, 4);
		glVertex2f(7, 3);
		glVertex2f(8, 3);
		glVertex2f(8, 4);
	glEnd();

	glBegin(GL_QUADS); /*sayap3*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(4, 4);
		glVertex2f(4, 3);
		glVertex2f(3, 3);
		glVertex2f(3, 4);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(9, 5);
		glVertex2f(11, 5);
		glVertex2f(11, 2);
		glVertex2f(9, 2);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah2*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(11, 4);
		glVertex2f(12, 4);
		glVertex2f(12, 3);
		glVertex2f(11, 3);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah3*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(8, 2);
		glVertex2f(9, 2);
		glVertex2f(9, 3);
		glVertex2f(8, 3);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah4*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(8, 8);
		glVertex2f(10, 8);
		glVertex2f(10, 5);
		glVertex2f(8, 5);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah5*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(7, 7);
		glVertex2f(7, 6);
		glVertex2f(8, 6);
		glVertex2f(8, 7);
	glEnd();

	glBegin(GL_QUADS); /*sayap atas*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(4, 3);
		glVertex2f(7, 3);
		glVertex2f(7, 6);
		glVertex2f(4, 6);
	glEnd();

	glBegin(GL_QUADS); /*sayap atas2*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(7, 5);
		glVertex2f(8, 5);
		glVertex2f(8, 3);
		glVertex2f(7, 3);
	glEnd();

    glBegin(GL_QUADS); /*sayap atas3*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(4, 4);
		glVertex2f(3, 4);
		glVertex2f(3, 6);
		glVertex2f(4, 6);
	glEnd();

    glBegin(GL_QUADS); /*badan atas*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(8, 8);
		glVertex2f(8, 9);
		glVertex2f(11, 9);
		glVertex2f(11, 8);
	glEnd();
	glFlush();

	glBegin(GL_QUADS); /*badan atas2*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(6, 7);
		glVertex2f(6, 8);
		glVertex2f(8, 8);
		glVertex2f(8, 7);
	glEnd();

	glBegin(GL_QUADS); /*mata putih*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(12, 9);
		glVertex2f(12, 4);
		glVertex2f(14, 4);
		glVertex2f(14, 9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih2*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(11, 8);
		glVertex2f(12, 8);
		glVertex2f(12, 5);
		glVertex2f(11, 5);
	glEnd();

	glBegin(GL_QUADS); /*mata putih3*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(15, 7);
		glVertex2f(16, 7);
		glVertex2f(16, 4);
		glVertex2f(15, 4);
	glEnd();

	glBegin(GL_QUADS); /*mata putih4*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(15, 8);
		glVertex2f(14, 8);
		glVertex2f(14, 7);
		glVertex2f(15, 7);
	glEnd();

	glBegin(GL_QUADS); /*mata putih5*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(14, 5);
		glVertex2f(14, 4);
		glVertex2f(15, 4);
		glVertex2f(15, 5);
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
