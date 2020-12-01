#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <time.h>
#include <stdlib.h>

 

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif
 
#define RAD2DEG 180.0/M_PI
#define DEG2RAD M_PI/180.0
 

#define KEY_ESCAPE 27
 

#define KEY_UP 101
#define KEY_DOWN 103
#define KEY_LEFT 100
#define KEY_RIGHT 102
 

#define myTranslate2D(x,y) glTranslated(x, y, 0.0)
#define myScale2D(x,y) glScalef(x, y, 1.0)
#define myRotate2D(angle) glRotatef(RAD2DEG*angle, 0.0, 0.0, 1.0)
 

#define MAX_ACC_PLAYER  0.15
#define MAX_VELO_PLAYER 2
 

typedef struct {
    int width;
        int height;
        char* title;
 
        float field_of_view_angle;
        float z_near;
        float z_far;
} glutWindow;
 
typedef struct Coords {
    double x, y;
} Coords;
 
typedef struct {
    double  x, y, phi, dx, dy, vmax, vmax2, radius;
} Player;
 

 
static void initialize ();
 

void keyboard (unsigned char, int, int);
void keyPress (int, int, int);
void keyRelease (int, int, int);
 
void myTimer (int);
 

void drawPlayer (Player *p);
void movePlayer ();
void checkMapBoundries ();
 

void display ();
void myReshape (int, int);
 
void setWindowValues ();
 

 
static glutWindow win;
 

static int up = 0;
static int down = 0;
static int left = 0;
static int right = 0;
 
static double x2;
static double y2;
static Player player;
static Coords coords;
 

 
int main (int argc, char **argv) {
 
    setWindowValues();
 
    srand((unsigned int) time(NULL));
 
    
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  
    glutInitWindowSize(win.width, win.height); 
    glutCreateWindow(win.title); 
    glutDisplayFunc(display); 
    glutIdleFunc(display); 
 
    
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyPress);
    glutSpecialUpFunc(keyRelease); 
 
    glutReshapeFunc(myReshape);
    glutTimerFunc(33, myTimer, 0);
 
    initialize();
 
    glutMainLoop(); 
 
    return 0;
}
 
static void initialize () {
    player.x = 50.0;
    player.y = 50.0;
    player.dx = player. dy = 0;
    player.vmax = MAX_VELO_PLAYER;
    player.vmax2 = MAX_VELO_PLAYER * MAX_VELO_PLAYER;
 
}
 
void keyboard ( unsigned char key, int mousePositionX, int mousePositionY ) {
 
    switch (key) {
 
        
        case KEY_ESCAPE:
            exit (0);
            break;
 
        default:
            break;
    }
}
 

void keyPress (int key, int x, int y) {
 
    switch (key) {
        case KEY_LEFT:
            left = 1;
            break;
 
        case KEY_UP:
            up = 1;
            break;
 
        case KEY_RIGHT:
            right = 1;
            break;
 
        case KEY_DOWN:
            down = 1;
            break;
 
        default:
            break;
    }
}
 

void keyRelease (int key, int x, int y) {
 
    switch (key) {
        case KEY_LEFT:
            left = 0;
            break;
 
        case KEY_UP:
            up = 0;
            break;
 
        case KEY_RIGHT:
            right = 0;
            break;
 
        case KEY_DOWN:
            down = 0;
            break;
 
        default:
            break;
    }
}
 

void myTimer (int value) {
 
    movePlayer();
    checkMapBoundries();
 
    glutPostRedisplay();
    glutTimerFunc(33, myTimer, value);      
 
}
 
void movePlayer () {
 
     
    if(left && right) {
        
    }
    else if(left == 1) {
        player.phi = player.phi + DEG2RAD * 11.5; 
    }
    else if(right == 1) {
        player.phi = player.phi - DEG2RAD * 11.5;
    }
 
    
    if(up && down) {
        
        player.dx = 0.0;
        player.dy = 0.0;
    }
    
    else if(up == 1) {
        player.dx = player.dx - MAX_ACC_PLAYER * sin(player.phi);
        player.dy = player.dy + MAX_ACC_PLAYER * cos(player.phi);
    }
    
    else if(down == 1) {
        player.dx = player.dx + (MAX_ACC_PLAYER - 0.09) * sin(player.phi);
        player.dy = player.dy - (MAX_ACC_PLAYER - 0.09) * cos(player.phi);
    }
    
    else if (up == 0 && down == 0) {
 
        if (player.dx > 0) {
            player.dx -= 0.2;
        }
 
        if (player.dy > 0) {
            player.dy -= 0.2;
        }
 
        if (player.dx < 0 || player.dy < 0) {
            player.dx = 0;
            player.dy = 0;
        }
    }
 
    double temp;
    
    if(down == 1 && (temp = (player.dx * player.dx + player.dy * player.dy)) > (player.vmax)) {
        temp = player.vmax / sqrt(temp);
        player.dx *= temp - 0.5;
        player.dy *= temp - 0.5;
    }
     
    else if((temp = (player.dx * player.dx + player.dy * player.dy)) > player.vmax2) {
        temp = player.vmax / sqrt(temp);
        player.dx *= temp;
        player.dy *= temp;
    }
 
    
    player.x = player.x + player.dx;
    player.y = player.y + player.dy;
 
} 
 

void checkMapBoundries () {
 
    if(player.x > win.width) {
        player.x = win.width;
    }
    if(player.x < 0) {
        player.x = 0;
    }
    if(player.y > win.height) {
        player.y = win.height;
    }
    if(player.y < 0) {
        player.y = 0;
    }
}
 

void display () {
 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-3.0f);
 
    drawPlayer(&player);
 
    glutSwapBuffers();
}
 

void myReshape (int w, int h) {
 
    glMatrixMode(GL_PROJECTION); 
    glViewport(0, 0, win.width, win.height); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    
 
    glOrtho(0.0, win.width, 0.0, win.height, win.z_near, win.z_far);
    
 
    glMatrixMode(GL_MODELVIEW); 
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );                                                                                                               // specify the clear value for the depth buffer
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ); 
    glClearColor(0.0, 0.0, 0.02, 1.0); 
 
}
 

void setWindowValues () {
 
    win.width = 640;
    win.height = 480;
    win.title = "AGIP";
    win.field_of_view_angle = 0;
    win.z_near = 1.0f;
    win.z_far = 100.0f;
}
 

 
void drawPlayer (Player *p) {
 
    glLineWidth(1.5);
    glEnable( GL_LINE_SMOOTH );
    glColor3f(0.2f, 0.9f, 1.0f);
    glPushMatrix();
        myTranslate2D(p->x, p->y);
        myRotate2D(p->phi);
        myScale2D(5,5);
        /* Starting position */
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
    glPopMatrix();
}