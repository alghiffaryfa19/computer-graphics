#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include"tiles.h"
class MapStrip
{
   public:
      MapStrip(GLint);
      void draw();
      void update(GLfloat);
   private:
      GLint xMap;
      GLfloat xMov;
      GLfloat starArrayX[120];
      GLfloat starArrayY[120];
};

MapStrip::MapStrip(GLint x)
:xMov((GLfloat)(x*tileW)), xMap(x)
{
   for(int i = 0; i < 120; i++)
   {
      starArrayX[i] = (GLfloat)(rand()%tileW);
      starArrayY[i] = (GLfloat)(rand()%winH);
   }
}

void MapStrip::draw()
{
   glLoadIdentity();									// Reset The Modelview Matrix
   glTranslatef(xMov, 0.0f, 0.0f);
   glPointSize(.5f);
   glBegin(GL_POINTS);
      for(int i = 0; i < 120; i++)
      {
         glColor3f((rand()%10)/10.0f, (rand()%10)/10.0f, (rand()%10)/10.0f);
         glVertex2f(starArrayX[i], starArrayY[i]);
      }
   glEnd();
}

void MapStrip::update(GLfloat step)
{
   --xMap;
   if(xMap < 0)
   {
      xMap = winW/tileW;
      xMov = winW;
   }
   if(xMov > xMap * tileW)
      xMov -= step;
}
