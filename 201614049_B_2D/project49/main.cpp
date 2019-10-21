#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>


#include <stdlib.h>

#include <math.h>

#define PI 3.1416


static GLfloat spin = 0.0;//spin korar jnne initial degree
static float	tx	=  0.0;
static float	ty	=  0.0;
float x=-7.0,y=-5.0,z=0.0,zz=0.0;
float bx=0.0,by=0.0,ballAngle=0.0,cx=0.0,cy=0.0,cx1=-70.0,cy1=190.0,cx2=90.0,cy2=190.0,bax=-5.0,bay=20.0,ux=0.0,uy=0.0,fx=0.0,fy=0.0;
int f = 0,sp=0;
int timer=0;
int day=0;

void drawSmallBall(float p,float q,int c){
    int i=0;
	float angle = 0.0;
	glBegin(GL_POLYGON);
    //glColor3f(0.686274,0.933333,0.933333);
    //glColor3f( 0.5294117  , 0.8078431  , 0.980392);
    if(c==1)glColor3f(1.0,0.5,0);
    else if(c==2) glColor3f(1.0,1.0,0);
    else if(c==3) glColor3f(0,1.0,0);
    else if (c==4)glColor3f(0,0.5,1.0);
    else if (c==5)glColor3f(0,1.00,1.0);
    else if (c==6)glColor3f(1.0,0,1.0);
    else if (c==7)glColor3f(0,0.5,1.0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (p+cos(angle) * 5,q+ sin(angle) * 5);
    }

	glEnd();
}

void drawBall(){
    glPushMatrix();//static part static thakbe
    int i=0;
	float angle = 0.0;
	glBegin(GL_POLYGON);
    //glColor3f(0.686274,0.933333,0.933333);
    //glColor3f( 0.5294117  , 0.8078431  , 0.980392);

    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (bx-70.0+cos(angle) * 20,by-70.0+ sin(angle) * 20);
        glColor3f(0.5,0.3,1);
    }

	glEnd();

	drawSmallBall(bx-70.0,by-70.0,1);

	drawSmallBall(bx-70.0,by-85.0,2);

	drawSmallBall(bx-57.0,by-77.5,3);

	drawSmallBall(bx-57.0,by-63.0,4);

	drawSmallBall(bx-70.0,by-55.0,5);

	drawSmallBall(bx-83.0,by-77.5,6);

    drawSmallBall(bx-83.0,by-63.0,7);

	glPopMatrix();
}

void drawCloud1(){

    //cloud 1
    glPushMatrix();
    int i=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx+20+cos(angle) * 30, cy+250+sin(angle) * 20);
    }

	glEnd();
	glPopMatrix();

	glPushMatrix();
    i=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx+-10+cos(angle) * 20, cy+240+sin(angle) * 10);
    }

	glEnd();
	glPopMatrix();

	glPushMatrix();
    i=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx+40+cos(angle) * 20, cy+240+sin(angle) * 10);
    }

	glEnd();
	glPopMatrix();


}

void drawCloud2(){
    glPushMatrix();//static part static thakbe
    int i=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx1-20+cos(angle) * 30, cy1+10+sin(angle) * 20);
    }

	glEnd();
	glPopMatrix();

	glPushMatrix();//static part static thakbe
    i=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx1-45+cos(angle) * 20, cy1+sin(angle) * 10);
    }

	glEnd();
	glPopMatrix();

	glPushMatrix();//static part static thakbe
    i=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx1+cos(angle) * 20, cy1+sin(angle) * 10);
    }

	glEnd();
	glPopMatrix();
}

void drawCloud3(){

	glPushMatrix();//static part static thakbe
    int i=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx2+20+cos(angle) * 30, cy2+10+sin(angle) * 20);
    }

	glEnd();
	glPopMatrix();

	glPushMatrix();//static part static thakbe
    i=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx2+45+cos(angle) * 20, cy2+sin(angle) * 10);
    }

	glEnd();
	glPopMatrix();

	glPushMatrix();//static part static thakbe
    i=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (cx2+cos(angle) * 20, cy2+sin(angle) * 10);
    }

	glEnd();
	glPopMatrix();
}
void drawSun(){

    glPushMatrix();//static part static thakbe
    int i=0;
    int k=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
	 glColor3f(1,1,0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (80+cos(angle) * 20, 250+sin(angle) * 20);
        if(k==0){
            glColor3f(1,1,0);
            k=1;
        }
        else{
            glColor3f(1,1,1);
            k=0;
        }
    }

	glEnd();
	glPopMatrix();
}

void drawPool(){

    glPushMatrix();//static part static thakbe
    int i=0;
    int k=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (13+cos(angle) * 125, sin(angle) * 75);
        if(k==1){
            glColor3f(0.933333,0.933333,0);
            k=0;
        }
        else{
             glColor3f(1,1,0);
             k=1;
        }

    }

	glEnd();
	glPopMatrix();


    glPushMatrix();//static part static thakbe
    i=0;
	angle = 0.0;
	glBegin(GL_POLYGON);
    //glColor3f(0.686274,0.933333,0.933333);
    //glColor3f( 0.5294117  , 0.8078431  , 0.980392);
    glColor3f(1,1,1);
    //glColor3f(0,0.749019,1.0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (13+cos(angle) * 100, sin(angle) * 60);

        glColor3f(0,0.749019,1.0);
    }

	glEnd();

	glPopMatrix();


}


void drawDolphin(){
    float x1,y1,x2,y2,x3,y3;

    //glColor3f( 0.5294117  , 0.8078431  , 0.980392);
    //glColor3f(0.690196,0.768627,0.870588);
    glColor3f(0.690196,0.768627,0.870588);
    //Head
    glPushMatrix();
    glBegin(GL_POLYGON);
	x1=x;y1=y;x2=x+15;y2=y+20;x3=x+40;y3=y-5;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {
        float tempx=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float tempy=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
       // cout<<x<<" "<<y<<endl;
        glVertex3f( tempx, tempy,0 );
    }
    glEnd();
    glPopMatrix();
    //Beak
    glPushMatrix();
	glBegin(GL_POLYGON);
	x1=x;y1=y;x2=x-25;y2=y-5;x3=x;y3=y-10;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {
        float tempx=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float tempy=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
       // cout<<x<<" "<<y<<endl;
        glVertex3f( tempx, tempy,0 );
    }
    glEnd();
    glPopMatrix();
    //UpFin
    glBegin(GL_POLYGON);
	x1=x+40;y1=y-5;x2=x+70;y2=y-20;x3=x+45;y3=y-20;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {
        float tempx=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float tempy=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
       // cout<<x<<" "<<y<<endl;
        glVertex3f( tempx, tempy,0 );
    }
    glEnd();

    //Body

    glBegin(GL_POLYGON);
    glVertex3f( x+40, y-5 , 0 );
    glVertex3f( x, y, 0 );
    glVertex3f( x, y-10,0 );
    glVertex3f( x+10,y-18,0);
    glVertex3f( x+20,y-20,0);
    glVertex3f( x+20,y-35,0);
    glVertex3f( x+25,y-40,0);
    glVertex3f( x+50,y-40,0);
    glVertex3f( x+45, y-20,0 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f( x+20,y-20,0);
    glVertex3f( x+20,y-35,0);
    glVertex3f( x+14,y-25,0);
    glEnd();

    //WhitePart
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(x+10,y-10,0);
    glVertex3f(x,y-10,0);
    glVertex3f(x+10,y-18,0);
    glVertex3f( x+20,y-20,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f( x+20,y-20,0);
    glVertex3f( x+14,y-25,0);
    glVertex3f( x+20,y-35,0);
    glVertex3f( x+25,y-40,0);
    glVertex3f( x+30,y-40,0);
    glEnd();

    glColor3f(0.690196,0.768627,0.870588);
    //LFin
    glBegin(GL_POLYGON);
	x1=x;y1=y-35;x2=x+10;y2=y-10;x3=x+20;y3=y-20;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {
        float tempx=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float tempy=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
       // cout<<x<<" "<<y<<endl;
        glVertex3f( tempx, tempy,0 );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x,y-35,0);
    glVertex3f(x+25,y-25,0);
    glVertex3f(x+20,y-20,0);
    glEnd();

    //BeakLine

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(x-13,y-5,0);
    glVertex3f(x,y-5,0);
    glEnd();

    //Eye
    int i=0;
	float angle = 0.0;
	glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (x+13+cos(angle) * 5, y+sin(angle) * 5);
    }

	glEnd();

	angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);

    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (x+14+cos(angle) * 2, y+1+sin(angle) * 2);
    }

	glEnd();

	angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);

    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (x+12+cos(angle) * 1, y-1+sin(angle) * 1);
    }

	glEnd();

}

void spinDisplay(void)
{
        zz++;
        if(zz>100)zz-=100;
        float angle = 2 * PI * zz / 100;
        x =x+cos(angle) * 4;
        y= y+sin(angle) * 2;
        Sleep(80);
        //printf("%f %f %f\n",x,y,zz);
        glutPostRedisplay();
   //glutPostRedisplay();
}

void spinIt(){
    ballAngle+=1.0;
    if(ballAngle>360.0) ballAngle-=360.0;
    glutPostRedisplay();
}

void drawScene(){
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0.392156,0);
    glVertex3f(150,80,0);
    glColor3f(0,0.392156,0);
    glVertex3f(-150,80,0);
    glColor3f(0,0.803921,0);
    glVertex3f(-150,-150,0);
    glColor3f(0,1,0.498039);
    glVertex3f(150,-150,0);
    glEnd();
    glPushMatrix();
    glBegin(GL_POLYGON);
   // glColor3f(0.529411,0.807843,0.921568);
    glColor3f(0,0.749019,1);
    glVertex3f(150,300,0);
    glColor3f(0,0.749019,1);

    glVertex3f(-150,300,0);
   // glColor3f(0,0.749019,1);
    glColor3f(1,1,1);
    glVertex3f(-150,80,0);
    //glColor3f(0.529411,0.807843,0.921568);
    glColor3f(1,1,1);
    glVertex3f(150,80,0);
    glEnd();

}

void moveCloud1(){
    cx+=1;
    if(cx>150)cx=-200;
}

void moveCloud2(){
    cx1+=1;
    if(cx1>200)cx1=-200;
}

void moveCloud3(){
    cx2+=1;
    if(cx2>150)cx2=-200;
}

void drawWater(){
    glPushMatrix();//static part static thakbe
    int i=0;
    int k=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
	//glColor3f(1,1,1);
	glColor3f(0,0.749019,1.0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (-125+cos(angle) * 20,-70+sin(angle) * 8);
        //glColor3f(0,0.749019,1.0);
    }
	glEnd();
	glPopMatrix();
	glPushMatrix();//static part static thakbe
    i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (-115+cos(angle) * 10,-75+sin(angle) * 5);
        glColor3f(0,0.749019,1.0);
    }
	glEnd();
	glPopMatrix();

    glPushMatrix();//static part static thakbe
    i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(0,0.749019,1.0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (-70+cos(angle) * 20,-86+sin(angle) * 8);
    }
	glEnd();
	glPopMatrix();
	glPushMatrix();//static part static thakbe
    i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (-80+cos(angle) * 10,-95+sin(angle) * 5);
        glColor3f(0,0.749019,1.0);
    }
	glEnd();
	glPopMatrix();

	glPushMatrix();//static part static thakbe
    i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);

    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (110+cos(angle) * 30,-120+sin(angle) * 8);glColor3f(0,0.749019,1.0);
    }
	glEnd();
	glPopMatrix();
	glPushMatrix();//static part static thakbe
    i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (80+cos(angle) * 10,-125+sin(angle) * 5);
        glColor3f(0,0.749019,1.0);
    }
	glEnd();
	glPopMatrix();
}

void drawBucket(){
	glPushMatrix();//static part static thakbe
    int i=0;
    int k=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (bax-120+cos(angle) * 15,bay-90+sin(angle) * 5);
    }
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0.388235,0.278431);
    glVertex3f(bax-100,bay-30,0);
    glColor3f(1,0.388235,0.278431);
    glVertex3f(bax-140,bay-30,0);
    glColor3f(1,0,0);
    glVertex3f(bax-135,bay-90,0);
    glColor3f(1,0,0);
    glVertex3f(bax-105,bay-90,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();//static part static thakbe
    i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (bax-120+cos(angle) * 20,bay-30+sin(angle) * 10);
        if(k==0){
            glColor3f(1,0,0);
            k=1;
        }
        else{
            glColor3f(1,0,0);
            k=0;
        }
    }

	glEnd();
	glPopMatrix();

	i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (bax-120+cos(angle) * 17,bay-30+sin(angle) * 7);
        glColor3f(0,0.749019,1.0);
    }
	glEnd();
	glPopMatrix();
}

void drawUmbrella(){

    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3f(1,0.388235,0.278431);
    glColor3f(1,0,0);
    glVertex3f(ux-105,uy+220,0);
    glColor3f(1,1,1);
    glVertex3f(ux-170,uy+180,0);
    glColor3f(1,0,0);
    glVertex3f(ux-154,uy+180,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex3f(ux-105,uy+220,0);
    glColor3f(1,1,1);
    glVertex3f(ux-154,uy+180,0);
    glColor3f(0,0,1);
    glVertex3f(ux-128,uy+180,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(ux-105,uy+220,0);
    glColor3f(1,1,1);
    glVertex3f(ux-128,uy+180,0);
    glColor3f(1,0,0);
    glVertex3f(ux-102,uy+180,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex3f(ux-105,uy+220,0);
    glColor3f(1,1,1);
    glVertex3f(ux-102,uy+180,0);
    glColor3f(0,0,1);
    glVertex3f(ux-76,uy+180,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(ux-105,uy+220,0);
    glColor3f(1,1,1);
    glVertex3f(ux-76,uy+180,0);
    glColor3f(1,0,0);
    glVertex3f(ux-50,uy+180,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex3f(ux-105,uy+220,0);
    glColor3f(1,1,1);
    glVertex3f(ux-50,uy+180,0);
    glColor3f(0,0,1);
    glVertex3f(ux-40,uy+180,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex3f(ux-102,uy+180,0);
    glColor3f(1,0,1);
    glVertex3f(ux-105,uy+180,0);
    glColor3f(1,1,1);
    glVertex3f(ux-100,uy+0,0);
    glColor3f(1,1,1);
    glVertex3f(ux-97,uy+0,0);
    glEnd();
    glPopMatrix();
}

void fence(){
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(fx-140,fy+150,0);
    glColor3f(0.803921,0.521568,0.247058);
    glVertex3f(fx-150,fy+140,0);
    glColor3f(1,0.647058,0.309803);
    glVertex3f(fx-130,fy+140,0);
    glColor3f(0.803921,0.521568,0.247058);
    //glVertex3f(ux-97,uy+0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0.647058,0.309803);
    glVertex3f(fx-130,fy+140,0);
    glColor3f(0.803921,0.521568,0.247058);
    glVertex3f(fx-150,fy+140,0);
    glColor3f(0.803921,0.521568,0.247058);
    glVertex3f(fx-150,fy+80,0);
    glColor3f(1,0.647058,0.309803);
    glVertex3f(fx-130,fy+80,0);
    glEnd();
    glPopMatrix();
}

void drawFence(){
    for(int i=0;i<20;i++){
        fence();
        fx+=20;
        if(fx>280) fx=0;
    }
}

void drawLifebuoy(){
    glPushMatrix();//static part static thakbe
    int i=0;
    int k=0;
    float angle = 0.0;
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (bax+110+cos(angle) * 30,bay-120+sin(angle) * 25);
        if(k=0){
            glColor3f(1,0,0);
            k=1;
        }
        else{
            glColor3f(1,0.5,0);
            k=0;
        }
    }
	glEnd();
	glPopMatrix();
	i=0;
    k=0;
    angle = 0.0;
	glBegin(GL_POLYGON);
    glColor3f(0.462745,0.933333,0);
    for(i = 0; i < 100; i++)
    {
        float angle = 2 * PI * i / 100;
        glVertex2f (bax+110+cos(angle) * 18,bay-117+sin(angle) * 10);
    }
	glEnd();
	glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    timer++;
    Sleep(38);
    if(timer==120){
        PlaySound("Dolphin.wav", NULL, SND_FILENAME| SND_ASYNC);
        timer=0;
    }
    if(f==1 && zz==97.00){

    }
    else spinDisplay();


    drawScene();

    drawSun();

    moveCloud1();

    moveCloud2();

    moveCloud3();

    drawCloud1();

    drawCloud2();

    drawCloud3();

    drawPool();

    drawFence();

    drawUmbrella();

    drawDolphin();

    drawWater();

    glPushMatrix();
    if(sp==1 && zz==97.00){
        spinIt();
        bx=70.0;
        by=70.0;
        glTranslatef(0.0,24.0, 0.0);
        glRotatef(ballAngle, 0.0f, 0.0f, 1.0f);
        //Sleep(10);
        drawBall();
    }
    else{
        bx=0.0;
        by=0.0;
        drawBall();
        printf("%f %f\n",cx,cy);
        glutPostRedisplay();
        Sleep(35);
    }
    glPopMatrix();

    drawLifebuoy();

    drawBucket();

    glFlush();
}



void stop(){
    if(f==1){
        f=0;
        sp=0;
    }
    else{
        f=1;
        sp=0;
    }
    glutPostRedisplay();
}


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-150.0, 150.0, -150.0, 300.0, -150.0, 150.0);
}

void spinBall(){
    if(sp==1){
        sp=0;
    }
    else if(f==1){
        sp=1;
    }
    else{
        stop();
        sp=1;
    }
    glutPostRedisplay();
}

void right(){
    bx+=1;
    printf("%f %f\n",bx,by);
    glutPostRedisplay();
}

void up(){
    by+=1;
    printf("%f %f\n",bx,by);
    glutPostRedisplay();
}

void leftt(){
    bx-=1;
    printf("%f %f\n",bx,by);
    glutPostRedisplay();
}

void down(){
    by-=1;
    printf("%f %f\n",bx,by);
    glutPostRedisplay();
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 's':
			stop();
			break;
        case 'b':
			spinBall();
			break;
        case 'i':
            up();
            break;
        case 'k':
            down();
            break;
        case 'l':
            right();
            break;
        case 'j':
            leftt();
            break;
        default:
			break;
	}
}



void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            spinBall();
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN){
            //printf("LL\n");
            spinBall();
         }
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:
         break;
   }
}


void my_reshape(int w, int h)
{
	glViewport (0,0,1000, 700);//frame boro kora

}


int main()
{
    PlaySound("Dolphin.wav", NULL, SND_FILENAME| SND_ASYNC);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 700);
	glutInitWindowPosition (100, 100);
	//glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-1000)/2,(glutGet(GLUT_SCREEN_HEIGHT)-700)/2);
	glutCreateWindow ("201614049");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutReshapeFunc(my_reshape);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

