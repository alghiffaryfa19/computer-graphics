#include<ctime>
#include<list>
#include<vector>
#include<string>
#include<sstream>
#include "mapstrip.h"
using namespace std;

void display();
void reshape(int, int); 
void getSpecialKey(int , int, int);
void getKey(unsigned char , int, int);
void timer(int); 

int score;
MapStrip* scrollBg[mapW];
list<EnemyShip> eShipList;
vector<list<EnemyShip>::iterator> destroyEship;
list<EnemyBullet> eBulletList;
vector<list<EnemyBullet>::iterator> destroyEbullet;
list<HeroBullet> hBulletList;
vector<list<HeroBullet>::iterator> destroyHbullet;
list<Explosion> expList;
vector<list<Explosion>::iterator> destroyExp;
HeroShip hShip(mapW/2, mapH/2);

void printBmpStr(int x, int y, int z, GLfloat r, GLfloat g, GLfloat b, string txt, void *font)
{
  glLoadIdentity();   
  glColor3f(r, g, b);// set text color
  glRasterPos3f(x, y, 0);// ste position for text to be ratsrized
  for (int i = 0; i < txt.size(); i++) 
	 glutBitmapCharacter(font, txt[i]);  
}

void initBg()
{
   glClearColor(0, 0, 0, 0);  
   for(int i = 0; i < mapW; i++)
      scrollBg[i] = new MapStrip(i);        
}

int main(int argc, char* argv[])
{
  srand(time(NULL));
  initBg();
  glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
  glutInitWindowSize (winW, winH);   
  glutCreateWindow("Lab Assesment 2");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(getKey);
  glutSpecialFunc(getSpecialKey);
  glutTimerFunc(100, timer, 0);  
  glutMainLoop();
}

void reshape(int w, int h)
{
    h = h==0 ? 1: h;											// Prevent A Divide By Zero By

	glViewport(0,0,w,h);							// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);							// Select The Projection Matrix
	glLoadIdentity();										// Reset The Projection Matrix

	glOrtho(0.0f,w,h,0.0f,-1.0f,1.0f);				// Create Ortho 800x640 View (0,0 At Top Left)

	glMatrixMode(GL_MODELVIEW);								// Select The Modelview Matrix
	glLoadIdentity();				
}

void display()
{
   stringstream oss1, oss2;
   oss1 << score;
   oss2 <<  hShip.getLives();  
   glClear(GL_COLOR_BUFFER_BIT);
   for(int i = 0; i < mapW; i++)
      scrollBg[i]->draw();
      
   for(list<EnemyShip>::iterator it = eShipList.begin(); it != eShipList.end(); it++)
      it->draw();
      
   for(list<EnemyBullet>::iterator it = eBulletList.begin(); it != eBulletList.end(); it++)
      it->draw();
       
   for(list<HeroBullet>::iterator it = hBulletList.begin(); it != hBulletList.end(); it++)
      it->draw();
   
   for(list<Explosion>::iterator it = expList.begin(); it != expList.end(); it++)
      it->draw();
         
   if(hShip.getLives() != 0)
      hShip.draw();
   else
       printBmpStr(400, 320, 0, 1, 0, 0,"GAME OVER", GLUT_BITMAP_9_BY_15);
   
   printBmpStr(20, 20, 0, 1, 0, 0,"SCORE: " + oss1.str() , GLUT_BITMAP_9_BY_15);
   printBmpStr(700, 20, 0, 1, 0, 0,"LIVES: " + oss2.str() , GLUT_BITMAP_9_BY_15);
           
   glFlush();
   glutSwapBuffers();
}

void timer(int val)
{
   int spawnShip = 2;  
   val = (val+1)%1000;
   bool destroyed;    
   
   if(val%20 == 0 && !eShipList.empty())
      for(list<EnemyShip>::iterator it = eShipList.begin(); it != eShipList.end(); it++)
         eBulletList.push_back(it->shoot());
   
   if(val%10 == 0)
      for(int i = 0; i < spawnShip; i++)
         eShipList.push_back(EnemyShip(mapW, rand()%mapH));
   
    
   for(int i = 0; i < mapW; i++)
      scrollBg[i]->update(20.0f); 
   
   if(hShip.getLives() > 0)
      hShip.update(10.0f);                 
   
   for(list<EnemyBullet>::iterator it = eBulletList.begin(); it != eBulletList.end(); it++)
   {
      it->update(20.0f);
      if(it->getXMap() == -1)
         destroyEbullet.push_back(it);
      else if(it->getXMap() == hShip.getXMap() && it->getYMap() == hShip.getYMap())
      {
         destroyEbullet.push_back(it);  
         hShip.takeDmg();
      }
            
            
   }
      
   for(list<EnemyShip>::iterator it = eShipList.begin(); it != eShipList.end(); it++)
   {
      it->update(10.0f);
      if(it->getXMap() == -1)
         destroyEship.push_back(it);
      else if(it->getXMap() == hShip.getXMap() && it->getYMap() == hShip.getYMap())
      {
         destroyEship.push_back(it);  
         hShip.takeDmg();
      }
   }
   
   for(list<HeroBullet>::iterator it = hBulletList.begin(); it != hBulletList.end(); it++)
   {
      it->update(20.0f);
      if(it->getXMap() == mapW)
         destroyHbullet.push_back(it);
      else
      {   
         for(list<EnemyBullet>::iterator eb = eBulletList.begin(); eb != eBulletList.end(); eb++)
            if(it->getXMap() == eb->getXMap() && it->getYMap() == eb->getYMap())
            {
               destroyEbullet.push_back(eb);
               destroyHbullet.push_back(it);
               score += 5;
               break;
            }
         
         for(list<EnemyShip>::iterator es = eShipList.begin(); es != eShipList.end(); es++)
            if(it->getXMap() == es->getXMap() && it->getYMap() == es->getYMap())
            {
               destroyEship.push_back(es);
               destroyHbullet.push_back(it);
               expList.push_back(Explosion(it->getXMap(), it->getYMap()));
               score += 50;
               break;
            }
      }      
   
   }
   
   for(list<Explosion>::iterator it = expList.begin(); it != expList.end(); it++)
   {
      it->update(20.0f);
      if(it->hasEnded() || it->getXMap() == -1)
         destroyExp.push_back(it);
   }
   
   for(int i = 0; i < destroyEbullet.size(); i++)
       eBulletList.erase(destroyEbullet[i]);
   destroyEbullet.clear();  
   
   for(int i = 0; i < destroyEship.size(); i++)
       eShipList.erase(destroyEship[i]);
   destroyEship.clear();
   
   for(int i = 0; i < destroyHbullet.size(); i++)
       hBulletList.erase(destroyHbullet[i]);
   destroyHbullet.clear();
   
    for(int i = 0; i < destroyExp.size(); i++)
       expList.erase(destroyExp[i]);
   destroyExp.clear();             
    
   glutPostRedisplay();
   glutTimerFunc(20, timer, val);
}

void getSpecialKey(int key, int x, int y)
{
   if(hShip.getLives() > 0)  
   switch(key)
   {
       case GLUT_KEY_UP: hShip.updateUp();
       break;
       case GLUT_KEY_DOWN: hShip.updateDown();
       break;
       case GLUT_KEY_LEFT: hShip.updateLeft();
       break;
       case GLUT_KEY_RIGHT: hShip.updateRight();
       break;                                                        
   }         
}

void getKey(unsigned char key, int x, int y)
{
   if(hShip.getLives() > 0)  
   if(key == ' ')
      hBulletList.push_back(hShip.shoot());
}
