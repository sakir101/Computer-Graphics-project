#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

float boat1_m = 0;
float boat2_m = 26.5;
float cloud1_m = 7;
float cloud2_m = 25;



void init(void)
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(-12,38,-19,14);//range
    glMatrixMode(GL_MODELVIEW);
}



void circle(GLfloat cx, GLfloat cy, GLfloat rx, GLfloat ry)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(242.0 / 255.0, 250.0 / 255.0, 22.0 / 255.0);
    glVertex2d(cx,cy);

    for(int i=0; i<=100; i++)
    {
        float angle= 2.0f*3.1416f * i/100;
        float x= rx*cosf(angle);
        float y=ry*sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}


void circle2(GLfloat cx, GLfloat cy, GLfloat rx, GLfloat ry)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
    glVertex2d(cx,cy);

    for(int i=0; i<=100; i++)
    {
        float angle= 2.0f*3.1416f * i/100;
        float x= rx*cosf(angle);
        float y=ry*sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}



void circle3(GLfloat cx, GLfloat cy, GLfloat rx, GLfloat ry)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(242.0 / 255.0, 250.0 / 255.0, 243.0 / 255.0);
    glVertex2d(cx,cy);

    for(int i=0; i<=100; i++)
    {
        float angle= 2.0f*3.1416f * i/100;
        float x= rx*cosf(angle);
        float y=ry*sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}



void circle4(GLfloat cx, GLfloat cy, GLfloat rx, GLfloat ry)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.2, 0.2, 0.4);
    glVertex2d(cx,cy);

    for(int i=0; i<=100; i++)
    {
        float angle= 2.0f*3.1416f * i/100;
        float x= rx*cosf(angle);
        float y=ry*sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}




void DrawDay()
{
    glClear(GL_COLOR_BUFFER_BIT);



    ///sky///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3d(20.0 / 255.0, 246.0 / 255.0, 250.0 / 255.0);
    glVertex2f(38.0f,3.0f);
    glVertex2f(38.0f,14.0f);
    glVertex2f(-12.0f,14.0f);
    glVertex2f(-12.0f,3.0f);

    glEnd();

    ///Field///
    glBegin(GL_POLYGON);
    glColor3d(204.0 / 255.0, 177.0 / 255.0, 55.0 / 255.0);
    glVertex2f(-12, 3);
    glVertex2f(-12, -12);
    glVertex2f(38, -2);
    glVertex2f(38, 3);
    glEnd();

    ///Road1///
    glBegin(GL_POLYGON);
    glColor3d(178.0 / 255.0, 201.0 / 255.0, 93.0 / 255.0);
    glVertex2f(5, 3);
    glVertex2f(10, 3);
    glVertex2f(18.3, 1.2);
    glVertex2f(16.3, 1);
    glEnd();

    ///Road2///
    glBegin(GL_POLYGON);
    glColor3d(178.0 / 255.0, 201.0 / 255.0, 93.0 / 255.0);
    glVertex2f(7, 0);
    glVertex2f(7, -2);
    glVertex2f(18.3, 1.2);
    glVertex2f(18.3, 1.2);
    glEnd();

    ///Road3///
    glBegin(GL_POLYGON);
    glColor3d(178.0 / 255.0, 201.0 / 255.0, 93.0 / 255.0);
    glVertex2f(7, 0);
    glVertex2f(7, -2);
    glVertex2f(30.3, -5);
    glVertex2f(30.3, -4);
    glEnd();


    ///River///
    glBegin(GL_POLYGON);
    glColor3d(92.0 / 255.0, 171.0 / 255.0, 250.0 / 255.0);
    glVertex2f(-12, -12);
    glVertex2f(-12, -19);
    glVertex2f(38, -19);
    glVertex2f(38, -2);
    glEnd();

    if(boat1_m < -25)
        boat1_m = 0;
    else
        boat1_m = boat1_m - 0.005;

    glutPostRedisplay();

    ///Boat1///
    glBegin(GL_POLYGON);
    glColor3d(5.0 / 255.0, 37.0 / 255.0, 69.0 / 255.0);
    glVertex2f(boat1_m + 0, -15);
    glVertex2f(boat1_m + 2, -17.5);
    glVertex2f(boat1_m + 10, -17.5);
    glVertex2f(boat1_m + 12, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 113.0 / 255.0, 3.0 / 255.0);
    glVertex2f(boat1_m + 5, -15);
    glVertex2f(boat1_m + 5, -13);
    glVertex2f(boat1_m -0.5, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(77.0 / 255.0, 55.0 / 255.0, 6.0 / 255.0);
    glVertex2f(boat1_m + 7, -15);
    glVertex2f(boat1_m + 7, -12);
    glVertex2f(boat1_m + 7.2, -12);
    glVertex2f(boat1_m + 7.2, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(77.0 / 255.0, 55.0 / 255.0, 6.0 / 255.0);
    glVertex2f(boat1_m + 8, -15);
    glVertex2f(boat1_m + 8, -12);
    glVertex2f(boat1_m + 8.2, -12);
    glVertex2f(boat1_m + 8.2, -15);
    glEnd();

    if(boat2_m > 40 )
        boat2_m = 26.5;
    else
        boat2_m = boat2_m + 0.005;

    glutPostRedisplay();

    ///Boat2///
    glBegin(GL_POLYGON);
    glColor3d(5.0 / 255.0, 37.0 / 255.0, 69.0 / 255.0);
    glVertex2f(boat2_m, -13);
    glVertex2f(boat2_m -1, -11.5);
    glVertex2f(boat2_m + 5, -11.5);
    glVertex2f(boat2_m + 3.5, -13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(156.0 / 255.0, 117.0 / 255.0, 128.0 / 255.0);
    glVertex2f(boat2_m - 0.1, -11.5),
    glVertex2f(boat2_m - 0.1, -10),
    glVertex2f(boat2_m + 2.5, -10),
    glVertex2f(boat2_m + 2.5, -11.5),
    glEnd();

    ///House1///
    glBegin(GL_POLYGON);
    glColor3d(209.0 / 255.0, 6.0 / 255.0, 43.0 / 255.0);
    glVertex2f(0, 0);
    glVertex2f(0, -4);
    glVertex2f(6, -4);
    glVertex2f(6, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(110.0 / 255.0, 4.0 / 255.0, 24.0 / 255.0);
    glVertex2f(-1, 0);
    glVertex2f(0, 2.5);
    glVertex2f(6, 2.5);
    glVertex2f(7, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(54.0 / 255.0, 4.0 / 49.0, 32.0 / 255.0);
    glVertex2f(2,-2);
    glVertex2f(2, -4);
    glVertex2f(3.5, -4);
    glVertex2f(3.5, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(54.0 / 255.0, 4.0 / 49.0, 32.0 / 255.0);
    glVertex2f(4.5, -1);
    glVertex2f(4.5, -2.5);
    glVertex2f(5.5, -2.5);
    glVertex2f(5.5, -1);
    glEnd();

    ///House2///
    glBegin(GL_POLYGON);
    glColor3d(130.0 / 255.0, 111.0 / 255.0, 40.0 / 255.0);
    glVertex2f(-6, -4.5);
    glVertex2f(-6, -8.5);
    glVertex2f(0, -8.5);
    glVertex2f(0, -4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(255.0 / 255.0, 200.0 / 255.0, 0.0 / 255.0);
    glVertex2f(-7, -4.5);
    glVertex2f(-6, -2.5);
    glVertex2f(0, -2.5);
    glVertex2f(1, -4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(54.0 / 255.0, 4.0 / 49.0, 32.0 / 255.0);
    glVertex2f(-4,-6.5);
    glVertex2f(-4, -8.5);
    glVertex2f(-2.5, -8.5);
    glVertex2f(-2.5, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(54.0 / 255.0, 4.0 / 49.0, 32.0 / 255.0);
    glVertex2f(-2, -7);
    glVertex2f(-2, -5.5);
    glVertex2f(-1, -5.5);
    glVertex2f(-1, -7);
    glEnd();

    ///House3///
    glBegin(GL_POLYGON);
    glColor3d(168.0 / 255.0, 151.0 / 255.0, 121.0 / 255.0);
    glVertex2f(29, 0);
    glVertex2f(29, -2);
    glVertex2f(32, -2);
    glVertex2f(32, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(105.0 / 255.0, 100.0 / 255.0, 92.0 / 255.0);
    glVertex2f(28, 0);
    glVertex2f(29, 1);
    glVertex2f(32, 1);
    glVertex2f(33, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(54.0 / 255.0, 4.0 / 49.0, 32.0 / 255.0);
    glVertex2f(30, -0.5);
    glVertex2f(30, -2);
    glVertex2f(31, -2);
    glVertex2f(31, -0.5);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3d(54.0 / 255.0, 4.0 / 49.0, 32.0 / 255.0);
    glVertex2f(31.3, -0.2);
    glVertex2f(31.3, -1);
    glVertex2f(31.8, -1);
    glVertex2f(31.8, -0.2);
    glEnd();

    ///Tree1///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(8, -1);
    glVertex2f(8, -4);
    glVertex2f(8.2, -4);
    glVertex2f(8.2, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(6.5, -1.5);
    glVertex2f(9.5, -1.5);
    glVertex2f(8, 1.5);
    glEnd();

    ///Tree2///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(2, -8.5);
    glVertex2f(2, -6.5);
    glVertex2f(2.2, -6.5);
    glVertex2f(2.2, -8.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(0, -7.5);
    glVertex2f(4, -7.5);
    glVertex2f(2, -5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(0, -7);
    glVertex2f(4, -7);
    glVertex2f(2, -4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(0, -6.5);
    glVertex2f(4, -6.5);
    glVertex2f(2, -3.5);
    glEnd();

    ///Tree3///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(12, -3);
    glVertex2f(12, -5);
    glVertex2f(12.2, -5);
    glVertex2f(12.2, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(11, -3.5);
    glVertex2f(13, -3.5);
    glVertex2f(12, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(11, -2.8);
    glVertex2f(13, -2.8);
    glVertex2f(12, -1.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(11, -2.4);
    glVertex2f(13, -2.4);
    glVertex2f(12, 1);
    glEnd();



    ///Hill1///
    glBegin(GL_POLYGON);
    glColor3d(125.0 / 255.0, 104.0 / 255.0, 67.0 / 255.0);
    glVertex2f(-12.0,3);
    glVertex2f(-12.0,3.8);
    glVertex2f(-8, 6);
    glVertex2f(-3, 3.5);
    glVertex2f(1, 6);
    glVertex2f(5, 3);
    glVertex2f(10, 6.5);
    glVertex2f(15, 3.0);
    glVertex2f(20, 6);
    glVertex2f(25, 3.2);
    glVertex2f(30, 6.1);
    glVertex2f(33, 3.5);
    glVertex2f(36, 6);
    glVertex2f(38, 3.8);
    glVertex2f(38, 3);

    glEnd();

    ///Tree4///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(19, 0);
    glVertex2f(19, 1);
    glVertex2f(19.1, 1);
    glVertex2f(19.1, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(18, 1);
    glVertex2f(20, 1);
    glVertex2f(19, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(18, 1.5);
    glVertex2f(20, 1.5);
    glVertex2f(19, 2.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(18, 1.9);
    glVertex2f(20, 1.9);
    glVertex2f(19, 3);
    glEnd();

    ///Tree5///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(35, 1);
    glVertex2f(35, 2);
    glVertex2f(35.03, 2);
    glVertex2f(35.03, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(34.5, 1.5);
    glVertex2f(35.5, 1.5);
    glVertex2f(35, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(34.5, 1.8);
    glVertex2f(35.5, 1.8);
    glVertex2f(35, 2.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(34.5, 2.1);
    glVertex2f(35.5, 2.1);
    glVertex2f(35, 2.9);
    glEnd();

    ///Tree6///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(19.4, -2);
    glVertex2f(19.4, -1);
    glVertex2f(19.5, -1);
    glVertex2f(19.5, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(18.5, -1);
    glVertex2f(20.5, -1);
    glVertex2f(19.5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(161.0 / 255.0, 124.0 / 255.0, 59.0 / 255.0);
    glVertex2f(18.5, -0.5);
    glVertex2f(20.5, -0.5);
    glVertex2f(19.5, 1);
    glEnd();

    ///Sun///
    circle(13,9.5,1.5,1.5);

    if(cloud1_m > 45)
        cloud1_m = -12;
    else
        cloud1_m = cloud1_m + 0.005;

    ///Cloud1///
    circle2(cloud1_m, 9.5, 1.5, 1.5);

    ///Cloud2///
    circle2(cloud1_m + 1.5, 10.5, 1.5, 1.5);

    ///Cloud3///
    circle2(cloud1_m + 3, 9.5, 1.5, 1.5);

    if(cloud2_m < -25)
        cloud2_m = 38;
    else
        cloud2_m = cloud2_m - 0.005;

    ///Cloud4///
    circle2(cloud2_m, 10.5, 1.5, 1.5);

    ///Cloud5///
    circle2(cloud2_m + 1, 9.5, 1.5, 1.5);

    ///Cloud6///
    circle2(cloud2_m + 3, 10.5, 1.5, 1.5);

    glutSwapBuffers();
}


void DrawNight()
{
    glClear(GL_COLOR_BUFFER_BIT);



    ///sky///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3d(0.0, 0.1, 0.4);
    glVertex2f(38.0f,3.0f);
    glVertex2f(38.0f,14.0f);
    glVertex2f(-12.0f,14.0f);
    glVertex2f(-12.0f,3.0f);

    glEnd();

    ///Field///
    glBegin(GL_POLYGON);
    glColor3d(3.0 / 255.0, 61.0 / 255.0, 9.0 / 255.0);
    glVertex2f(-12, 3);
    glVertex2f(-12, -12);
    glVertex2f(38, -2);
    glVertex2f(38, 3);
    glEnd();

    ///Road1///
    glBegin(GL_POLYGON);
    glColor3d(8.0 / 255.0, 99.0 / 255.0, 17.0 / 255.0);
    glVertex2f(5, 3);
    glVertex2f(10, 3);
    glVertex2f(18.3, 1.2);
    glVertex2f(16.3, 1);
    glEnd();

    ///Road2///
    glBegin(GL_POLYGON);
    glColor3d(8.0 / 255.0, 99.0 / 255.0, 17.0 / 255.0);
    glVertex2f(7, 0);
    glVertex2f(7, -2);
    glVertex2f(18.3, 1.2);
    glVertex2f(18.3, 1.2);
    glEnd();

    ///Road3///
    glBegin(GL_POLYGON);
    glColor3d(8.0 / 255.0, 99.0 / 255.0, 17.0 / 255.0);
    glVertex2f(7, 0);
    glVertex2f(7, -2);
    glVertex2f(30.3, -5);
    glVertex2f(30.3, -4);
    glEnd();

    ///River///
    glBegin(GL_POLYGON);
    glColor3d(0.0, 0.0, 0.2);
    glVertex2f(-12, -12);
    glVertex2f(-12, -19);
    glVertex2f(38, -19);
    glVertex2f(38, -2);
    glEnd();



    ///Boat1///
    glBegin(GL_POLYGON);
    glColor3d(5.0 / 255.0, 37.0 / 255.0, 69.0 / 255.0);
    glVertex2f(17, -5);
    glVertex2f(19, -7);
    glVertex2f(22, -7);
    glVertex2f(24, -5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(87.0 / 255.0, 65.0 / 255.0, 16.0 / 255.0);
    glVertex2f(20, -5);
    glVertex2f(20, -3);
    glVertex2f(16.7, -5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(77.0 / 255.0, 55.0 / 255.0, 6.0 / 255.0);
    glVertex2f(21, -5);
    glVertex2f(21, -2.5);
    glVertex2f(21.2, -2.5);
    glVertex2f(21.2, -5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(77.0 / 255.0, 55.0 / 255.0, 6.0 / 255.0);
    glVertex2f(21.7, -5);
    glVertex2f(21.7, -2.5);
    glVertex2f(21.9, -2.5);
    glVertex2f(21.9, -5);
    glEnd();


    ///Boat2///
    glBegin(GL_POLYGON);
    glColor3d(5.0 / 255.0, 37.0 / 255.0, 69.0 / 255.0);
    glVertex2f(26, -3.5);
    glVertex2f(27.5, -4.5);
    glVertex2f(30, -4.5);
    glVertex2f(31.5, -3.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(115.0 / 255.0, 91.0 / 255.0, 97.0 / 255.0);
    glVertex2f(27.4, -3.5),
    glVertex2f(27.4, -2.5),
    glVertex2f(29.4, -2.5),
    glVertex2f(29.4, -3.5),
    glEnd();


    ///House1///
    glBegin(GL_POLYGON);
    glColor3d(115.0 / 255.0, 1.0 / 255.0, 22.0 / 255.0);
    glVertex2f(0, 0);
    glVertex2f(0, -4);
    glVertex2f(6, -4);
    glVertex2f(6, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(99.0 / 255.0, 1.0 / 255.0, 19.0 / 255.0);
    glVertex2f(-1, 0);
    glVertex2f(0, 2.5);
    glVertex2f(6, 2.5);
    glVertex2f(7, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(164.0 / 255.0, 186.0 / 255.0, 65.0 / 255.0);
    glVertex2f(2,-2);
    glVertex2f(2, -4);
    glVertex2f(3.5, -4);
    glVertex2f(3.5, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(164.0 / 255.0, 186.0 / 255.0, 65.0 / 255.0);
    glVertex2f(4.5, -1);
    glVertex2f(4.5, -2.5);
    glVertex2f(5.5, -2.5);
    glVertex2f(5.5, -1);
    glEnd();

    ///House2///
    glBegin(GL_POLYGON);
    glColor3d(82.0 / 255.0, 69.0 / 255.0, 24.0 / 255.0);
    glVertex2f(-6, -4.5);
    glVertex2f(-6, -8.5);
    glVertex2f(0, -8.5);
    glVertex2f(0, -4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(148.0 / 255.0, 119.0 / 255.0, 13.0 / 255.0);
    glVertex2f(-7, -4.5);
    glVertex2f(-6, -2.5);
    glVertex2f(0, -2.5);
    glVertex2f(1, -4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(164.0 / 255.0, 186.0 / 255.0, 65.0 / 255.0);
    glVertex2f(-4,-6.5);
    glVertex2f(-4, -8.5);
    glVertex2f(-2.5, -8.5);
    glVertex2f(-2.5, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(164.0 / 255.0, 186.0 / 255.0, 65.0 / 255.0);
    glVertex2f(-2, -7);
    glVertex2f(-2, -5.5);
    glVertex2f(-1, -5.5);
    glVertex2f(-1, -7);
    glEnd();

    ///House3///
    glBegin(GL_POLYGON);
    glColor3d(89.0 / 255.0, 80.0 / 255.0, 64.0 / 255.0);
    glVertex2f(29, 0);
    glVertex2f(29, -2);
    glVertex2f(32, -2);
    glVertex2f(32, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(87.0 / 255.0, 84.0 / 255.0, 81.0 / 255.0);
    glVertex2f(28, 0);
    glVertex2f(29, 1);
    glVertex2f(32, 1);
    glVertex2f(33, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(164.0 / 255.0, 186.0 / 255.0, 65.0 / 255.0);
    glVertex2f(30, -0.5);
    glVertex2f(30, -2);
    glVertex2f(31, -2);
    glVertex2f(31, -0.5);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3d(164.0 / 255.0, 186.0 / 255.0, 65.0 / 255.0);
    glVertex2f(31.3, -0.2);
    glVertex2f(31.3, -1);
    glVertex2f(31.8, -1);
    glVertex2f(31.8, -0.2);
    glEnd();

    ///Tree1///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(8, -1);
    glVertex2f(8, -4);
    glVertex2f(8.2, -4);
    glVertex2f(8.2, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(6.5, -1.5);
    glVertex2f(9.5, -1.5);
    glVertex2f(8, 1.5);
    glEnd();

    ///Tree2///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(2, -8.5);
    glVertex2f(2, -6.5);
    glVertex2f(2.2, -6.5);
    glVertex2f(2.2, -8.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(0, -7.5);
    glVertex2f(4, -7.5);
    glVertex2f(2, -5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(0, -7);
    glVertex2f(4, -7);
    glVertex2f(2, -4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(0, -6.5);
    glVertex2f(4, -6.5);
    glVertex2f(2, -3.5);
    glEnd();

    ///Tree3///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(12, -3);
    glVertex2f(12, -5);
    glVertex2f(12.2, -5);
    glVertex2f(12.2, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(11, -3.5);
    glVertex2f(13, -3.5);
    glVertex2f(12, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(11, -2.8);
    glVertex2f(13, -2.8);
    glVertex2f(12, -1.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(11, -2.4);
    glVertex2f(13, -2.4);
    glVertex2f(12, 1);
    glEnd();

    ///Hill1///
    glBegin(GL_POLYGON);
    glColor3d(94.0 / 255.0, 81.0 / 255.0, 58.0 / 255.0);
    glVertex2f(-12.0,3);
    glVertex2f(-12.0,3.8);
    glVertex2f(-8, 6);
    glVertex2f(-3, 3.5);
    glVertex2f(1, 6);
    glVertex2f(5, 3);
    glVertex2f(10, 6.5);
    glVertex2f(15, 3.0);
    glVertex2f(20, 6);
    glVertex2f(25, 3.2);
    glVertex2f(30, 6.1);
    glVertex2f(33, 3.5);
    glVertex2f(36, 6);
    glVertex2f(38, 3.8);
    glVertex2f(38, 3);

    glEnd();

    ///Tree4///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(19, 0);
    glVertex2f(19, 1);
    glVertex2f(19.1, 1);
    glVertex2f(19.1, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(18, 1);
    glVertex2f(20, 1);
    glVertex2f(19, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(18, 1.5);
    glVertex2f(20, 1.5);
    glVertex2f(19, 2.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(18, 1.9);
    glVertex2f(20, 1.9);
    glVertex2f(19, 3);
    glEnd();

    ///Tree5///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(35, 1);
    glVertex2f(35, 2);
    glVertex2f(35.03, 2);
    glVertex2f(35.03, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(34.5, 1.5);
    glVertex2f(35.5, 1.5);
    glVertex2f(35, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(34.5, 1.8);
    glVertex2f(35.5, 1.8);
    glVertex2f(35, 2.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(34.5, 2.1);
    glVertex2f(35.5, 2.1);
    glVertex2f(35, 2.9);
    glEnd();

    ///Tree6///
    glBegin(GL_POLYGON);
    glColor3d(69.0 / 255.0, 64.0 / 255.0, 56.0 / 255.0);
    glVertex2f(19.4, -2);
    glVertex2f(19.4, -1);
    glVertex2f(19.5, -1);
    glVertex2f(19.5, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(18.5, -1);
    glVertex2f(20.5, -1);
    glVertex2f(19.5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(117.0 / 255.0, 93.0 / 255.0, 42.0 / 255.0);
    glVertex2f(18.5, -0.5);
    glVertex2f(20.5, -0.5);
    glVertex2f(19.5, 1);
    glEnd();

    ///Moon///
    circle3(13,9.5,2,2);

    if(cloud1_m > 45)
        cloud1_m = -12;
    else
        cloud1_m = cloud1_m + 0.005;

    ///Cloud1///
    circle4(cloud1_m, 9.5, 1.5, 1.5);

    ///Cloud2///
    circle4(cloud1_m + 1.5, 10.5, 1.5, 1.5);

    ///Cloud3///
    circle4(cloud1_m + 3, 9.5, 1.5, 1.5);

    if(cloud2_m < -25)
        cloud2_m = 38;
    else
        cloud2_m = cloud2_m - 0.005;

    glutPostRedisplay();

    ///Cloud4///
    circle4(cloud2_m, 10.5, 1.5, 1.5);

    ///Cloud5///
    circle4(cloud2_m + 1, 9.5, 1.5, 1.5);

    ///Cloud6///
    circle4(cloud2_m + 3, 10.5, 1.5, 1.5);

    glutSwapBuffers();
}



void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:

        glutDisplayFunc(DrawDay);
        break;
    case GLUT_KEY_DOWN:

        glutDisplayFunc(DrawNight);
        break;

    }
    glutPostRedisplay();
}



int main(int argc,char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Ruposhi Bangla");
    init();
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(DrawDay);
    glutMainLoop();
    return 0;
}
