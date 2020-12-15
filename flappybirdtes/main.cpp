#include<GL/gl.h>
#include<GL/glut.h>

#define COLUMNS 60
#define ROWS 60

#define FPS 10

#include <ctime>
#include<iostream>

#define NOB 10      //NOB = Number Of Bars

void initGrid(int ,int );
//void drawGrid();
void drawBall();
void drawBars();
void random(int &);

int prev_num=-1;
int gridX;
int gridY;
extern bool gameOver;
extern int score;

bool change=true;

int flag=0;
int posX=12,posY=30;

int posBarX[NOB]={55,110,165,220,275,330,385,430,485,530};
int posBarY[NOB]={24,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void initGrid(int x,int y)
{
    gridX=x;
    gridY=y;
}

void drawBall()
{
    glColor3f(0.0,1.0,0.0);
    glRectf(posX,posY,posX+1,posY+1);
    if(posY==0 || posY==gridX-1)
    {
        gameOver=true;
    }
    if(posX==posBarX[0] && (posY<=posBarY[0] || posY>=posBarY[0]+12))
    {
        gameOver=true;
    }
    else if(posX==posBarX[0])
    {
        score++;
    }
}

void drawBars()
{
    srand(time(NULL));
    if(flag==0)
    {
        for(int i=1;i<NOB;i++)
        {
            int num;
            random(num);
            posBarY[i]=num;
        }
        change=false;
        flag=1;
    }
    glColor3f(1.0,0.0,0.0);
    for(int i=0;i<NOB;i++)
    {
        for(int j=0;j<posBarY[i];j++)
        {
            glRectd(posBarX[i],j,posBarX[i]+5,j+1);
        }
        for(int j=posBarY[i]+12;j<gridY;j++)
        {
            glRectd(posBarX[i],j,posBarX[i]+5,j+1);
        }
    }
    for(int i=0;i<NOB;i++)
    {
        posBarX[i]--;
    }
    if(posBarX[0]==0)
    {
        for(int i=0;i<NOB-1;i++)
        {
            posBarX[i]=posBarX[i+1];
            posBarY[i]=posBarY[i+1];
        }
        posBarX[NOB-1]=posBarX[NOB-2]+15;
        change=true;
    }
    if(change==true)
    {
        int num;
        random(num);
        if(num>10)
            posBarY[NOB-1]=num;
        else
            posBarY[NOB-1]=num+12;
        change=false;
    }
}

void random(int &num)
{
    int _max=gridY-12;
    int _min=1;
    num=_min + rand()%(_max - _min);
    std::cout<<num<<std::endl;
    if(num==prev_num+3)
    {
        if(num>6)
        {
            num+=6;
        }
        else
        {
            num-=5;
        }
    }
    else if(num==prev_num+4)
    {
        if(num>8)
        {
            num+=8;
        }
        else
        {
            num-=7;
        }
    }
    prev_num=num;
}

bool gameOver=false;
int score=0;

extern int posY;

void timer_callback(int);
void display_callback();
void reshape_callback(int,int);
void keyboard_callback(int,int,int);

void background() {

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

void init()
{

glClearColor(50.0f/255.0f, 168.0f/255.0f, 82.0f/255.0f, 1.0);
    initGrid(COLUMNS,ROWS);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(350,40);
    glutCreateWindow("FLIP FLOP");

    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();
return 0;
}

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    background();
//    drawGrid();
    drawBars();
    drawBall();
    glutSwapBuffers();
    if(gameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50]="Your Score: ";
        strcat(text,_score);
        MessageBox(NULL,text,"Game Over",0);
        exit(0);
    }
}

void reshape_callback(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

void keyboard_callback(int key,int,int)
{
    if(key==GLUT_KEY_UP)
    {
        posY++;
    }
    else if(key==GLUT_KEY_DOWN)
    {
        posY--;
    }
}
