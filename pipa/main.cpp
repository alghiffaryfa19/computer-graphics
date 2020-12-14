#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void displayMe(void){
//baground
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
        glVertex2d(-700, 700);
        glVertex2d(700, 700);
        glVertex2d(700, -700);
        glVertex2d(-700, -700);
    glEnd();
    glFlush();

//atas hitam kiri
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-6.2, 7.2);
        glVertex2f(-6.08, 7.2);
        glVertex2f(-6.08, 5.4);
        glVertex2f(-6.2, 5.4);
    glEnd();
    glFlush();

//atas hitam atas
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-6.2, 7.2);
        glVertex2f(-6.2, 7.08);
        glVertex2f(-2.6, 7.08);
        glVertex2f(-2.6, 7.2);
    glEnd();
    glFlush();

//atas hitam kanan
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-2.6, 7.2);
        glVertex2f(-2.71, 7.2);
        glVertex2f(-2.72, 5.4);
        glVertex2f(-2.6, 5.4);
    glEnd();
    glFlush();

//atas hitam bawah
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-2.61, 5.52);
        glVertex2f(-2.6, 5.4);
        glVertex2f(-6.2, 5.4);
        glVertex2f(-6.19, 5.52);
    glEnd();
    glFlush();

//atas hijau tua bawah
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(26, 130, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-6.08, 5.64);
        glVertex2f(-6.08, 5.52);
        glVertex2f(-2.70, 5.52);
        glVertex2f(-2.70, 5.64);
    glEnd();
    glFlush();

//atas hijau muda kiri
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 6);
    glBegin(GL_POLYGON);
        glVertex2f(-6.08, 7.08);
        glVertex2f(-6.08, 5.64);
        glVertex2f(-5.96, 5.64);
        glVertex2f(-5.95, 7.08);
    glEnd();
    glFlush();

//atas hijau kuning muda kiri
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(214, 255, 117);
    glBegin(GL_POLYGON);
        glVertex2f(-5.96, 7.08);
        glVertex2f(-5.96, 5.64);
        glVertex2f(-5.84, 5.64);
        glVertex2f(-5.85, 7.08);
    glEnd();
    glFlush();

//atas hijau muda lebar
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(121, 217, 56);
    glBegin(GL_POLYGON);
        glVertex2f(-5.85, 6.91);
        glVertex2f(-5.85, 5.64);
        glVertex2f(-5.6, 5.64);
        glVertex2f(-5.6, 6.91);
    glEnd();
    glFlush();

//atas hijau kuning kecil
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(214, 255, 117);
    glBegin(GL_POLYGON);
        glVertex2f(-5.85, 7.08);
        glVertex2f(-5.85, 6.90);
        glVertex2f(-5.6, 6.90);
        glVertex2f(-5.6, 7.08);
    glEnd();
    glFlush();

//atas hijau kuning kanan
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(214, 255, 117);
    glBegin(GL_POLYGON);
        glVertex2f(-5.6, 7.08);
        glVertex2f(-5.6, 5.64);
        glVertex2f(-5.47, 5.64);
        glVertex2f(-5.47, 7.08);
    glEnd();
    glFlush();

//atas hijau kuning atas
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(214, 255, 117);
    glBegin(GL_POLYGON);
        glVertex2f(-5.48, 7.08);
        glVertex2f(-5.48, 6.92);
        glVertex2f(-3.4, 6.92);
        glVertex2f(-3.4, 7.08);
    glEnd();
    glFlush();

//atas hijau muda besar
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 6);
    glBegin(GL_POLYGON);
        glVertex2f(-5.48, 6.92);
        glVertex2f(-5.48, 5.64);
        glVertex2f(-3.4, 5.64);
        glVertex2f(-3.4, 6.92);
    glEnd();
    glFlush();

//atas hijau tua kanan 1
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(26, 130, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-3.4, 6.92);
        glVertex2f(-3.4, 5.64);
        glVertex2f(-3.17, 5.64);
        glVertex2f(-3.17, 6.92);
    glEnd();
    glFlush();

//atas hijau tua diatasnya kanan 1
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 6);
    glBegin(GL_POLYGON);
        glVertex2f(-3.4, 7.08);
        glVertex2f(-3.4, 6.92);
        glVertex2f(-3.16, 6.92);
        glVertex2f(-3.16, 7.08);
    glEnd();
    glFlush();

//atas hijau muda besar
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 6);
    glBegin(GL_POLYGON);
        glVertex2f(-3.16, 6.92);
        glVertex2f(-3.16, 5.64);
        glVertex2f(-3.04, 5.64);
        glVertex2f(-3.04, 6.92);
    glEnd();
    glFlush();

//atas hijau tua kanan 2
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(26, 130, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-3.04, 6.92);
        glVertex2f(-3.04, 5.64);
        glVertex2f(-2.70, 5.64);
        glVertex2f(-2.70, 6.92);
    glEnd();
    glFlush();

//atas hijau muda kecil
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(161, 222, 82);
    glBegin(GL_POLYGON);
        glVertex2f(-3.16, 7.08);
        glVertex2f(-3.16, 6.92);
        glVertex2f(-3.04, 6.92);
        glVertex2f(-3.04, 7.08);
    glEnd();
    glFlush();

//atas hijau tua diatasnya kanan 1
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 6);
    glBegin(GL_POLYGON);
        glVertex2f(-3.04, 7.08);
        glVertex2f(-3.04, 6.91);
        glVertex2f(-2.70, 6.91);
        glVertex2f(-2.70, 7.08);
    glEnd();
    glFlush();

//bawah hitam kiri
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-6.08, 5.4);
        glVertex2f(-6.08, 0.2);
        glVertex2f(-5.96, 0.2);
        glVertex2f(-5.96, 5.4);
    glEnd();
    glFlush();

//bawah hitam bawah
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-5.96, 0.32);
        glVertex2f(-5.96, 0.19);
        glVertex2f(-2.85, 0.19);
        glVertex2f(-2.85, 0.32);
    glEnd();
    glFlush();

//bawah hitam kanan
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-2.85, 5.4);
        glVertex2f(-2.85, 0.19);
        glVertex2f(-2.72, 0.19);
        glVertex2f(-2.72, 5.4);
    glEnd();
    glFlush();

//bawah hijau tua atas
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(26, 130, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-5.96, 5.4);
        glVertex2f(-5.96, 5.28);
        glVertex2f(-2.84, 5.28);
        glVertex2f(-2.84, 5.4);
    glEnd();
    glFlush();

//bawah hijau muda kiri
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 6);
    glBegin(GL_POLYGON);
        glVertex2f(-5.96, 5.28);
        glVertex2f(-5.96, 0.32);
        glVertex2f(-5.84, 0.32);
        glVertex2f(-5.84, 5.28);
    glEnd();
    glFlush();

//bawah hijau kuning 1
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(214, 255, 117);
    glBegin(GL_POLYGON);
        glVertex2f(-5.84, 5.28);
        glVertex2f(-5.84, 0.32);
        glVertex2f(-5.6, 0.32);
        glVertex2f(-5.6, 5.28);
    glEnd();
    glFlush();

//bawah hijau muda banget
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(121, 217, 56);
    glBegin(GL_POLYGON);
        glVertex2f(-5.6, 5.28);
        glVertex2f(-5.6, 0.32);
        glVertex2f(-5.24, 0.32);
        glVertex2f(-5.24, 5.28);
    glEnd();
    glFlush();

//bawah hijau kuning 2
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(214, 255, 117);
    glBegin(GL_POLYGON);
        glVertex2f(-5.24, 5.28);
        glVertex2f(-5.24, 0.32);
        glVertex2f(-5.12, 0.32);
        glVertex2f(-5.12, 5.28);
    glEnd();
    glFlush();

//bawah hijau muda lebar
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-5.12, 5.28);
        glVertex2f(-5.12, 0.32);
        glVertex2f(-3.52, 0.32);
        glVertex2f(-3.52, 5.28);
    glEnd();
    glFlush();

//bawah hijau tua kanan 1
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(26, 130, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-3.52, 5.28);
        glVertex2f(-3.52, 0.32);
        glVertex2f(-3.28, 0.32);
        glVertex2f(-3.28, 5.28);
    glEnd();
    glFlush();

//bawah hijau muda kanan
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(0, 163, 6);
    glBegin(GL_POLYGON);
        glVertex2f(-3.28, 5.28);
        glVertex2f(-3.28, 0.32);
        glVertex2f(-3.16, 0.32);
        glVertex2f(-3.16, 5.28);
    glEnd();
    glFlush();

//bawah hijau tua kanan 2
    glMatrixMode(GL_MODELVIEW);
    glColor3ub(26, 130, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-3.16, 5.28);
        glVertex2f(-3.16, 0.32);
        glVertex2f(-2.85, 0.32);
        glVertex2f(-2.85, 5.28);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hello world!");
	glutDisplayFunc(displayMe);
	gluOrtho2D(-18, -2, -2, 14);
	glutMainLoop();
}
