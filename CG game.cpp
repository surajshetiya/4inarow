Game project
 #include<GL/glut.h>
#include<math.h>
#include<stdio.h>
int p[2]={5,7};
int shape[2]={0,1};
int tshape,tcolor,tx,ty; // Temp variables
GLfloat arr[8][3]={ {0.0,0.0,1.0},{0.0,1.0,0.0},{0.0,1.0,1.0},
     {1.0,0.0,0.0},{1.0,0.0,1.0},{1.0,1.0,0.0},
     {1.0,1.0,1.0},{0.59,0.59,0.59}};
int a[8][7];
int chance=1;
int done;
int disp;
int first;
void output(GLfloat x, GLfloat y, char *text);
void func();
void square(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c);
void circle(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c);
void shaper(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c,int shape);
void grid();
void init();
void display();
int cal(int val,int j,int i,int val1,int val2);
int check(int i);
void demo_menu(int id);
void call();
void demo_menu1(int id);
void menu();
void demo_menu3(int id);
void newmenu();
void demo_menu2(int id);
void menu2(int &b);
void menu1(int &a);
void mainmenu();
void mouse(int btn,int st,int x,int y);
void square1(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c);
void circle1(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c);
void triangle(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c);
void triangle1(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c);
void newshape(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c);
void newshape(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c)
{
 float i,j;
 glColor3f(a,b,c);
 glPointSize(1.0);
 for(j=2*r;j>=r/2;j-=0.5)
 {
  glFlush();
  glBegin(GL_POINTS);
  for(i=0;i<=2*3.14;i=i+0.01)
  {
   if((r/2<abs(j*cos(i)))||(r/2<abs(j*sin(i))))
    continue;
   glVertex2f(h+j*cos(i),k+j*sin(i));
  }
  glEnd();
 }
 glFlush();
}
void triangle(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c)
{
 if(r==0)
  return;
 glColor3f(a,b,c);
 glBegin(GL_LINE_LOOP);
 glVertex2f(h+r*cos(3.14/2),k+r*sin(3.14/2));
 glVertex2f(h+r*cos((7*3.14)/6),k+r*sin((7*3.14)/6));
 glVertex2f(h+r*cos(3.14/6),k-r*sin(3.14/6));
 glEnd();
 glFlush();
 triangle(h,k,r-0.5,a,b,c);
}
void triangle1(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c)
{
 if(r==10)
  return;
 glColor3f(a,b,c);
 glBegin(GL_LINE_LOOP);
 glVertex2f(h+r*cos(3.14/2),k+r*sin(3.14/2));
 glVertex2f(h+r*cos((7*3.14)/6),k+r*sin((7*3.14)/6));
 glVertex2f(h+r*cos(3.14/6),k-r*sin(3.14/6));
 glEnd();
 glFlush();
 triangle1(h,k,r-0.5,a,b,c);
}
void circle1(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c)
{
 float i,j;
 glColor3f(a,b,c);
 glPointSize(1.0);
 for(j=r;j>=r/2;j-=0.5)
 {
  glFlush();
  glBegin(GL_POINTS);
  for(i=0;i<=2*3.14;i=i+0.01)
   glVertex2f(h+j*cos(i),k+j*sin(i));
  glEnd();
 }
 glFlush();
}
void square1(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c)
{
 if(r==15)
  return;
 glColor3f(a,b,c);
 glBegin(GL_LINE_LOOP);
 glVertex2f(h-r/2,k-r/2);
 glVertex2f(h-r/2,k+r/2);
 glVertex2f(h+r/2,k+r/2);
 glVertex2f(h+r/2,k-r/2);
 glEnd();
 glFlush();
 square1(h,k,r-0.5,a,b,c);
}
void output(GLfloat x, GLfloat y, char *text)
{
  char *p;
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.5,0.5,0.9);
  for (p = text; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}
void func()
{
 int i,j;
 for(i=0;i<=7;i++)
  for(j=0;j<=6;j++)
   a[i][j]=0;
}
void square(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c)
{
 if(r==0)
  return;
 glColor3f(a,b,c);
 glBegin(GL_LINE_LOOP);
 glVertex2f(h-r/2,k-r/2);
 glVertex2f(h-r/2,k+r/2);
 glVertex2f(h+r/2,k+r/2);
 glVertex2f(h+r/2,k-r/2);
 glEnd();
 glFlush();
 square(h,k,r-0.5,a,b,c);
}
void circle(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c)
{
 float i,j;
 glColor3f(a,b,c);
 glPointSize(1.0);
 for(j=0;j<=r;j+=0.5)
 {
  glFlush();
  glBegin(GL_POINTS);
  for(i=0;i<=2*3.14;i=i+0.01)
   glVertex2f(h+j*cos(i),k+j*sin(i));
  glEnd();
 }
 glFlush();
}
void shaper(GLfloat h,GLfloat k,GLfloat r,GLfloat a,GLfloat b,GLfloat c,int shape)
{
 if(shape==0)
  square(h,k,r,a,b,c);
 else if(shape==1)
  square1(h,k,r,a,b,c);
 else if(shape==2)
  circle(h,k,r,a,b,c);
 else if(shape==3)
  circle1(h,k,r,a,b,c);
 else if(shape==4)
  triangle(h,k,r,a,b,c);
 else if(shape==5)
  triangle1(h,k,r,a,b,c);
 else
  newshape(h,k,r,a,b,c);
}
void grid()
{
 GLint i;
 glColor3f(1.0,1.0,0.0);
 glBegin(GL_LINES);
  for(i=0;i<=7;i++)
  {
   glVertex2i(70*i+5,5);
   glVertex2i(70*i+5,495);
   glVertex2i(5,70*i+5);
   glVertex2i(495,70*i+5);
  }
 glEnd();
}
void init()
{
 glClearColor(0.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,600.0,0.0,600.0);
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glPointSize(2.0);
 grid();
 glColor3f(1.0,0.0,0.0);
 output(50,530,"Winning 4");
 glFlush();
}
int cal(int val,int j,int i,int val1,int val2)
{
 if(((j+val1)<0)||((j+val1)>6)||((i+val2)<0)||((i+val2)>6))
  return 0;
 else if(a[j+val1][i+val2]!=val)
  return 0;
 return 1+cal(val,j+val1,i+val2,val1,val2);
}
int check(int i)
{
 int j,l;
 if(a[7][i]==7)
  return 0;
 a[a[7][i]][i]=chance;
 chance=chance%2+1;
 a[7][i]+=1;
 j=a[7][i]-1;
 l=cal(a[j][i],j,i,1,0)+cal(a[j][i],j,i,-1,0)+1;
 if(l==4)
  return a[j][i];
 l=cal(a[j][i],j,i,0,1)+cal(a[j][i],j,i,0,-1)+1;
 if(l==4)
  return a[j][i];
 l=cal(a[j][i],j,i,1,1)+cal(a[j][i],j,i,-1,-1)+1;
 if(l==4)
  return a[j][i];
 l=cal(a[j][i],j,i,1,-1)+cal(a[j][i],j,i,-1,1)+1;
 if(l==4)
  return a[j][i]; 
 return 3;
}
void demo_menu(int id)
{
 switch(id)
 {
 case 1: done=0;
   chance=1;
   disp=0;
   func();
   mainmenu();
   glutAttachMenu(GLUT_RIGHT_BUTTON);
   break;
 case 2: exit(0);
   break;
 }
 glutPostRedisplay();
}
void call()
{
 shaper(tx,ty,30,arr[tcolor][0],arr[tcolor][1],arr[tcolor][2],tshape);
}
void demo_menu1(int id)
{
 int val;
 if(disp==2)
  return;
 switch(id)
 {
  case 1: val=1;
    break;
  case 2: val=2;
    break;
  case 3: val=3;
    break;
  case 4: val=4;
    break;
  case 5: val=5;
    break; 
  case 6: val=6;
    break; 
  case 7: val=7;
    break;
  case 8: val=8;
    break;
 }
 if(disp==0)
  p[0]=val-1;
 else if(disp==1&&p[0]!=(val-1))
  p[1]=val-1;
 if(disp==1)
  call();
}
void menu()
{
 glutCreateMenu(demo_menu);
 glutAddMenuEntry("Restart",1);
 glutAddMenuEntry("Quit",2);
}
void demo_menu3(int id)
{
 if(id==1)
  exit(0);
}
void newmenu()
{
 glutCreateMenu(demo_menu3);
 glutAddMenuEntry("Exit",1);
}
void demo_menu2(int id)
{
 if(disp==2)
  return;
 shape[disp]=id-1;
 if(disp==1)
  call();
}
void menu2(int &b)
{
 b=glutCreateMenu(demo_menu2);
 glutAddMenuEntry("Square",1);
 glutAddMenuEntry("HolowSquare",2);
 glutAddMenuEntry("Circle",3);
 glutAddMenuEntry("HollowCircle",4);
 glutAddMenuEntry("Triangle",5);
 glutAddMenuEntry("HollowTriangle",6);
 glutAddMenuEntry("Square-Circle",7);
}
void menu1(int &a)
{
 a=glutCreateMenu(demo_menu1);
 glutAddMenuEntry("Blue",1);
 glutAddMenuEntry("Green",2);
 glutAddMenuEntry("Cyan",3);
 glutAddMenuEntry("Red",4);
 glutAddMenuEntry("Magenta",5);
 glutAddMenuEntry("Yellow",6);
 glutAddMenuEntry("White",7);
 glutAddMenuEntry("Gray",8);
}
void mainmenu()
{
 int a,b;
 menu1(a);
 menu2(b);
 glutCreateMenu(demo_menu3);
 glutAddSubMenu("Colors",a);
 glutAddSubMenu("Shape",b);
 glutAddMenuEntry("Exit",1);
}
void mouse(int btn,int st,int x,int y)
{
 if(done)
  return;
 if(btn==GLUT_LEFT_BUTTON&&st==GLUT_DOWN)
 {
  if(x<5||x>495)
   return;
  int k=check((x-5)/70);
  if(k==0)
  {
   printf("%c",7);
   return;
  }
  disp++;
  int i=((x-5)/70),j=a[7][i],temp=chance;
  temp=temp%2;
  j--;
  j*=70;
  i=i*70;
  if(disp==1)
  {
   tx=i+40;
   ty=j+40;
   tshape=shape[temp];
   tcolor=p[temp];
  }
  if(disp==2)
  {
   newmenu();
   glutAttachMenu(GLUT_RIGHT_BUTTON);
  }
  shaper(i+40,j+40,30,arr[p[temp]][0],arr[p[temp]][1],arr[p[temp]][2],shape[temp]);
  glFlush();
  if(k!=3)
  {
   k=k-1;
   glClearColor(0,0,0,1);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(arr[p[k]][0],arr[p[k]][1],arr[p[k]][2]);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,450);
   glVertex2f(350,275);
   glEnd();
   output(50,500,"The Winner Is : ");
   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(100,10);
   glVertex2f(100,450);
   glVertex2f(90,450);
   glVertex2f(90,10);
   glEnd();
   glFlush(); 
   menu();
   glutAttachMenu(GLUT_RIGHT_BUTTON);
   done=1;
   disp=2;
   return ;
  }  
 }
}
void main(int argc,char **argv)
{
 func();
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,50);
 glutInitWindowSize(600,600);
 glutCreateWindow("Winning4");
 init(); 
 glutDisplayFunc(display);
  glutMouseFunc(mouse);
 mainmenu();
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 glutMainLoop();
}
