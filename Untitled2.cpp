#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<time.h>
#include<cstdlib>
#include <fstream>
#include<string>
using namespace std;
char map[50][55];
int ViTri[4];
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Draw(int x, int y,int codeCol,int a)
{
	gotoxy(x,y);
	textcolor(codeCol);
	cout<<a;


}

//Tao Map Tao Khung Vien
int SetMap(char map[][55] )
{
	resizeConsole(700,280);
	//Ve Khung GameView
	for(int i=0;i<17;i++)
	{

		for(int j=0;j<25;j++)
		{


			if((j==6 || j==12 || j== 18) && (i!=0 || i!= 24))
			{

				map[i][j]=' ';

			}
			if(i==0 || i== 16)
			{
				map[i][j]=' ';

			}
			if(i==4 || i==8 || i==12)
			{

				map[i][j]=' ';

			}
			if(j==0 || j== 24)
			{
				map[i][j]=' ';

			}

		}

	}
	map[0][0]=' ';
	map[16][24]=' ';
	map[0][24]=' ';
	map[16][0]=' ';

	return 0;
}
//In Map ra man hinh + set mau
int DrawMap(char map[][55])
{
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<25;j++)
		{
			//textcolor(32);
			if(i==0 || i==16|| j==0 || j==24 || i==4 || i==8 || i==12 || j==6 || j==12 || j== 18)
				textcolor(112);
			else
				textcolor(51);

			cout<<map[i][j];
		}
		cout<<endl;
	}
	textcolor(11);
	gotoxy(30,4);
	cout<<"Huong Dan:";
	textcolor(7);
	gotoxy(30,5);
	cout<<"_A: Sang Trai";
	textcolor(13);
	gotoxy(30,6);
	cout<<"_D: Sang Phai";
	textcolor(14);
	gotoxy(30,7);
	cout<<"_W: Keo  Len";
	gotoxy(30,8);
	textcolor(10);
	cout<<"_S: Keo Xuong";
	gotoxy(27,10);
	textcolor(15);
	cout<<"Nhan X de thoat chuong trinh.";
	textcolor(10);
	return 0;
}

