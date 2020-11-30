#include <cstdlib>
#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#define PI 3.14159265
const int winW = 800;
const int winH = 640;
const int mapW = 40;
const int mapH = 32;
const int tileW = 20;
const int tileH = 20;

class Tile
{
   public:
      Tile(GLint, GLint, bool = false);
      int getXMap();
      int getYMap();
      virtual void draw() = 0;
      virtual void update(GLfloat) = 0;
   protected:
      bool collidable;
      int xMap;
      int yMap;
      GLfloat xMov;
      GLfloat yMov;
};

Tile::Tile(GLint x, GLint y, bool collide)
:xMap(x), yMap(y), xMov((GLfloat)(x * tileW)), yMov((GLfloat)(y * tileH)), collidable(collide){}

GLint Tile::getXMap()
{return xMap;}

GLint Tile::getYMap()
{return yMap;}

class HeroBullet: public Tile
{
   public:
      HeroBullet(GLint, GLint);
      void draw();
      void update(GLfloat);
};

HeroBullet::HeroBullet(GLint x, GLint y)
:Tile(x, y){}

void HeroBullet::draw()
{
      glLoadIdentity();									// Reset The Modelview Matrix
      glTranslatef(xMov, yMov, 0.0f);
         glColor3f(0.5f,0.7f,1.0f);
         glRectf(0.0f, 8.0f, 20.0f, 12.0f);
}

void HeroBullet::update(GLfloat step)
{
   if(xMap < mapW)
      xMov += step;

   xMap = (GLint)(xMov/tileW);
}

class EnemyBullet: public Tile
{
   public:
      EnemyBullet(GLint, GLint);
      void draw();
      void update(GLfloat);

};

EnemyBullet::EnemyBullet(GLint x, GLint y)
:Tile(x, y){}

void EnemyBullet::draw()
{
      glLoadIdentity();									// Reset The Modelview Matrix
      glTranslatef(xMov, yMov, 0.0f);
         glColor3f(1.0f, 0.6f, 0.0f);
         glRectf(8.0f, 8.0f, 12.0f, 12.0f);
}

void EnemyBullet::update(GLfloat step)
{
   if(xMap > -1)
      xMov -= step;

  xMap = (GLint)(xMov/tileW);
}

class EnemyShip: public Tile
{
   public:
      EnemyShip(GLint, GLint);
      void draw();
      void update(GLfloat);
      EnemyBullet shoot();
};

EnemyShip::EnemyShip(GLint x, GLint y)
:Tile(x, y){}

void EnemyShip::draw()
{
      glLoadIdentity();									// Reset The Modelview Matrix
      glTranslatef(xMov, yMov, 0.0f);
      glBegin(GL_TRIANGLES);
         glColor3f(0.6f, 0.1f, 0.9f);
         glVertex2f(10.0f, 0.0f);
         glVertex2f(0, 10.0f);
         glVertex2f(10.0f, 20.0f);
      glEnd();
}

void EnemyShip::update(GLfloat step)
{
  if(xMap > -1)
      xMov -= step;

  xMap = (GLint)(xMov/tileW);

}

EnemyBullet EnemyShip::shoot()
{return EnemyBullet(xMap-1, yMap);}


class HeroShip: public Tile
{
   public:
      HeroShip(GLint, GLint);
      void draw();
      void update(GLfloat);
      void updateUp();
      void updateDown();
      void updateLeft();
      void updateRight();
      void takeDmg();
      int getLives();
      HeroBullet shoot();
   private:
      int lives;
};

HeroShip::HeroShip(GLint x, GLint y)
:Tile(x, y), lives(3){}

void HeroShip::takeDmg()
{
   if(lives != 0)
      --lives;
}

int HeroShip::getLives()
{return lives;}

void HeroShip::draw()
{
      glLoadIdentity();									// Reset The Modelview Matrix
      glTranslatef(xMov, yMov, 0.0f);
      glBegin(GL_TRIANGLES);
         glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(0.0f, 0.0f);
         glVertex2f(20.0f, 10.0f);
         glVertex2f(0.0f, 20.0f);
         glColor3f(1.0f, 0.0f, 0.0f);
         glVertex2f(0.0f, 5.0f);
         glVertex2f(0, 15.0f);
         glVertex2f(10.0f, 10.0f);
      glEnd();
}

void HeroShip::updateUp()
{
   if(yMap > 0)
      --yMap;
}

void HeroShip::updateDown()
{
   if(yMap < mapH - 1)
      ++yMap;
}

void HeroShip::updateLeft()
{
   if(xMap > 0)
      --xMap;
}

void HeroShip::updateRight()
{
   if(xMap < mapW - 1)
      ++xMap;
}

void HeroShip::update(GLfloat step)
{
   if(yMov > yMap*tileW)
      yMov -= step;

   if(yMov < yMap*tileH)
      yMov += step;

   if(xMov > xMap*tileW)
      xMov -= step;

   if(xMov < xMap*tileW)
      xMov += step;
}

HeroBullet HeroShip::shoot()
{return HeroBullet(xMap+1, yMap);}

class Explosion: public Tile
{
    public:
       Explosion(GLint, GLint);
       void draw();
       bool hasEnded();
       void update(GLfloat);
    private:
       bool end;
       GLfloat radius;
       GLfloat originX;
       GLfloat originY;
       GLfloat scale;
       GLfloat alpha;

};

Explosion::Explosion(GLint x, GLint y)
:Tile(x, y), end(false), originX(10), originY(10), radius(2), alpha(1), scale(10){}

bool Explosion::hasEnded()
{return end;}
void Explosion::draw()
{
    GLfloat x1;
    GLfloat y1;
    GLfloat xTemp;
    GLfloat yTemp;
   glLoadIdentity();									// Reset The Modelview Matrix
   glTranslatef(xMov, yMov, 0.0f);
    glColor3f(1.0f, 0.6f, 0.0f);
    glLineWidth(10);
      glBegin(GL_LINE_STRIP);

      xTemp = originX;
      yTemp = originY + radius;

      for(double angle = 0.0f; angle <= 2.0f*PI; angle += 0.01f)
      {
         x1 = originX + radius*(float)sin(angle);
         y1 = originY + radius*(float)cos(angle);
         glVertex2f(xTemp, yTemp);
         xTemp = x1;
         yTemp = y1;
      }

      glEnd();
}

void Explosion::update(GLfloat step)
{
   if(xMap > -1)
      xMov -= step;

   xMap = (GLint)(xMov/tileW);
   radius++;
   end = (radius > 40);
}
