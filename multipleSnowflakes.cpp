#include <windows.h>
#include "graphics2dpartb.h"

Canvas:: Canvas(int width, int height) {
  char* argv[1]; 
  char dummyString[8];
  argv[0] = dummyString; 
  int argc = 1; 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(200, 200);
  setWindow(0, (float)width, 0, (float)height); 
  setViewport(0, width, 0, height); 
  CP.set(0.0f, 0.0f); 
}


void Canvas :: setWindow(float l, float r, float b, float t) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); 
  gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
  if(t == b) return; 
  windowAspect = (r - 1)/(t - b);
}

void Canvas :: setViewport(int l, int r, int b, int t) {
  glViewport((GLint)l, (GLint)b, (GLint)(r-l), (GLint)(t-b));
}

void Canvas :: lineTo(float x, float y) {
  glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
    CP.x = x; CP.y = y;
    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
  glEnd();
  glFlush();
}

void Canvas :: forward(float dist, int vis) {
  #define RadPerDeg 0.017453393 
  float x = CP.x + dist * cos(RadPerDeg * CD);
  float y = CP.y + dist * sin(RadPerDeg * CD); 
  if(vis) lineTo(x, y);
  else moveTo(x, y);
  CP.x = x; CP.y = y;
}

void Canvas::ngon(int n,float cx, float cy, float radius) {
  #define RadPerDeg 0.017453393 
  if(n < 3) 
    return; 
  double angle = 0, angleInc = 2 * 3.14159265 /n; 
  moveTo(cx + radius, cy);
  for(int k = 1; k <= n; k++) {
    angle += angleInc;
    lineTo(radius * cos(angle) + cx, radius*sin(angle) + cy);
  }
}
void Canvas::moveRel(float dx, float dy) {
  CP.set(CP.x+dx, CP.y+dy);
}

void Canvas::lineRel(float dx, float dy) {
  float x=CP.x+dx, y=CP.y+dy;
  lineTo(x,y);
  CP.set(x, y);
}

#define TWOPI 2*3.14159265

const int SCREENWIDTH = 680; 
const int SCREENHEIGHT = 480;

Point2 CP1;
Canvas cvs(SCREENWIDTH,SCREENHEIGHT);

void snowflakemotiff(float cx,float cy, float size) {
  cvs.moveTo(cx,cy);
  cvs.turn(30);
  cvs.forward(size*.5,1);
  cvs.turn(40);
  cvs.forward(size*.75,1);
  cvs.turn(290);
  cvs.forward(size*.25,1);
  cvs.turn(260);
  cvs.forward(size*.5,1);
  cvs.turn(130);
  cvs.forward(size*.6,1);
  cvs.turn(270);
  cvs.forward(size*.125,1);
}
void snowflake(float cx,float cy, float size) {
  cvs.moveTo(cx,cy);
  cvs.initCT();
  cvs.pushCT();
  snowflakemotiff(cx,cy,size);
  cvs.translate2D (cx,cy);
  cvs.scale2D(-1,1);
  cvs.rotate2D(190);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.popCT();
  cvs.pushCT();
  cvs.translate2D (cx,cy);
  cvs.rotate2D(60);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.translate2D (cx,cy);
  cvs.scale2D(-1,1);
  cvs.rotate2D(70);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.popCT();
  cvs.pushCT();
  cvs.translate2D (cx,cy);
  cvs.rotate2D(120);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.translate2D (cx,cy);
  cvs.scale2D(-1,1);
  cvs.rotate2D(310);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.popCT();
  cvs.pushCT();
  cvs.translate2D (cx,cy);
  cvs.rotate2D(180);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.translate2D (cx,cy);
  cvs.scale2D(-1,1);
  cvs.rotate2D(190);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.popCT();
  cvs.pushCT();
  cvs.translate2D (cx,cy);
  cvs.rotate2D(240);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.translate2D (cx,cy);
  cvs.scale2D(-1,1);
  cvs.rotate2D(70);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.popCT();
  cvs.pushCT();
  cvs.translate2D (cx,cy);
  cvs.rotate2D(300);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.translate2D (cx,cy);
  cvs.scale2D(-1,1);
  cvs.rotate2D(310);
  cvs.translate2D (-cx,-cy);
  snowflakemotiff(cx,cy,size);
  cvs.popCT();
  cvs.popCT();
}
void myInit(void) {
  glClearColor(0,0,0,0.0); 
  glColor3f(0.0f, 0.0f, 0.0f); 
  glPointSize(2.0);
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
}

void myDisplay(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  cvs.setWindow(0.0, SCREENWIDTH, 0.0, SCREENHEIGHT); 
  cvs.setViewport(0,SCREENWIDTH,0,SCREENHEIGHT);
  glColor3f(1,1,1);
  snowflake(400,200,25);
  glColor3f(.321431,.1246663,9123131);
  snowflake(300,220,25);
  glColor3f(.3,1,.3);
  snowflake(650,420,50);
  glColor3f(1,.2,1); 
  snowflake(400,110,40);
  glColor3f(1,0,.2);
  snowflake(240,300,70);
  glColor3f(.4,.4,.4); 
  snowflake(50,50,50);
  glColor3f(0,0,1); 
  snowflake(350,250,150);
  glColor3f(1,1,1); 
  snowflake(240,240,240);

  glFlush();
}
void main(int argc, char** argv) {
  glutCreateWindow("Multiple Snowflakes"); 
  glutDisplayFunc(myDisplay); 
  myInit();
  glutMainLoop(); 
}
