#include <windows.h>
#include <glut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535898  

void myInit(void) {
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(1.0f,1.0f,0.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,640.0,0.0,480.0);
}

void myDisplay(void) {

  GLubyte houseStippleOne[] = {
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99,
    0xFF,  0xFF,  0xFF, 0xFF, 0x99, 0x99, 0x99, 0x99};

  GLubyte houseStippleTwo[] = {
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11,
    0xBB,  0xBB,  0xBB, 0xBB, 0x11, 0x11, 0x11, 0x11};

  GLubyte houseStippleThree[] = {
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66,
    0xAA,  0xAA,  0xAA, 0xAA, 0x66, 0x66, 0x66, 0x66};

  GLubyte houseStippleFour[] = {
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77,
    0xAA,  0xAA,  0xAA, 0xAA, 0x77, 0x77, 0x77, 0x77};

  GLubyte houseStippleFive[] = {
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88,
    0xCC,  0xCC,  0xCC, 0xCC, 0x88, 0x88, 0x88, 0x88};

  GLubyte houseStippleSix[] = {
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44,
    0xAB,  0xAB,  0xAB, 0xAB, 0x44, 0x44, 0x44, 0x44};

  GLubyte houseStippleSeven[] = {
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91,
    0xFE,  0xFE,  0xFE, 0xFE, 0x91, 0x91, 0x91, 0x91};

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS);    //draw grass color red 0.419608 green 0.556863 blue 0.137255
  glColor3f(0.419608f, 0.556863f, 0.137255f);
    glVertex3f(0,0,0);
    glVertex3f(0,240,0);
    glVertex3f(839,240,0);
    glVertex3f(839,0,0);
  glEnd();

  glBegin(GL_QUADS);    //draw night sky
  glColor3f(0.0f, 0.0f, 0.1f);
    glVertex3f(0,240,0);
    glVertex3f(0,480,0);
    glVertex3f(840,480,0);
    glVertex3f(840,240,0);
  glEnd();

  glEnable (GL_POLYGON_STIPPLE);  //draw apartment building
  glPolygonStipple(houseStippleTwo);
  glRectf(60, 150, 360, 200);
  glDisable (GL_POLYGON_STIPPLE);
  
  glBegin(GL_LINE_LOOP); //door of stipple apartment building
  glColor3f(2.2f, 0.7f, .29f);
    glVertex2i(150,160);  //lower left side of door
    glVertex2i(150,190);  //left side of door
    glVertex2i(170,190); //top of door
    glVertex2i(170,160); //right side of door
  glEnd();

    glBegin(GL_LINE_LOOP); //door of stipple apartment building
  glColor3f(2.2f, 0.7f, .29f);
    glVertex2i(70,160); //lower left side of door
    glVertex2i(70,190);  //left side of door
    glVertex2i(90,190); //top of door
    glVertex2i(90,160); //right side of door
  glEnd();

    glBegin(GL_LINE_LOOP); //door of stipple apartment building
  glColor3f(2.2f, 0.7f, .29f);
    glVertex2i(110,160);  //lower left side of door
    glVertex2i(110,190);  //left side of door
    glVertex2i(130,190); //top of door
    glVertex2i(130,160); //right side of door
  glEnd();

    glBegin(GL_LINE_LOOP); //door of stipple apartment building
  glColor3f(2.2f, 0.7f, .29f);
    glVertex2i(190,160);  //lower left side of door
    glVertex2i(190,190);  //left side of door
    glVertex2i(210,190); //top of door
    glVertex2i(210,160); //right side of door
  glEnd();

  glBegin(GL_LINE_LOOP); //door of stipple apartment building
    glColor3f(2.2f, 0.7f, .29f);
    glVertex2i(230,160);  //lower left side of door
    glVertex2i(230,190);  //left side of door
    glVertex2i(250,190); //top of door
    glVertex2i(250,160); //right side of door
  glEnd();
  
  glBegin(GL_LINE_LOOP); //door of stipple apartment building
    glColor3f(2.2f, 0.7f, .29f);
    glVertex2i(270,160);  //lower left side of door
    glVertex2i(270,190);  //left side of door
    glVertex2i(290,190); //top of door
    glVertex2i(290,160); //right side of door
  glEnd();

  glBegin(GL_LINE_LOOP); //door of stipple apartment building
    glColor3f(2.2f, 0.7f, .29f);
    glVertex2i(310,160);  //lower left side of door
    glVertex2i(310,190);  //left side of door
    glVertex2i(330,190); //top of door
    glVertex2i(330,160); //right side of door
  glEnd();

  glEnable (GL_POLYGON_STIPPLE);  //orange stippling on first house
  glPolygonStipple(houseStippleOne);
  glRectf(40, 90, 100, 40);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2i(40,40); //lower left side of house
    glVertex2i(40,90); //draw line from lower left to roof
    glVertex2i(70,120); //draw slant on roof from left to top
    glVertex2i(100,90); //draw slant on roof from top to right
    glVertex2i(100,40);//draw line down right side of house
  glEnd();


  glBegin(GL_LINE_LOOP); //door of first house
    glColor3f(0.4f,0.1f,1.0f);
    glVertex2i(50,40);  //lower left side of door
    glVertex2i(50,70);  //left side of door
    glVertex2i(70,70); //top of door
    glVertex2i(70,40); //right side of door
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //blue stippling on second house
  glPolygonStipple(houseStippleFour);
  glRectf(140, 90, 200, 40);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP); // second house
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2i(140,40);
    glVertex2i(140,90);
    glVertex2i(170,120);
    glVertex2i(200,90);
    glVertex2i(200,40);
  glEnd();

  glBegin(GL_LINE_LOOP); //3Dimensional part of second house
    glColor3f(1.0f,0.0f,0.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glVertex2i(240,40);
    glVertex2i(240,90);
    glVertex2i(170,120);
    glVertex2i(200,90);
    glVertex2i(200,40);
  glEnd();

  glBegin(GL_LINE_LOOP); //door of second house
    glColor3f(0.12891040104f,0.92193921939f,.2131414f);
    glVertex2i(160,40); //lower left side of door
    glVertex2i(160,70);  //left side of door
    glVertex2i(170,70); //top of door
    glVertex2i(170,40); //right side of door
  glEnd();

  glEnable (GL_POLYGON_STIPPLE);  //green stippling on large window of third house
  glPolygonStipple(houseStippleFive);
  glRectf(350, 90, 390, 100);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP);  //third house
  glColor3f(0.528492940f,0.727177741f,0.914381848149f);
    glVertex2i(340,40); //lower left side of house
    glVertex2i(340,90); //draw line from lower left to roof
    glVertex2i(370,120);  //draw slant on roof from left to top
    glVertex2i(400,90); //draw slant on roof from top to right
    glVertex2i(400,40);//draw line down right side of house
  glEnd();

  glEnable (GL_POLYGON_STIPPLE);  //blue-gray stippling on door of third house
  glPolygonStipple(houseStippleFive);
  glRectf(350, 40, 370, 70);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP); //door of third house
  glColor3f(0.4f,0.1f,1.0f);
    glVertex2i(350,40); //lower left side of door
    glVertex2i(350,70);  //left side of door
    glVertex2i(370,70); //top of door
    glVertex2i(370,40); //right side of door
  glEnd();
  
  glBegin(GL_LINE_LOOP); // roof of fourth home
  glColor3f(0.0f,.0f,0.0f);
    glVertex2i(440,90);
    glVertex2i(470,120);
    glVertex2i(500, 90);
  glEnd();

  glBegin(GL_LINE_LOOP);  //fourth house
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2i(440,0); //lower left side of house
    glVertex2i(440,90); //draw line from lower left to roof
    glVertex2i(470,120);  //draw slant on roof from left to top
    glVertex2i(500,90); //draw slant on roof from top to right
    glVertex2i(500,0);//draw line down right side of house
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //white stippling on door of fourth house
  glPolygonStipple(houseStippleFour);
  glRectf(450, 0, 470, 35);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP); //door of fourth house
    glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(450,0);  //lower left side of door
    glVertex2i(450,35);  //left side of door
    glVertex2i(470,35); //top of door
    glVertex2i(470,0); //right side of door
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //white stippling on window of fourth house
  glPolygonStipple(houseStippleFour);
  glRectf(450, 50, 470, 80);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP); //window of house
    glColor3f(0.91947147f,0.7247294f,.814736641f);
    glVertex2i(450,50); //lower left side of door
    glVertex2i(450,80);  //left side of door
    glVertex2i(470,80); //top of door
    glVertex2i(470,50); //right side of door
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //white stippling on window of fourth house
  glPolygonStipple(houseStippleFour);
  glRectf(480, 50, 495, 80);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP); //window of house
    glColor3f(0.14285287582,0.43174895f,1.123415263f);
    glVertex2i(480,50); //lower left side of door
    glVertex2i(480,80);  //left side of door
    glVertex2i(495,80); //top of door
    glVertex2i(495,50); //right side of door
  glEnd();

  glBegin(GL_LINE_LOOP);  //fifth house
    glColor3f(1.2839492492f,0.232425252f,1.8382482f);
    glVertex2i(540,150); //lower left side of house
    glVertex2i(540,190); //draw line from lower left to roof
    glVertex2i(570,220);  //draw slant on roof from left to top
    glVertex2i(610,190); //draw slant on roof from top to right
    glVertex2i(610,150);//draw line down right side of house
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //magenta stippling on door of fifth house
  glPolygonStipple(houseStippleFour);
  glRectf(540, 150, 610, 190);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP); //door of fifth house
  glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(550,150);  //lower left side of door
    glVertex2i(550,170);  //left side of door
    glVertex2i(580,170); //top of door
    glVertex2i(580,150); //right side of door
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //teal stippling on window of fourth house
  glPolygonStipple(houseStippleFour);
  glRectf(550, 200, 590, 180);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP);  //sixth house
    glColor3f(0.2839492492f,0.232425252f,1.8382482f);
    glVertex2i(500,230); //lower left side of house
    glVertex2i(500,320); //draw line from lower left to roof
    glVertex2i(545,350);  //draw slant on roof from left to top
    glVertex2i(590,320); //draw slant on roof from top to right
    glVertex2i(590,230);//draw line down right side of house
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //blue stippling on window of sixth house
  glPolygonStipple(houseStippleFour);
  glRectf(500, 230, 590, 320);
  glDisable (GL_POLYGON_STIPPLE);

  glColor3f(0.5747147174f, 0.92347274f, 0.32516313f);
  glBegin(GL_LINE_LOOP); //door of sixth house
    glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(520,230);  //lower left side of door
    glVertex2i(520,250);  //left side of door
    glVertex2i(570,250); //top of door
    glVertex2i(570,230); //right side of door
  glEnd();

  glEnable (GL_POLYGON_STIPPLE);  //teal stippling on door of sixth house
  glPolygonStipple(houseStippleSeven);
  glRectf(520, 230, 570, 250);
  glDisable (GL_POLYGON_STIPPLE);

  glBegin(GL_LINE_LOOP); //right window of sixth house
    glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(550,280);  //lower left side of door
    glVertex2i(550,299);  //left side of door
    glVertex2i(585,299); //top of door
    glVertex2i(585,280); //right side of door
  glEnd();

  glBegin(GL_LINE_LOOP); //left window of sixth house
    glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(530,280);  //lower left side of door
    glVertex2i(530,299);  //left side of door
    glVertex2i(565,299); //top of door
    glVertex2i(565,280); //right side of door
  glEnd();


  glBegin(GL_LINE_LOOP);  //seventh house
    glColor3f(0.9839492492f,1.232425252f,0.4382482f);
    glVertex2i(400,220); //lower left side of house
    glVertex2i(400,290); //draw line from lower left to roof
    glVertex2i(445,320);  //draw slant on roof from left to top
    glVertex2i(490,290); //draw slant on roof from top to right
    glVertex2i(490,220);//draw line down right side of house
  glEnd();
  
  glEnable (GL_POLYGON_STIPPLE);  //yellow stippling on seventh house
  glPolygonStipple(houseStippleOne);
  glRectf(400, 220, 490, 290);
  glDisable (GL_POLYGON_STIPPLE);

  glColor3f(0.1747147174f, 1.32347274f, 1.19212f);
  glBegin(GL_LINE_LOOP); //door of seventh house
    glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(420,220);  //lower left side of door
    glVertex2i(420,250);  //left side of door
    glVertex2i(460,250); //top of door
    glVertex2i(460,220); //right side of door
  glEnd();

  glColor3f(0.382822617, 0.1228813f, 0.827136136f);
  glBegin(GL_LINE_LOOP); //right window of seventh house
    glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(450,280);  //lower left side of door
    glVertex2i(450,299);  //left side of door
    glVertex2i(485,299); //top of door
    glVertex2i(485,280); //right side of door
  glEnd();

  glColor3f(1.010201f, 0.020424f, 0.35267f);
  glBegin(GL_LINE_LOOP); //left window of seventh house
    glColor3f(0.2424242425f,0.919291439f,1.0f);
    glVertex2i(410,280);  //lower left side of door
    glVertex2i(410,299);  //left side of door
    glVertex2i(430,299); //top of door
    glVertex2i(430,280); //right side of door
  glEnd();

  glBegin(GL_LINE_LOOP);    //star
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2i(370,320);  
    glVertex2i(400,390);
    glVertex2i(430,320);
    glVertex2i(320,370);
    glVertex2i(390,400); 
    glVertex2i(320,430);
  glEnd();

  glBegin(GL_LINE_LOOP);    //star
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2i(270,240);  
    glVertex2i(300,310);
    glVertex2i(330, 240);
    glVertex2i(220,290);  
    glVertex2i(290,320);
    glVertex2i(220,350);  
  glEnd();

  glFlush();
}
void main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(840,480);
  glutInitWindowPosition(250,150);
  glutCreateWindow("CSC706");
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
}
