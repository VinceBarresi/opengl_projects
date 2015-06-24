#include <windows.h>
#include <glut.h>

void myInit(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(1.0f,1.0f,0.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,640.0,0.0,480.0);
}
void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.0,1.0,1.0,0); // white background
  glColor3f(1,.2,1.2);// pink

  glBegin(GL_POLYGON); //pink faded to blue
    glVertex2i(30,30);
    glVertex2i(145,30);
  
    glColor3f(0,0,1); //blue
    glVertex2i(145,270);
    
    glColor3f(0,0,1); //blue
    glVertex2i(30,270);
  
  glEnd();
  
    glColor3f(1.4,3,.4); //pale yellow
    glRecti(250,20,215,460);
  
  glColor3f(1.73,1.22,1.9);     //light green
  
  glBegin(GL_POLYGON);  //light green to light red
    glVertex2i(150,300);
    glVertex2i(210,300);
    glColor3f(10, .10, .42);  //light red
    glVertex2i(210,180);
    glColor3f(0, .29, .0);  //light green
    glVertex2i(150,180);
  glEnd();
    
    glColor3f(1, 1.2, 1.88); //off white
    glRecti(530,120,25,110);

    glColor3f(0, 0, 0); //black
    glRecti(130,320,125,300);

    glColor3f(2.2, .7, .29);  //light orange
    glRecti(128,203,155,280);
  
    glColor3f(.2, .8 , 1);  //teal
    glRecti(220,220,345,275);

    glColor3f(.2, 1.5, .4); //light green
    glRecti(450,360,505,550);
    
    glColor3f(0, 0, 0); //black
    glClearColor(1.0,1.0,1.0,.5); // white background
    glRecti(470,100,605,350);

    glColor3f(1, 0,0);  //red
    glRecti(570,50,405,350);

  glColor3f(1, 1, 1); //white
  
  glBegin(GL_POLYGON);// black to sky blue
    glVertex2i(395,320);
    
    glColor3f(0, 0.68, 1);  //sky blue
    glVertex2i(435,320);
    glVertex2i(435,150);
    
    glColor3f(0, 0, 0); //black
    glVertex2i(395,150);
  glEnd();
  glFlush();
}
void main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(840, 480);
  glutInitWindowPosition(250, 150);
  glutCreateWindow("CSC 706 - Assignment 1");
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
} 
