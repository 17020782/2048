#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<time.h>
#include<cstdlib>
#include <fstream>
#include<string>
using namespace std;
//toa do bien
int Val[4][4]={0};
char map[55][55];
int ViTri[4];
int diem=0;
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
void Draw(int x, int y,int a)
{
	gotoxy(x,y);
	
	cout<<a;
}
struct paint
{
	
	int x;
	int y;
	int color;
	string str;
	
};
void Paint(int x, int y, int color, string str)
{
	gotoxy(x,y);
	textcolor(color);
	cout << str;
}

int DrawMap()
{	
	
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<25;j++)
		{
			
			if(i==0 || i==16|| j==0 || j==24 || i==4 || i==8 || i==12 || j==6 || j==12 || j== 18)
				textcolor(112);
			else
				textcolor(51);

			cout<<map[i][j];
		}
		cout<<endl;
	}

	paint hd={30, 4, 11, "Huong Dan: "};
	Paint(hd.x, hd.y, hd.color, hd.str);
	
	paint st={31,5,6,"A: Sang Trai"};
	Paint(st.x, st.y, st.color, st.str);
	

	paint sp={ 31, 6, 13, "D: Sang Phai"};
	Paint(sp.x, sp.y, sp.color, sp.str );

	paint lt={ 31, 7, 14, "W: Len Tren"};
	Paint(lt.x, lt.y, lt.color, lt.str );

	paint xd={ 31, 8, 10, "S: Xuong Duoi"};
	Paint(xd.x, xd.y, xd.color, xd.str);


	paint quit={ 30, 10, 15, "Nhan X de thoat game."};
	Paint(quit.x, quit.y, quit.color, quit.str );
	textcolor(10);
	return 0;
}
int main()
{
	DrawMap();
	gotoxy(1,18);
}

