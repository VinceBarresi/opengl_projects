#include <windows.h> 
#include <math.h>
#include <glut.h>

#define PI 3.14159265
#define TWOPI 2*3.14159265

Point2 CP1;
Canvas cvs(640,480);

const int screenWidth = 640; // width of screen window in pixels
const int screenHeight = 480; // height of screen window in pixels

void stellation(int n,float radius, int rotAngle)
{
   if (n < 5) return; //bad number of sides
    double angle = rotAngle * PI / 180.0;  //initial angle
    float angleInc = TWOPI / n; //angle increment
    float cx, cy;
    cx = radius * cos(angle);
    cy = radius * sin(angle);
    cvs.moveRel(cx, cy);
    for(int k = 0; k < n; k++)
    {
      angle += 2 * angleInc;
      cx = radius * cos(angle);
      cy = radius * sin(angle);
      cvs.lineRel(cx, cy);
    }
    cvs.moveRel(-cx, -cy);
}

float fx(float t1)
{ 
  return 0.3 * t1 * t1;
}

float fy(float t2)
{
  return 2 * 0.3 * t2;
}

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0); // background color is white
  glColor3f(0.0f, 0.0f, 0.0f); // drawing color is black
  glPointSize(4.0); // a 'dot' is 2 by 2 pixels
  glMatrixMode(GL_PROJECTION); // set "camera shape"
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glEnable(GL_COLOR_MATERIAL);
  glLoadIdentity();
}

void myDisplay(void)
{ 
  glClear(GL_COLOR_BUFFER_BIT);
  cvs.setWindow(-30.0, 30.0, -30.0, 30.0); 
  cvs.setViewport(0, 640, 0, 480); 
  GLdouble len = 0.002;
  
  cvs.setWindow(-10.0, 10.0, -10.0, 10.0); 
  cvs.setViewport(0, 540, 0, 480); 
    
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1, 0, 0);
  stellation(7, 6, 20);

}

void main(int argc, char** argv)
{
  glutCreateWindow("Stellation"); // open the screen window
  glutDisplayFunc(myDisplay); // register redraw function
  myInit();
  glutMainLoop();
}
