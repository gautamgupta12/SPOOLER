#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int a[100][3];
#define INTIALXCQ 214
#define INTIALY 479
#define INTIALXPQ 564
int cpu_flage=1;
float processing=0;
int printer_flage=1;
float printing=0;
int count=0;
float speed=1;
int com=0;

void info(int c)
{
	setcolor(c);
	char *a;
	int e=112;
	sprintf(a,"     INFORMATION ");
	line(40,e-10,110+20-3,e-10);
	outtextxy(0,e-20,a);
	sprintf(a," Total job    : %d",count);
	outtextxy(0,e,a);
	sprintf(a," Left job     : %d",count-com);
	outtextxy(0,e +20,a);
	sprintf(a," Completed job: %d",com);
	outtextxy(0,e +20*2,a);
	sprintf(a," Speed        : %.1f",speed);
	outtextxy(0,e +20*3,a);
}
int on=0;
void con()
{
	int c=(on==1)?15:0;
	setcolor(c);
	char *a;
	int e=132;
	sprintf(a,"      CONTROAL ");
	line(50-2,e+20*4+10,80+30,e+20*4+10);
	outtextxy(0,e+20*4,a);
	sprintf(a," q    : Quit");
	outtextxy(0,e +20*5,a);
	sprintf(a," a    : Add new job");
	outtextxy(0,e +20*6,a);
	sprintf(a," s    : Increse speed");
	outtextxy(0,e +20*7,a);
	sprintf(a," x    : Increse speed");
	outtextxy(0,e +20*8,a);
	sprintf(a," d    : decrese speed");
	outtextxy(0,e +20*9,a);
	sprintf(a," c    : decrese speed");
	outtextxy(0,e +20*10,a);
	sprintf(a," spcebar: Pause");
	outtextxy(0,e +20*11,a);
	sprintf(a," h     : Hide/show");
	outtextxy(0,e +20*12,a);
}
void welcome(int x,int y)
{
	char *p="spooling";
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setcolor(3);
	outtextxy(x-100,y-20,p);
	delay(1500);
	setcolor(0);
	outtextxy(x-100,y-20,p);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setcolor(15);
}
//cpu
void cpu()
{
	rectangle(50*4+139,74,50*7+139,74+6*20);
}
//Printer
void printer()
{
	rectangle(50*4+139,74+12*20,50*7+139,74+18*20);
}
void queu_cpu()
{
	rectangle(50+139-2,74+40-1,50+50+139+2,94+380+2);
}
void queu_printer()
{
	rectangle(50*8+139-2,74+13*20-1,50*9+139+2,74+20*20+2);
}
// random genrater job
void job_random(int i)
{
	time_t t;
	srand((unsigned)time(&t));
//	int r;
//	do{
//	r=rand();
//	}while(r>3&&r<10);
	a[i][0]=1;
	a[i][1]=INTIALXCQ;
	a[i][2]=INTIALY;
}
void greed()
{
	setcolor(6);
	int i;
	for(i=0;i<10;i++)
	rectangle(0+50*i+139,74,50+50*i+139,479-15);
	setcolor(8);
	for(i=0;i<21;i++)
	rectangle(0+139,74+20*i,500+139,94+20*i);//479-15);
}
void combo(int x,int y)
{
	setcolor(15);
	rectangle(0,0,x,y);
	//greed();
	rectangle(139+30,72,500+139,INTIALY);
	setcolor(15);
	cpu();
	printer();
	setcolor(7);
	queu_cpu();
	queu_printer();
}
void creat(int x,int y,int c)
{
	setcolor(c);
	rectangle(x-25,y,x+25,y+20);
}
int cpu_processing()
{
	char *p;
	sprintf(p,"%d %",(int)processing);
	setcolor(0);
	outtextxy(139+275-4-4,114+10-2-2,p);
	processing+=.5;
	sprintf(p,"%d %",(int)processing);
	setcolor(15);
	outtextxy(139+275-4-4,114+10-2-2,p);
       //	delay(speed);
	if(processing==100)
	{
		setcolor(0);
		outtextxy(139+275-4-4,114+10-4,p);
		setcolor(15);
		processing=0;
		return 1;
	}
	else
		return 0;
}
int printer_processing()
{
	char *p;
	sprintf(p,"%d %",(int)printing);
	setcolor(0);
	outtextxy(139+275-4-4,314+10-2-2,p);
	printing+=.1;
	sprintf(p,"%d %",(int)printing);
	setcolor(15);
	outtextxy(139+275-4-4,314+10-2-2,p);
       //	delay(speed);
	if(printing>=100)
	{
		setcolor(0);
		outtextxy(139+275-4-4,314+10-4,p);
		setcolor(15);
		printing=0;
		return 1;
	}
	else
		return 0;
}
void move()
{
	int i;
	for(i=0;i<100;i++)
	{
		if(a[i][0]!=0)
		{
		       //	if(i==1||i==0)
		       //	cout<<a[i][1]<<" "<<a[i][2]<<" ";
			delay(speed);
			//clrscr();
			//cout<<c<<" ";
			switch(a[i][0])
			{
			case 1://cpu queue
				if(a[i][2]!=114)
				{
					//whenever array will filled up to 100 check condition
					if(((a[i][2]-20-2)-a[i-1][2]>=2)||((i-1)<0))
					{
						creat(a[i][1],a[i][2],0);
						a[i][2]--;
						creat(a[i][1],a[i][2],7);
			       //			delay(speed);
					}
					else
					{
						if(a[i-1][1]>=100+25+139)
						{
							creat(a[i][1],a[i][2],0);
							a[i][2]--;
							creat(a[i][1],a[i][2],7);
			     //				delay(speed);
						}
					}
				}
				else
				{
				//check cpu is free or not if it is then assign job
					if(cpu_flage==1)
					{
						a[i][0]++;
						i--;
					}


				}
				break;
			case 2://entering cpu
				if(a[i][1]!=414)
				{
					cpu_flage=0;
					creat(a[i][1],a[i][2],0);
					a[i][1]++;
					creat(a[i][1],a[i][2],7);
			   //		delay(speed);
				}
				else
				{
					a[i][0]++;
					i--;
				}
				break;
			case 3://cpu processing
				cpu_flage=cpu_processing();
				if(cpu_flage==1)
				{
					a[i][0]++;
					i--;
				}
				break;
			case 4://leve cpu
				if(a[i][1]!=500+139+25+1)
				{
					creat(a[i][1],a[i][2],0);
					a[i][1]++;
					creat(a[i][1],a[i][2],7);
				       //	delay(speed);
				}
				else
				{
					a[i][0]++;
					a[i][1]=INTIALXPQ;
					a[i][2]=INTIALY;
				}
				break;
			case 5://printer queue
				if(a[i][2]!=334)
				{
					//whenever array will filled up to 100 check condition
					if(((a[i][2]-20-2)-a[i-1][2]>=2)||((i-1)<0))
					{
						creat(a[i][1],a[i][2],0);
						a[i][2]--;
						creat(a[i][1],a[i][2],7);
				     //		delay(speed);
					}
					else
					{
						if(a[i-1][1]<=139+400-25)
						{
							creat(a[i][1],a[i][2],0);
							a[i][2]--;
							creat(a[i][1],a[i][2],7);
				   //			delay(speed);
						}
					}
				}
				else
				{
				//check cpu is free or not if it is then assign job
					if(printer_flage==1)
					{
						a[i][0]++;
						i--;
					}
				}
				break;
			case 6://entering printer
				if(a[i][1]!=414)
				{
					printer_flage=0;
					creat(a[i][1],a[i][2],0);
					a[i][1]--;
					creat(a[i][1],a[i][2],7);
				 //	delay(speed);
				}
				else
				{
					a[i][0]++;
					i--;
				}
				break;
			case 7://printing
				printer_flage=printer_processing();
				if(printer_flage==1)
				{
					info(0);
					a[i][0]++;
					creat(a[i][1],a[i][2],0);
					a[i][0]=0;
					i--;
				       //	c--;
					if(count-com<=10)
						job_random(count++);
				      //	c++;
					com++;
					info(15);
				}
				break;
			}
		}
	}
}

void arro(int xi,int yi,int xf,int yf,int f)
{
	line(xi,yi,xf,yf);
	if(f)
	{
		if(f==1)
		{
			line(xf,yf,xf-10,yf-5);
			line(xf,yf,xf-10,yf+5);
		}
		else
		if(f==2)
		{
			line(xf,yf,xf-10,yf+5);
			line(xf,yf,xf+10,yf+5);
		}
	}
}
void information(int x,int y)
{
	//greed();
	char *p="INFORMATION";
	int sc=100;
	int si;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(200-10,60,p);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	sprintf(p,"CONTROAL");
	outtextxy((100+x)/2-35,y-100+30-20,p);
	sprintf(p,"DETAIL");
	outtextxy(x+80,y-100+30-20,p);
	rectangle(0,0,x*2,y*2);
	line(x,y-100,x,y+100+10);
	char a[6][30]={
		"    q    : Quit",
		"    a    : Add new job",
		"    s    : Increse speed",
		"    d    : decrese speed",
		" spcebar : Pause",
		"    h    : Hide/show controal"
	};
	char b[5][25]={
		" Total job           : 1",
		" Left job            : 1",
		" Completed job       : 0",
		" Job in cpu queu     : 1",
		" Job in printer queu : 0"
	};
	sc=100-20;
	for(int i=1;i<=7;i++)
	{
		if(i!=7)
			line(sc,y-100+30*i,x*2-100,y-100+30*i);
		if(i!=1)
		{
		    //	arro(sc+3,y-100+30*i-15,sc+20,y-100+30*i-15,1);
			outtextxy(sc+2,y-100+30*i-20+3,a[i-2]);
			if(i<7)
			{
		    //		arro(x+3,y-100+30*i-15,x+20,y-100+30*i-15,1);
				outtextxy(x+2,y-100+30*i-20+3,b[i-2]);
			}
		}
	}
	while(!kbhit())
	{
		setcolor(199);
		outtextxy(x-50,y+190,"PRESS ENTER");
		delay(400);
		setcolor(0);
		outtextxy(x-50,y+190,"PRESS ENTER");
		delay(200);
	}
	getch();
}
void head()
{
	char *p="spooling";
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setcolor(15);
	outtextxy(169+100-20,20,p);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(169+10+3,72+20,"cpu queu");
	outtextxy(200+139+60,74+120+20,"cpu");
	outtextxy(400+139-17,74+260-1-20,"printer queu");
	outtextxy(200+139+50,74+240-20,"printer");
	setcolor(15);
}
int main()
{
	int as=DETECT,sa;
	initgraph(&as,&sa,"");
	int x=getmaxx();
	int y=getmaxy();
	welcome(x/2,y/2);
	information(x/2,y/2);
	cleardevice();
	combo(x,y);
	head();
	job_random(count++);
	int special;
	while(special!='q')
	{
		while(!kbhit())
		{
			info(15);
			move();
		}
		special=getch();
		if(special=='a')
		{
			info(0);
			job_random(count++);
		       //	c++;
			info(15);
		}
		if(special==' ')
		{
			int z;
			do
			{
			//pause
				z=getch();
			}while(z!=' ');
		}
		if(special=='s')
		{
			if(speed>=0.1)
			{
				info(0);
				speed-=.1;
				info(15);
			}
			else
			{
				info(0);
				speed=0.0;
				info(15);
			}
		}
		if(special=='d')
		{
			info(0);
			speed+=.1;
			info(15);
		}
		if(special=='x')
		{
			if(speed>=0.05)
			{
				info(0);
				speed-=.05;
				info(15);
			}
			else
			{
				info(0);
				speed=0.0;
				info(15);
			}
		}
		if(special=='c')
		{
			info(0);
			speed+=.05;
			info(15);
		}
		if(special=='h')
		{
			on=(on==1)?0:1;
			con();
		}
	}
	//thanks
	getch();
	closegraph();
	return 0;
}
