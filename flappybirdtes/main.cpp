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
int angle;

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

float horizontalMove;
float verticalMove;

// Collider
float posisiX[2] = {0, 10};
float posisiY[2] = {0, 10};

void karakter() {


	glBegin(GL_POLYGON); /*garis 1*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+8, posY+10);
		glVertex2f(posX+8, posY+9);
		glVertex2f(posX+14, posY+9);
		glVertex2f(posX+14, posY+10);

	glEnd();

	glBegin(GL_QUADS); /*garis 2*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+8, posY+9);
		glVertex2f(posX+8, posY+8);
		glVertex2f(posX+6, posY+8);
		glVertex2f(posX+6, posY+9);
	glEnd();

	glBegin(GL_QUADS); /*garis 3*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+6, posY+8);
		glVertex2f(posX+6, posY+7);
		glVertex2f(posX+5, posY+7);
		glVertex2f(posX+5, posY+8);
	glEnd();

	glBegin(GL_QUADS); /*garis 4*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+7, posY+7);
		glVertex2f(posX+7, posY+6);
		glVertex2f(posX+3, posY+6);
		glVertex2f(posX+3, posY+7);
	glEnd();

	glBegin(GL_QUADS); /*garis 5*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+3, posY+6);
		glVertex2f(posX+3, posY+3);
		glVertex2f(posX+2, posY+3);
		glVertex2f(posX+2, posY+6);
	glEnd();

    glBegin(GL_QUADS); /*garis 6*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+4, posY+3);
		glVertex2f(posX+4, posY+2);
		glVertex2f(posX+3, posY+2);
		glVertex2f(posX+3, posY+3);
	glEnd();

	glBegin(GL_POLYGON); /*garis 7*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+4, posY+2);
		glVertex2f(posX+7, posY+2);
		glVertex2f(posX+7, posY+1);
		glVertex2f(posX+5, posY+1);
		glVertex2f(posX+5, posY+0);
		glVertex2f(posX+4, posY+0);
	glEnd();

    glBegin(GL_QUADS); /*garis 8*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+7, posY+0);
		glVertex2f(posX+7, posY-1);
		glVertex2f(posX+5, posY-1);
		glVertex2f(posX+5, posY+0);
	glEnd();

	glBegin(GL_QUADS); /*garis 9*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+7, posY-1);
		glVertex2f(posX+7, posY-2);
		glVertex2f(posX+12, posY-2);
		glVertex2f(posX+12, posY-1);
	glEnd();

	glBegin(GL_QUADS); /*garis 10*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+12, posY+0);
		glVertex2f(posX+12, posY-1);
		glVertex2f(posX+17, posY-1);
		glVertex2f(posX+17, posY+0);
	glEnd();

	glBegin(GL_QUADS); /*garis 11*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+18, posY+0);
		glVertex2f(posX+17, posY+0);
		glVertex2f(posX+17, posY+1);
		glVertex2f(posX+18, posY+1);
	glEnd();

	glBegin(GL_QUADS); /*garis 12*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+12, posY+1);
		glVertex2f(posX+18, posY+1);
		glVertex2f(posX+18, posY+2);
		glVertex2f(posX+12, posY+2);
	glEnd();

	glBegin(GL_QUADS); /*garis 13*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+18, posY+2);
		glVertex2f(posX+19, posY+2);
		glVertex2f(posX+19, posY+3);
		glVertex2f(posX+18, posY+3);
	glEnd();

	glBegin(GL_QUADS); /*garis 14*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+12, posY+2);
		glVertex2f(posX+12, posY+3);
		glVertex2f(posX+11, posY+3);
		glVertex2f(posX+11, posY+2);
	glEnd();

	glBegin(GL_QUADS); /*garis 15*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+11, posY+2);
		glVertex2f(posX+10, posY+2);
		glVertex2f(posX+10, posY+1);
		glVertex2f(posX+11, posY+1);
	glEnd();

	glBegin(GL_QUADS); /*garis 16*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+11, posY+1);
		glVertex2f(posX+12, posY+1);
		glVertex2f(posX+12, posY+0);
		glVertex2f(posX+11, posY+0);
	glEnd();

	glBegin(GL_QUADS); /*garis 17*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+12, posY+3);
		glVertex2f(posX+18, posY+3);
		glVertex2f(posX+18, posY+4);
		glVertex2f(posX+12, posY+4);
	glEnd();

	glBegin(GL_QUADS); /*garis 18*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+16, posY+4);
		glVertex2f(posX+17, posY+4);
		glVertex2f(posX+17, posY+7);
		glVertex2f(posX+16, posY+7);
	glEnd();

	glBegin(GL_QUADS); /*garis 19*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+16, posY+7);
		glVertex2f(posX+15, posY+7);
		glVertex2f(posX+15, posY+8);
		glVertex2f(posX+16, posY+8);
	glEnd();

	glBegin(GL_QUADS); /*garis 20*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+15, posY+8);
		glVertex2f(posX+14, posY+8);
		glVertex2f(posX+14, posY+9);
		glVertex2f(posX+15, posY+9);
	glEnd();

	glBegin(GL_QUADS); /*garis 21*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+11, posY+9);
		glVertex2f(posX+12, posY+9);
		glVertex2f(posX+12, posY+8);
		glVertex2f(posX+11, posY+8);
	glEnd();

	glBegin(GL_QUADS); /*garis 22*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+10, posY+8);
		glVertex2f(posX+11, posY+8);
		glVertex2f(posX+11, posY+5);
		glVertex2f(posX+10, posY+5);
	glEnd();

	glBegin(GL_QUADS); /*garis 23*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+11, posY+5);
		glVertex2f(posX+12, posY+5);
		glVertex2f(posX+12, posY+4);
		glVertex2f(posX+11, posY+4);
	glEnd();

	glBegin(GL_QUADS); /*garis 24*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+7, posY+6);
		glVertex2f(posX+8, posY+6);
		glVertex2f(posX+8, posY+5);
		glVertex2f(posX+7, posY+5);
	glEnd();

	glBegin(GL_QUADS); /*garis 25*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+8, posY+3);
		glVertex2f(posX+9, posY+3);
		glVertex2f(posX+9, posY+5);
		glVertex2f(posX+8, posY+5);
	glEnd();

	glBegin(GL_QUADS); /*garis 26*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+7, posY+3);
		glVertex2f(posX+8, posY+3);
		glVertex2f(posX+8, posY+2);
		glVertex2f(posX+7, posY+2);
	glEnd();

	glBegin(GL_QUADS); /*mata*/
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(posX+14, posY+7);
		glVertex2f(posX+15, posY+7);
		glVertex2f(posX+15, posY+5);
		glVertex2f(posX+14, posY+5);
	glEnd();

	glBegin(GL_QUADS); /*mulut atas*/
		glColor3f(1, 0.549, 0); /*oren*/
		glVertex2f(posX+12, posY+3);
		glVertex2f(posX+12, posY+2);
		glVertex2f(posX+18, posY+2);
		glVertex2f(posX+18, posY+3);
	glEnd();

	glBegin(GL_QUADS); /*mulut bawah*/
		glColor3f(1, 0.549, 0); /*oren*/
		glVertex2f(posX+12, posY+1);
		glVertex2f(posX+12, posY+0);
		glVertex2f(posX+17, posY+0);
		glVertex2f(posX+17, posY+1);
	glEnd();

	glBegin(GL_QUADS); /*mulut tengah*/
		glColor3f(1, 0.549, 0); /*oren*/
		glVertex2f(posX+11, posY+2);
		glVertex2f(posX+12, posY+2);
		glVertex2f(posX+12, posY+1);
		glVertex2f(posX+11, posY+1);
	glEnd();

	glBegin(GL_QUADS); /*badan 1*/
		glColor3f(0.855, 0.647, 0.125); /*goldenrod*/
		glVertex2f(posX+7, posY+0);
		glVertex2f(posX+7, posY-1);
		glVertex2f(posX+12, posY-1);
		glVertex2f(posX+12, posY+0);
	glEnd();

    glBegin(GL_QUADS); /*badan 2*/
		glColor3f(0.855, 0.647, 0.125); /*goldenrod*/
		glVertex2f(posX+7, posY+2);
		glVertex2f(posX+7, posY+1);
		glVertex2f(posX+10, posY+1);
		glVertex2f(posX+10, posY+2);
	glEnd();

	glBegin(GL_QUADS); /*badan 3*/
		glColor3f(0.855, 0.647, 0.125); /*goldenrod*/
		glVertex2f(posX+5, posY+1);
		glVertex2f(posX+5, posY+0);
		glVertex2f(posX+11, posY+0);
		glVertex2f(posX+11, posY+1);
	glEnd();

	glBegin(GL_QUADS); /*sayap1*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+4, posY+3);
		glVertex2f(posX+4, posY+2);
		glVertex2f(posX+7, posY+2);
		glVertex2f(posX+7, posY+3);
	glEnd();

	glBegin(GL_QUADS); /*sayap2*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+7, posY+4);
		glVertex2f(posX+7, posY+3);
		glVertex2f(posX+8, posY+3);
		glVertex2f(posX+8, posY+4);
	glEnd();

	glBegin(GL_QUADS); /*sayap3*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+4, posY+4);
		glVertex2f(posX+4, posY+3);
		glVertex2f(posX+3, posY+3);
		glVertex2f(posX+3, posY+4);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+9, posY+5);
		glVertex2f(posX+11, posY+5);
		glVertex2f(posX+11, posY+2);
		glVertex2f(posX+9, posY+2);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah2*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+11, posY+4);
		glVertex2f(posX+12, posY+4);
		glVertex2f(posX+12, posY+3);
		glVertex2f(posX+11, posY+3);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah3*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+8, posY+2);
		glVertex2f(posX+9, posY+2);
		glVertex2f(posX+9, posY+3);
		glVertex2f(posX+8, posY+3);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah4*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+8, posY+8);
		glVertex2f(posX+10, posY+8);
		glVertex2f(posX+10, posY+5);
		glVertex2f(posX+8, posY+5);
	glEnd();

	glBegin(GL_QUADS); /*badan tengah5*/
		glColor3f(1, 1, 0); /*kuning*/
		glVertex2f(posX+7, posY+7);
		glVertex2f(posX+7, posY+6);
		glVertex2f(posX+8, posY+6);
		glVertex2f(posX+8, posY+7);
	glEnd();

	glBegin(GL_QUADS); /*sayap atas*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(posX+4, posY+3);
		glVertex2f(posX+7, posY+3);
		glVertex2f(posX+7, posY+6);
		glVertex2f(posX+4, posY+6);
	glEnd();

	glBegin(GL_QUADS); /*sayap atas2*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(posX+7, posY+5);
		glVertex2f(posX+8, posY+5);
		glVertex2f(posX+8, posY+3);
		glVertex2f(posX+7, posY+3);
	glEnd();

    glBegin(GL_QUADS); /*sayap atas3*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(posX+4, posY+4);
		glVertex2f(posX+3, posY+4);
		glVertex2f(posX+3, posY+6);
		glVertex2f(posX+4, posY+6);
	glEnd();

    glBegin(GL_QUADS); /*badan atas*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(posX+8, posY+8);
		glVertex2f(posX+8, posY+9);
		glVertex2f(posX+11, posY+9);
		glVertex2f(posX+11, posY+8);
	glEnd();
	glFlush();

	glBegin(GL_QUADS); /*badan atas2*/
		glColor3f(1, 0.961, 0.933); /*seashell*/
		glVertex2f(posX+6, posY+7);
		glVertex2f(posX+6, posY+8);
		glVertex2f(posX+8, posY+8);
		glVertex2f(posX+8, posY+7);
	glEnd();

	glBegin(GL_QUADS); /*mata putih*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(posX+12, posY+9);
		glVertex2f(posX+12, posY+4);
		glVertex2f(posX+14, posY+4);
		glVertex2f(posX+14, posY+9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih2*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(posX+11, posY+8);
		glVertex2f(posX+12, posY+8);
		glVertex2f(posX+12, posY+5);
		glVertex2f(posX+11, posY+5);
	glEnd();

	glBegin(GL_QUADS); /*mata putih3*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(posX+15, posY+7);
		glVertex2f(posX+16, posY+7);
		glVertex2f(posX+16, posY+4);
		glVertex2f(posX+15, posY+4);
	glEnd();

	glBegin(GL_QUADS); /*mata putih4*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(posX+15, posY+8);
		glVertex2f(posX+14, posY+8);
		glVertex2f(posX+14, posY+7);
		glVertex2f(posX+15, posY+7);
	glEnd();

	glBegin(GL_QUADS); /*mata putih5*/
		glColor3f(1, 1, 1); /*putih*/
		glVertex2f(posX+14, posY+5);
		glVertex2f(posX+14, posY+4);
		glVertex2f(posX+15, posY+4);
		glVertex2f(posX+15, posY+5);
	glEnd();

	glFlush();
}




// Menggambar segitiga dengan titik putar berada di tengah object


void initGrid(int x,int y)
{
    gridX=x;
    gridY=y;
}

void drawBall()
{
    glColor3f(0.0,1.0,0.0);
   karakter();
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


void drawEnemy()
{
    srand(time(NULL));

    glColor3f(1.0,0.0,0.0);
    for(int i=0;i<NOB;i++)
    {
        for(int j=posBarY[i]+12;j<gridY;j++)
        {
            glBegin(GL_QUADS); /*kepala*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+16);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+15);
		glVertex2f(posBarX[i]+10+10, posBarY[i]+10+15);
		glVertex2f(posBarX[i]+10+10, posBarY[i]+10+16);
	glEnd();

	glBegin(GL_QUADS); /*kepala 2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+15);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+15);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+13);
	glEnd();

	glBegin(GL_QUADS); /*kepala 3*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+4, posBarY[i]+10+14);
		glVertex2f(posBarX[i]+10+4, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+14);
	glEnd();

	glBegin(GL_QUADS); /*kepala 4*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+14);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+14);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+13);
	glEnd();

	glBegin(GL_QUADS); /*kepala 5*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+12);
	glEnd();

	glBegin(GL_QUADS); /*kepala 6*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+13);
	glEnd();

	glBegin(GL_QUADS); /*badan*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+3);
	glEnd();

	glBegin(GL_QUADS); /*kaki kiri*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+2, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+1);
		glVertex2f(posBarX[i]+10+2, posBarY[i]+10+1);
	glEnd();

	glBegin(GL_QUADS); /*kaki kiri2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+4, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+4, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+3, posBarY[i]+10+3);
	glEnd();

	glBegin(GL_QUADS); /*badan*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+8);
	glEnd();

	glBegin(GL_QUADS); /*badan2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+10, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+10, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+8);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata3*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*bagian deket mata4*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+3);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+1);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+1);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+2);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah3*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+1);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+1);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+3);
	glEnd();

	glBegin(GL_QUADS); /*kaki bawah*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+3);
	glEnd();

	glBegin(GL_QUADS); /*kaki kanan*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+3);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+3);
	glEnd();

	glBegin(GL_QUADS); /*kaki kanan 2*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+2);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+1);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+1);
		glVertex2f(posBarX[i]+10+15, posBarY[i]+10+2);
	glEnd();

	glBegin(GL_QUADS); /*mata kiri*/
		glColor3f(0, 0.545, 0.545);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+10);
	glEnd();

	glBegin(GL_QUADS); /*mata kanan*/
		glColor3f(0, 0.545, 0.545);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+10);
	glEnd();

	glBegin(GL_QUADS); /*mata putih*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+13);
	glEnd();

	glBegin(GL_QUADS); /*mata putih2*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+13);
	glEnd();

    glBegin(GL_QUADS); /*mata putih3*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+5, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih4*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+9, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+7, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih5*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+8, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10, posBarY[i]+10+8);
	glEnd();

    glBegin(GL_QUADS); /*mata putih6*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10+10, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+10, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+12);
	glEnd();

	glBegin(GL_QUADS); /*mata putih7*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+10);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+12, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih8*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+9);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+8);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+9);
	glEnd();

	glBegin(GL_QUADS); /*mata putih*/
		glColor3f(1, 1, 1);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10+11, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+13);
	glEnd();

	glBegin(GL_QUADS); /*mata ujung*/
		glColor3f(1, 0.647, 0);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+13);
		glVertex2f(posBarX[i]+10+13, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+12);
		glVertex2f(posBarX[i]+10+14, posBarY[i]+10+13);
	glEnd();

    glFlush();
        }
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
    glutInitWindowSize(720,480);
    glutInitWindowPosition(350,40);
    glutCreateWindow("FLIP FLOP");

    glutDisplayFunc(utama);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();
return 0;
}

void utama()
{
    glClear(GL_COLOR_BUFFER_BIT);
    background();
//    drawGrid();
    drawBars();
    drawBall();
    drawEnemy();
    glutSwapBuffers();
    if(gameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50]="Skor Akhir: ";
        strcat(text,_score);
        MessageBox(NULL,text,"Gim Berakhir",0);
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
