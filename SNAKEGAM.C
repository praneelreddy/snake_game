#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int count1=0;
void food(int *,int *);
void move(int*,int*,int*,int*,int,int,int *,int *);
void main()
{
 char ch;
 int i,j=1,n,gd=DETECT,gm;
 int a=300,u=1,x=0,t=0,b=225,c=320,d=245,count=0,f=1,g=0,h=0,flag=0,flag1=0,flag2=0,flag3=0,flag4=0,r=0;
 char s[20],z[20];
 clrscr();
 initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
 cleardevice();
 setcolor(BLUE);
 settextstyle(3,0,3);
 outtextxy(250,100,z);
 setcolor(GREEN);
 setbkcolor(LIGHTBLUE);
 for(i=0;i<500;i++){
 sound(5000*i);
 delay(5);
 nosound();
 sound(3000*i);
 delay(5);
 nosound();
 cleardevice();
 setcolor(BLUE);
 sprintf(z,"%d%",u);
 outtextxy(350,200,z);
 setfillstyle(1,BLUE);
 outtextxy(245,200,"Loading..");
 setcolor(GREEN);
 bar(80,250,90+i,270);
 x++;
 if(x==5)
 {
  x=0;
  u++;
 }
 }
 cleardevice();
 setbkcolor(6);
 delay(1000);
 setcolor(BLUE);
 settextstyle(6,0,6);
 outtextxy(120,200,"THE SNAKE GAME");
 delay(1000);
 cleardevice();
 setbkcolor(9);
 setcolor(RED);
 rectangle(20,100,620,460);
 setfillstyle(1,BLUE);
 bar(a,b,c,d);
 delay(500);
 for(i=0;i<10000;i++)
 {
  if(f==0){
  setfillstyle(SOLID_FILL,RED);
  bar(g,h,g+20,h+20);   }
  if(f==1)
  {
   food(&g,&h);
   f=0;
  }
  if(c<=620 && d<=460 && a>=20 &&b>=100){
  delay(50);
  cleardevice();
  settextstyle(8,0,7);
  setcolor(BLUE);
  outtextxy(170,10,"Score:");
  outtextxy(380,10,s);
  sprintf(s,"%d",t);
  setbkcolor(9);
  setcolor(RED);
  rectangle(20,100,620,460);
  setfillstyle(1,BLUE);
  bar(a,b,c,d);
  if(flag1==1){
  for(r=1;r<=count1;r++){
  bar(a,b+(20*r),c,d+(20*r));}
  }
  if(flag2==1)
  {
  for(r=1;r<=count1;r++){
  bar(a,b-(20*r),c,d-(20*r));}
  }
  if(flag3==1)
  {
  for(r=1;r<=count1;r++){
  bar(a+(20*r),b,c+(20*r),d);}
  }
  if(flag4==1)
  {
  for(r=1;r<=count1;r++){
  bar(a-(20*r),b,c-(20*r),d);}
  }
  if(kbhit())
  {
   ch=getch();
   if(ch=='w'|| ch==0x48 )
   {
   sound(6000);
   delay(100);
   nosound();
   count=1;
   flag1=1;
   flag2=0;
   flag3=0;
   flag4=0;
   for(r=1;r<=count1;r++){
   bar(a,b+(20*r),c,d+(20*r));}
    }
   else if(ch=='s'|| ch==0x50)
   {
   sound(5000);
   delay(100);
   nosound();
   count=2;
   flag1=0;
   flag2=1;
   flag3=0;
   flag4=0;
   for(r=1;r<=count1;r++){
   bar(a,b-(20*r),c,d-(20*r));}
   }
   else if(ch=='a' || ch==0x4b)
   {
   sound(5000);
   delay(100);
   nosound();
   count=3;
   flag1=0;
   flag2=0;
   flag3=1;
   flag4=0;
   for(r=1;r<=count1;r++){
   bar(a+(20*r),b,c+(20*r),d);}
   }
   else if(ch=='d'|| ch==0x4d)
   {
   sound(5000);
   delay(100);
   nosound();
   count=4;
   flag1=0;
   flag2=0;
   flag3=0;
   flag4=1;
   for(r=1;r<=count1;r++){
   bar(a-(20*r),b,c-(20*r),d);}
   }
   }
   else if(ch=='q')
   break;
   else
   {
   setfillstyle(1,BLUE);
   move(&a,&b,&c,&d,count,f,&flag,&count1);
   bar(a,b,c,d);
   }
   if(f==0 && c>=g+10 && c<=g+30 && b>=h-10 && b<=h+10 && d>=h+10 && d<=h+30 && a>=g-10 && a<=g+10)
   {
    f=1;
    t=t+10;
    sound(3000);
    delay(200);
    nosound();
    move(&a,&b,&c,&d,count,f,&flag,&count1);
   }
 }
   else
  {
  sound(1000);
  delay(500);
  nosound();
  cleardevice();
  setbkcolor(GREEN);
  settextstyle(7,0,6);
  outtextxy(170,190,"GAME OVER");
  delay(800);
  break;
  }
 }
}
void food(int *g,int *h)
{
 *g=rand()%580+20;
 *h=rand()%360+90;
}
void move(int *a,int *b,int *c,int *d,int count,int f,int *flag,int *count1)
{
 if(count==0 && f==0)
 {
  *a=*a+5;
  *c=*c+5;
 }
 else if(count==1 && f==0)
 {
  *b=*b-5;
  *d=*d-5;
 }
 else if(count==2 && f==0)
 {
  *b=*b+5;
  *d=*d+5;
 }
 else if(count==3 && f==0)
 {
  *a=*a-5;
  *c=*c-5;
 }
 else if(count==4 && f==0)
 {
  *a=*a+5;
  *c=*c+5;
 }
 else if(count==0 && f==1)
 {
  *flag=4;
  *count1=*count1+1;
 }
 else if(count==1 && f==1)
 {
  *flag=1;
  *count1=*count1+1;
 }
 else if(count==2 && f==1)
 {
  *flag=2;
  *count1=*count1+1;
 }
 else if(count==3 && f==1)
 {
  *flag=3;
  *count1=*count1+1;
 }
 else if(count==4 && f==1)
 {
  *flag=4;
  *count1=*count1+1;
 }
}
