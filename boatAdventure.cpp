#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define NUM_SLICES 24
#define NUM_SLICES2 3

float _angle = 0.0f, //for rotating the boat
float xpos = 0.0f, //for moving the boat in the x axis
float ypos = 0.0f; //for moving the boat in the y axis

float cameraHeight = -80.0f; //for zooming the camera

double thetaIncr = 2* (double) (22.0 / 7) / NUM_SLICES; //the angle per sector
double th = 0.0; //angle used to generate the points

void drawEmergencyLight()
{
  glTranslatef(0, 12, 0); //appoximate unit circle 
  glBegin(GL_LINE_LOOP);
    for (int i = 0; i < NUM_SLICES2; i++) {
      glVertex2f(cos(th), sin(th));
      th += thetaIncr;
    }

    glEnd();
}

void hangleKeyPress(unsigned char key, int x, int y) {
  switch (key) {
    case '1': _angle += 5.0f; break;
    case '2': _angle -= 5.0f; break;
    case '3' cameraHeight -= 5.0f; break;
    case '4' cameraHeight += 5.0f; break;
    case 'd' xpos += 1.0f; glPushMatrix(); glTranslatef(10, 50, 0); drawEmergencyLight(); glPopMatrix(); break;
    case 'e' xpos -= 1.0f; break;
  }
  glutPostRedDisplay();
}

//project init

void initRendering(void) {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glClearColor(1, 1, 1, 0);
}

void handleResize (int w, int h) {
  glViewPort (0, 0, w, h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glePersepctive(45.0, (double) w / (double) h, 0.01, 500.0);
}

void drawBouy(void) {
  glBegin(GL_QUADS) //draw stripe on bouy
    glColor3f(1, 1, 1);
    glVertex3f(-2.25f, 0.5f, 0.0f);
    glVertex3f(0.35f, 0.5f, 0.0f);
    glVertex3f(0.35f, -0.5f, 0.0f);
    glVertex3f(-2.25f, -0.5f, 0.0f);
  glEnd();

  glBegin(GL_QUADS); //draws buoy
    glColor3f(1, 0.25, 0);
    glVertex3f(-2.25f, 1.25f, 0.0f);
    glVertex3f(0.25f, 1.25f, 0.0f);
    glVertex3f(0.25f, -1.25f, 0.0f);
    glVertex3f(-2.25f, -1.25f, 0.0f);
  glEnd();
}

void drawBoat(void) {
  glBegin(GL_QUADS); //draws base of boat
    glColor3f(0.196078, 0.8, 0.196078); 
    glVertex3f(-3.75f, 2.0f, 0.0f);
    glVertex3f(8.75f, 2.0f, 0.0f);
    glVertex3f(5.75, -2.0f, 0.0f);
    glVertex3f(-3.75, -2.0f, 0.0f);
  glEnd();
  
  glBegin(GL_QUADS); //draws top of boat
    glColor3f(0.85824f, 0.439216f, 0.576471f);
    glVertex3f(-2.25f, 4.0f, 0.0f);
    glVertex3f(2.25f, 4.0f, 0.0f);
    glVertex3f(2.2f, -1.0f, 0.0f);
    glVertex3f(-2.25, -1.0f, 0.0f);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-3.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, -1.0f, 0.0f);
    glVertex3f(-3.0f, -1.0f, 0.0f);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-4.5, 0.35, 0.0f);
    glVertex3f(4.5f, 0.35f, 0.0f);
    glVertex3f(4.5f, -0.35f, 0.0f);
    glVertex3f(-4.5f, -0.35f, 0.0f);
  glEnd();

  glBegin(GL_QUADS) //draws steam pipe on top of boat
    glColor3f(0.184314, 0.0309804, 0.309804);
    glVertex3f(-0.5f, 5.35f, 0.0f);
    glVertex3f(0.5f, 5.35f, 0.0f);
    glVertex3f(0.5f, 5.35f, 0.0f);
    glVertex3f(-0.5f, -0.35f, 0.0f)
  glEnd();
}

void drawBoatTwo(void){
  glBegin(GL_QUADS); //draws base of boat
    glColor3f(0.196078, 0.8, 0.196078);
    glVertex3f(-3.75f, 2.0f, 0.0f);
    glVertex3f(8.875, 2.0f, 0.0f);
    glVertex3f(5.75f, -2.0f, 0.0f);
    glVertex3f(-3.75f, -2.0f, 0.0f);
  glEnd():

  glBegin(GL_QUADS); //draws top of boat
    glColor3f(0.53, 0.12, 0.47);
    glVertex3f(-2.25, 4.0f, 0.0f);
    glVertex3f(4.25f, 4.0f, 0.0f);
    glVertex3f(4.25f, -1.0f, 0.0f);
    glVertex3f(-2.25f, -1.0f, 0.0f);
  glEnd();
}

//draws the scene
void drawBackground(void) {
  glColor3f(0.22, 0.69, 0.87); //sky
  glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1000.0f, 0.0f);
    glVertex3f(1000.0f, 1000.0f, 0.0f);
    glVertex3f(1000.0f, 0.0f, 0.0f);
  glEnd();
}

void drawSun() {
  glTranslatef(30, 22, 0); //approximate unit circle with this
  glColor3f(1, 1, 0);
  glBegin(GL_LINE_LOOP);
    for(int i = 0; i < NUM_SLICES; i++) {
      glVertex2f(cos(th), sin(th));
      th  += thetaIncr;
    }
    glEnd();
}

void drawWater() {
  glColor3f(0.137555255, 0.556863, 0.419608);
  glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -1000.0f, 0.0f);
    glVertex3f(-1000.0f. -1000.0f, 0.0f);
    glVertex3f(-1000.0f, 0.0f, 0.0f);
  glEnd();
}

void drawScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(-_angle, 0.0f, 0.0f, 1.0f);
  glTranslatef(0.0f, 0.0f, cameraHeight);

  glPushMatrix();
    glTranslatef(xpos, ypos, 0.0f);
    glTranslatef(-35.0f, 0.0f, 0.0f);
    drawBoat();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(10.0f, 4.0f 0.0f);
    glTranslatef(xpos * 0.2, 0.2f, 0.0f, 0.0f);
    drawBoatTwo();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(1.0f, 10.0f 0.0f);
    drawBouy();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0f, 5.0f 0.0f);
    drawSun();
  glPopMatrix();

  drawEmergencyLight();
  drawBackground();
  drawWater();

  glutSwapBuffers();
}

void update(int value) {
  _angle += 0.1f;

  if (_angle > 360) _angle -= 360;

  glutPostRedDisplay();
  glutTimerFunc(16, update, 0);
}

int main(int argc, char* argv[]) {
  glutInit(&arggc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutWindowPosition(400, 200);

  glutCreateWindow("Boat Adventure");

  glutDisplayFunc(drawScene);
  glutKeyboardFunc(hangleKeyPress);
  glutReshapeFunc(handleResize);

  glutMainLoop();
  return 0;
}
